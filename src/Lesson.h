#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Mechanic.h"
#include "ChallengeBox.h"
#include <iostream>
using namespace std;

class Lesson {
    public:
        Lesson(sf::RenderWindow* win, int challenge_number, sf::Font* fnt, int fontsize, bool is_dark);
        ~Lesson();

        void execute();

        //setter functions
        Mechanic* getMechanic();
        ChallengeBox* getChallengeBox();
        //getter functions
        void setMechanic(Mechanic mec);
        void setChallengeBox(ChallengeBox box);

    private:
        int bisi = 0;
        sf::Clock timer;
        ChallengeBox* chl_box = NULL;
        Mechanic* mechanic = NULL;
        wstring lesson_num[15] = {
            L"asdf", L"jklş", L"asdfjklş", L"asdfghghjklş", L"asdfghjklşii,,",
            L"asdfghjklşi,AASSDDFFGGHHJJKKLLŞŞİİ", L"asdfghjklşi,ASDFGHJKLŞİ;qqwweerrttQQWWEERRTT",
            L"asdfghjklşi,ASDFGHJKLŞİqwertQWERTyyuuııooppYYUUIIOOPP", L"asdfghjklşiqwertyuıop,ASDFGHJKLŞİğğüüĞĞÜÜ",
            L"asdfghjklşiqwertyuıopğü,ASDFGHJKLŞİQWERTYUIOPĞÜzzxxccvvbbZZXXCCVVBB",
            L"asdfghjklşiqwertyuıopğüzxcvb,ASDFGHJKLŞİQWERTYUIOPĞÜZXCVBnnmmööçç..NNMMÖÖÇÇ",
            L"qwertyuıopğüasdfghjklşizxcvbnmöç.,QWERTYUIOPĞÜASDFGHJKLŞİZXCVBNMÖÇ1122334455",
            L"qwertyuıopğüasdfghjklşizxcvbnmöç.,QWERTYUIOPĞÜASDFGHJKLŞİZXCVBNMÖÇ123456677889900",
            L"qwertyuıopğüasdfghjklşizxcvbnmöç.,QWERTYUIOPĞÜASDFGHJKLŞİZXCVBNMÖÇ1234567890\"\"!!'%'%/(())??--==::;;",
            L"qwertyuıopğüasdfghjklşizxcvbnmöç.,QWERTYUIOPĞÜASDFGHJKLŞİZXCVBNMÖÇ1234567890\"!'%/()?-=:;"
        };
};