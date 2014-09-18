//
//  Card.h
//  Brain
//
//  Created by jintao on 14-9-17.
//
//

#ifndef __Brain__Card__
#define __Brain__Card__

#include <iostream>
#include "GameConfig.h"
#include "cocos2d.h"
#include "cocos-ext.h"


class Card:public cocos2d::Node
{
public:
    //CREATE_FUNC(Card);
    static Card* create(int type);
    virtual bool init(int type);
    virtual void onEnter();
    virtual void onExit();
    void turnBack();
    void turnFront(const std::function<void()>& func);
    void showOut(const std::function<void()>& func);
    CC_SYNTHESIZE(int, _type, Type);
    CC_SYNTHESIZE(bool,_enableClick,EnableClick);
    CC_SYNTHESIZE(cocos2d::Ref*, _selectTarget, SelectTarget);
    CC_SYNTHESIZE(cocos2d::SEL_CallFuncN, _selectSelector, SelectSelector);

    //    typedef void (Ref::*Handler)(Ref*, EventType);
private:
    void flipCard();
    void clickButton(cocos2d::Ref* pSender, cocos2d::extension::Control::EventType event);

    cocos2d::extension::Scale9Sprite* _spBg;
    cocos2d::extension::Scale9Sprite* _spType;
    cocos2d::Menu* _menu;
    cocos2d::extension::ControlButton* _button;
    bool _bCover;
    
};

#endif /* defined(__Brain__Card__) */
