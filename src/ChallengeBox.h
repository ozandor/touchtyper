#pragma once
#include <SFML/Graphics.hpp>
#include <string>
//#include "Mechanic.h"

using namespace std;

class ChallengeBox{
    public:    
        ChallengeBox(sf::RenderWindow* win, sf::Font* fnt, wstring chl_str, int fontsize, bool is_dark);
        ~ChallengeBox();

        void DrawChallenge();
        void calculate(int index_to_check,bool is_correct);

    private:
        inline int getCharLength(char &letter, sf::Font &font, int font_size, bool boldness);
        sf::RenderWindow* MyWindow;
        sf::Text* txt_wrong;
        sf::Text* txt_waiting;
        sf::Text* txt_checked;
        sf::Text writer;
        sf::Font font;
        wstring challenge_str;
        sf::Transformable start_pos;
    //    Mechanic mec;
        int font_size;
        bool dark;
}; 
