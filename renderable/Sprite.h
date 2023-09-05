#include "Renderable.h"
#include <citro2d.h>

class Sprite : Renderable {
    public:
        Sprite();
        ~Sprite();

        C2D_Sprite c2dSprite;
        unsigned int scaleX = 1;
        unsigned int scaleY = 1;

        /** Returns the width in pixels. */
        unsigned int getWidth();
        /** Returns the height in pixels. */
        unsigned int getHeight();
        /**
         * Calculates the X scale to match the specified pixel width
         * @param width Width in pixels.
        */
        unsigned int setWidth(unsigned int width);
        /**
         * Calculates the Y scale to match the specified pixel height and sets it.
         * @param height Height in pixels.
        */
        unsigned int setHeight(unsigned int height);
        /**
         * Calculates the X and Y scale from the specified pixel with and height and sets it.
         * @param width Width in pixels.
         * @param height Height in pixels.
        */
        unsigned int setSize(unsigned int width, unsigned int height);

        bool loadFromSheet(C2D_SpriteSheet sheet, unsigned int index=0);
        bool loadFromSheetFile(char* path, unsigned int index=0);

    private:
        unsigned int width = 0;
        unsigned int height = 0;

};