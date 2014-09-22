//
//  PlayerInfo.cpp
//  Brain
//
//  Created by jintao on 14-9-19.
//
//

#include "PlayerInfo.h"


USING_NS_CC;

bool PlayerInfo::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    //ClippingNode* clipNode = ClippingNode::create(Sprite::create("image/pic_frame_n.png"));
    Sprite* spHead = Sprite::create("image/pic_default_n.png");
    
    
    
    return true;
}
