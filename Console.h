#pragma once
#include <3ds.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

enum Color {
    black,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
};

enum Ansi_code {
    reset = 0,
    bold = 1,
    italic = 3,
    underline = 4,
    strikethrough = 9,
};

class Console
{
private:
    vector<string> output;
    PrintConsole printConsole;
public:
    gfxScreen_t screen;

    static const int FG_POS = 30;
    static const int BG_POS = 40;
    

    Console(gfxScreen_t screen_);
    ~Console();
    void print(string text);
    void clear();
    void render();
    void setFont(ConsoleFont font);
    int getRows();
    int getColumns();
    string getPositionPrefix(int row, int column = 0);
    string getFgPrefix(Color color);
    string getBgPrefix(Color color);
    string getAnsiPrefix(Ansi_code type);
};
