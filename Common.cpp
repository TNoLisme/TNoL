#include "Common.h"
//#include <bits/stdc++.h>


LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;

	onstart = false;
    click = false;
	Height = 0;
	Width = 0;
}
LButton::~LButton()
{
	free();
}
void LButton::setPosition( int x, int y , bool _onstart)
{
	mPosition.x = x;
	mPosition.y = y;
	onstart = _onstart;
}
void LButton::free()
{
	//Free texture if it exists
	if( afterstartTexture != NULL )
	{
		SDL_DestroyTexture( afterstartTexture );
		afterstartTexture = NULL;
		Width = 0;
		Height = 0;
	}
}
void LButton::render( int x, int y )
{
	//Set rendering space and render to screen
	SDL_Rect render = { x, y, Width, Height };
	SDL_RenderCopy( gRenderer, afterstartTexture, NULL, &render );
}

void LButton::handleEvent(SDL_Event* e)
{
    // If mouse button is pressed
    if (e->type == SDL_MOUSEBUTTONDOWN && !click)
    {
        // Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        // Check if mouse is in the middle area
        bool inside = (x >= SCREEN_WIDTH / 4 && x <= SCREEN_WIDTH * 3 / 4 && y >= SCREEN_HEIGHT / 4 && y <= SCREEN_HEIGHT * 3 / 4);
        
        if(inside){
            onstart=true;
            click=true;
        }
    }
    else onstart = false;
}

bool LButton::loadTexture(string path){
    free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		cout << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			cout << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << endl;
		}
		else
		{
			//Get image dimensions
			Width = loadedSurface->w*2/3;
			Height = loadedSurface->h*2/3;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	afterstartTexture = newTexture;
	return afterstartTexture != NULL;
}