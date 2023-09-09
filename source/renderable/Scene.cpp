#include "../../include/renderable/Scene.h"

Scene::Scene(gfxScreen_t screen, u32 backgroundColor_){
    name = "Scene";
    renderTarget = C2D_CreateScreenTarget(screen, GFX_LEFT);
    backgroundColor = backgroundColor_;
}

void Scene::render(){
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_TargetClear(renderTarget, backgroundColor);
    C2D_SceneBegin(renderTarget);

    vector<TreeElement *> descendants = getDescendants();
    for(TreeElement *desc : descendants){
        if (is_base_of<Renderable* , decltype(desc)>::value){
            Renderable *rend = (Renderable*)desc;
            rend->render();
        }
    }
    descendants.clear();
    C3D_FrameEnd(0);
}
