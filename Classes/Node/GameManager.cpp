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
