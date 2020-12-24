#include <stdio.h>
#include <string>
#include <ctime>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
using namespace std;


class Mechanic{
    Mechanic(wstring lesson);
    ~Mechanic();
/* Checker not done yet
inline bool checker(char a,char b){
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}

//expected from user
char letterexpected(string lastStr){
    
}

//user's input.
char inputletter(string userInput){

}
*/
int LengRand(){
    srand(time(NULL));
    int LR = rand()%4+2;
    return LR;
}

wstring randomizer(wstring lesson,const int length){

    wstring randomized_s; 
    
    srand((unsigned)time(NULL)*getpid());

    randomized_s.reserve(length);
     for (int i = 0; i < length;i++){ 
        randomized_s += lesson[rand()%(sizeof(lesson)-1)];
     }

     return randomized_s;
}

wstring LastStr(wstring lesson){
    wstring LS;
    for(int i=0;i<41;i++){
    LS += randomizer(lesson,LengRand());
    LS += ' ';
    }
    return LS;
}


};