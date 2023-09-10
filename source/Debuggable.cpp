#include "../include/Debuggable.h"

void Debuggable::msg(const char* message){
    svcOutputDebugString(message,std::strlen(message));
}

void Debuggable::msg(std::string* message){
    msg(message->c_str());
}

void Debuggable::msg(std::string message){
    msg(message.c_str());
}
