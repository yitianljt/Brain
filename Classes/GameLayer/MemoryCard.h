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

enum GameStatus{
    WAITSTART,
    PLAYGAME
};


class MemoryCard:public cocos2d::Layer
{
public:
    CREATE_FUNC(MemoryCard);
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
private:
    void updateCount(float ft);
    void newRound();
    void click(cocos2d::Ref* pSender, cocos2d::extension::Control::EventType event);
    void setCardEnable(bool able);
    void turnCards();
    void clickCard(cocos2d::Ref* pSender);
    
    std::vector<Card*> *_vecCard;
    std::vector<Card*> *_vecOpenCard;
    cocos2d::extension::ControlButton* _btnStart;
    cocos2d::LayerColor* _coverLayer;
    cocos2d::LabelTTF*  _labelCount;
    bool _isCountDown;
    GameStatus _gameStatus;
    int  _count;
    int  _level;
    
};



#endif /* defined(__Brain__MemoryCard__) */
