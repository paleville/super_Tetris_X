#pragma once
#include"gameClass.h"
#include"windowManager.h"



class buttonClass :
    public gameClass
{
public:

    inline static int buttonStates = 0, BTN_IDLE = 1, BTN_HOVER = 2, BTN_PRESSED = 3;
    //static int buttonStates;

    /*enum buttonStates
    {
        BTN_IDLE = 0,
        BTN_HOVER,
        BTN_PRESSED
    };

    inline static buttonStates bS;*/


    buttonClass();
    ~buttonClass();

    //Mouse
    static sf::Vector2i mousePosScreen;
    static sf::Vector2i mousePosWindow;
    static sf::Vector2f mousePosView;

    //Button
    const bool isPressed() const;
    //short unsigned buttonState;

    //START GAME BUTTON
    static sf::RectangleShape buttonShape;
    static sf::Font buttonFont;
    static sf::Text buttonText;
    //EXIT GAME BUTTON
    static sf::RectangleShape exitButtonShape;
    static sf::Font exitButtonFont;
    static sf::Text exitButtonText;
    //RETRY GAME BUTTON
    static sf::RectangleShape retryButtonShape;
    static sf::Font retryButtonFont;
    static sf::Text retryButtonText;

    //BUTTON COLORs
    static sf::Color idleColor;
    static sf::Color hoverColor;
    static sf::Color activeColor;

    //Functions
    static void button(float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    static void exitbutton(float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    static void retry(float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

    static void updateMousePosition();
    static void updateButton(const sf::Vector2f mousePos);
    static void exitupdateButton(const sf::Vector2f mousePos);
    static void retryupdateButton(const sf::Vector2f mousePos);
};

