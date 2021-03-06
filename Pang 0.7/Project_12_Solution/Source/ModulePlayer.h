#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	// Constructor
	ModulePlayer(bool startEnabled);

	// Destructor
	~ModulePlayer();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	Update_Status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	Update_Status PostUpdate() override;

	bool CleanUp() override;

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;

	void DebugDrawGamepadInfo();

public:
	// Position of the player in the map
	iPoint position;

	// The speed in which we move the player (pixels per frame)
	int speed = 1;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;
	boolean shoot = true;
	boolean debug = false;

	boolean doubleshot = false;

	int shoots = 0;

	uint lives = 2;

	int tempDW = 0;

	int tempIn = 0;

	bool stairs = false;

	bool start = true;

	bool dead = false;

	int tempdeath = 0;
	
	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// A set of animations
	Animation idleAnim;
	Animation upAnim;
	Animation downAnim;
	Animation rightAnim;
	Animation leftAnim;
	Animation shootAnim;
	Animation death;

	Animation godIdle;
	Animation godUp;
	Animation godRight;
	Animation godLeft;
	Animation godShoot;


	SDL_Texture* livess;

	// The player's collider
	Collider* collider = nullptr;

	bool godmode = false;
	bool godmodetime = false;
	// A flag to detect when the player has been destroyed
	bool destroyed = false;

	uint destroyedCountdown = 120;
	// Sound effects indices
	uint laserFx = 0;
	uint explosionFx = 0;

	bool level1 = false;
	bool level2 = false;
	bool level3 = false;
	bool level4 = false;
	bool level5 = false;
	bool level6 = false;

	// Font score index
	uint score = 000;
	uint totalscore = 0;
	int scoreFont = -1;
	char scoreText[10] = { "\0" };
	bool debugGamepadInfo = false;
	int livepo = 10;
	bool VulcanB = false;
	bool powerwireB = false;
	bool dynamite = false;

	int ms = 0;
	int t = 0;
	char time[3] = { "\0" };
};

#endif //!__MODULE_PLAYER_H__