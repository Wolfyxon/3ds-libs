#pragma once
#include <citro2d.h>
#include <3ds.h>
#include "Renderable.h"
#include "../TreeElement.h"

class Scene : Renderable, TreeElement {
    public:
        Scene(gfxScreen_t screen_, u32 backgroundColor_ = C2D_Color32f(0.0f,0.0f,0.0f,1.0f));
        ~Scene();

        u32 backgroundColor;
        bool clearOnRender = true;
        C3D_RenderTarget* renderTarget;

        void render();
};