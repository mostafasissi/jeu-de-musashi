#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED

#include <iostream>
#include "SDL_image.h"
#include "musacshi.h"
#define Window_width 900
#define Window_height 700

class SDL{
public :
    SDL();
    ~SDL();
    void SDL_ExitWithError(const char*);
    SDL_Texture* DessinerForme(SDL_Surface *srcsurface, SDL_Rect srcrect);
    //void afficherPlateau(const plateau& Unplateau);
    void afficher(const plateau& Unplateau);
    //void musaschi(const plateau& Unplateau, int position);
    //void policier(const plateau& Unplateau, int position);
    //void Menu(const plateau& Unplateau);
    int input(const plateau& Unplateau);
    //int musicON=1,effectON=1;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface *icon;
    friend class plateau;
};




#endif // SDL_H_INCLUDED
