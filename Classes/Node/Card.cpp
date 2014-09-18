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
    setType(iType);
    setEnableClick(false);
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


void Card::flipCard()
{
    if (_bCover) {
        //(getSelectTarget()->*getSelectSelector())(this);
        turnFront([this]{
            (getSelectTarget()->*getSelectSelector())(this);
        });
    }
}

void Card::clickButton(Ref* pSender, Control::EventType event)
{
    if (!getEnableClick()) {
        return;
    }
    flipCard();
}


void Card::onEnter()
{
    Node::onEnter();
}

void Card::onExit()
{
    Node::onExit();
}

void Card::turnBack()
{
    CCLOG("turnBack");
    if (_bCover) {
        return;
    }
    CallFunc* callF = CallFunc::create([this]{
        _spBg->setColor(Color3B(31,195,190));
        _spType->setVisible(false);
        _button->runAction(ScaleTo::create(0.15, 1, 1));
        
    });
    
    ScaleTo* scaleTo1 = ScaleTo::create(0.15, 0, 1);
    _button->runAction(Sequence::create(scaleTo1,callF,CallFunc::create([this]{_bCover=true; CCLOG("_bCover=%d",_bCover);}),nullptr));
}

void Card::turnFront(const std::function<void()>& func)
{
    CCLOG("Card::turnFront");
    if (!_bCover) {
        return;
    }
    CallFunc* callF = CallFunc::create([this,func]{
        _spBg->setColor(Color3B(255,255,255));
        _spType->setVisible(true);
        _spType->setColor(Color3B(31,195,190));
        _button->runAction(Sequence::create(ScaleTo::create(0.15, 1, 1),CallFunc::create([this]{_bCover=false;}),CallFunc::create(func),nullptr));

    });
    
    ScaleTo* scaleTo1 = ScaleTo::create(0.15, 0, 1);
    _button->runAction(Sequence::create(scaleTo1,callF,nullptr));
}

void Card::showOut(const std::function<void()>& func)
{
    this->runAction(Sequence::create(EaseBackIn::create(ScaleTo::create(0.2, 0.2)), RemoveSelf::create(),NULL));
}


