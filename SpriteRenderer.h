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
        void renderSprite(Sprite sprite);
        void renderC2DSprite(C2D_Sprite sprite, float posX, float posY, float rotation, float scaleX, float scaleY);
};