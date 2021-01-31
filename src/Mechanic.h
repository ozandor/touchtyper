#include <stdio.h>
#include <string>
#include <ctime>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;


class Mechanic{
    public:
        Mechanic(wstring lesson);
        ~Mechanic();

        int getIndex();
        wstring InputUser();
        void InputHandler(sf::Event* event);
        bool correct();
        wstring getLessonString();

        int getIterator();
        void startIterator();

        sf::String Input;
    private:
        int iterator = 0;
        wstring les;
        bool is_correct;
        wstring InputExp;

        void LastStr(wstring lesson);
        wstring randomizer(wstring lesson,const int length);
        int LengRand(int l);

        inline bool checker(char a,char b);
};