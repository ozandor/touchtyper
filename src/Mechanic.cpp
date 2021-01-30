#include "Mechanic.h"

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

wstring Mechanic::LastStr(wstring lesson){
    wstring LS;
    for(int i=0;i<41;i++){
        LS += randomizer(lesson,LengRand());
        LS += ' ';
    }
    InputExp=LS;
    return LS;
}

wstring Mechanic::InputUser(sf::Event* event){

    return Input.toWideString();
}

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

inline bool checker(char a,char b){
    
    if(a==b){
        return true;
    }
    return false;
}

inline bool Mechanic::correct(){
    return is_correct;
}