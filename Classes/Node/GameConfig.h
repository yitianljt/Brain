//
//  GameConfig.h
//  Brain
//
//  Created by jintao on 14-9-15.
//
//

#ifndef Brain_GameConfig_h
#define Brain_GameConfig_h

enum EGameState{
    NONE,
    LOGINERROR,
    LOGINSUCCESS,
    RANDING,
	PLAYING,
    PAUSE,
    RESUME,
	GAMEOVER,
    LOGINOUT
};

enum EGameScene
{
    WELCOME,
	MENU,
    GAMELAYER,
	GAMEVIEW
};

enum MemCardType{
    CIRCLE,
    TRIANGLE,
    SQUARE,
    PENTAGON
};



#endif
