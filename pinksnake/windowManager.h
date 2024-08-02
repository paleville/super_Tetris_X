#pragma once
#include"gameClass.h"
#include"introSplash.h"
#include"mainMenuClass.h"


class windowManager
{
public:
	windowManager();
	windowManager(sf::RenderWindow *theWindow);
	~windowManager();
	windowManager(windowManager const&);

	static windowManager& getinstance();
	

	static sf::RenderWindow* theWindow;

	gameClass* currentwindow;

	sf::Event ev;
	sf::Font font;
	sf::Text myText;


	void addscreen(gameClass *screen);

	void initialize();
	void loadFile();
	void update();
	void draw();

	




};

