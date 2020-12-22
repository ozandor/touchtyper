#include <SFML/Graphics.hpp>

int ref_width = 800;
int ref_height = 600;

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(ref_width, ref_height),"TIKTIKTIK", sf::Style::Default);

    sf::Clock clock;
	double deltaTime = 0;

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



        window->display();
    }

    return EXIT_SUCCESS;
}