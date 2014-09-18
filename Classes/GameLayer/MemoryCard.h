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
    
private:
    void newRound();
    
    std::vector<Card*> *_vecCard;
    int  _level;
    
};



#endif /* defined(__Brain__MemoryCard__) */
