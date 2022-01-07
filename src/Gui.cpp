#include "Gui.hpp"

//using namespace Gui;
Gui::TextSystem::TextSystem(){
    
}

Gui::TextSystem::TextSystem(std::string words, std::string path, sf::Color color, int size, float x, float y) {
    sf::Font f;
    if (!f.loadFromFile(path))
    {
        std::cout << "Coudln't get that font, try again." << std::endl;
    }
    
    font = f;
    
    sf::Text t;
    t.setFont(font);
    t.setString(words);
    t.setCharacterSize(size);
    t.setFillColor(color);
    t.setPosition(x,y);
    textStore = t;
}

void Gui::TextSystem::drawText(sf::RenderWindow &window){
    window.draw(textStore);
}

Gui::Button::Button() {
}

Gui::Button::Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color txtColor, sf::Vector2f point) {
    button.setSize(buttonSize);
    button.setFillColor(bgColor);

    // get these for later use:
    btnWidth = buttonSize.x;
    btnHeight = buttonSize.y;

    pointPos = point;

    button.setPosition(point);

    // Center text on button:
    float div = 2.0 + btnHeight / btnWidth;

    float x = (point.x + btnWidth / div) - (text.textStore.getLocalBounds().width / 2);
    float y = (point.y + btnHeight / div) - (text.textStore.getLocalBounds().height / 2);

    buttonText = btnText;
    fontPath = "../tests/fonts/manaspc.ttf";
    textColor = txtColor;
    textSize = charSize;
    xPos = x;
    yPos = y;

    Gui::TextSystem textHold = Gui::TextSystem(btnText, "../tests/fonts/manaspc.ttf", txtColor, 25, xPos,yPos);

    text = textHold;
}

void Gui::Button::setTexture(std::string path, float width, float height){
    buttonTexture.loadFromFile(path);
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(pointPos);
    buttonSprite.setScale(sf::Vector2f(width, height));
    hasTexture = true;
}

void Gui::Button::setSize(sf::Vector2f s) {
    button.setSize(s);
}

void Gui::Button::setBackColor(sf::Color color) {
    button.setFillColor(color);
}

void Gui::Button::drawTo(sf::RenderWindow &window) {
    if (!hasTexture){
        window.draw(button);
        Gui::TextSystem textDisplay(buttonText, fontPath, textColor, textSize, xPos,yPos);
        textDisplay.drawText(window);
    }
    if (hasTexture){
        window.draw(buttonSprite);
    }
    
}

// Check if the mouse is within the bounds of the button:
bool Gui::Button::isMouseOver(sf::RenderWindow &window) {
    sf::Vector2i mouseCoords({ sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y });

    sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

    float mouseX = realCoords.x;
    float mouseY = realCoords.y;

    int btnPosX = button.getPosition().x;
    int btnPosY = button.getPosition().y;

    int btnxPosWidth = button.getPosition().x + button.getGlobalBounds().width;
    int btnyPosHeight = button.getPosition().y + button.getGlobalBounds().height;

    if (mouseX < btnxPosWidth + 20 && mouseX > btnPosX - 20 && mouseY < btnyPosHeight + 20 && mouseY > btnPosY - 20) {
        return true;
    }
    return false;
}

Gui::Textbox::Textbox(int size, sf::Color color, bool sel) {
    textbox.setCharacterSize(size);
    textbox.setFillColor(color);
    isSelected = sel;

    // Check if the textbox is selected upon creation and display it accordingly:
    if (isSelected)
        textbox.setString("_");
    else
        textbox.setString("");
}

void Gui::Textbox::setFont(sf::Font &fonts) {
    textbox.setFont(fonts);
}

void Gui::Textbox::setPosition(sf::Vector2f point) {
    textbox.setPosition(point);
}

// Set char limits:
void Gui::Textbox::setLimit(bool ToF) {
    hasLimit = ToF;
}

void Gui::Textbox::setLimit(bool ToF, int lim) {
    hasLimit = ToF;
    limit = lim - 1;
}

// Change selected state:
void Gui::Textbox::setSelected(bool sel) {
    isSelected = sel;

    // If not selected, remove the '_' at the end:
    if (!sel) {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++) {
            newT += t[i];
        }
        textbox.setString(newT);
    }
}

std::string Gui::Textbox::getText() {
    return text.str();
}

void Gui::Textbox::drawTo(sf::RenderWindow &window) {
    window.draw(textbox);
}

// function for event loop:
void Gui::Textbox::typedOn(sf::Event input) {
    if (isSelected) {
        int charTyped = input.text.unicode;

        // Only allow normal inputs:
        if (charTyped < 128) {
            if (hasLimit) {
                // If there's a limit, don't go over it:
                if (text.str().length() <= limit) {
                    inputLogic(charTyped);
                }
                // But allow for char deletions:
                else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                    deleteLastChar();
                }
            }
            // If no limit exists, just run the function:
            else {
                inputLogic(charTyped);
            }
        }
    }
}

void Gui::Textbox::deleteLastChar() {
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++) {
        newT += t[i];
    }
    text.str("");
    text << newT;
    textbox.setString(text.str() + "_");
}

void Gui::Textbox::inputLogic(int charTyped) {
    // If the key pressed isn't delete, or the two selection keys, then append the text with the char:
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        text << static_cast<char>(charTyped);
    }
    // If the key is delete, then delete the char:
    else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }
    // Set the textbox text:
    textbox.setString(text.str() + "_");
}

Gui::Settings::Settings(){

}

Gui::Settings::Settings(sf::Vector2f size, sf::Vector2f position){
    settingsButton = Gui::Button("", {8,8}, 50, sf::Color(91, 193, 240), sf::Color::Red, {64,80});
}

void Gui::Settings::drawSettings(sf::RenderWindow &window){
    settingsButton.setTexture("../tests/images/settings.png", 0.009f, 0.009f);
    settingsButton.drawTo(window);
}

void Gui::Settings::showSettingsWindow(sf::RenderWindow &window){
    settingsWindow.setSize({100,50});
    settingsWindow.setFillColor(sf::Color::White);
    settingsWindow.setPosition({80.f,80.f});

    TextSystem settingsText = TextSystem("SETTINGS", "../tests/fonts/manaspc.ttf", sf::Color::Red, 50, 80.f, 80.f);

    window.draw(settingsWindow);
    settingsText.textStore.setScale({0.2,0.2});
    settingsText.drawText(window);
}