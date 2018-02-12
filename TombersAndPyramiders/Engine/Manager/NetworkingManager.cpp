#include "NetworkingManager.h"
#include "MessageManager.h"

NetworkingManager* NetworkingManager::s_instance;

NetworkingManager* NetworkingManager::getInstance()
{
	if (s_instance == NULL)
		s_instance = new NetworkingManager();
	return s_instance;
}

NetworkingManager::NetworkingManager()
{
	SDLNet_Init();
	m_messageQueue = new ThreadQueue<std::string>();

	for (int i = 0; i < 16; ++i)
		m_players[i] = NULL;
}

bool NetworkingManager::createHost()
{
	return host();
}

bool NetworkingManager::createClient()
{
	return join();
}

bool NetworkingManager::isConnected()
{
	return m_socket != NULL;
}

bool NetworkingManager::isHost()
{
	return m_client != NULL;
}

bool NetworkingManager::host()
{
	// create a listening TCP socket on port 9999 (server)
	IPaddress ip;
	int channel;

	int startConnTime = SDL_GetTicks();
	int timeoutTime = SDL_GetTicks();
	const int TIMEOUT = 60000;

	if (SDLNet_ResolveHost(&ip, NULL, m_port) == -1)
	{
		printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		return false;
	}

	m_socket = SDLNet_TCP_Open(&ip);
	if (!m_socket)
	{
		//  printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		std::string error = SDLNet_GetError();
		return false;
	}
	m_udpSocket = SDLNet_UDP_Open(m_port);
	if (!m_udpSocket)
	{
		std::string udpError = SDLNet_GetError();
		return false;
	}

	//addPlayer(ip.host);
	channel = SDLNet_UDP_Bind(m_udpSocket, DEFAULT_CHANNEL, &ip);

	bool result = false;
	while (!(result = accept()) && SDL_GetTicks() - startConnTime < TIMEOUT);
	if (result)
	{
		std::cout << "Connection established." << std::endl;
		pollMessages();
		return true;
	}
	else
	{
		std::cout << "No peer found, destroying server." << std::endl;
		close();
		return false;
	}
}

