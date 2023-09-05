#include "Sprite.h"

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