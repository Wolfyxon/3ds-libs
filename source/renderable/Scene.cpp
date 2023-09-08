#include "../../include/renderable/Scene.h"

Scene::Scene(gfxScreen_t screen, u32 backgroundColor_){
    C2D_CreateScreenTarget(&renderTarget, GFX_LEFT);
    backgroundColor = backgroundColor_;
}
