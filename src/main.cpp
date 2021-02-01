#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include "Button.h"
#include "Messager.h"
#include "Lesson.h"
#include <iostream>

using namespace std;

int ref_width = 1366;
int ref_height = 768;
//değişim deneme
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

	
	Lesson* lesson = new Lesson(window, 1, &coolvetica, 40, true);

	Messager* msg = new Messager();

	vector<Button*> lesson_buttons;

	for (int i = 0; i < 15; i++) {
		wstring name = L"Ders";
		name += to_wstring(i+1);
		Button* temp = new Button(window, name, 10, 10 + i*50, 160, 40, &coolvetica, i+1, msg);
		lesson_buttons.push_back(temp);
	}

    sf::Event event;
    while(window->isOpen()) {
        deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		while(window->pollEvent(event)) {

			lesson->getMechanic()->InputHandler(&event);

			if(event.type == sf::Event::Closed)
				window->close();
			if(event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window->close();
				}
			}
		}
		msg->setMessage(0);
		for (int i = 0; i < lesson_buttons.size(); i++) {
			lesson_buttons[i]->Calculate();
		}
		if (msg->getMessage()) {
			lesson->setLessonNumber(msg->getMessage());

			//Burada butonlarla ilgili tüm işlemler yapılacak.
			//soldaki butonlar için ders seçimi.
			//derslerin içindeki butonlar için de başlangıç ve yenileme seçimi.
		}

        window->clear(sf::Color::Black); 

		for (int i = 0; i < lesson_buttons.size(); i++) {
			lesson_buttons[i]->Draw();
		}
		
		lesson->execute();
        
		window->display();
    }

    return EXIT_SUCCESS;
}