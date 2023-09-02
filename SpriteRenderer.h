#pragma once
#include <citro2d.h>
#include <3ds.h>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    C2D_Sprite sprite;
    float posX, posY;
    float scaleX, scaleY;
    float rotation;
} Sprite;

class SpriteRenderer{
    public:
        vector<Sprite> sprites;
        C3D_RenderTarget* renderTarget;

        SpriteRenderer(gfxScreen_t screen);
        ~SpriteRenderer();
        Sprite C2DSpriteToSprite(C2D_Sprite c2d_sprite, float posX=0, float posY=0, float rotation=0, float scaleX=1, float scaleY=1);
        C2D_Sprite getC2DSpriteFromSheetFile(char* path, size_t index);
        Sprite getSpriteFromSheetFile(char* path, size_t index);
        Sprite addSprite(Sprite sprite);
        void renderSprite(Sprite sprite);
        void renderC2DSprite(C2D_Sprite sprite, float posX, float posY, float rotation, float scaleX, float scaleY);
        void render(bool clearScreen=true);
};