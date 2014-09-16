//
//  GameManager.cpp
//  Brain
//
//  Created by jintao on 14-9-15.
//
//

#include "GameManager.h"
#include "MainLayer.h"


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
    changeScene(EGameScene::WELCOME);
}


void GameManager::changeScene(EGameScene gs)
{
	auto *scene = Scene::create();
	switch (gs)
	{
        case EGameScene::MENU:
        {

            break;
        }
        case EGameScene::GAMEVIEW:
        {

            break;
        }
        case EGameScene::GAMELAYER:
        {

            break;
        }
        case EGameScene::WELCOME:
        {
            MainLayer* layer = MainLayer::create();
            scene->addChild(layer);
            if (!Director::getInstance()->getRunningScene()) {
                Director::getInstance()->runWithScene(scene);
            }
            else
            {
                Director::getInstance()->replaceScene(scene);
            }
            break;
        }
        default:
            break;
	}
	
}


void GameManager::changeGameState(EGameState gs)
{
	switch (gs)
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