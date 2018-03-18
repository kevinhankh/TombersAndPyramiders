
#include "Codec.h"
#include "Room.h"
#include "BinaryTree.h"
#include <vector>

class GeneratorManager
{
private:
	static GeneratorManager* s_instance;
	std::shared_ptr<BinaryTree> m_worldTree;

public:
	std::vector<std::shared_ptr<Room>> rooms;
	std::vector<std::shared_ptr<Room>> corridors;

	static GeneratorManager* getInstance();
	void generateLevel(int width, int height, int detailLevel);
	GeneratorManager();
};