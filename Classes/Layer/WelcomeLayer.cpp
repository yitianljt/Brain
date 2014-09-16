//
//  WelcomeLayer.cpp
//  Brain
//
//  Created by jintao on 14-9-15.
//
//

#include "WelcomeLayer.h"
#include "BnInterface.h"


USING_NS_CC;

bool WelcomeLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    LayerColor* layerBg = LayerColor::create(Color4B(100,200,100,200));
    addChild(layerBg);
    GameManager::getInstance()->setLoginDelegate(this);
    MenuItemLabel* item = MenuItemLabel::create(LabelTTF::create( "Test", "黑体", 30), [](Ref*)
    {
        CCLOG("Click button");
        BnLogin(3);
    });
    Menu* menu= Menu::create(item, nullptr);
    menu->setPosition(Point(200,300));
    addChild(menu);
    return true;
}

void WelcomeLayer::onEnter()
{
    Layer::onEnter();
    
}

void WelcomeLayer::loginSuccess()
{
    CCLOG("loginSuccess");
    BnShowGameHome();
}
