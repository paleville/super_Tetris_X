#pragma once
#include "gameClass.h"
#include<iostream>
#include"windowManager.h"
#include"entityClass.h"
#include"playerClass.h"
#include<time.h>
#include"buttonClass.h"
#include<vector>

using namespace sf;
using namespace std;



class actualGame :
    public gameClass
{

public:

    int i, j;

    Sprite background, frame, s;
    Texture t2, t3;

    sf::Texture t1;
    std::vector<sf::Sprite> s_Vector;
   
    //sf::Sprite s_tiles[3] = {tile[3]};
    
    
    
    bool pushBackBool;
    bool spriteClear;
    
    //int spriteNum = 0;
    sf::Music music;
    static bool gameOver;
    bool horizontalBound;
    bool verticalBound;

    int dx = 0; bool rotate = 0; int colorNum = 1;
    float timer = 0, delay = 0.3;

    Clock clock;
    static float time;

    struct Point
    {
        int x = 0, y = 0;
    } a[4], b[4];


    static const int M = 20;
    static const int N = 10;

    inline static int field[M][N] = { 0 };


    int figures[7][4] =
    {
        1,3,5,7, // I
        2,4,5,7, // Z
        3,5,4,6, // S
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // O
    };



    actualGame();
    ~actualGame();

    sf::Event ev;
    sf::Font font;
    sf::Text myText;

    //entityClass eC;
    //
    //playerClass pC;


    bool check();
    

    void loadFile();
    //bool startFirstFrame();
    void resetGame();
    void update();
    void draw();

    //Level01
    //sf::Texture build01_tex, build01_tex02;
    //sf::Sprite build01_spr, build01_spr02;

};

