#include "musacshi.h"
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_mixer.h>


int main( int argc, char* args[] )
{
    SDL sdl;
    sdl.JeuGraphique();
    return 0;
}


/*
void SDL_ExitWithError(const char* message);
void TraceInterface();
void DessinerForme(SDL_Texture* texture, SDL_Rect srcrect,SDL_Window* window, SDL_Renderer* renderer ){
    if(texture==NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    if(SDL_QueryTexture(texture,NULL,NULL, &srcrect.w, &srcrect.h)!=0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    if(SDL_RenderCopy(renderer,texture,NULL,&srcrect)!=0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
}
int main( int argc, char* args[]){

      //SDL_Event event;
    SDL_Window *window=NULL;   //une fenetre juste le cadre rien dedans
    SDL_Renderer *renderer=NULL;
    //SDL_Surface *ecran=NULL;
    //=== Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
       SDL_ExitWithError("Initialisation SDL");
    }
    //=== Cr�ation fenetre et rendu
    if(SDL_CreateWindowAndRenderer(Window_width,Window_height,0,&window,&renderer) !=0)SDL_ExitWithError("Impossible de creer la fenetre et le rendu");

    // creation de surface et de texture
    SDL_Surface *menu=NULL,*play=NULL,*exit=NULL,*rules=NULL;
    SDL_Texture *T_menu=NULL,*T_play=NULL,*T_exit=NULL,*T_rules=NULL;

    SDL_Surface *level=NULL,*easy=NULL,*medium=NULL,*hard=NULL;
    SDL_Texture *T_level=NULL,*T_easy=NULL,*T_medium=NULL,*T_hard=NULL;

    menu=IMG_Load("C:\\Users\\hp\\Desktop\\ProjetMusacshi\\musacshiSDL\\src\\bmpMenu\\MenuPrincipale.bmp");
    play = IMG_Load("C:\\Users\\hp\\Desktop\\ProjetMusacshi\\musacshiSDL\\src\\bmpMenu\\Play.bmp");
    exit = IMG_Load("C:\\Users\\hp\\Desktop\\ProjetMusacshi\\musacshiSDL\\src\\bmpMenu\\Exit.bmp");
    rules = IMG_Load("C:\\Users\\hp\\Desktop\\ProjetMusacshi\\musacshiSDL\\src\\bmpMenu\\Rules.bmp");


    level=IMG_Load("C:\\Users\\hp\\Desktop\\ProjetMusacshi\\musacshiSDL\\src\\bmpLevel\\level.bmp");
    easy = IMG_Load("C:\\Users\\hp\\Desktop\\ProjetMusacshi\\musacshiSDL\\src\\bmpLevel\\easy.bmp");
    medium = IMG_Load("C:\\Users\\hp\\Desktop\\ProjetMusacshi\\musacshiSDL\\src\\bmpLevel\\medium.bmp");
    hard = IMG_Load("C:\\Users\\hp\\Desktop\\ProjetMusacshi\\musacshiSDL\\src\\bmpLevel\\hard.bmp");



    T_menu=SDL_CreateTextureFromSurface(renderer,menu);
    T_play=SDL_CreateTextureFromSurface(renderer,play);
    T_exit=SDL_CreateTextureFromSurface(renderer,exit);
    T_rules=SDL_CreateTextureFromSurface(renderer,rules);

    T_level=SDL_CreateTextureFromSurface(renderer,level);
    T_easy=SDL_CreateTextureFromSurface(renderer,easy);
    T_medium=SDL_CreateTextureFromSurface(renderer,medium);
    T_hard=SDL_CreateTextureFromSurface(renderer,hard);

    SDL_FreeSurface(menu);SDL_FreeSurface(play);SDL_FreeSurface(exit);SDL_FreeSurface(rules);
    SDL_FreeSurface(level);SDL_FreeSurface(easy);SDL_FreeSurface(medium);SDL_FreeSurface(hard);


    SDL_Rect R_menu,R_play,R_exit,R_rules;
    SDL_Rect R_level,R_easy,R_medium,R_hard;

    R_menu.w=20;R_menu.w=13;R_menu.x=0;R_menu.y=0;
    R_play.w=20;R_play.w= 13;R_play.x=0;R_play.y=0;
    R_exit.w=20;R_exit.w=13;R_exit.x=0;R_exit.y=0;
    R_rules.w=20;R_rules.w= 13;R_rules.x=0;R_rules.y=0;

    R_level.w=20;R_level.w=13;R_level.x=0;R_level.y=0;
    R_easy.w=20;R_easy.w= 13;R_easy.x=0;R_easy.y=0;
    R_medium.w=20;R_medium.w=13;R_medium.x=0;R_medium.y=0;
    R_hard.w=20;R_hard.w= 13;R_hard.x=0;R_hard.y=0;


    DessinerForme(T_menu,R_menu,window,renderer);
    DessinerForme(T_level,R_level,window,renderer);
    //=== Charger le rendu(s'affiche en noir)

    SDL_bool program_lanched = SDL_TRUE;
    while (program_lanched){
        SDL_Event event;
        int x,y;

        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_MOUSEMOTION:

                x=event.motion.x;y=event.motion.y;
                if((x>=265 && x <=580 && y>=175 && y<=230))DessinerForme(T_play,R_play,window,renderer);
                else if (x>=280 && x <=570 && y>=310 && y<=385)DessinerForme(T_rules,R_rules,window,renderer);
                else if (x>=255 && x <=545 && y>=470 && y<=545)DessinerForme(T_exit,R_exit,window,renderer);
                else DessinerForme(T_menu,R_menu,window,renderer);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if((x>=265 && x <=580 && y>=175 && y<=230))goto evenement2;
            case SDL_QUIT:
                program_lanched=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);


        }
    }


    evenement2:
    DessinerForme(T_level,R_level,window,renderer);
    program_lanched = SDL_TRUE;
    while (program_lanched){
        SDL_Event event;
        int x,y;

        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_MOUSEMOTION:

                x=event.motion.x;y=event.motion.y;
                if((x>=265 && x <=580 && y>=175 && y<=230))DessinerForme(T_easy,R_easy,window,renderer);
                else if (x>=280 && x <=570 && y>=310 && y<=385)DessinerForme(T_medium,R_medium,window,renderer);
                else if (x>=255 && x <=545 && y>=470 && y<=545)DessinerForme(T_hard,R_hard,window,renderer);
                else DessinerForme(T_level,R_level,window,renderer);
                break;
            case SDL_MOUSEBUTTONDOWN:
            case SDL_QUIT:
                program_lanched=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);


        }
    }




    //=== La dur�e d'affichage de la fenetre
    SDL_Delay(10000);
    //Detruire SDL
    SDL_DestroyTexture(T_menu);SDL_DestroyTexture(T_play);SDL_DestroyTexture(T_rules);SDL_DestroyTexture(T_exit);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char* message){
    SDL_Log("ERREUR:  %s >%s\n",message, SDL_GetError());
    SDL_Quit;
    exit(EXIT_FAILURE);
}


*/


