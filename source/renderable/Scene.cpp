#include "../../include/renderable/Scene.h"

Scene::Scene(gfxScreen_t screen, u32 backgroundColor_){
    renderTarget = C2D_CreateScreenTarget(screen, GFX_LEFT);
    backgroundColor = backgroundColor_;
}

void Scene::render(){
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_TargetClear(renderTarget, backgroundColor);
    C2D_SceneBegin(renderTarget);

    vector<TreeElement*> descendants = getDescendants();
    for(size_t i=0; i<descendants.size();i++){
        TreeElement* desc = descendants[i];
        if(dynamic_cast<Renderable*>(desc) != nullptr){
            Renderable* rend = (Renderable*)desc;
            rend->render();
        }
    }
    descendants.clear();
    C3D_FrameEnd(0);
}
