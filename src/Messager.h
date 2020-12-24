#pragma once
#include <SFML/Graphics.hpp>

class Messager {
    public:
        Messager();
        ~Messager();

        void setMessage(int mes);
        int getMessage();
    private:
        int Message = 0;
};