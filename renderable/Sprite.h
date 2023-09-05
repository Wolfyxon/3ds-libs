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
        void setWidth(unsigned int width);
        /**
         * Calculates the Y scale to match the specified pixel height and sets it.
         * @param height Height in pixels.
        */
        void setHeight(unsigned int height);
        /**
         * Calculates the X and Y scale from the specified pixel with and height and sets it.
         * @param width Width in pixels.
         * @param height Height in pixels.
        */
        void setSize(unsigned int width, unsigned int height);
        /**
         * Set X and Y scale of the sprite at the same time.
         * @param x Width scale percent.
         * @param y Height scale percent.
        */
        void setScale(unsigned int x, unsigned int y);
        /**
         * Loads a sprite from a sprite sheet.
         * @param sheet The sprite sheet.
         * @param index Index of the sprite in sheet.
        */
        bool loadFromSheet(C2D_SpriteSheet sheet, unsigned int index=0);
        /**
         * Loads a sprite from a sprite sheet at the specified file path.
         * @param path File path to the sprite sheet, example 'someSheet.t3x'.
         * @param index Index of the sprite in sheet.
        */
        bool loadFromSheetFile(char* path, unsigned int index=0);
            /**
         * Loads a sprite from a C2D_Image.
         * @param image The image you want to load.
        */
        void loadFromImage(C2D_Image image);

    private:
        unsigned int width = 0;
        unsigned int height = 0;

};