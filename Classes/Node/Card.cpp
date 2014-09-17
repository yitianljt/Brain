//
//  Card.cpp
//  Brain
//
//  Created by jintao on 14-9-17.
//
//

#include "Card.h"
#include "ui/widgets/UIButton.h"

USING_NS_CC;

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
    _bCover = false;
    _spBg = Sprite::create("image/btn_bg.png");
    __String* str = __String::createWithFormat("image/dc_m_%d.png",iType);
    _spType = Sprite::create(str->getCString());
    _spBg->addChild(_spType);
    _spType->setColor(Color3B(31,195,190));
    _spType->setPosition(Point(_spBg->getContentSize().width/2,_spBg->getContentSize().height/2));
    

    
    
    
    MenuItemSprite* item = MenuItemSprite::create(_spBg, _spBg, [this](Ref*){
        flipCard(_bCover);
    });
    _menu = Menu::create(item, NULL);
    addChild(_menu);
    
    return true;
}


void Card::flipCard(bool bCover)
{
    if (_bCover) {
        //auto call = [this](Ref* sender){
        CallFunc* callF = CallFunc::create([this]{
            _spBg->setColor(Color3B(255,255,255));
            _spType->setColor(Color3B(31,195,190));
            //_menu->runAction(OrbitCamera::create(2.0f,1,0,90,180,0,0));
            _menu->runAction(ScaleBy::create(0.5, -1, 1));
        });
        
        ScaleBy* scaleBy1 = ScaleBy::create(0.5, -1, 1);
        _menu->runAction(Sequence::create(scaleBy1,callF,CallFunc::create([this]{_bCover=false;}),nullptr));
    }
    else
    {
        CallFunc* callF = CallFunc::create([this]{
            _spBg->setColor(Color3B(31,195,190));
            _spType->setColor(Color3B(31,195,190));
            //_menu->runAction(OrbitCamera::create(2.0f,1,0,90,180,0,0));
            _menu->runAction(ScaleBy::create(0.5, -1, 1));

        });
        
        ScaleBy* scaleBy1 = ScaleBy::create(0.5, -1, 1);
        _menu->runAction(Sequence::create(scaleBy1,callF,CallFunc::create([this]{_bCover=false;}),nullptr));
    }
    
    
}
