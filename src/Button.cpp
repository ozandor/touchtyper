#include "Button.h"

Button::Button(sf::RenderWindow* window, wstring title, int dx, int dy, int dw, int dh, sf::Font* font) {
    wind = window;
    font_size = dh*0.8;
    
    x = dx;
    y = dy;
    w = dw;
    h = dh;

    darkI = new sf::Texture();
    darkH = new sf::Texture();
    darkP = new sf::Texture();
    lightI = new sf::Texture();
    lightH = new sf::Texture();
    lightP = new sf::Texture();

    if (!darkI->loadFromFile("buttons/dark_idle.png")) { //! Texture read from file.
    	printf("Couldn't load dark_idle texture. \n"); //Message if file doesn't load.
	} else {
		printf("dark_idle texture loaded. \n"); //Message if file loads.
	}

    if (!darkH->loadFromFile("buttons/dark_hover.png")) { //! Texture read from file.
    	printf("Couldn't load dark_hover texture. \n"); //Message if file doesn't load.
	} else {
		printf("dark_hover texture loaded. \n"); //Message if file loads.
	}

    if (!darkP->loadFromFile("buttons/dark_pressed.png")) { //! Texture read from file.
    	printf("Couldn't load dark_pressed texture. \n"); //Message if file doesn't load.
	} else {
		printf("dark_pressed texture loaded. \n"); //Message if file loads.
	}

    if (!lightI->loadFromFile("buttons/light_idle.png")) { //! Texture read from file.
    	printf("Couldn't load light_idle texture. \n"); //Message if file doesn't load.
	} else {
		printf("light_idle texture loaded. \n"); //Message if file loads.
	}

    if (!lightH->loadFromFile("buttons/light_hover.png")) { //! Texture read from file.
    	printf("Couldn't load light_hover texture. \n"); //Message if file doesn't load.
	} else {
		printf("light_hover texture loaded. \n"); //Message if file loads.
	}

    if (!lightP->loadFromFile("buttons/light_pressed.png")) { //! Texture read from file.
    	printf("Couldn't load light_pressed texture. \n"); //Message if file doesn't load.
	} else {
		printf("light_pressed texture loaded. \n"); //Message if file loads.
	}

    drawing = new sf::Sprite();
    drawing->setTexture(*darkI);
    drawing->setScale(dw / 1000, dh / 250);
    drawing->setPosition(dx, dy);
    

    button_title = new sf::Text();

    button_title->setString(title);
    button_title->setFont(*font);
    button_title->setCharacterSize(font_size);
    button_title->setOrigin(button_title->getGlobalBounds().width / 2, button_title->getGlobalBounds().height / 2);
    button_title->setPosition(dx + dw/2, dy + dh/2);
}

Button::~Button() {

}

void Button::SetColorMode(bool m) {
    dark_mode = m;
}

void Button::SetVisibility(bool v) {
    visibility = v;
}

void Button::Calculate() {
    if (visibility) {

    }
}

void Button::Draw() {
    if (visibility) {
        wind->draw(*drawing);
    }
}