//
//  MemoryCard.cpp
//  Brain
//
//  Created by jintao on 14-9-17.
//
//

#include "MemoryCard.h"
#include "ComUtil.h"
#include "cocos-ext.h"

using namespace std;
USING_NS_CC;
USING_NS_CC_EXT;

#define ROW_NUM 3
#define COLUMN_NUM 2

enum {
    kButtonTagStart
};


bool MemoryCard::init()
{
    if (!Layer::init()) {
        return false;
    }
    _level = 1;
    _vecCard = new vector<Card*>();
    _vecOpenCard = new vector<Card*>();
    Scale9Sprite* spBtn = Scale9Sprite::create("image/btn_start.png");
    spBtn->setColor(COM_COLOR);
    _btnStart = ControlButton::create(LabelTTF::create("开始游戏","黑体", 35), spBtn);
    _btnStart->setPreferredSize(spBtn->getPreferredSize());
    _btnStart->addTargetWithActionForControlEvents(this,cccontrol_selector(MemoryCard::click), cocos2d::extension::Control::EventType::TOUCH_UP_INSIDE);
    _btnStart->setTag(kButtonTagStart);
    _btnStart->setPosition(Point(COMWinSize().width/2,200));
    addChild(_btnStart);
    return true;
}

void MemoryCard::onEnter()
{
    Layer::onEnter();
    newRound();
}
void MemoryCard::onExit()
{
    Layer::onExit();
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
        Card* card = Card::create(i%3);
        card->setScale(0.4);
        card->setTag(i);
        card->setSelectTarget(this);
        card->setSelectSelector(SEL_CallFuncN(&MemoryCard::clickCard));
        addChild(card);
        _vecCard->push_back(card);
    }
    
    int iRow = ROW_NUM;
    int iWidth = 120;
    int iGap = iWidth+10;
    int iStartX = (COMWinSize().width-(iRow-1)*10-iRow*iWidth)/2+iWidth/2;
    int iStartY = COMWinSize().height/2-100;
    Point ptStart = Point(iStartX,iStartY);

    for (int i=0;i<_vecCard->size();i++)
    {
        Card* card = _vecCard->at(i);
        card->setPosition(ptStart+Point((i%iRow)*iGap,(i/iRow)*iGap));
    }
}

void MemoryCard::click(cocos2d::Ref* pSender, cocos2d::extension::Control::EventType event)
{
    Node* node = (Node*) pSender;
    switch (node->getTag()) {
        case kButtonTagStart:
        {
            setCardEnable(true);
            turnCards();
            _vecOpenCard->clear();
            _btnStart->setVisible(false);
            break;
        }

        default:
            break;
    }
}

void MemoryCard::clickCard(cocos2d::Ref* pSender)
{
    Card* newCard = (Card*)pSender;
    if (_vecOpenCard->size()>0) {
        Card* oldCard = _vecOpenCard->at(_vecOpenCard->size()-1);
        if (newCard->getType() == oldCard->getType()) {
            oldCard->showOut([]{});
            newCard->showOut([]{});
            _vecOpenCard->clear();
        }
        else
        {
            _vecOpenCard->pop_back();
            oldCard->turnBack();
            newCard->turnBack();
        }
    }
    else
    {
        _vecOpenCard->push_back(newCard);
    }
}


void MemoryCard::setCardEnable(bool able)
{
    for (int i=0;i<_vecCard->size();i++)
    {
        Card* card = _vecCard->at(i);
        card->setEnableClick(true);
    }
}

void MemoryCard::turnCards()
{
    for (int i=0;i<_vecCard->size();i++)
    {
        Card* card = _vecCard->at(i);
        card->turnBack();
    }
}



