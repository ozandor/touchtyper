#include "Mechanic.h"

Mechanic::Mechanic(wstring lesson) {
    srand(time(NULL));
    LastStr(lesson);
}

Mechanic::~Mechanic() {

}

//This should ne in main.cpp event handler.

void Mechanic::InputHandler(sf::Event* event){
    if (event->type == sf::Event::TextEntered){
        sf::String temp = event->text.unicode;
        if(checker(InputExp[iterator],temp.toWideString()[0])){
            is_correct = true;
            iterator++;
        }
        else{
            is_correct = false;
        }
    }
}

bool Mechanic::correct(){
    return is_correct;
}

inline bool Mechanic::checker(char a,char b){
    
    if(a==b){
        return true;
    }
    return false;
}



int Mechanic::LengRand(int l){
    int LR = rand() % l;
    return LR;
}

wstring Mechanic::randomizer(wstring lesson,const int length){
    sf::String randomized_s;
    //wstring randomized_s; 
    
    //srand((unsigned)time(NULL)*getpid());

    for (int i = 0; i < length;i++){ 
        randomized_s += lesson[rand()%(lesson.length())];
    }

     return randomized_s.toWideString();
}

void Mechanic::LastStr(wstring lesson){
    sf::String LS;
    for (int i = 0; i < 41; i++) {
        LS += randomizer(lesson,LengRand(lesson.length()));
        LS += ' ';
    }
    InputExp = LS.toWideString();
}

wstring Mechanic::getLessonString(){
    return InputExp;
}

int Mechanic::getIterator(){
    return iterator;
}