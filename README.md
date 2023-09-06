# 3ds-libs
Multi purpose C++ library for easier Homebrew development on the Nintendo 3DS
## Features
Complete:
- Better console with automatic text positioning and many formatting functions

In progress:
- Image rendering
- Easy UI system with tree structure

TODO:
- Easy audio playing

## Installing
Assuming you are using the [Homebrew app template](https://github.com/devkitPro/3ds-examples/tree/master/templates/application) or have a similar structure and Makefile follow these steps:
1. Clone this repository into the `source` directory in your project.
2. Add
```
3DS_LIBS     := source/3ds-libs
3DS_LIBS_DIRS := $(3DS_LIBS) $(3DS_LIBS)/renderable $(3DS_LIBS)/structure
```
to your `Makefile` to make sure the library is compiled and found by the linker.  
3. In your `Makefile` add
```
$(3DS_LIBS)
```
to `SOURCES`.  
Example of a correct setup:
```
3DS_LIBS     := source/3ds-libs
3DS_LIBS_DIRS := $(3DS_LIBS) $(3DS_LIBS)/renderable $(3DS_LIBS)/structure
#IMPORTANT: Do not add these lines below if they are already in the makefile (and they probably are)!
TARGET		 :=	$(notdir $(CURDIR))
BUILD		 :=	build
SOURCES		 :=	source $(3DS_LIBS) 
DATA		 :=	data
INCLUDES	 :=	include
GRAPHICS	 :=	gfx
#GFXBUILD	 :=	$(BUILD)
ROMFS		 :=	romfs
GFXBUILD	 :=	$(ROMFS)/gfx
```
4. Run `make` to check if your project compiles.
