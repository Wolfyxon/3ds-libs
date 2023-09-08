#pragma once
#include <3ds.h>

class Renderable {
    public:
        /** 
        * Renders the renderable object. 
        * @param screen The screen where the object will be rendered.
        */
        virtual void render(gfxScreen_t screen);
};