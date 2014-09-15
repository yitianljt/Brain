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

class GameManager:public cocos2d::Ref
{
public:
    GameManager();
    ~GameManager();
    static GameManager* getInstance();
    
private:
    bool init();
};



#endif /* defined(__Brain__GameManager__) */
