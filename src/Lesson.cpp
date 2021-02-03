#include "Lesson.h"

Lesson::Lesson(sf::RenderWindow* win, int challenge_number, sf::Font* fnt, int fontsize, bool is_dark){
    mechanic = new Mechanic(lesson_num[challenge_number - 1]);
    chl_box = new ChallengeBox(win, fnt, fontsize, is_dark);
    MistakeCount = new sf::Text("", *fnt, 70);
    LasTimeCount = new sf::Text("", *fnt, 50);

    window = win;
    
    win_height = window->getSize().y;
    win_width = window->getSize().x;
    LasTimeCount->setPosition(win_width*0.37, win_height*0.07);
    MistakeCount->setPosition(win_width*0.5, win_height*0.8);
}

Lesson::~Lesson() {
    
}

void Lesson::execute(){
    
    chl_box->calculate(mechanic->getIterator(), mechanic->correct());

    if (chl_box->DrawChallenge() && LastLesson == 1) {
        curTime = timer.getElapsedTime().asSeconds();
        LastLesson = -1;
        strTime = "";
        strTime += to_string(curTime);
        strTime += L" saniyede tamamlandı.";
    }
}

Mechanic* Lesson::getMechanic(){
    return mechanic;
}

void Lesson::setMechanic(Mechanic mec){
    mechanic = &mec;
}

ChallengeBox* Lesson::getChallengeBox(){
    return chl_box;
}

void Lesson::setChallengeBox(ChallengeBox box){
    chl_box = &box;
}

void Lesson::setLessonNumber(int a){
    mechanic->setLessonNumber(lesson_num[a-1]);
    chl_box->setChallengeString(mechanic->getLessonString());
    curTime = 0;
    LastLesson = 1;
}

void Lesson::resetTimer() {
    timer.restart();
}


void Lesson::displayMistakeCount(){
    MistakeCount->setString(to_string(mechanic->getMistakeCount()));
    LasTimeCount->setString(strTime.toWideString());
    window->draw(*MistakeCount);
    window->draw(*LasTimeCount);
}