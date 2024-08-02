#pragma once
#include "gameClass.h"
#include<iostream>

#include"windowManager.h"
#include"actualGame.h"
#include"buttonClass.h"


class mainMenuClass :
    public gameClass
{

public:

    //Button Object

    
    //Constructor and Destructor
    mainMenuClass();
    ~mainMenuClass();

    //Font
    sf::Font font;
    sf::Text myText;

    

    void loadFile();
    
    void update();
    void draw();
    
};

