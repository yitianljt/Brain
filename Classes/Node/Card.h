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

class Card:public cocos2d::Node
{
public:
    //CREATE_FUNC(Card);
    static Card* create(int type);
    virtual bool init(int type);
private:
    void flipCard(bool bCover);
    cocos2d::Sprite* _spBg;
    cocos2d::Sprite* _spType;
    cocos2d::Menu* _menu;
    bool _bCover;
};

#endif /* defined(__Brain__Card__) */
