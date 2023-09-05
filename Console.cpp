#include "Console.h"
#include <3ds.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

gfxScreen_t screen;
Console::Console(gfxScreen_t screen_){
    screen = screen_;
}

Console::~Console(){
    clear();
}

string Console::pos(int row, int column){
    return "\x1b[" + to_string(row) + ";" + to_string(column) + "H";
}

string Console::fg(Color color){
    return "\x1b["+ to_string( FG_POS+(int)color)+"m";
}

string Console::bg(Color color){
    return "\x1b["+ to_string( BG_POS+(int)color)+"m";
}

string Console::ansi(Ansi_code type){
    return "\x1b["+ to_string(type);
}

void Console::print(string text){
    if((int)output.size() > 30){
        output.erase(output.begin());
    }
    output.push_back(text);
}

void Console::clear(){
    output.clear();
}

void Console::setFont(ConsoleFont font){
    consoleSetFont(&printConsole, &font);
}

int Console::getRows(){
    return 30;
}

int Console::getColumns(){
    if(screen == GFX_TOP) return 50;
    if(screen == GFX_BOTTOM) return 40;
    return 0;
}

void Console::render(){
    consoleInit(screen, &printConsole);
    consoleSelect(&printConsole);
    //consoleClear();
    
    for(int i = 0; i<(int)output.size(); i++){
        int topOffset = i+1;
        cout << pos(topOffset) << output[i];
    }
}