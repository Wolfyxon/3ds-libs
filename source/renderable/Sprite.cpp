#include "../../include/renderable/Sprite.h"

Sprite::Sprite(){
    name = "Sprite";
}
Sprite::~Sprite(){
    
}

bool Sprite::loadFromSheet(C2D_SpriteSheet sheet, unsigned int index){
    if(index > C2D_SpriteSheetCount(sheet)) return false;
    C2D_SpriteFromSheet(&c2dSprite,sheet,index);
    return true;
}

bool Sprite::loadFromSheetFile(char* path, unsigned int index){
    C2D_SpriteSheet sheet = C2D_SpriteSheetLoad(path);
    if(sheet == NULL) return false;
    bool res = loadFromSheet(sheet, index);
    C2D_SpriteSheetFree(sheet);
    return res;
}

void Sprite::loadFromImage(C2D_Image image){
    C2D_SpriteFromImage(&c2dSprite,image);
}

unsigned int Sprite::getHeight(){
    return c2dSprite.image.tex->height;
}

unsigned int Sprite::getWidth(){
    return c2dSprite.image.tex->width;
}

void Sprite::setScale(float x, float y){
    scaleX = x;
    scaleY = y;
}

void Sprite::setCenter(float x, float y){
    C2D_SpriteSetCenter(&c2dSprite,x,y);
}

void Sprite::render(){
    C2D_SpriteSetPos(&c2dSprite,posX,posY);
    C2D_SpriteScale(&c2dSprite,scaleX,scaleY);
    C2D_DrawSprite(&c2dSprite);
}