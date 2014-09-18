//
//  MemoryCard.h
//  Brain
//
//  Created by jintao on 14-9-17.
//
//

#ifndef __Brain__MemoryCard__
#define __Brain__MemoryCard__

#include <iostream>
#include "Card.h"
#include "cocos2d.h"

class MemoryCard:public cocos2d::Layer
{
public:
    CREATE_FUNC(MemoryCard);
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
private:
    void newRound();
    void click(cocos2d::Ref* pSender, cocos2d::extension::Control::EventType event);
    void setCardEnable(bool able);
    void turnCards();
    void clickCard(cocos2d::Ref* pSender);
    
    std::vector<Card*> *_vecCard;
    std::vector<Card*> *_vecOpenCard;
    cocos2d::extension::ControlButton* _btnStart;
    int  _level;
    
};



#endif /* defined(__Brain__MemoryCard__) */
