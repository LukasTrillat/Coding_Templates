#include <SDL2/SDL.h>
#include "classes.h"

int main(int argc, char* args[]){

    // ------- INITIAL SETUP ------- //
    Screen screen(140,120, 8);
    screen.Setup();


    // ------ MAIN LOOP ------ //
    bool running = true;
    SDL_Event event;
    while(running){
	// - Event Handler - //
	while(SDL_PollEvent(&event)){
	    if (event.type == SDL_QUIT) running = false;
	}

	// ------- MAIN LOGIC -------- //
	screen.PutPixel(50,50, 0xFFFF0000);
	// General code goes here... //


	// ------- Render -------- //
	screen.Render();
    }
    
    screen.Cleanup();
    return 0;
}
