#include "Mechanic.h"

Mechanic::Mechanic(wstring lesson) {
    LastStr(lesson);
}

Mechanic::~Mechanic() {

}

wstring Mechanic::InputUser(){
    return Input.toWideString();
}

//This should ne in main.cpp event handler.

void Mechanic::InputHandler(sf::Event* event){
    if (event->type == sf::Event::TextEntered){
        sf::String temp = event->text.unicode;
        if(checker(InputExp[Input.getSize()],temp.toWideString()[0])){
            Input +=event->text.unicode;
            is_correct = true;
        }
        else{
            is_correct = false;
        }
    }
}

int Mechanic::indexLast(){
    
    return Input.getSize() -1;
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



int Mechanic::LengRand(){
    srand(time(NULL));
    int LR = rand()%4+2;
    return LR;
}

wstring Mechanic::randomizer(wstring lesson,const int length){

    wstring randomized_s; 
    
    srand((unsigned)time(NULL)*getpid());

    randomized_s.reserve(length);
     for (int i = 0; i < length;i++){ 
        randomized_s += lesson[rand()%(sizeof(lesson)-1)];
     }

     return randomized_s;
}

void Mechanic::LastStr(wstring lesson){
    wstring LS;
    for(int i=0;i<41;i++){
        LS += randomizer(lesson,LengRand());
        LS += ' ';
    }
    InputExp=LS;
}

wstring Mechanic::getLessonString(){
    return InputExp;
}
