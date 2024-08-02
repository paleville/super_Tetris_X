#include "mainMenuClass.h"

mainMenuClass::mainMenuClass()
{
	buttonClass::button(90, 100, 150, 50, buttonClass::buttonFont, "New Game", sf::Color::White, sf::Color::Blue, sf::Color::Green);
	buttonClass::exitbutton(90, 170, 150, 50, buttonClass::exitButtonFont, "EXIT", sf::Color::White, sf::Color::Blue, sf::Color::Green);
}

mainMenuClass::~mainMenuClass()
{
}

void mainMenuClass::loadFile()
{	
	update();
	draw();
}

void mainMenuClass::update()
{
	buttonClass::updateMousePosition();

	buttonClass::updateButton(buttonClass::mousePosView);

	system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";


	if (buttonClass::buttonShape.getGlobalBounds().contains(buttonClass::mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		windowManager::getinstance().addscreen(new actualGame);
	}

	if (buttonClass::exitButtonShape.getGlobalBounds().contains(buttonClass::mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		windowManager::getinstance().theWindow->close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		windowManager::getinstance().theWindow->close();
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		windowManager::getinstance().addscreen(new introSplash);
	}
}


void mainMenuClass::draw()
{	
	font.loadFromFile("Fonts/ARCADECLASSIC.TTF");
	myText.setFont(font);
	myText.setString("MAIN MENU");
	myText.setFillColor(sf::Color::Red);
	myText.setPosition(90, 50);

	while (windowManager::getinstance().theWindow->isOpen())
	{
		sf::Event ev;
		
		windowManager::getinstance().update();		

		while (windowManager::getinstance().theWindow->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				windowManager::getinstance().theWindow->close();
			}
		}

		//CLEAR SCREEN
		windowManager::getinstance().theWindow->clear(sf::Color::Cyan);
		//MAIN MENU TEXT
		windowManager::getinstance().theWindow->draw(myText);
		//START BUTTON
		windowManager::getinstance().theWindow->draw(buttonClass::buttonShape);
		windowManager::getinstance().theWindow->draw(buttonClass::buttonText);
		//EXIT BUTTON
		windowManager::getinstance().theWindow->draw(buttonClass::exitButtonShape);
		windowManager::getinstance().theWindow->draw(buttonClass::exitButtonText);
		//DISPLAY SCREEN
		windowManager::getinstance().theWindow->display();
		
	}	
}


