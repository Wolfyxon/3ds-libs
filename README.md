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
```make
3DS_LIBS          := source/3ds-libs
3DS_LIBS_SRC      := $(3DS_LIBS)/source
3DS_LIBS_INC      := $(3DS_LIBS)/include
3DS_LIBS_SRC_DIRS := $(3DS_LIBS_SRC)/renderable
3DS_LIBS_INC_DIRS := $(3DS_LIBS_INC)/renderable
3DS_LIBS_DIRS     := $(3DS_LIBS_INC_DIRS) $(3DS_LIBS_SRC)
```
to your `Makefile` to make sure the library is compiled and found by the linker.  
3. In your `Makefile` add
```
$(3DS_LIBS)
```
to `SOURCES`.  
Example of a correct setup:
```make
3DS_LIBS          := source/3ds-libs
3DS_LIBS_SRC      := $(3DS_LIBS)/source
3DS_LIBS_INC      := $(3DS_LIBS)/include
3DS_LIBS_SRC_DIRS := $(3DS_LIBS_SRC)/renderable
3DS_LIBS_INC_DIRS := $(3DS_LIBS_INC)/renderable
3DS_LIBS_DIRS     := $(3DS_LIBS_INC_DIRS) $(3DS_LIBS_SRC)

TARGET		 :=	$(notdir $(CURDIR))
BUILD		 :=	build
SOURCES		 :=	source $(3DS_LIBS_DIRS) 
DATA		 :=	data
INCLUDES	 :=	include
GRAPHICS	 :=	gfx
#GFXBUILD	 :=	$(BUILD)
ROMFS		 :=	romfs
GFXBUILD	 :=	$(ROMFS)/gfx
```
4. Run `make` to check if your project compiles.
