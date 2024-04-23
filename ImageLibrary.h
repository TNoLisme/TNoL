#ifndef IMAGE_LIBRARY_H
#define IMAGE_LIBRARY_H

#include "Common.h"
using namespace std;
class Image{

private: 
    SDL_Texture* mTexture = NULL;
    int mWidth;
	int mHeight;

public: 
    Image();
    ~Image();

    int getWidth();
	int getHeight();
    bool loadTexture(string path);
    void render(int x, int y);
    void renderIndex(int x, int y, int w, int h);
    void free();
};

#endif