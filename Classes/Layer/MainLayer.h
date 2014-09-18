//
//  MainLayer.h
//  Brain
//
//  Created by jintao on 14-9-16.
//
//

#ifndef __Brain__MainLayer__
#define __Brain__MainLayer__

#include <iostream>
#include "MemoryCard.h"
#include "cocos2d.h"

class MainLayer:public cocos2d::Layer
{
public:
    CREATE_FUNC(MainLayer);
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
private:
    
};

#endif /* defined(__Brain__MainLayer__) */
