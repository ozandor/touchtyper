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

        void displayMistakeCount();
        //setter functions
        Mechanic* getMechanic();
        ChallengeBox* getChallengeBox();
        //getter functions
        void setMechanic(Mechanic mec);
        void setChallengeBox(ChallengeBox box);
        void setLessonNumber(int a);

        void resetTimer();

    private:
        sf::RenderWindow* window = NULL;

        sf::Text* MistakeCount = NULL;
        sf::Text* LasTimeCount = NULL;

        sf::Clock timer;
        sf::Text* timer_text = NULL;

        ChallengeBox* chl_box = NULL;
        Mechanic* mechanic = NULL;
        
        int win_height;
        int win_width;
        
        int curTime = 0;
        int LastLesson = 0;

        sf::String strTime;
        wstring lesson_num[15] = {
            L"asdf", L"jklş", L"asdfjklş", L"asdfghghjklş", L"asdfghjklşii,",
            L"asdfghjklşiasdfghjklşi,ASDFGHJKLŞİ", L"asdfghjklşiqqwweerrttasdfghjklşiqqwweerrtt,ASDFGHJKLŞİQWERT",
            L"asdfghjklşiqwertyyuuııooppasdfghjklşiqwertyyuuııoopp,ASDFGHJKLŞİQWERTYUIOP",
            L"asdfghjklşiqwertyuıopğğüüasdfghjklşiqwertyuıopğğüüğğüüğğüü,ASDFGHJKLŞİQWERTYUIOPĞĞÜÜ",
            L"asdfghjklşiqwertyuıopğüzzxxccvvbbasdfghjklşiqwertyuıopğüzzxxccvvbbzzxxccvvbb,ASDFGHJKLŞİQWERTYUIOPĞÜZXCVB",
            L"asdfghjklşiqwertyuıopğüzxcvbnnmmööççasdfghjklşiqwertyuıopğüzxcvbnnmmööççnnmmööçç...,ASDFGHJKLŞİQWERTYUIOPĞÜZXCVBNNMMÖÖÇÇ",
            L"qwertyuıopğüasdfghjklşizxcvbnmöçqwertyuıopğüasdfghjklşizxcvbnmöç.,QWERTYUIOPĞÜASDFGHJKLŞİZXCVBNMÖÇ1122334455",
            L"qwertyuıopğüasdfghjklşizxcvbnmöçqwertyuıopğüasdfghjklşizxcvbnmöç.,QWERTYUIOPĞÜASDFGHJKLŞİZXCVBNMÖÇ123456677889900",
            L"qwertyuıopğüasdfghjklşizxcvbnmöçqwertyuıopğüasdfghjklşizxcvbnmöç.,QWERTYUIOPĞÜASDFGHJKLŞİZXCVBNMÖÇ1234567890\"!''%/()?-=:;",
            L"qwertyuıopğüasdfghjklşizxcvbnmöçqwertyuıopğüasdfghjklşizxcvbnmöç.,QWERTYUIOPĞÜASDFGHJKLŞİZXCVBNMÖÇ1234567890\"!'%/()?-=:;"
        };


};