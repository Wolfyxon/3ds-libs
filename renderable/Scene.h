#include <citro2d.h>
#include <3ds.h>
#include "Renderable.h"

class Scene : Renderable {
    public:
        Scene(u32 backgroundColor_ = C2D_Color32f(0.0f,0.0f,0.0f,1.0f));
        ~Scene();

        u32 backgroundColor;
        bool clearOnRender = true;

        void render(gfxScreen_t screen);
};