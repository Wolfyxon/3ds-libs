#ifndef DEBUGGABLE_H
#define DEBUGGABLE_H

#pragma once

#include <3ds.h>
#include <string>

class Debuggable {
    public:
        static void msg(const char* message);
        static void msg(std::string* message);
};

#endif