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
    void changeGameState(EGameState state);

private:
    bool init();
    void start();
    void changeScene(EGameScene scene);

};



#endif /* defined(__Brain__GameManager__) */
