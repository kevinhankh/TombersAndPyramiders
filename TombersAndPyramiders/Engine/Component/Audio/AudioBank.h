#pragma once

//These are keys to access the proper audio chunks
#define MUSIC_MENU 0
#define MUSIC_LEVEL_1 1
#define MUSIC_GHOST 3

#define SFX_HIT 10
#define SFX_SWORD 11
#define SFX_BOW 12
#define SFX_SHIELD 13
#define SFX_DASH 14
#define SFX_DOOR 15
#define SFX_BUTTON_HOVER 16

//Audio file paths
#ifdef __APPLE__
#define PATH_MUSIC_MENU "Game/Assets/Audio/SpectralSands.ogg"
#define PATH_MUSIC_LEVEL_1 "Game/Assets/Audio/MystifyingTombs.ogg"
#define PATH_MUSIC_LEVEL_2 "Game/Assets/Audio/GhastlyNuisance.ogg"
#elif defined _WIN32 || defined _WIN64
#define PATH_MUSIC_MENU "Game/Assets/Audio/SpectralSands.mp3"
#define PATH_MUSIC_LEVEL_1 "Game/Assets/Audio/MystifyingTombs.mp3"
#define PATH_MUSIC_LEVEL_2 "Game/Assets/Audio/GhastlyNuisance.mp3"
#endif 


#define PATH_SFX_HIT "Game/Assets/Audio/Hit.wav"
#define PATH_SFX_SWORD "Game/Assets/Audio/Sword.wav"
#define PATH_SFX_BOW "Game/Assets/Audio/Arrow.wav"
#define PATH_SFX_SHIELD "Game/Assets/Audio/Shield.wav"
#define PATH_SFX_DASH "Game/Assets/Audio/Dash.wav"
#define PATH_SFX_DOOR "Game/Assets/Audio/Door.wav"
#define PATH_SFX_BUTTON_HOVER "Game/Assets/Audio/Torch.wav"