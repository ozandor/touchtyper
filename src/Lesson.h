#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Lesson {
    public:
        Lesson(sf::RenderWindow* window);
        ~Lesson();

        void Calculate();
        void Draw();

    private:
        sf::Clock timer;
        sf::RenderWindow* w = NULL;
};