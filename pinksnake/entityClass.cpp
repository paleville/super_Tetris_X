#include "entityClass.h"

sf::RectangleShape entityClass::entRectShape;

entityClass::entityClass()
{
	entRectShape.setSize(sf::Vector2f(120, 120));
	entRectShape.setFillColor(sf::Color::Blue);
	entRectShape.setPosition(sf::Vector2f(0, 0));
}

//entityClass::entityClass(sf::RectangleShape entRectShape, sf::Vector2f sizeX, sf::Vector2f sixeY, sf::Color color, sf::Vector2f PosX, sf::Vector2f PosY)
//{
//	//entRectShape.setSize(sf::Vector2f(120, 120));
//	//entRectShape.setFillColor(sf::Color::Blue);
//	//entRectShape.setPosition(sf::Vector2f(0, 0));
//}

entityClass::~entityClass()
{
}




