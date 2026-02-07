#include <vector>
#include <SDL2/SDL.h>
#include "classes.h"
#include <cstdlib>
#include <ctime>

// -- SET UP -- //
Screen::Screen(int width, int height, int scale){
    Width = width;
    Height = height;
    Scale = scale;
}

void Screen::Setup(){
    // - Initialize SDL - //
    SDL_Init(SDL_INIT_VIDEO);

    // - Create Window and Renderer - //
    Window = SDL_CreateWindow("Pixel Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width * Scale, Height*Scale, SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(Renderer, Width, Height);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"); // - Scaling quality to "nearest" to keep pixelated - // 
							      
    // - Screen Buffer - //
    // ARGB8888 means each pixel is 32 bits: Alpha, Red, Green, Blue
    Texture = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, Width, Height);

    // - Pixel Array (Canvas) - //
    PixelBuffer.resize(Width * Height);
    
}

void Screen::Render(){
    // - Upload pixel array to the GPU texture
    SDL_UpdateTexture(Texture, NULL, PixelBuffer.data(), Width * sizeof(uint32_t));

    // - Clear screen, Copy texture, Present - //
    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, Texture, NULL, NULL);
    SDL_RenderPresent(Renderer);
}

void Screen::Cleanup(){
    SDL_DestroyTexture(Texture);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void Screen::PutPixel(int posX, int posY, uint32_t color){
    PixelBuffer[posY * Width + posX] = color;
}

