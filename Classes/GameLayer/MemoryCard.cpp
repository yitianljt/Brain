//
//  MemoryCard.cpp
//  Brain
//
//  Created by jintao on 14-9-17.
//
//

#include "MemoryCard.h"

using namespace std;
USING_NS_CC;

#define ROW_NUM 3
#define COLUMN_NUM 2

bool MemoryCard::init()
{
    if (!Layer::init()) {
        return false;
    }
    _level = 1;
    
    _vecCard = new vector<Card*>();
    newRound();
    return true;
}

void MemoryCard::newRound()
{
    if (_vecCard && _vecCard->size()>0) {
        for (vector<Card*>::iterator it=_vecCard->begin(); it!=_vecCard->end();){
            ((Card*)(&it))->removeFromParent();
        }
        _vecCard->clear();
    }
    
    for (int i=0; i<6; i++) {
        Card* card = Card::create(i%2);
        card->setScale(0.5);
        addChild(card);
        _vecCard->push_back(card);
    }
    Point ptStart = Point(100,700);

    for (int i=0;i<_vecCard->size();i++)
    {
        Card* card = _vecCard->at(i);
        card->setPosition(Point(10,10));
        card->setPosition(ptStart+Point((i/ROW_NUM)* 300,(i%ROW_NUM)*200));
    }
//    for (vector<Card*>::iterator it=_vecCard->begin(); it!=_vecCard->end();){
//        (*it)->setPosition(Point(10,10));
//        it++;
//    }
}


