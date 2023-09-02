#include "SpriteRenderer.h"
#include <citro2d.h>
#include <string>
#include <vector>

using namespace std;

vector<Sprite> sprites;
SpriteRenderer::SpriteRenderer(){
    
}
SpriteRenderer::~SpriteRenderer(){

}

void SpriteRenderer::renderC2DSprite(C2D_Sprite sprite, float posX, float posY, float rotation, float scaleX, float scaleY){
    C2D_SpriteSetPos(&sprite, posX, posY);
    C2D_SpriteSetScale(&sprite, scaleX, scaleY);
    C2D_DrawSprite(&sprite);
}