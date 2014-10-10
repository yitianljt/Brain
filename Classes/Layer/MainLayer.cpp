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
#include "GameManager.h"
#include "Card.h"

USING_NS_CC;
USING_NS_CC_EXT;

enum{
    kChallengeTag
};

bool MainLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    _layerBg = LayerColor::create(Color4B(233,233,233,255), COMWinSize().width, COMWinSize().height);
    this->addChild(_layerBg);
    
    Scale9Sprite* spBtnBg = Scale9Sprite::create("image/btn_start.png");
    spBtnBg->setColor(COM_COLOR);
    _btnChallenge = ControlButton::create(LabelTTF::create("挑战模式","黑体", 35),spBtnBg);
    _btnChallenge->setPreferredSize(spBtnBg->getPreferredSize());
    _btnChallenge->setPosition(Point(COMWinSize().width/2,COMWinSize().height/2));
    _btnChallenge->setTag(kChallengeTag);
    _btnChallenge->addTargetWithActionForControlEvents(this,cccontrol_selector(MainLayer::onClick), cocos2d::extension::Control::EventType::TOUCH_UP_INSIDE);
    _layerBg->addChild(_btnChallenge);
    
    
    
//    MemoryCard* layerMemory = MemoryCard::create();
//    addChild(layerMemory);
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

void MainLayer::onClick(Ref* pSender,Control::EventType)
{
    Node* btn = (Node*)pSender;
    switch (btn->getTag()) {
        case kChallengeTag:
        {
            GameManager::getInstance()->changeScene(GAMELAYER);
            break;
        }
            
        default:
            break;
    }
}
