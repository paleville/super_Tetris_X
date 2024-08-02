#pragma once
#include "entityClass.h"
#include<iostream>


class playerClass :
    public entityClass
{
public:

    playerClass();
    ~playerClass();
    
    


    static void input();   
    static void update();

    /*inline static int idle = 0, right = 1, left = 2, up = 3 , down= 4;
    inline static bool isIdle, isRight, isLeft, isUp, isDown;
    static int statesInt;
    inline static int startIdleFrame = 0, idleFrame = 37, punchFrame = 37;*/

    

};

