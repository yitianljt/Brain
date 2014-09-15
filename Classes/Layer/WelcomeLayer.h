//
//  WelcomeLayer.h
//  Brain
//
//  Created by jintao on 14-9-15.
//
//

#ifndef __Brain__WelcomeLayer__
#define __Brain__WelcomeLayer__

#include <iostream>
#include "cocos2d.h"

class WelcomeLayer:public cocos2d::Layer
{
public:
    CREATE_FUNC(WelcomeLayer);
private:
    bool init();
};

#endif /* defined(__Brain__WelcomeLayer__) */
