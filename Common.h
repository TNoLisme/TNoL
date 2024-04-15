#ifndef COMMON_H
#define COMMON_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

inline SDL_Window* gWindow = NULL;
inline SDL_Texture* gTexture = NULL;
inline SDL_Renderer* gRenderer = NULL;
inline TTF_Font* gFont = NULL;
#endif 
 
