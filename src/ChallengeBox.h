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
        sf::RenderWindow* MyWindow = NULL;
        sf::Text* txt_wrong = NULL;
        sf::Text* txt_waiting = NULL;
        sf::Text* txt_checked = NULL;
        sf::Text* writer = NULL;
        sf::Font* font = NULL;
        wstring challenge_str;
        sf::Transformable start_pos;
    //    Mechanic mec;
        int font_size;
        bool dark;
}; 
