// MARKED FOR REMOVAL

#include "../include/SpriteRenderer.h"
#include <3ds.h>
#include <citro2d.h>
#include <string>
#include <vector>

using namespace std;

vector<Sprite*> sprites;
C3D_RenderTarget* renderTarget;
SpriteRenderer::SpriteRenderer(gfxScreen_t screen){
    renderTarget = C2D_CreateScreenTarget(screen,GFX_LEFT);
}
SpriteRenderer::~SpriteRenderer(){
    sprites.clear();
}

Sprite SpriteRenderer::C2DSpriteToSprite(C2D_Sprite c2d_sprite, float posX, float posY, float rotation, float scaleX, float scaleY){
    C2D_SpriteSetCenter(&c2d_sprite,0.5f,0.5f);
    Sprite sprite = {c2d_sprite, posX,posY, scaleX,scaleY, rotation};
    return sprite;
}

C2D_Sprite SpriteRenderer::getC2DSpriteFromSheetFile(char* path, size_t index){
    C2D_SpriteSheet sheet = C2D_SpriteSheetLoad(path);
    C2D_Sprite sprite;
    C2D_SpriteFromImage(&sprite,C2D_SpriteSheetGetImage(sheet,index));
    C2D_SpriteSheetFree(sheet);
    return sprite;
}

Sprite SpriteRenderer::getSpriteFromSheetFile(char* path, size_t index){
    C2D_Sprite c2d_s = getC2DSpriteFromSheetFile(path,index);
    return C2DSpriteToSprite(c2d_s);
}

Sprite* SpriteRenderer::addSprite(Sprite* sprite){
    sprites.push_back(sprite);
    return sprite;
}

void SpriteRenderer::renderSprite(Sprite* sprite){
    renderC2DSprite(&sprite->sprite,
        sprite->posX, 
        sprite->posY,
        sprite->rotation,
        sprite->scaleX,
        sprite->scaleY
    );
}

void SpriteRenderer::renderC2DSprite(C2D_Sprite* sprite, float posX, float posY, float rotation, float scaleX, float scaleY){
    C2D_SpriteSetPos(sprite, posX, posY);
    C2D_SpriteSetScale(sprite, scaleX, scaleY);
    C2D_SpriteSetRotation(sprite,rotation);
    C2D_DrawSprite(sprite);
}

void SpriteRenderer::render(bool clearScreen){
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    if(clearScreen) C2D_TargetClear(renderTarget, C2D_Color32f(0.0f,0.0f,0.0f,1.0f));
    C2D_SceneBegin(renderTarget);

    for(size_t i=0; i<sprites.size(); i++){
        Sprite* sprite = sprites[i];
        renderSprite(sprite);
    }

    C3D_FrameEnd(0);
}