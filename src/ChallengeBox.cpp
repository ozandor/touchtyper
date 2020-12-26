#include "ChallengeBox.h"

ChallengeBox::ChallengeBox(sf::RenderWindow* win, sf::Font* fnt, wstring challenge_str, bool is_dark){
    window = win;
    txt_wrong.setFont(*fnt); txt_waiting.setFont(*fnt); txt_checked.setFont(*fnt);
    txt_waiting.setString(challenge_str);
    dark = is_dark;
    if(dark){
        txt_wrong.setFillColor(sf::Color(139,0,0));
        txt_checked.setFillColor(sf::Color(0,100,0));
        txt_waiting.setFillColor(sf::Color(192,192,192));
    }else{
        txt_wrong.setFillColor(sf::Color(255,0,0));
        txt_checked.setFillColor(sf::Color(0,255,0));
        txt_waiting.setFillColor(sf::Color::Black);
    }
}

void ChallengeBox::calculate(int index_to_check, bool is_correct){
    
     if(is_correct){
         txt_checked.setString(txt_waiting.getString().substring(0,index_to_check));
         txt_waiting.setString(txt_waiting.getString().substring(index_to_check+1));
     }
     else
     {
         txt_checked.setString(txt_waiting.getString().substring(0,index_to_check - 1));
         txt_wrong.setString(txt_waiting.getString()[index_to_check]);
         txt_waiting.setString(txt_waiting.getString().substring(index_to_check + 1));
     }
}

void ChallengeBox::DrawChallenge(){
    
}

