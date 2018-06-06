#include "SDL2/SDL.h"

#include "StageScene.hpp"
#include "Sprite.hpp"
#include "Sound.hpp"
#include "TileMap.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"
#include "CameraFollower.hpp"
#include "Collider.hpp"
#include "Collision.hpp"
#include "TitleScene.hpp"
#include "Game.hpp"
#include "Player.hpp"

StageScene::StageScene()
{
    quitRequested = false;
	started = false;

    backgroundMusic = Music("sample_assets/audio/stageState.ogg");
    backgroundMusic.Play(-1);
        
    GameObject* bg = new GameObject();
    bg->AddComponent(new Sprite(*bg, "assets/img/background.png"));
	bg->AddComponent(new CameraFollower(*bg));
	objectArray.emplace_back(bg);

	/*
	GameObject* map = new GameObject();
	TileSet* tile = new TileSet(*map, 64, 64, "sample_assets/img/tileset.png");
	TileMap* tileMap = new TileMap(*map, "sample_assets/map/tileMap.txt", tile);
	map->box.y = map->box.x = 0;
	map->AddComponent(tileMap);
	objectArray.emplace_back(map);
	*/

	GameObject* playerGO = new GameObject();
	Player* player = new Player(*playerGO);
	playerGO->box.x = 512;
	playerGO->box.y = 300;
	playerGO->AddComponent(player);
	objectArray.emplace_back(playerGO);

	Camera::pos.x = Camera::pos.y = 0;
	//Camera::Follow(playerGO);
}

StageScene::~StageScene()
{
    objectArray.clear();
}

void StageScene::LoadAssets()
{

}

void StageScene::Start()
{
	LoadAssets();

	StartArray();
}

void StageScene::Update(float dt)
{
	Camera::Update(dt);

	if(InputManager::GetInstance().KeyPress(SDLK_ESCAPE) || InputManager::GetInstance().QuitRequested())
	{
		popRequested = true;
		TitleScene* titleScene = new TitleScene();
        Game::GetInstance().Push(titleScene);
	}

	UpdateArray(dt);

	for(int i = 0; i < (int) objectArray.size(); ++i) 
	{
		Collider* a = (Collider*)objectArray[i]->GetComponent("Collider");
		if (a != nullptr) 
		{
			for(int j = i+1; j < (int) objectArray.size(); ++j) 
			{
				Collider* b = (Collider*)objectArray[j]->GetComponent("Collider");
				if (b != nullptr) 
				{
					if (Collision::IsColliding(a->box, b->box, objectArray[i]->angleDeg * (M_PI / 180), objectArray[j]->angleDeg * M_PI / 180)) 
					{
						objectArray[i]->NotifyCollision(*objectArray[j].get());
						objectArray[j]->NotifyCollision(*objectArray[i].get());
					}
				}
			}
		}
	}


	for(int i = 0; i < (int) objectArray.size(); ++i)
	{
		if(objectArray[i]->IsDead())
		{
			objectArray.erase(objectArray.begin() + i);
		}
	}
}

void StageScene::Render()
{
	for(int i = 0; i < (int) objectArray.size(); ++i)
	{
		if(objectArray[i]->GetComponent("TileMap") != nullptr)
		{
			objectArray[i]->box.x = Camera::pos.x;
			objectArray[i]->box.y = Camera::pos.y;
		}
		objectArray[i]->Render();
	}
}

void StageScene::Pause()
{

}

void StageScene::Resume()
{

}