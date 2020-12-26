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

    public:
        wstring LastStr(wstring lesson);
// Checker not done yet
        inline bool checker(char a,char b);
/*
//expected from user
char letterexpected(string lastStr){
    
}

//user's input.
char inputletter(string userInput){

}
*/
    private:

        int LengRand();

        wstring randomizer(wstring lesson,const int length);




};