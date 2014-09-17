//
//  MainLayer.cpp
//  Brain
//
//  Created by jintao on 14-9-16.
//
//

#include "MainLayer.h"
#include "ComUtil.h"
#include "MainBarLayer.h"

USING_NS_CC;

bool MainLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    LayerColor* layerBg = LayerColor::create(Color4B(255,255,255,255), COMWinSize().width, COMWinSize().height);
    addChild(layerBg);
    
//    MainBarLayer* bar = MainBarLayer::create();
//    addChild(bar);
    
    
    return true;
}


void MainLayer::onEnter()
{
    Layer::onEnter();
}

void MainLayer::onExit()
{
    Layer::onExit();
}
