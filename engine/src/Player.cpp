#include "Player.hpp"

#include "InputManager.hpp"
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Game.hpp"

Player* Player::player;

Player::Player(GameObject& associated) : Component(associated)
{
    associated.AddComponent(new Collider(associated));
    
    Sprite* sprite = new Sprite(associated, "assets/img/player_iddle.png", 4, 0.25);
    associated.AddComponent(sprite);

    associated.box.h = sprite->GetHeight();
    associated.box.w = sprite->GetWidth();

    state = MOVING;
    punchTimer = Timer();
    punchOffset = 2.5;
}

Player::~Player()
{
    player = nullptr;
}

void Player::Start()
{

}

void Player::Update(float dt)
{
    if(state == MOVING)
    {
        if(InputManager::GetInstance().IsKeyDown(SDLK_UP))
        {
            if(Game::GetInstance().GetHeight()/4 < associated.box.y)
            {
                associated.box.y -= 10;
            }
        }
        if(InputManager::GetInstance().IsKeyDown(SDLK_DOWN))
        {
            if(Game::GetInstance().GetHeight() - 200 > associated.box.y)
            {
                associated.box.y += 10;
            }
        }
        if(InputManager::GetInstance().IsKeyDown(SDLK_LEFT))
        {
            associated.box.x -= 10;
        }
        if(InputManager::GetInstance().IsKeyDown(SDLK_RIGHT))
        {
            associated.box.x += 10;
        }
        if(InputManager::GetInstance().IsKeyDown(SDLK_SPACE))
        {
            state = PUNCH;
            punchTimer.Restart();

            GameObject* playerPunch = new GameObject();
		    playerPunch->box.x = associated.box.x;
		    playerPunch->box.y = associated.box.y;
            playerPunch->AddComponent(new Sprite(*playerPunch, "assets/img/player_punch_left.png", 5, 0.5, 2.5));
		    //Sound* sound = new Sound(*playerPunch, "assets/audio/boom.wav");
        }
    }
    else if(state == PUNCH)
    {
        punchTimer.Update(dt);

        if (punchTimer.Get() > punchOffset)
        {
            state = MOVING;
        }
    }
}

void Player::Render()
{

}

bool Player::Is(std::string type)
{
    return type == "Player";
}


void Player::NotifyCollision (GameObject& other)
{

}