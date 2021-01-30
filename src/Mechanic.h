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

        sf::String Input;

        wstring LastStr(wstring lesson);

        inline bool checker(char a,char b);

        int indexLast();
        
        wstring InputUser(sf::Event* event);
        
        void InputHandler(sf::Event* event);

        inline bool correct();
    private:

        int LengRand();

        wstring InputExp;

        wstring randomizer(wstring lesson,const int length);

        bool is_correct;
};