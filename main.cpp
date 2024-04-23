
#include "Common.h"
#include "ImageLibrary.h"
#include "Player.h"
using namespace std;

bool init();
bool loadMedia();
void close();
Image startImage;
Image loadingImage;


LButton button;
bool ok = false;

Dot player;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			cout << "Warning: Linear texture filtering not enabled!" << endl;
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_JPG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
					success = false;
				}
				//44100, MIX_DEFAULT_FORMAT, 2, 1024
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 1024 ) < 0 )
				{
					cout<<"SDL_mixer could not initialize! SDL_mixer Error: "<<Mix_GetError()<<endl;
					success = false;
				}
				
			}
		}
	}
	return success;
}

bool loadMedia()
{
	bool success = true;
	

	if( !startImage.loadTexture( "image/1.jpg" ) )
	{
		cout << "Failed to load Foo' texture image!" << endl;
		success = false;
	}
	
	//Load background texture
	if( !loadingImage.loadTexture( "image/aot.jpg" ) )
	{
		cout << "Failed to load background texture image!" << endl;
		success = false;
	}
	if( !button.loadTexture( "image/bg2.jpg" ) )
	{
		cout << "Failed to load background texture image!" << endl;
		success = false;
	}
	if (!player.loadTexture("image/player2.jpg"))
    {
        cout << "Failed to load player texture!" << endl;
        success = false;
    }

	gMusic = Mix_LoadMUS( "music/Tuongquan.mp3" );
	if( gMusic == NULL )
	{
		cout << "Failed to load background texture image!" << Mix_GetError()<< endl;
		success = false;
	}
	 else
    {
        // Phát nhạc nền
        Mix_PlayMusic( gMusic, -1 ); // -1 để lặp vô hạn
		Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
		//max là 128
    }

	return success;
}

void close()
{
	startImage.free();
	loadingImage.free();
	player.free();

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic( gMusic );
	gMusic = NULL;

	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	if( !init() )
	{
		cout << "Failed to initialize!" << endl;
	}
	else
	{
		if( !loadMedia() )
		{
			cout << "Failed to load media!" << endl;
		}
		else
		{	
			bool quit = false;
			SDL_Event e;


			while( !quit )
			{
				
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						button.handleEvent(&e);
					}
					
					player.handleEvent(e);
					
				}
				// Hiển thị nhân vật và cập nhật di chuyển khi chuyển vào background game
                if(ok) {
                    //player.handleEvent(e); // Xử lý sự kiện
					player.move();
                    //player.update(); // Cập nhật trạng thái của nhân vật
				}
				
				
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                if(!ok){
                    loadingImage.render( 0, 0 );
                    startImage.renderIndex( SCREEN_WIDTH/4,SCREEN_HEIGHT/4,SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
                }
                if(button.onstart||ok){
                    //biến ok giúp giữ cửa sổ nguyên ảnh background của game
                    button.render(0,0);
                    ok=true;
					player.render(); // Vẽ nhân vật lên màn hình
                }
                
                //player.render(); // Vẽ nhân vật lên màn hình

                SDL_RenderPresent( gRenderer );
			}
		}
	}
	close();
	return 0;
}
