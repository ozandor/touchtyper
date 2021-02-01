#include "ChallengeBox.h"

using namespace std;

ChallengeBox::ChallengeBox(sf::RenderWindow* win, sf::Font* fnt, wstring chl_str, int fontsize, bool is_dark){
    MyWindow = win;
    font = fnt;
    font_size = fontsize;
    dark = is_dark;

    challenge_str = chl_str;
    str_waiting = chl_str;

    win_height = MyWindow->getSize().y;
    win_width = MyWindow->getSize().x;

    writer = new sf::Text("", *font, font_size);
}

ChallengeBox::~ChallengeBox(){}

void ChallengeBox::calculate(int index_to_check, bool is_correct){
    
    str_wrong.clear();
    str_checked.clear();
    str_waiting.clear();

    if(is_correct){
        str_checked = challenge_str.substr(0, index_to_check);
        if(index_to_check < challenge_str.length()){
            str_waiting = challenge_str.substr(index_to_check);
        }
    }
    else{

        str_checked = challenge_str.substr(0, index_to_check);
        str_wrong = challenge_str[index_to_check];
        if(index_to_check < challenge_str.length()){
            str_waiting = challenge_str.substr(index_to_check+1);
        }         
    }
}

void ChallengeBox::DrawChallenge(){
    int linewidth = 0;
    int widthlimit = win_width*0.7;
    int char_length;
    char current;
    
    newline.setPosition(win_width*0.2, win_height*0.2);
    writer->setPosition(newline.getPosition().x, newline.getPosition().y);
    
    str_checked.shrink_to_fit();
    str_waiting.shrink_to_fit();
    str_wrong.shrink_to_fit();

    if(str_checked.size() < challenge_str.size()){
        if(!str_checked.empty()){

            writer->setStyle(sf::Text::Regular);

            if(dark){
                writer->setFillColor(sf::Color(50,205,50));
            }
            else{
                writer->setFillColor(sf::Color(0,255,0));
            }

            for(int i = 0; i < str_checked.length(); i++){
                if( linewidth < widthlimit){
                    current = str_checked[i];
                    char_length = getCharLength(current, *font, font_size, false);
                    writer->setString(str_checked[i]);
                    MyWindow->draw(*writer);
                    
                    writer->move(char_length, 0);
                    linewidth += char_length;
                }
                else{
                    writer->setString(str_checked[i]);
                    MyWindow->draw(*writer);
                    newline.move(0, font_size);
                    writer->setPosition(newline.getPosition().x, newline.getPosition().y);
                    linewidth = 0;
                    
                }
            }
        }

        if(!str_wrong.empty()){

            writer->setStyle(sf::Text::Underlined | sf::Text::Bold);
            writer->setFillColor(sf::Color(255,0,0));

            if( linewidth < widthlimit){
                current = str_wrong[0];
                char_length = getCharLength(current, *font, font_size, true);
                writer->setString(str_wrong[0]);
                MyWindow->draw(*writer);
                
                writer->move(char_length, 0);
                linewidth += char_length;
            }
            else{
                writer->setString(str_wrong[0]);
                MyWindow->draw(*writer);
                newline.move(0, font_size);
                writer->setPosition(newline.getPosition().x, newline.getPosition().y);
                linewidth = 0;
                
            }
        }

        if(!str_waiting.empty()){

            writer->setStyle(sf::Text::Underlined);

            if(dark){
                writer->setFillColor(sf::Color::White);
            }
            else{
                writer->setFillColor(sf::Color::Black);
            }

            for(int i = 0; i < str_waiting.length(); i++){
                if( linewidth < widthlimit){
                    current = str_waiting[i];
                    char_length = getCharLength(current, *font, font_size, false);
                    writer->setString(str_waiting[i]);
                    MyWindow->draw(*writer);
                    
                    writer->move(char_length, 0);
                    linewidth += char_length;
                }
                else{
                    writer->setString(str_waiting[i]);
                    MyWindow->draw(*writer);
                    newline.move(0, font_size);
                    writer->setPosition(newline.getPosition().x, newline.getPosition().y);
                    linewidth = 0;
                    
                }
            }
        }
    }
}

inline int ChallengeBox::getCharLength(char &letter, sf::Font &font, int font_size, bool boldness) {
    return font.getGlyph(int(letter), font_size, boldness).advance;
}

void ChallengeBox::setChallengeString(wstring new_str){
    challenge_str = new_str;
    
    while(challenge_str[challenge_str.size() - 1] == ' '){
        challenge_str.erase(challenge_str.size()- 1);
    }
}