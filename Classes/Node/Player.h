//
//  Player.h
//  Brain
//
//  Created by jintao on 14-9-16.
//
//

#ifndef __Brain__Player__
#define __Brain__Player__

#include <iostream>
#include "cocos2d.h"

class Player:cocos2d::Ref
{
public:
    static Player* getInstance();
    
    virtual bool init();
    
private:
    
    
};


#endif /* defined(__Brain__Player__) */
