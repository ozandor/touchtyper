#include "Lesson.h"

Lesson::Lesson(sf::RenderWindow* win, int challenge_number, sf::Font* fnt, int fontsize, bool is_dark){
    mechanic = new Mechanic(lesson_num[challenge_number - 1]);
    chl_box = new ChallengeBox(win, fnt, fontsize, is_dark);
    MistakeCount = new sf::Text("", *fnt, 100);

    window = win;
    
    win_height = window->getSize().y;
    win_width = window->getSize().x;
    MistakeCount->setPosition(win_width*0.5, win_height*0.5);
}

Lesson::~Lesson() {
    
}

void Lesson::execute(){

    chl_box->calculate(mechanic->getIterator(), mechanic->correct());

    chl_box->DrawChallenge();

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
}


void Lesson::displayMistakeCount(){
    MistakeCount->setString(to_string(mechanic->getMistakeCount()));

    window->draw(*MistakeCount);
}