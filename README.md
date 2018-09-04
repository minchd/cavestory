# cavestory
This project is the remaking of the somewhat famous side scrolling game Cave Story. If you would like to read more about Cave Story please visit: https://www.cavestory.org/

I created this project as I followed the 'Remaking Cavestory in C++' tutorial found in this YouTube playlist: https://www.youtube.com/playlist?list=PLNOBk_id22bw6LXhrGfhVwqQIa-M2MsLa.

This application is based on the Simple DirectMedia Layer library (SDL2) which is a 'cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.' You can find out more about SDL2 here: https://www.libsdl.org/

Additionaly, SDL2_image is used in order to work with PNG graphic files. You can find out more about SDL2_image here: https://www.libsdl.org/projects/SDL_image/

In learning about SDL and getting familiar with it, I also came accross the following site and it's tutorials: http://lazyfoo.net/tutorials/SDL/index.php.
# OS
I am using Fedora 28, however, SDL2 has libraries for Mac and Windows if you would rather go that route.
# Dependencies
- GCC
- Make
- SDL2
- SDL_image
- Visual Studio Code - although you can use whatever IDE or source file editor you want, I used VS Code with the C++ extension made by microsoft.
# Setup
On Fedora I used DNF to install both SDL2-devel and SDL2_image-devel. I made the mistake of installing SDL_image-devel at first (without the 2) and ran into several issues during compilation and linking that took some time to resolve. The big indicator of what was wrong is that the SDL_image.h file was not located in the SDL2 directory.
# Project layout
The project is compiled by a make file that expects the follwing directoy layout:
- project root: Makefile lives here
    - build: executable is produced here
    - include: any includes not part of the system live here
    - obj: object files with debug information end up here
    - src: source files and headers live here
# Build
I toyed with using CMake but landed with make instead based on my experience with it already. The make file will pick up all source files in the src directory automatically but any included libraries will need to be added to the makefile firectly in order to be linked sucessfuly.
# Known Issues
None that I know of.