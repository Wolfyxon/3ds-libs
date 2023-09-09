#ifndef RENDERABLE_H
#define RENDERABLE_H

#pragma once
#include <3ds.h>

class Renderable {
    public:
        /** Renders the renderable object. */
        virtual void render();
};

#endif