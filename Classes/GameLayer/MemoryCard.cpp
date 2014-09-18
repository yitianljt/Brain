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

bool MemoryCard::init()
{
    if (!Layer::init()) {
        return false;
    }
    _level = 1;
    _vecCard = new vector<Card*>();
    newRound();
    Scale9Sprite* spBtn = Scale9Sprite::create("image/btn_start.png");
    spBtn->setColor(COM_COLOR);
    ControlButton* btn_start = ControlButton::create(LabelTTF::create("开始游戏","黑体", 35), spBtn);
    btn_start->setPreferredSize(spBtn->getPreferredSize());
    btn_start->addTargetWithActionForControlEvents(this,cccontrol_selector(MemoryCard::click), cocos2d::extension::Control::EventType::TOUCH_UP_INSIDE);
    btn_start->setPosition(Point(COMWinSize().width/2,200));
    addChild(btn_start);
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
        card->setScale(0.4);
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
    setCardEnable(true);
}

void MemoryCard::setCardEnable(bool able)
{
    for (int i=0;i<_vecCard->size();i++)
    {
        Card* card = _vecCard->at(i);
        card->setEnableClick(true);
        card->turnBack();
    }
}

