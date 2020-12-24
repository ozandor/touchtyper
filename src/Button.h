#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class Button {
    public:
        Button(sf::RenderWindow* window, wstring title, int dx, int dy, int dw, int dh, sf::Font* font, int output);
        ~Button();

        void SetColorMode(bool m);
        void SetVisibility(bool v);

        void Calculate();
        void Draw();
    private:
        sf::RenderWindow* wind = NULL;
        sf::Sprite* drawing = NULL;
        sf::Texture *darkI = NULL, *darkH = NULL, *darkP = NULL;
        sf::Texture *lightI = NULL, *lightH = NULL, *lightP = NULL;
        sf::Text* button_title = NULL;

        int font_size = 0;
        bool dark_mode = false;
        bool visibility = true;

        int x = 0;
        int y = 0;
        int w = 0;
        int h = 0;

        int output_mod = 0;

        bool pressed = false;

};