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