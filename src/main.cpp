#include <SFML/Graphics.hpp>
#include <stdio.h>

int ref_width = 800;
int ref_height = 450;

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(ref_width, ref_height), "TIKTIKTIK", sf::Style::Default);

    sf::Clock clock;
	double deltaTime = 0;

	sf::Font coolvetica;
	if (!coolvetica.loadFromFile("coolvetica.ttf")) { //Font being read from file.
    	printf("Couldn't load Coolvetica. \n"); //Message for load error
	} else {
		printf("Coolvetica loaded. \n"); //Message if font loaded.
	}

	sf::Font coolvetica_ince;
	if (!coolvetica_ince.loadFromFile("coolvetica-ince.ttf")) { //Font being read from file
    	printf("Couldn't load Coolvetica Condensed. \n"); //Message for load error
	} else {
		printf("Coolvetica Condensed loaded. \n"); //Message if font loaded.
	}

	sf::Text firstText(L"Deneme yazısı", coolvetica, 30);
	sf::Text secondText(L"Deneme yazısı2", coolvetica_ince, 30);
	secondText.setPosition(0,40);

    sf::Event event;
    while(window->isOpen()) {
        deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		while(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window->close();
			if(event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window->close();
				}
			}
		}
        
        window->clear(sf::Color::Black); 

		window->draw(firstText);
		window->draw(secondText);

        window->display();
    }

    return EXIT_SUCCESS;
}