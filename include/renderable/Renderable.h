#ifndef RENDERABLE_H
#define RENDERABLE_H

#pragma once
#include <3ds.h>

class Renderable {
    public:
        Renderable();
        ~Renderable();
        
        /** Renders the renderable object. */
        virtual void render();
};

#endif