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

class ManagerLoginDelegate{
public:
    virtual void loginSuccess()=0;
};


class GameManager:public cocos2d::Ref
{
public:
    GameManager();
    ~GameManager();
    static GameManager* getInstance();
    void changeGameState(EGameState state);
    void start();
    
    CC_SYNTHESIZE(ManagerLoginDelegate*, _loginDelegate, LoginDelegate);


private:
    bool init();
    void changeScene(EGameScene scene);

};



#endif /* defined(__Brain__GameManager__) */
