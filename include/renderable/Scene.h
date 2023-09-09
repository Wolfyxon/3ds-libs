#ifndef SCENE_H
#define SCENE_H

#pragma once
#include <citro2d.h>
#include <3ds.h>
#include <type_traits>
#include "Renderable.h"
#include "../TreeElement.h"

using namespace std;

class Scene : public Renderable, public TreeElement {
    public:
        Scene(gfxScreen_t screen_, u32 backgroundColor_ = C2D_Color32f(0.0f,0.0f,0.0f,1.0f));
        ~Scene();

        u32 backgroundColor;
        bool clearOnRender = true;
        C3D_RenderTarget* renderTarget;

        /** Returns the type name of the TreeElement. */
        virtual string getType(){return "Scene";}

        void render();
};

#endif