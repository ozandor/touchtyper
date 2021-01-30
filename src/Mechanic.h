#include <stdio.h>
#include <string>
#include <ctime>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
using namespace std;


class Mechanic{
    public:
        Mechanic(wstring lesson);
        ~Mechanic();

        int indexLast();
        wstring InputUser();
        void InputHandler(sf::Event* event);
        inline bool correct();

        sf::String Input;

    private:
        wstring les;
        bool is_correct;
        wstring InputExp;

        wstring LastStr(wstring lesson);
        wstring randomizer(wstring lesson,const int length);
        int LengRand();

        inline bool checker(char a,char b);
};