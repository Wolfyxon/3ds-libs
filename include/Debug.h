#ifndef DEBUG_H
#define DEBUG_H

#pragma once

#include <3ds.h>
#include <string>
#include <cstring>

static void debugMsg(const char* message);
static void debugMsg(std::string* message);
static void debugMsg(std::string message);
        

#endif