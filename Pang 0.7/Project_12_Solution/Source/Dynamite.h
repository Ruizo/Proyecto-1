#ifndef _Dynamite_H_
#define _Dynamite_H_

#include "Booster.h"

class Dynamite : public Booster
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Dynamite(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

	void OnCollision(Collider* collider);

	boolean godmode = false;

private:

	// The original spawning position. The wave will be calculated from that
	int spawn_y = 0;

	// The total height of the wave
	int waveHeight = 15;

	Collider* c3;
	// The enemy animation
	Animation flyAnim;

	Animation anim;
};



#endif // _Dynamite_H
