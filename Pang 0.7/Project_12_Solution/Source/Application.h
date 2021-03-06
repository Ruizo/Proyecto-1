#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 27

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class ModulePlayer;
class ScenePreIntro;
class SceneIntro;
class worldMap;
class SceneLevel1;
class SceneLevel2;
class SceneLevel3;
class SceneLevel4;
class SceneLevel5;
class SceneLevel6;
class SceneOver;
class SceneWin;
class ModuleParticles;
class ModuleCollisions;
class ModuleEnemies;
class ModuleFadeToBlack;
class ModuleDebugInfo;
class ModuleBoosters;
class ModuleFonts;
class Death;
class ModuleRender;
class Vulcan;
class PowerWire;

class Application
{

public:

	//Constructor. Creates all necessary modules for the application
	Application();

	//Destructor. Removes all module objects
	~Application();

	//Initializes all modules
	bool Init();

	//Updates all modules (PreUpdate, Update and PostUpdate)
	Update_Status Update();

	//Releases all the application data
	bool CleanUp();

public:
	// An array to store all modules
	Module* modules[NUM_MODULES];

	// All the modules stored individually
	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;

	ModulePlayer* player = nullptr;

	ScenePreIntro* scenePreIntro = nullptr;
	SceneIntro* sceneIntro = nullptr;
	worldMap* WorldMap = nullptr;
	SceneLevel1* sceneLevel_1 = nullptr;
	SceneLevel2* sceneLevel_2 = nullptr;
	SceneLevel3* sceneLevel_3 = nullptr;
	SceneLevel4* sceneLevel_4 = nullptr;
	SceneLevel5* sceneLevel_5 = nullptr;
	SceneLevel6* sceneLevel_6 = nullptr;

	Death* death = nullptr;
	SceneOver* sceneOver = nullptr;
	SceneWin* sceneWin = nullptr;
	ModuleEnemies* enemies = nullptr;
	ModuleParticles* particles = nullptr;

	ModuleCollisions* collisions = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	ModuleFonts* fonts = nullptr;
	ModuleBoosters* Boosters = nullptr;
	ModuleDebugInfo* debugInfo = nullptr;
	Vulcan* vulcanB = nullptr;
	PowerWire* powerwireB = nullptr;
	ModuleRender* render = nullptr;
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__