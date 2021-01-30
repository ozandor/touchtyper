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
        wstring str_wrong;
        wstring str_waiting;
        wstring str_checked;
        wstring challenge_str;
        sf::Text* writer = NULL;
        sf::Font* font = NULL;
        sf::Transformable newline;
    //    Mechanic mec;
        int win_height;
        int win_width;
        int font_size;
        bool dark;
}; 
