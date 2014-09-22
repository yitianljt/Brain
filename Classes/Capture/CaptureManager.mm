//
//  CaptureManager.cpp
//  Brain
//
//  Created by jintao on 14-9-19.
//
//

#include "CaptureManager.h"


USING_NS_CC;

static CaptureManager* s_CaptureManager;

CaptureManager* CaptureManager::getInstance()
{
    if (!s_CaptureManager) {
        s_CaptureManager = new CaptureManager();
        s_CaptureManager->init();
    }
    return s_CaptureManager;
}

bool CaptureManager::init()
{
    return true;
}

void CaptureManager::takePicture()
{
    
}
