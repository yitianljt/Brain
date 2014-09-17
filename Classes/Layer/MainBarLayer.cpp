//
//  MainBarLayer.cpp
//  Brain
//
//  Created by jintao on 14-9-16.
//
//

#include "MainBarLayer.h"
#include "ComUtil.h"

USING_NS_CC;


bool MainBarLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    LayerColor* layerBar = LayerColor::create(Color4B(200,200,200,255),COMWinSize().width,100);
    addChild(layerBar);
    
    Sprite* spMainNor = Sprite::create("image/icon_home.png");
    Sprite* spMainSel = Sprite::create("image/icon_home.png");
    spMainSel->setColor(Color3B(95,112,140));

    
    MenuItemSprite* itemMain = MenuItemSprite::create(spMainNor, spMainSel, [](Ref*)
    {
        CCLOG("main");
    });
    
    Sprite* spBattleNor = Sprite::create("image/icon_home.png");
    Sprite* spBattleSel = Sprite::create("image/icon_home.png");
    spBattleSel->setColor(Color3B(95,112,140));
    
    
    MenuItemSprite* itemBattle = MenuItemSprite::create(spBattleNor, spBattleSel, [](Ref*)
                                                      {
                                                          CCLOG("spBattleNor");
                                                      });
    
    
    Sprite* spTrainNor = Sprite::create("image/icon_home.png");
    Sprite* spTrainSel = Sprite::create("image/icon_home.png");
    spTrainSel->setColor(Color3B(95,112,140));
    
    
    MenuItemSprite* itemTrain = MenuItemSprite::create(spTrainNor, spTrainSel, [](Ref*)
                                                      {
                                                          CCLOG("Train");
                                                      });
    
    Sprite* spMineNor = Sprite::create("image/icon_home.png");
    Sprite* spMineSel = Sprite::create("image/icon_home.png");
    spMineSel->setColor(Color3B(95,112,140));
    
    
    MenuItemSprite* itemMine = MenuItemSprite::create(spMineNor, spMineSel, [](Ref*)
                                                      {
                                                          CCLOG("mine");
                                                      });
    
    Menu* menu = Menu::create(itemMain,itemBattle,itemTrain,itemMine, NULL);
    menu->alignItemsHorizontally();
    menu->alignItemsHorizontallyWithPadding(60);
    menu->setPosition(Point(COMWinSize().width/2,50));
    addChild(menu);
    
    return true;
}
