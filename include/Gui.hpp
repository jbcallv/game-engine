#pragma once
#ifndef GUI_HPP
#define GUI_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

namespace Gui {

    class TextSystem {
    private:
        sf::Font font;
        

    public:
        
        TextSystem();
        
        TextSystem(std::string words, std::string path, sf::Color color, int size, float x, float y);
            
        void drawText(sf::RenderWindow &window);

        sf::Text textStore;
    };

    class Button {
    public:
        Button();

        Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor, sf::Vector2f point);

        void setSize(sf::Vector2f);

        void setBackColor(sf::Color color);

        void drawTo(sf::RenderWindow &window);

        bool isMouseOver(sf::RenderWindow &window);

        void setTexture(std::string path, float width, float height);

    private:
        sf::RectangleShape button;
        Gui::TextSystem text;

        std::string buttonText;
        std::string fontPath;
        sf::Color textColor;
        int textSize;
        float xPos;
        float yPos;
        sf::Vector2f pointPos;

        //Texture
        sf::Texture buttonTexture;
        sf::Sprite buttonSprite;
        bool hasTexture = false;

        float btnWidth;
        float btnHeight;
    };


    class Textbox {
    public:
        Textbox(int size, sf::Color color, bool sel);

        // make sure font is passed by reference:
        void setFont(sf::Font &fonts);

        void setPosition(sf::Vector2f point);

        // set char limits:
        void setLimit(bool ToF);

        void setLimit(bool ToF, int lim);

        // change selected state:
        void setSelected(bool sel);

        std::string getText();

        void drawTo(sf::RenderWindow &window);

        // function for event loop:
        void typedOn(sf::Event input);

    private:
        sf::Text textbox;

        std::ostringstream text;
        bool isSelected = false;
        bool hasLimit = false;
        int limit = 0;

        // Delete the last character of the text:
        void deleteLastChar();

        // Get user input:
        void inputLogic(int charTyped);
    };

    class Settings{
        public:

        Settings();

        Settings(sf::Vector2f size, sf::Vector2f position);

        void drawSettings(sf::RenderWindow &window);

        void showSettingsWindow(sf::RenderWindow &window);

        void setTexture();

        Gui::Button settingsButton;
        bool showSettings = false;

        private:

        sf::RectangleShape settingsWindow;
    };
};

#endif