#pragma once
#include "gameClass.h"
#include<iostream>

#include"windowManager.h"


class introSplash :
    public gameClass
{
public:


    introSplash();
    ~introSplash();

    sf::Event ev;
    sf::Font font;
    sf::Text myText;

    //TETRIS IMAGE
    sf::Texture iTex;
    sf::Sprite iSprite;
    //TETRI X
    sf::Texture iTexX;
    sf::Sprite iSpriteX;

    //TIMER
    sf::Clock clock;
    sf::Time timer;

    float logoSpeed = 2.f;

    float deltaTimeRotation = 2;
    
    //Functions
    void loadFile();
    void update();
    void draw();    
};

