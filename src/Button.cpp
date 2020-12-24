#include "Button.h"

Button::Button(sf::RenderWindow* window, wstring title, int dx, int dy, int dw, int dh, sf::Font* font, int output) {
    wind = window;
    font_size = dh*0.7;
    
    output_mod = output;

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

    
    drawing = new sf::Sprite(*darkI);
    //drawing->setPosition(dx, dy);
    drawing->setPosition(sf::Vector2f(dx, dy));
    drawing->setScale((double)dw / 1000, (double)dh / 250);
    

    button_title = new sf::Text(title, *font, font_size);
    button_title->setOrigin(button_title->getGlobalBounds().width / 2, button_title->getGlobalBounds().height / 2);
    button_title->setPosition(dx + dw/2, dy + dh/4);
    //button_title->setFillColor(sf::Color::Black);
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
        sf::Vector2i pixelPos = sf::Mouse::getPosition(*wind);
        // convert it to world coordinates
        sf::Vector2f worldPos = wind->mapPixelToCoords(pixelPos);
        if (dark_mode) {
            drawing->setTexture(*darkI);
            button_title->setFillColor(sf::Color::White);
        } else {
            drawing->setTexture(*lightI);
            button_title->setFillColor(sf::Color::Black);
        }
        if (worldPos.x >= x &&
            worldPos.x <= x + w &&
            worldPos.y >= y &&
            worldPos.y <= y + h) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (dark_mode) {
                    drawing->setTexture(*darkP);
                    button_title->setFillColor(sf::Color::White);
                } else {
                    drawing->setTexture(*lightP);
                    button_title->setFillColor(sf::Color::Black);
                }
                pressed = true;
            } else {
                if (pressed) {
                    pressed = false;
                    printf("%d\n",output_mod);
                }
                if (dark_mode) {
                    drawing->setTexture(*darkH);
                    button_title->setFillColor(sf::Color::White);
                } else {
                    drawing->setTexture(*lightH);
                    button_title->setFillColor(sf::Color::Black);
                }

            }
        }
    }
}

void Button::Draw() {
    if (visibility) {
        wind->draw(*drawing);
        wind->draw(*button_title);
    }
}