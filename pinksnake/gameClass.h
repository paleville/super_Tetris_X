#pragma once
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"

class gameClass
{

public:
	gameClass();
	~gameClass();


	virtual void loadFile();
	virtual void update();
	virtual void draw();

	
};

