# 3ds-libs
Multi purpose C++ library for easier Homebrew development on the Nintendo 3DS
## Features
Complete:
- Better console with automatic text positioning and many formatting functions
- Image rendering

In progress:
- Easy UI system with tree structure

TODO:
- Easy audio playing

## Installing
### Uncompiled library method
Assuming you are using the [DevkitPro app template Makefile](https://github.com/devkitPro/3ds-examples/blob/master/templates/application/Makefile) or a similar Makefile and file structure, and **3ds-libs** is not compiled, follow these steps.
1. `cd source` to go to your directory with your CPP files.
2. `git clone https://github.com/Wolfyxon/3ds-libs` to download the library.
3. Add this somewhere in your Makefile

 ```make
3DS_LIBS     := source/3ds-libs
3DS_LIBS_SRC := $(3DS_LIBS)/source
3DS_LIBS_INC := $(3DS_LIBS)/include
 ```
This will add variables with the paths to the files of the library. Modify the `source/3ds-libs` if you downloaded the library somewhere else.

4. Modify the `SOURCES` variable

Add
```
$(3DS_LIBS_SRC) $(3DS_LIBS_SRC)/renderable
```
To include the .CPP files for compilation. Example setup:
```make
SOURCES		 :=	source $(3DS_LIBS_SRC) $(3DS_LIBS_SRC)/renderable
```

6. Modify the `INCLUDES` variable

Add
```
include $(3DS_LIBS_INC) $(3DS_LIBS_SRC)/renderable
```
To include the necessary .H files for compilation. Example setup:
```make
INCLUDES	 :=	include $(3DS_LIBS_INC) $(3DS_LIBS_SRC)/renderable
```

7. Enjoy! Now you can use the `#include` statement to import the headers you need for your code. Example:
```cpp
#include "3ds-libs/include/Console.h"
```
