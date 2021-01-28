#include "ChallengeBox.h"

ChallengeBox::ChallengeBox(sf::RenderWindow* win, sf::Font* fnt, wstring chl_str, int fontsize, bool is_dark){
    MyWindow = win;
    font = fnt;
    txt_waiting->setString(challenge_str);
    dark = is_dark;
    challenge_str = chl_str;

    font_size = fontsize;

    txt_checked = new sf::Text("", *font, font_size);// tırnaklarla yaptığım tanımlamanın doğruluğundan emin değilim
    txt_waiting = new sf::Text("", *font, font_size);// debugda bi bakmak lazım
    txt_wrong = new sf::Text("", *font, font_size);

    if(dark){
        txt_wrong->setFillColor(sf::Color(139,0,0));
        txt_checked->setFillColor(sf::Color(0,100,0));
        txt_waiting->setFillColor(sf::Color(192,192,192));
    }else{
        txt_wrong->setFillColor(sf::Color(255,0,0));
        txt_checked->setFillColor(sf::Color(0,255,0));
        txt_waiting->setFillColor(sf::Color::Black);
    }

    txt_checked->setStyle((sf::Text::Bold | sf::Text::Underlined));
    
    start_pos.setPosition(100, 100);
}

void ChallengeBox::calculate(int index_to_check, bool is_correct){
    
     if(is_correct){
         txt_checked->setString(txt_waiting->getString().substring(0,index_to_check));
         txt_waiting->setString(txt_waiting->getString().substring(index_to_check+1));
     }
     else
     {
         txt_checked->setString(txt_waiting->getString().substring(0,index_to_check - 1));
         txt_wrong->setString(txt_waiting->getString()[index_to_check]);
         txt_waiting->setString(txt_waiting->getString().substring(index_to_check + 1));
     }
}

void ChallengeBox::DrawChallenge(){
    int linewidth = 0;
    int widthlimit = 200;
    int char_length;
    char current;

    if(txt_checked->getString().getSize() > 0){
        writer->setPosition(start_pos.getPosition());
        writer->setStyle(txt_checked->getStyle());
        writer->setFont(*font);

        for(int i = 0; i < txt_checked->getString().getSize(); i++){
            if(linewidth < widthlimit){
                current = txt_checked->getString()[i];
                char_length = getCharLength(current, *font, font_size, true);
                writer->setString(current);
                MyWindow->draw(*writer);
                writer->move(char_length + 2, 0);
                linewidth += (char_length + 2);
            }
            else{
                writer->setPosition(start_pos.getPosition().x, font_size + 10);
                start_pos.move(0, font_size + 10);
                linewidth = 0;
            }
        }
    }

    if(txt_wrong->getString().getSize() > 0){
        if(!(linewidth < widthlimit)){
            writer->setPosition(start_pos.getPosition().x, font_size + 10);
            start_pos.move(0, font_size + 10);
            linewidth = 0;
        }
        current = txt_wrong->getString()[0];
        char_length = getCharLength(current, *font, 16, false);
        writer->setString(current);
        MyWindow->draw(*writer);
        writer->move(char_length + 2, 0);
        linewidth += (char_length + 2);
    }
    
    if(txt_waiting->getString().getSize() > 0){
        writer->setPosition(start_pos.getPosition());
        writer->setStyle(txt_waiting->getStyle());
        writer->setFont(*font);

        for(int i = 0; i < txt_waiting->getString().getSize(); i++){
            if(linewidth < widthlimit){
                current = txt_waiting->getString()[i];
                char_length = getCharLength(current, *font, font_size, false);
                writer->setString(current);
                MyWindow->draw(*writer);
                writer->move(char_length + 2, 0);
                linewidth += (char_length + 2);
            }
            else{
                writer->setPosition(start_pos.getPosition().x, font_size + 10);
                start_pos.move(0, font_size + 10);
                linewidth = 0;
            }
        }
    }

}

inline int ChallengeBox::getCharLength(char &letter, sf::Font &font, int font_size, bool boldness) {
    return font.getGlyph(int(letter), font_size, boldness).advance;
}