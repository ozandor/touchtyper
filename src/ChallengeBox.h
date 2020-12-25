#pragma once
#include <SFML/Graphics.hpp>
#include <string>
//#include "Mechanic.h"

using namespace std;

class ChallengeBox{
    public:    
        ChallengeBox(sf::RenderWindow* win, sf::Font fnt, wstring challenge_str, bool is_dark);
        ~ChallengeBox();
        void Calculate(bool is_correct);
        void DrawChallenge();


    private:
        inline int GetCharLength(char &letter, sf::Font &font, int font_size);
        
        sf::RenderWindow* window = NULL;
        sf::Text txt;
    //    Mechanic mec;
    
}; 
