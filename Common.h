#ifndef COMMON_H
#define COMMON_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include <string> 
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

inline SDL_Window* gWindow = NULL;
inline SDL_Texture* gTexture = NULL;
inline SDL_Renderer* gRenderer = NULL;
inline TTF_Font* gFont = NULL;
inline Mix_Music *gMusic = NULL;

class LButton
{
	public:
		//Initializes internal variables
		LButton();
        ~LButton();
		
		bool onstart;
		//Sets top left position
		void setPosition( int x, int y, bool _onstart);

		//Handles mouse event
		void handleEvent( SDL_Event* e );
	
		//Shows button sprite
		void render();
		bool loadTexture(string path);
		void free();
		void render(int x,int y);

	private:
		//Top left position
		SDL_Point mPosition;
		SDL_Texture* afterstartTexture = NULL;
        bool click;
		int Width;
		int Height;


};

#endif 
 
