#include "introSplash.h"




introSplash::introSplash()
{
}

introSplash::~introSplash()
{
}

void introSplash::loadFile()
{
		
	update();
	draw();
	
}

void introSplash::update()
{

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		windowManager::getinstance().addscreen(new mainMenuClass);
	}

}

void introSplash::draw()
{
	font.loadFromFile("Fonts/ARCADECLASSIC.TTF");
	myText.setFont(font);
	myText.setString("Created by Christian Orosa");
	myText.setFillColor(sf::Color::Black);
	myText.setPosition(50, 250);


	if (!iTex.loadFromFile("Images/tet.png"))
	{
		std::cout << "Error at loading tet.png" << std::endl;
	}
	if (!iTexX.loadFromFile("Images/X.png"))
	{
		std::cout << "Error at loading X.png" << std::endl;
	}
	
	timer = clock.getElapsedTime();
	
	//Tetris Image
	iSprite.setTexture(iTex);
	iSprite.setOrigin(sf::Vector2f(420, 507.5f));
	iSprite.setScale(sf::Vector2f(1.f, 1.f));
	iSprite.setPosition(sf::Vector2f(440, 500));
	
	
	//X Imgage
	iSpriteX.setTexture(iTexX);
	iSpriteX.setOrigin(sf::Vector2f(420, 507.5f));
	iSpriteX.setScale(sf::Vector2f(1.f, 1.f));
	iSpriteX.setPosition(sf::Vector2f(420, 500));

	while (windowManager::getinstance().theWindow->isOpen())
	{
		
		windowManager::getinstance().update();

		
		while (windowManager::getinstance().theWindow->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				windowManager::getinstance().theWindow->close();
			}
		}

		windowManager::getinstance().theWindow->clear(sf::Color::White);

		timer = clock.getElapsedTime();



		if (timer.asSeconds() >= 0.1)
		{
			std::cout << timer.asSeconds() << std::endl;
			iSpriteX.setColor(sf::Color::White);
			if (timer.asSeconds() >= 0.2)
			{
				std::cout << timer.asSeconds() << std::endl;
				iSpriteX.setColor(sf::Color::Cyan);
				if (timer.asSeconds() >= 0.3)
				{
					std::cout << timer.asSeconds() << std::endl;
					iSpriteX.setColor(sf::Color::Yellow);
					if (timer.asSeconds() >= 0.4)
					{
						std::cout << timer.asSeconds() << std::endl;
						clock.restart();
					}
				}
			}
		}
		
		windowManager::getinstance().theWindow->draw(iSpriteX);
		windowManager::getinstance().theWindow->draw(iSprite);		
		windowManager::getinstance().theWindow->draw(myText);		
		windowManager::getinstance().theWindow->display();
	}
}