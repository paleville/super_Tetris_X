#include "buttonClass.h"

//int buttonClass::buttonStates;
//int buttonClass::BTN_IDLE;
//int buttonClass::BTN_HOVER;
//int buttonClass::BTN_PRESSED;

sf::Vector2i buttonClass::mousePosScreen;
sf::Vector2i buttonClass::mousePosWindow;
sf::Vector2f buttonClass::mousePosView;

sf::RectangleShape buttonClass::buttonShape;
sf::Font buttonClass::buttonFont;
sf::Text buttonClass::buttonText;

sf::RectangleShape buttonClass::exitButtonShape;
sf::Font buttonClass::exitButtonFont;
sf::Text buttonClass::exitButtonText;

sf::RectangleShape buttonClass::retryButtonShape;
sf::Font buttonClass::retryButtonFont;
sf::Text buttonClass::retryButtonText;

sf::Color buttonClass::idleColor;
sf::Color buttonClass::hoverColor;
sf::Color buttonClass::activeColor;

//void buttonClass::button(float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

buttonClass::buttonClass()
{
}

buttonClass::~buttonClass()
{
}

const bool buttonClass::isPressed() const
{
	if (buttonStates == 3)
	{
		return true;
	}
	return false;
}

void buttonClass::button(float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	buttonShape.setPosition(sf::Vector2f(x, y));
	buttonShape.setSize(sf::Vector2f(width, height));

	BTN_IDLE = 1;

	buttonFont = font;
	buttonFont.loadFromFile("Fonts/ARCADECLASSIC.TTF");
	buttonText.setFont(buttonFont);
	buttonText.setString(text);
	buttonText.setFillColor(sf::Color::Black);
	buttonText.setCharacterSize(20);
	buttonText.setPosition(buttonShape.getPosition().x + (buttonShape.getGlobalBounds().width / 2.f) - buttonText.getGlobalBounds().width / 2.f,
	(buttonShape.getPosition().y + (buttonShape.getGlobalBounds().height / 2.f) - buttonText.getGlobalBounds().height / 2.f));

	idleColor = idleColor;
	hoverColor = hoverColor;
	activeColor = activeColor;

	buttonShape.setFillColor(idleColor);
}

void buttonClass::exitbutton(float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	exitButtonShape.setPosition(sf::Vector2f(x, y));
	exitButtonShape.setSize(sf::Vector2f(width, height));

	BTN_IDLE = 1;

	exitButtonFont = font;
	exitButtonFont.loadFromFile("Fonts/ARCADECLASSIC.TTF");
	exitButtonText.setFont(exitButtonFont);
	exitButtonText.setString(text);
	exitButtonText.setFillColor(sf::Color::Black);
	exitButtonText.setCharacterSize(20);
	exitButtonText.setPosition(exitButtonShape.getPosition().x + (exitButtonShape.getGlobalBounds().width / 2.f) - exitButtonText.getGlobalBounds().width / 2.f,
		(exitButtonShape.getPosition().y + (exitButtonShape.getGlobalBounds().height / 2.f) - exitButtonText.getGlobalBounds().height / 2.f));

	idleColor = idleColor;
	hoverColor = hoverColor;
	activeColor = activeColor;

	buttonShape.setFillColor(idleColor);
}

void buttonClass::retry(float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	retryButtonShape.setPosition(sf::Vector2f(x, y));
	retryButtonShape.setSize(sf::Vector2f(width, height));

	BTN_IDLE = 1;

	retryButtonFont = font;
	retryButtonFont.loadFromFile("Fonts/ARCADECLASSIC.TTF");
	retryButtonText.setFont(retryButtonFont);
	retryButtonText.setString(text);
	retryButtonText.setFillColor(sf::Color::Black);
	retryButtonText.setCharacterSize(20);
	retryButtonText.setPosition(retryButtonShape.getPosition().x + (retryButtonShape.getGlobalBounds().width / 2.f) - exitButtonText.getGlobalBounds().width / 2.f,
		(retryButtonShape.getPosition().y + (retryButtonShape.getGlobalBounds().height / 2.f) - exitButtonText.getGlobalBounds().height / 2.f));

	idleColor = idleColor;
	hoverColor = hoverColor;
	activeColor = activeColor;

	retryButtonShape.setFillColor(idleColor);
}

void buttonClass::updateMousePosition()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(*windowManager::theWindow);
	mousePosView = windowManager::theWindow->mapPixelToCoords(sf::Mouse::getPosition(*windowManager::theWindow));
}

void buttonClass::updateButton(const sf::Vector2f mousePos)
{
	BTN_IDLE = 1;

	if (buttonShape.getGlobalBounds().contains(mousePos))
	{
		BTN_HOVER = 2;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			BTN_PRESSED = 3;
			windowManager::getinstance().addscreen(new gameClass);
		}
	}

	switch (buttonStates)
	{
	case 1:
		buttonShape.setFillColor(idleColor);
		break;
	case 2:
		buttonShape.setFillColor(hoverColor);
		break;
	case 3:
		buttonShape.setFillColor(activeColor);
		break;
	default:
		buttonShape.setFillColor(sf::Color::Red);
		break;
	}
}

void buttonClass::exitupdateButton(const sf::Vector2f mousePos)
{
	BTN_IDLE = 1;

	if (exitButtonShape.getGlobalBounds().contains(mousePos))
	{
		BTN_HOVER = 2;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			BTN_PRESSED = 3;
			windowManager::getinstance().addscreen(new gameClass);
		}
	}

	switch (buttonStates)
	{
	case 1:
		exitButtonShape.setFillColor(idleColor);
		break;
	case 2:
		exitButtonShape.setFillColor(hoverColor);
		break;
	case 3:
		exitButtonShape.setFillColor(activeColor);
		break;
	default:
		exitButtonShape.setFillColor(sf::Color::Red);
		break;
	}
}

void buttonClass::retryupdateButton(const sf::Vector2f mousePos)
{
	BTN_IDLE = 1;

	if (retryButtonShape.getGlobalBounds().contains(mousePos))
	{
		BTN_HOVER = 2;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			BTN_PRESSED = 3;
			//windowManager::getinstance().addscreen(new actualGame);
		}
	}

	switch (buttonStates)
	{
	case 1:
		retryButtonShape.setFillColor(idleColor);
		break;
	case 2:
		retryButtonShape.setFillColor(hoverColor);
		break;
	case 3:
		retryButtonShape.setFillColor(activeColor);
		break;
	default:
		retryButtonShape.setFillColor(sf::Color::Red);
		break;
	}
}


