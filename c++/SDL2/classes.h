#ifndef CLASSES_H
#define CLASSES_H 

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

class Screen{

    public:

    // -- Attributes -- //
    int Width;
    int Height;
    int Scale;
    SDL_Window* Window;
    SDL_Renderer* Renderer;
    SDL_Texture* Texture;
    std::vector<uint32_t> PixelBuffer;

    // - Constructor - //
    Screen(int width, int height, int scale);
    
    // - Set Up Methods - //
    void Setup();
    void Render();
    void Cleanup();

    // - Render Methods - //
    void PutPixel(int posX, int posY, uint32_t color);

};

#endif //CLASSES_H
