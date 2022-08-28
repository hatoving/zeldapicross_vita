/*

    Zelda Picross

    Copyright (C) 2010  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#include <cstdlib>
#include <ctime>

#include "Window.h"
#include <vitasdk.h>

int main(int argc, char** argv) {
    if (argc && argv); //pour �viter un warning.....
    
    std::srand(std::time(NULL));

    //create folders if they don't exist yet already
    sceIoMkdir("ux0:data/ZeldaPicross", 0777);
    sceIoMkdir("ux0:data/ZeldaPicross/save", 0777);
    
    Window* window = new Window(true);
    window->loop();
    
    delete window;
    
    return 0;
}
