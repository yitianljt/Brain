//
//  Card.cpp
//  Brain
//
//  Created by jintao on 14-9-17.
//
//

#include "Card.h"

USING_NS_CC;
USING_NS_CC_EXT;

Card* Card::create(int type)
{
    Card *pRet = new Card();
    if (pRet && pRet->init(type))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}


bool Card::init(int iType)
{
    if (!Node::init()) {
        return false;
    }
    _bCover = false;
    _spBg = Scale9Sprite::create("image/btn_bg.png");
    __String* str = __String::createWithFormat("image/dc_m_%d.png",iType);
    _spType = Scale9Sprite::create(str->getCString());
    _spType->setColor(Color3B(31,195,190));
    _spType->setPosition(Point(_spBg->getPreferredSize().width/2,_spBg->getPreferredSize().height/2));
    
    _button = ControlButton::create(_spBg);
    _button->setPreferredSize(_spBg->getPreferredSize());
    _button->addChild(_spType);

    _button->addTargetWithActionForControlEvents(this,cccontrol_selector(Card::clickButton),cocos2d::extension::Control::EventType::TOUCH_UP_INSIDE);
    addChild(_button);
    
    return true;
}


void Card::flipCard(bool bCover)
{
    if (_bCover) {
        CallFunc* callF = CallFunc::create([this]{
            CCLOG("-111");
            _spBg->setColor(Color3B(255,255,255));
            _spType->setVisible(true);
            _spType->setColor(Color3B(31,195,190));
            _button->runAction(ScaleTo::create(0.15, 1, 1));
        });
        
        ScaleTo* scaleTo1 = ScaleTo::create(0.15, 0, 1);
        _button->runAction(Sequence::create(scaleTo1,callF,CallFunc::create([this]{_bCover=false;}),nullptr));
    }
    else
    {
        CallFunc* callF = CallFunc::create([this]{
            CCLOG("-1");
            _spBg->setColor(Color3B(31,195,190));
            _spType->setVisible(false);
            _button->runAction(ScaleTo::create(0.15, 1, 1));

        });
        
        ScaleTo* scaleTo1 = ScaleTo::create(0.15, 0, 1);
        _button->runAction(Sequence::create(scaleTo1,callF,CallFunc::create([this]{_bCover=true;}),nullptr));
    }
    
    
}

void Card::clickButton(Ref* pSender, Control::EventType event)
{
    CCLOG("clickButton");
    flipCard(_bCover);
}


void Card::onEnter()
{
    Node::onEnter();
}

void Card::onExit()
{
    Node::onExit();
}

