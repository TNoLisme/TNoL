#ifndef PLAYER_H
#define PLAYER_H

#include "Common.h"
#include "ImageLibrary.h"
using namespace std;

/*
class Player {
public:
    Player();
    ~Player();

    void handleEvent(SDL_Event& e);
    void update();
    void render();
    void free();
    void move();
    bool loadTexture(string path);

    SDL_Rect getPosition();

private:
    
    SDL_Texture* texture;
    SDL_Rect position;
    int velocityX;
    int velocityY;
    int v;
};
*/


class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 1;

        SDL_Texture* gDotTexture;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move();

		//Shows the dot on the screen
		void render();

        void free();
        bool loadTexture(string path);

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
        

};

#endif // PLAYER_H
