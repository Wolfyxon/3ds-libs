#ifndef DEBUGGABLE_H
#define DEBUGGABLE_H

#pragma once

#include <3ds.h>
#include <string>
#include <cstring>

static void debugMsg(const char* message);
static void debugMsg(std::string* message);
static void debugMsg(std::string message);
        

#endif