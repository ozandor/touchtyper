#include "ChallengeBox.h"

ChallengeBox::ChallengeBox(sf::RenderWindow* win, sf::Font fnt, wstring challenge_str, bool is_dark){
    window = win;
    txt.setFont(fnt);
    txt.setString(challenge_str);
    if(is_dark){
        txt.setFillColor(sf::Color(192,192,192));
    }else{
        txt.setFillColor(sf::Color::Black);
    }
}

