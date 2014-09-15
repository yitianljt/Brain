//
//  GameManager.cpp
//  Brain
//
//  Created by jintao on 14-9-15.
//
//

#include "GameManager.h"

USING_NS_CC;
static GameManager* s_SharedManager = nullptr;

GameManager::GameManager()
{
    
}

GameManager::~GameManager()
{
    
}

bool GameManager::init()
{
    return true;
}


GameManager* GameManager::getInstance()
{
    if (!s_SharedManager) {
        s_SharedManager = new GameManager();
        s_SharedManager->init();
    }
    return s_SharedManager;
}

void GameManager::start()
{
    
}

void GameManager::changeGameState(EGameState state)
{
    switch (state)
	{
        case EGameState::NONE:
            changeScene(EGameScene::WELCOME);
            break;
        case EGameState::LOGINERROR:
            break;
        case EGameState::LOGINSUCCESS:
            changeScene(EGameScene::MENU);
            break;
        case EGameState::PLAYING:
            changeScene(EGameScene::GAMELAYER);
            break;
        case EGameState::PAUSE:
            break;
        case EGameState::RESUME:
            break;
        case EGameState::GAMEOVER:
            break;
        case EGameState::RANDING:
        {
            changeScene(EGameScene::MENU);
            break;
        }
        case EGameState::LOGINOUT:
        {
            changeScene(EGameScene::WELCOME);
            break;
        }
        default:
            break;
            
	}
}

void GameManager::changeScene(EGameScene gs)
{
    auto* scene = Scene::create();
    switch (gs) {
        case EGameScene::WELCOME:
        {
            break;

        }
            
        default:
            break;
    }
    
    
}
