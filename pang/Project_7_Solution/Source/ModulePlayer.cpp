#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	// idle animation - just one sprite
	idleAnim.PushBack({ 0, 0, 25, 32 });

	// move upwards
	upAnim.PushBack({ 0, 0, 25, 32 });
	upAnim.PushBack({ 0, 0, 25, 32 });
	upAnim.loop = false;
	upAnim.speed = 0.1f;

	// Move down
	downAnim.PushBack({ 33, 1, 32, 14 });
	downAnim.PushBack({ 0, 1, 32, 14 });
	downAnim.loop = false;
	downAnim.speed = 0.1f;

	// Move right

	rightAnim.PushBack({ 26,0,30,32 });
	rightAnim.PushBack({ 56,0,30,32 });
	rightAnim.PushBack({ 86,0,28,32 });
	rightAnim.PushBack({ 114,0,29,32 });
	rightAnim.loop = true;
	rightAnim.speed = 0.1f;

	// Move left
	leftAnim.PushBack({ 145,0,30,32 });
	leftAnim.PushBack({ 175,0,30,32 });
	leftAnim.PushBack({ 205,0,28,32 });
	leftAnim.PushBack({ 233,0,30,32 });
	leftAnim.loop = true;
	leftAnim.speed = 0.1f;

	// Shoot
	shootAnim.PushBack({ 0,35,27,29 });
	shootAnim.loop = false;
	shootAnim.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/player.png");
	currentAnimation = &idleAnim;

	laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");

	position.x = 170;
	position.y = 200;

	collider = App->collisions->AddCollider({ position.x, position.y, 28, 32 }, Collider::Type::PLAYER, this);

	return ret;
}

update_status ModulePlayer::Update()
{
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}	
	}
	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	/*if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnim)
		{
			downAnim.Reset();
			currentAnimation = &downAnim;
		}
		
	}*/
	/*if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (currentAnimation != &upAnim)
		{
			upAnim.Reset();
			currentAnimation = &upAnim;
		}
	}*/

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		if (currentAnimation != &shootAnim)
		{
			position.y = 203;
			shootAnim.Reset();
			currentAnimation = &shootAnim;
		}
		App->particles->AddParticle(App->particles->laser, position.x + 12, position.y + 20, Collider::Type::PLAYER_SHOT);
		App->audio->PlayFx(laserFx);
	}

	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_IDLE)
	{
		currentAnimation = &idleAnim;
		position.y = 200;
	}

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	if (destroyed)
	{
		destroyedCountdown--;
		if (destroyedCountdown <= 0)
			return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	return update_status::UPDATE_CONTINUE;
}

/*void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);
		
		App->audio->PlayFx(explosionFx);

		destroyed = true;
	}
}*/