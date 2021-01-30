#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include "Button.h"
#include "Messager.h"
#include "ChallengeBox.h"

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

	wstring deneme = L"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
	ChallengeBox* box = new ChallengeBox(window, &coolvetica, deneme, 30, true);

	Messager* msg = new Messager();

	vector<Button> lesson_buttons;

	Button ders1(window, L"Ders1", 10, 10, 160, 40, &coolvetica, 1, msg); lesson_buttons.push_back(ders1);
	Button ders2(window, L"Ders2", 10, 60, 160, 40, &coolvetica, 2, msg); lesson_buttons.push_back(ders2);
	Button ders3(window, L"Ders3", 10, 110, 160, 40, &coolvetica, 3, msg); lesson_buttons.push_back(ders3);
	Button ders4(window, L"Ders4", 10, 160, 160, 40, &coolvetica, 4, msg); lesson_buttons.push_back(ders4);
	Button ders5(window, L"Ders5", 10, 210, 160, 40, &coolvetica, 5, msg); lesson_buttons.push_back(ders5);
	Button ders6(window, L"Ders6", 10, 260, 160, 40, &coolvetica, 6, msg); lesson_buttons.push_back(ders6);
	Button ders7(window, L"Ders7", 10, 310, 160, 40, &coolvetica, 7, msg); lesson_buttons.push_back(ders7);
	Button ders8(window, L"Ders8", 10, 360, 160, 40, &coolvetica, 8, msg); lesson_buttons.push_back(ders8);
	Button ders9(window, L"Ders9", 10, 410, 160, 40, &coolvetica, 9, msg); lesson_buttons.push_back(ders9);
	Button ders10(window, L"Ders10", 10, 460, 160, 40, &coolvetica, 10, msg); lesson_buttons.push_back(ders10);
	Button ders11(window, L"Ders11", 10, 510, 160, 40, &coolvetica, 11, msg); lesson_buttons.push_back(ders11);
	Button ders12(window, L"Ders12", 10, 560, 160, 40, &coolvetica, 12, msg); lesson_buttons.push_back(ders12);
	Button ders13(window, L"Ders13", 10, 610, 160, 40, &coolvetica, 13, msg); lesson_buttons.push_back(ders13);
	Button ders14(window, L"Ders14", 10, 660, 160, 40, &coolvetica, 14, msg); lesson_buttons.push_back(ders14);
	Button ders15(window, L"Ders15", 10, 710, 160, 40, &coolvetica, 15, msg); lesson_buttons.push_back(ders15);

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
		msg->setMessage(0);
		for (int i = 0; i < lesson_buttons.size(); i++) {
			lesson_buttons[i].Calculate();
		}
		if (msg->getMessage()) {
			//Burada butonlarla ilgili tüm işlemler yapılacak.
			//soldaki butonlar için ders seçimi.
			//derslerin içindeki butonlar için de başlangıç ve yenileme seçimi.
		}

        window->clear(sf::Color::Black); 

		for (int i = 0; i < lesson_buttons.size(); i++) {
			lesson_buttons[i].Draw();
		}
		

		box->calculate(221, false);
		box->DrawChallenge();
		


        window->display();
    }

    return EXIT_SUCCESS;
}