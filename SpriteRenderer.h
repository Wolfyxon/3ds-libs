#pragma once
#include <citro2d.h>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    C2D_Sprite sprite;
    float posX, posY;
    float sizeX, sizeY;
    float rotation;
} Sprite;

class SpriteRenderer{
    public:
        vector<Sprite> sprites;
        
        SpriteRenderer();
        ~SpriteRenderer();
};