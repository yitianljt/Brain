//
//  GameManager.h
//  Brain
//
//  Created by jintao on 14-9-15.
//
//

#ifndef __Brain__GameManager__
#define __Brain__GameManager__

#include <iostream>
#include "cocos2d.h"
#include "GameConfig.h"


class GameManager:public cocos2d::Ref
{
public:
    GameManager();
    ~GameManager();
    static GameManager* getInstance();
    void changeGameState(EGameState gs);
    void changeScene(EGameScene gs);
    void start();
private:
    bool init();
};



#endif /* defined(__Brain__GameManager__) */
