//
//  CaptureManager.h
//  Brain
//
//  Created by jintao on 14-9-19.
//
//

#ifndef __Brain__CaptureManager__
#define __Brain__CaptureManager__

#include <iostream>
#include "cocos2d.h"

class CaptureManager:public cocos2d::Ref
{
public:
    static CaptureManager* getInstance();
    virtual bool init();
    
    void takePicture();
};

#endif /* defined(__Brain__CaptureManager__) */
