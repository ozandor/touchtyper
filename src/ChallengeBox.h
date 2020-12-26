#pragma once
#include <SFML/Graphics.hpp>
#include <string>
//#include "Mechanic.h"

using namespace std;

class ChallengeBox{
    public:    
        ChallengeBox(sf::RenderWindow* win, sf::Font* fnt, wstring challenge_str, bool is_dark);
        ~ChallengeBox();

        void DrawChallenge();


    private:
        void calculate(int index_to_check,bool is_correct);
        int getCharLength();
        sf::RenderWindow* window;
        sf::Text txt_wrong;
        sf::Text txt_waiting;
        sf::Text txt_checked;
    //    Mechanic mec;
        bool dark;
}; 
