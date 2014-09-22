//
//  Player.cpp
//  Brain
//
//  Created by jintao on 14-9-16.
//
//

#include "Player.h"


USING_NS_CC;

static Player* s_PlayManager;


Player* Player::getInstance()
{
    if (!s_PlayManager) {
        s_PlayManager = new Player();
        s_PlayManager->init();
    }
    return s_PlayManager;
}

bool Player::init()
{
    return true;
}
