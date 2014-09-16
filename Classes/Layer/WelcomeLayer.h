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
#include "GameManager.h"

class WelcomeLayer:public cocos2d::Layer,
                            ManagerLoginDelegate
{
public:
    CREATE_FUNC(WelcomeLayer);
    void loginSuccess();

private:
    virtual bool init();
    virtual void onEnter();
};

#endif /* defined(__Brain__WelcomeLayer__) */
