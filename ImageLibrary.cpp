#include "Common.h"
#include "ImageLibrary.h"
using namespace std;
Image::Image(){
    mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Image::~Image(){
    free();
}

bool Image::loadTexture(string path){
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
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			cout << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << endl;
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w*2/3;
			mHeight = loadedSurface->h*2/3;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void Image::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Image::render( int x, int y )
{
	
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
}

void Image::renderIndex( int x, int y ,int w, int h)
{
	SDL_Rect render_Index;
    render_Index.x = x;
    render_Index.y = y;
    render_Index.w = w;
    render_Index.h = h;
	
	SDL_RenderCopy( gRenderer, mTexture, NULL, &render_Index );
}
 
 
int Image::getWidth()
{
	return mWidth;
}

int Image::getHeight()
{
	return mHeight;
}
