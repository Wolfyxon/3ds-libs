#include "../include/Debuggable.h"

void Debuggable::msg(char* message){
    svcOutputDebugString(message,sizeof(message));
}