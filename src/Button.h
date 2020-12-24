#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
using namespace std;

class Button {
    public:
        Button(sf::RenderWindow* window, wstring title, double dx, double dy, double dw, double dh);
        ~Button();

        void Calculate();
        void Draw();
    private:
        sf::RenderWindow* w = NULL;
        sf::Sprite* drawing = NULL;
        sf::Texture* darkI = NULL, darkH = NULL, darkP = NULL;
        sf::Texture* lightI = NULL, lightH = NULL, lightP = NULL;
};