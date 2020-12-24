#include "Messager.h"

Messager::Messager() {

}

Messager::~Messager() {

}

void Messager::setMessage(int mes) {
    Message = mes;
}

int Messager::getMessage() {
    return Message;
}