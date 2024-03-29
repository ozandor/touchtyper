#pragma once
#include <SFML/Graphics.hpp>
#include <string>
//#include "Mechanic.h"
#include <iostream>


using namespace std;

class ChallengeBox{
    public:    
        ChallengeBox(sf::RenderWindow* win, sf::Font* fnt, int fontsize, bool is_dark);
        ~ChallengeBox();

        bool DrawChallenge();
        void calculate(int index_to_check,bool is_correct);

        void setChallengeString(wstring new_str);

    private:
        inline int getCharLength(wchar_t &letter, sf::Font &font, int font_size, bool boldness);
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
