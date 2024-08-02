#include "windowManager.h"

sf::RenderWindow* windowManager::theWindow;

windowManager::windowManager()
{
	theWindow = new sf::RenderWindow(sf::VideoMode(600, 600), "Super Tetris X! by Christian Orosa", sf::Style::Close);
	theWindow->setFramerateLimit(30);
}

windowManager::windowManager(sf::RenderWindow* theWindow)
{



	while (theWindow->isOpen())
	{
		while (theWindow->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				theWindow->close();
			}
		}

		theWindow->clear(sf::Color::Green);

		theWindow->display();
	}
	std::cout << "We are in the WINDOW_MANAGER" << std::endl;
}

windowManager::~windowManager()
{
}

windowManager::windowManager(windowManager const&)
{
}

windowManager& windowManager::getinstance()
{
	static windowManager instance;
	return instance;
}

void windowManager::addscreen(gameClass* screen)
{
	currentwindow = screen;
	currentwindow->loadFile();
}

void windowManager::initialize()
{
	currentwindow = new introSplash();
}

void windowManager::loadFile()
{
	currentwindow->loadFile();
}

void windowManager::update()
{
	currentwindow->update();
}

void windowManager::draw()
{
	currentwindow->draw();
}


