# qnsl
Cross-platform cocos2dx-like 2D game engine for terminals
## Build
### Linux
```
$ mkdir build -p && cd build
$ cmake ..
$ make -j$(nproc)
```
Note: it will use NCurses if it was found, if not, it will build pdcurses with X11 as platform. The X11 platform is really buggy sometimes and shall not be used if you can install/use ncurses
### Windows
Open the project in visual studio and run it