bool NetworkingManager::join()
{
	IPaddress ip;
	int channel;

	if (SDLNet_ResolveHost(&ip, IP, m_port) == -1)
	{
		printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		return false;
	}

	m_socket = SDLNet_TCP_Open(&ip);
	if (!m_socket)
	{
		printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		close();
		return false;
	}
	m_udpSocket = SDLNet_UDP_Open(m_port);
	if (!m_udpSocket)
	{
		printf("SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		closeUDP();
		return false;
	}

	channel = SDLNet_UDP_Bind(m_udpSocket, DEFAULT_CHANNEL, &ip);

	std::cout << "SDLNet_TCP_Open:A>A>A WE DID IT JOIN" << std::endl;
	std::cout << "SDLNet_UDP_Open:A>A>A WE DID IT JOIN" << std::endl;
	pollMessages();
	return true;
}

bool NetworkingManager::accept()
{
	m_client = SDLNet_TCP_Accept(m_socket);
	if (!m_client)
	{
		return false;
	}
	// communicate over new_tcpsock
	std::cout << "SDLNet_TCP_Accept:A>A>A WE DID IT ACCETP" << std::endl;
	return true;
}

bool NetworkingManager::close()
{
	if (m_client != NULL)
	{
		SDLNet_TCP_Close(m_client);
		m_client = NULL;
	}
	if (m_socket != NULL)
	{
		SDLNet_TCP_Close(m_socket);
		m_socket = NULL;
	}
	return true;
}

bool NetworkingManager::closeUDP()
{
	if (m_udpClient != NULL)
	{
		SDLNet_UDP_Close(m_udpClient);
		m_udpClient = NULL;
	}
	if (m_udpSocket != NULL)
	{
		SDLNet_UDP_Close(m_udpSocket);
		m_udpSocket = NULL;
	}
	return true;
}

//Host->Sending Messages->Client Exits->Host Crashes on line SDLNet_TCP_Send
void NetworkingManager::send(std::string *msg)
{
	// send a hello over sock
	//TCPsocket sock;
	int result, len;
	len = msg->length() + 1;

	if (m_client != NULL)
		result = SDLNet_TCP_Send(m_client, msg->c_str(), len);
	else if (m_socket != NULL)
		result = SDLNet_TCP_Send(m_socket, msg->c_str(), len);

	if (result < len)
	{
		//printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
	}
}

bool NetworkingManager::createUDPPacket(int packetSize)
{
	m_udpPacket = SDLNet_AllocPacket(packetSize);

	if (m_udpPacket == NULL)
	{
		std::cout << "SDLNet_AllocPacket failed : " << SDLNet_GetError() << "\n";
		return false;
	}

	m_udpPacket->address.port = m_port;

	return true;
}

void NetworkingManager::sendUDP(std::string *msg)
{
	createUDPPacket(msg->length());
	memcpy(m_udpPacket->data, msg->c_str(), msg->length());

	if (SDLNet_UDP_Send(m_udpClient, DEFAULT_CHANNEL, m_udpPacket) == 0)
		std::cout << "SDLNET_UDP_SEND failed: " << SDLNet_GetError() << "\n";
}

void NetworkingManager::pollMessages()
{
	m_messagesToSend.clear();
	m_receiverThread = std::thread(&NetworkingManager::pollMessagesThread, this);
	m_receiverThread.detach();
}

void NetworkingManager::pollMessagesThread()
{
#define MAXLEN 16384
	int result;
	char msg[MAXLEN];

	while (m_socket != NULL)
	{ //replace with on connection lost

		if (m_client != NULL)
			result = SDLNet_TCP_Recv(m_client, msg, MAXLEN);
		else if (m_socket != NULL)
			result = SDLNet_TCP_Recv(m_socket, msg, MAXLEN);
		if (result <= 0)
		{
			close();
			continue;
		}
		std::string newMsg = msg;
		m_messageQueue->push(newMsg);
	}
	close();
}

void NetworkingManager::pollMessagesUDP()
{
	m_messagesToSend.clear();
	m_udpReceiverThread = std::thread(&NetworkingManager::pollMessagesThreadUDP, this);
	m_udpReceiverThread.detach();
}

void NetworkingManager::pollMessagesThreadUDP()
{
#define MAXLEN 16384
	int result;
	char msg[MAXLEN];

	while (m_udpSocket != NULL)
	{ //replace with on connection lost

		if (m_udpClient != NULL || m_udpSocket != NULL)
			result = SDLNet_UDP_Recv(m_udpClient, &m_udpReceivedPacket);
		if (result < 0)
		{
			closeUDP();
			continue;
		}
		std::string newMsg(m_udpReceivedPacket.data, m_udpReceivedPacket.data+MAXLEN);
		m_messageQueue->push(newMsg);
	}
	closeUDP();
}

bool NetworkingManager::getMessage(std::string &msg)
{
	if (!m_messageQueue->isEmpty())
	{
		m_messageQueue->pop(msg);
		return true;
	}
	return false;
}

void NetworkingManager::prepareMessageForSending(std::string key, std::map<std::string, std::string> data)
{
	Message message;
	message.key = key;
	message.data = data;
	m_messagesToSend.push_back(message);
}

//TODO: Do over time
void NetworkingManager::sendQueuedEvents()
{
	std::string packet = "[";
	for (size_t i = 0; i < m_messagesToSend.size(); i++)
	{
		packet += serializeMessage(m_messagesToSend[i]);
		packet += ",";
	}
	packet.pop_back();
	packet += "]";
	//Submit it
	m_messagesToSend.clear();

	//std::cout << "SENDING PACKET: " << packet << std::endl;
	send(new std::string(packet));
}

void NetworkingManager::sendEventToReceiver(std::map<std::string, void*> data)
{
	std::string* key = (std::string*)data["key"];
	std::string value = *key;
	MessageManager::sendEvent(value, data);
}

std::string NetworkingManager::serializeMessage(Message message)
{
	std::string result = "{";
	message.data["key"] = message.key.c_str();

	for (const auto tuple : message.data)
	{
		result += tuple.first + ":" + message.data[tuple.first] + ",";
	}
	result.pop_back();
	result += "}";
	return result;
}


void NetworkingManager::handleParsingEvents(std::string packet)
{
	std::vector<std::string> messages;
	if (packet.size() > 2)
	{
		packet.erase(0, 1);
		packet.pop_back();
		std::string currentMessage;
		bool reading = false;
		while (packet.size() > 0)
		{
			if (!reading)
			{
				if (packet[0] == '{')
				{
					reading = true;
					currentMessage += packet[0];
				}
			}
			else
			{
				currentMessage += packet[0];
				if (packet[0] == '}')
				{
					reading = false;
					messages.push_back(currentMessage);
					sendEventToReceiver(deserializeMessage(currentMessage));
					currentMessage = "";
				}
			}

			packet.erase(0, 1);
		}
	}
}



//TODO: Deserialize this:
//Example: {key : Player|UPDATE,rotation : 37.000000,scale : 1.000000,x : 1.000000,y : 0.000000}

std::map<std::string, void*> NetworkingManager::deserializeMessage(std::string message)
{
	std::map<std::string, void*> data;
	std::string currentKey = "";
	std::string currentValue = "";
	bool readingKey;
	bool readingValue;
	while (message.size() > 0)
	{
		char curChar = message[0];
		message.erase(0, 1);

		if (curChar == ',' || curChar == '{')
		{
			//Start reading key
			readingKey = true;
			readingValue = false;
			if (curChar == ',')
			{
				data[currentKey] = (void*)new std::string(currentValue);
			}
			std::string newCurrentString = "";
			std::string newCurrentValue = "";
			currentKey = newCurrentString;
			currentValue = newCurrentValue;
			continue;
		}
		else if (curChar == ':')
		{
			//Start reading value
			readingValue = true;
			readingKey = false;
			continue;
		}
		else if (curChar == '}')
		{
			//End
			data[currentKey] = (void*)new std::string(currentValue);
			break;
		}
		if (!isspace(curChar))
		{
			if (readingKey)
			{
				currentKey += curChar;
			}
			else if (readingValue)
			{
				currentValue += curChar;
			}
		}

	}
	return data;
}

void NetworkingManager::setIP(char *ip, int p)
{
	IP = ip;
	m_port = p;
}

int NetworkingManager::addPlayer(UINT32 ip)
{
	int playerId;

	for (int i = 0; i < 16; ++i)
	{
		if (m_players[i] != NULL)
		{
			m_players[i] = ip;
			playerId = i;
		}
	}

	return playerId;
}

int NetworkingManager::removePlayer(UINT32 ip)
{
	int playerId;

	for (int i = 0; i < 16; ++i)
	{
		if (m_players[i] == ip)
		{
			m_players[i] = NULL;
			playerId = i;
		}
	}

	return playerId;
}