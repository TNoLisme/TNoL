#include "Player.h"
/*
Player::Player() {

    texture = NULL;
    
    position.x = 0;
    position.y = 0;
    position.w = 20;
    position.h = 20;
    velocityX = 0;
    velocityY = 0;
    v = 1;
}

Player::~Player() {
    free();
}

void Player::handleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: velocityY -= v; break;
            case SDLK_DOWN: velocityY += v; break;
            case SDLK_LEFT: velocityX -= v; break;
            case SDLK_RIGHT: velocityX += v; break;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: velocityY += v; break;
            case SDLK_DOWN: velocityY -= v; break;
            case SDLK_LEFT: velocityX += v; break;
            case SDLK_RIGHT: velocityX -= v; break;
        }
    }
}

void Player::update() {
    position.x += velocityX;
    position.y += velocityY;
}

void Player::render() {
    SDL_RenderCopy(gRenderer, texture, NULL, &position);
}

SDL_Rect Player::getPosition() {
    return position;
}

void Player::free()
{
    // Giải phóng texture của nhân vật
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

bool Player::loadTexture(string path){
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
			position.w = loadedSurface->w;
            position.h = loadedSurface->h;
		}
            
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	texture = newTexture;
	return texture != NULL;
}


void Player::move()
{
    // Di chuyển nhân vật sang trái hoặc phải
    position.x += velocityX;

    // Nếu nhân vật đi quá xa sang trái hoặc phải
    if( ( position.x < 0 ) || ( position.x + position.w > SCREEN_WIDTH ) )
    {
        // Di chuyển trở lại
        position.x -= velocityX;
    }

    // Di chuyển nhân vật lên hoặc xuống
    position.y += velocityY;

    // Nếu nhân vật đi quá xa lên hoặc xuống
    if( ( position.y < 0 ) || ( position.y + position.h > SCREEN_HEIGHT ) )
    {
        // Di chuyển trở lại
        position.y -= velocityY;
    }
}
*/


Dot::Dot()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    gDotTexture = NULL;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; break;
            case SDLK_DOWN: mVelY += DOT_VEL; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY -= DOT_VEL; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void Dot::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

void Dot::render()
{
    //Show the dot
	SDL_Rect renderQuad;
    renderQuad.x = mPosX;
    renderQuad.y = mPosY;
    renderQuad.w = DOT_WIDTH;
    renderQuad.h = DOT_HEIGHT;

	SDL_RenderCopy( gRenderer, gDotTexture, NULL, &renderQuad );
}

void Dot::free()
{
    if( gDotTexture != NULL )
	{
		SDL_DestroyTexture( gDotTexture );
		gDotTexture = NULL;
		
	}
}



bool Dot::loadTexture(string path){
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
		
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	gDotTexture = newTexture;
	return gDotTexture != NULL;
}
