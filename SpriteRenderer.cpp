#include "SpriteRenderer.h"
#include <3ds.h>
#include <citro2d.h>
#include <string>
#include <vector>

using namespace std;

vector<Sprite> sprites;
C3D_RenderTarget* renderTarget;
SpriteRenderer::SpriteRenderer(gfxScreen_t screen){
    renderTarget = C2D_CreateScreenTarget(screen,GFX_LEFT);
}
SpriteRenderer::~SpriteRenderer(){
    sprites.clear();
}

void SpriteRenderer::renderSprite(Sprite sprite){
    renderC2DSprite(sprite.sprite,
        sprite.posX, 
        sprite.posY,
        sprite.rotation,
        sprite.sizeX,
        sprite.sizeY
    );
}

void SpriteRenderer::renderC2DSprite(C2D_Sprite sprite, float posX, float posY, float rotation, float scaleX, float scaleY){
    C2D_SpriteSetPos(&sprite, posX, posY);
    C2D_SpriteSetScale(&sprite, scaleX, scaleY);
    C2D_SpriteSetRotation(&sprite,rotation);
    C2D_DrawSprite(&sprite);
}

void SpriteRenderer::render(bool clearScreen){
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    if(clearScreen) C2D_TargetClear(renderTarget, C2D_Color32f(0.0f,0.0f,0.0f,1.0f));
    C2D_SceneBegin(renderTarget);

    for(size_t i=0; i<sprites.size(); i++){
        Sprite sprite = sprites[i];
        renderSprite(sprite);
    }
    
    C3D_FrameEnd(0);
}