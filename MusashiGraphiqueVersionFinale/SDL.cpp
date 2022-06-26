#include "musacshi.h"


SDL::SDL(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_ExitWithError("incapable d'initialiser la SDL\n");
    }
    window = SDL_CreateWindow("JEU MUSACSHI",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       Window_width, Window_height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2,30)!=0){
        SDL_ExitWithError("incapable d'initialiser le son\n");
    }
    music = Mix_LoadMUS("src/sons/music.mp3");
    effect1 = Mix_LoadWAV("src/sons/click.wav");
    effect2 = Mix_LoadWAV("src/sons/EAT.wav");
    effect3 = Mix_LoadWAV("src/sons/INVALIDECHOICE.wav");
    effect4 = Mix_LoadWAV("src/sons/LOSE.wav");
    effect5 = Mix_LoadWAV("src/sons/WIN.wav");
}
SDL::~SDL(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(EXIT_FAILURE);
}


void SDL::SDL_ExitWithError(const char* message)
{
    SDL_Log("ERREUR:  %s >%s\n",message, SDL_GetError());
    exit(EXIT_FAILURE);
}


SDL_Rect SDL::getMusashi(const plateau& Unplateau){
    position saPlace = Unplateau.positionDuVoleur();
    SDL_Rect srcrect;
    switch(saPlace.x){
    case 0:
        srcrect.y = 4;
        if(saPlace.y == 0)srcrect.x =10;
        else if(saPlace.y == 1)srcrect.x =98;
        else if(saPlace.y == 2)srcrect.x =186;
        else if(saPlace.y == 3)srcrect.x =274;
        else if(saPlace.y == 4)srcrect.x =362;
        break;
    case 1:
        srcrect.y = 92;
        if(saPlace.y == 0)srcrect.x =10;
        else if(saPlace.y == 1)srcrect.x =98;
        else if(saPlace.y == 2)srcrect.x =186;
        else if(saPlace.y == 3)srcrect.x =274;
        else if(saPlace.y == 4)srcrect.x =362;
        break;
    case 2:
        srcrect.y = 180;
        if(saPlace.y == 0)srcrect.x =10;
        else if(saPlace.y == 1)srcrect.x =98;
        else if(saPlace.y == 2)srcrect.x =186;
        else if(saPlace.y == 3)srcrect.x =274;
        else if(saPlace.y == 4)srcrect.x =362;
        break;
    case 3:
        srcrect.y = 268;
        if(saPlace.y == 0)srcrect.x =10;
        else if(saPlace.y == 1)srcrect.x =98;
        else if(saPlace.y == 2)srcrect.x =186;
        else if(saPlace.y == 3)srcrect.x =274;
        else if(saPlace.y == 4)srcrect.x =362;
        break;
    case 4:
        srcrect.y = 356;
        if(saPlace.y == 0)srcrect.x =10;
        else if(saPlace.y == 1)srcrect.x =98;
        else if(saPlace.y == 2)srcrect.x =186;
        else if(saPlace.y == 3)srcrect.x =274;
        else if(saPlace.y == 4)srcrect.x =362;
        break;
    case 5:
        srcrect.y = 444;
        if(saPlace.y == 1)srcrect.x =98;
        else if(saPlace.y == 2)srcrect.x =186;
        else if(saPlace.y == 3)srcrect.x =274;
        break;
    case 6:
        srcrect.y = 532;
        if(saPlace.y == 0)srcrect.x =10;
        else if(saPlace.y == 1)srcrect.x =98;
        else if(saPlace.y == 2)srcrect.x =186;
        else if(saPlace.y == 3)srcrect.x =274;
        else if(saPlace.y == 4)srcrect.x =362;
        break;
    }
    return srcrect;

}


void SDL::DessinerForme(SDL_Texture* texture, SDL_Rect srcrect){
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


void SDL::DessinerVoleurs(const plateau& Unplateau,SDL_Texture* texture, SDL_Rect destrect){
    for(int i=0; i<7; i++){
                                                                        //x est de la gauche vers la droite
                for(int j=0; j<5; j++){                               //y est de haut vers le bas
                    if(i==0 &&j==0){ destrect.x=10;destrect.y=4;}
                    if(i==0 &&j==1){ destrect.x=98;destrect.y=4;}
                    if(i==0 &&j==2){ destrect.x=186;destrect.y=4;}  //on va separer une chaque case avec un petit calcul
                    if(i==0 &&j==3){ destrect.x=274;destrect.y=4;}
                    if(i==0 &&j==4){ destrect.x=362;destrect.y=4;}
                    if(i==1 &&j==0){ destrect.x=10;destrect.y=92;}
                    if(i==1 &&j==1){ destrect.x=98;destrect.y=92;}
                    if(i==1 &&j==2){ destrect.x=186;destrect.y=92;}
                    if(i==1 &&j==3){ destrect.x=274;destrect.y=92;}
                    if(i==1 &&j==4){ destrect.x=362;destrect.y=92;}
                    if(i==2 &&j==0){ destrect.x=10;destrect.y=180;}
                    if(i==2 &&j==1){ destrect.x=98;destrect.y=180;}
                    if(i==2 &&j==2){ destrect.x=186;destrect.y=180;}
                    if(i==2 &&j==3){ destrect.x=274;destrect.y=180;}
                    if(i==2 &&j==4){ destrect.x=362;destrect.y=180;}
                    if(i==3 &&j==0){ destrect.x=10;destrect.y=268;}
                    if(i==3 &&j==1){ destrect.x=98;destrect.y=268;}
                    if(i==3 &&j==2){ destrect.x=186;destrect.y=268;}
                    if(i==3 &&j==3){ destrect.x=274;destrect.y=268;}
                    if(i==3 &&j==4){ destrect.x=362;destrect.y=268;}
                    if(i==4 &&j==0){ destrect.x=10;destrect.y=356;}
                    if(i==4 &&j==1){ destrect.x=98;destrect.y=356;}
                    if(i==4 &&j==2){ destrect.x=186;destrect.y=356;}
                    if(i==4 &&j==3){ destrect.x=274;destrect.y=356;}
                    if(i==4 &&j==4){ destrect.x=362;destrect.y=356;}
                    if(i==5 &&j==1){ destrect.x=98;destrect.y=444;}
                    if(i==5 &&j==2){ destrect.x=186;destrect.y=444;}
                    if(i==5 &&j==3){ destrect.x=274;destrect.y=444;}
                    if(i==6 &&j==0){ destrect.x=10;destrect.y=532;}
                    if(i==6 &&j==1){ destrect.x=98;destrect.y=532;}
                    if(i==6 &&j==2){ destrect.x=186;destrect.y=532;}
                    if(i==6 &&j==3){ destrect.x=274;destrect.y=532;}
                    if(i==6 &&j==4){ destrect.x=362;destrect.y=532;}

                    if(Unplateau.monPlateau[i][j]=='P'){
                        DessinerForme(texture,destrect);
                    }
                }
            }
}

void SDL::CaseMinimax_easy(){
    plateau Unplateau;
    deplacement d;
    player J1;
    minimax ab;
    int nbrEx=0,nbrGe=0;

    etat etatCourant;
    noeud* noeudCourant = new noeud[sizeof(noeud)];
    SDL_Surface* plateau = IMG_Load("src/GRILLE1.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,plateau);

    SDL_Surface* musashi = IMG_Load("src/musashi2.png");
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer,musashi);

    SDL_Surface* policier = IMG_Load("src/police1.png");
    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer,policier);

    SDL_Surface* background = IMG_Load("src\\images\\background.png");
    SDL_Texture* T_background=SDL_CreateTextureFromSurface(renderer,background);

    SDL_Surface* win = IMG_Load("src\\images\\win.png");
    SDL_Texture* T_win = SDL_CreateTextureFromSurface(renderer,win);

    SDL_Surface* lose = IMG_Load("src\\images\\lose.png");
    SDL_Texture* T_lose = SDL_CreateTextureFromSurface(renderer,lose);

    SDL_Surface* tryAgain = IMG_Load("src\\images\\tryAgain.png");
    SDL_Texture* T_tryAgain = SDL_CreateTextureFromSurface(renderer,tryAgain);

    SDL_Surface* exit = IMG_Load("src\\images\\exit2.png");
    SDL_Texture* T_exit = SDL_CreateTextureFromSurface(renderer,exit);

	SDL_Rect mus=getMusashi(Unplateau); //rectangle pour le musashi
    SDL_Rect plat; //rectangle pour le plateau
    plat.h = 600;
    plat.w =800;
    plat.x = 35;
    plat.y = 30;
    SDL_Rect destrect; //rectangle pour le policier

    SDL_FreeSurface(background);
    SDL_Rect R_background;
    R_background.w=20;R_background.h=13;R_background.x=0;R_background.y=0;

    SDL_Rect R_win;
    R_win.w=20;R_win.h=13;R_win.x=0;R_win.y=0;

    SDL_Rect R_lose;
    R_lose.w=20;R_lose.h=13;R_lose.x=0;R_lose.y=0;

    SDL_Rect R_tryAgain;
    R_tryAgain.w=20;R_tryAgain.h=13;R_tryAgain.x=0;R_tryAgain.y=0;

    SDL_Rect R_exit;
    R_exit.w=20;R_exit.h=13;R_exit.x=0;R_exit.y=0;

    SDL_bool program_launghed = SDL_TRUE;
    J1.tour = voleur;
    while(!(Unplateau.etatfinale()) && !(Unplateau.gameOver())){
        if(J1.tour == voleur){
        program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_background,R_background);
            DessinerForme(texture,plat);
            destrect.w=20;destrect.h=20;destrect.w=20;destrect.h=20;
            destrect.x = 4;destrect.y = 356;
            DessinerVoleurs(Unplateau,texture3,destrect);
            DessinerForme(texture2,mus);
            position place = Unplateau.positionDuVoleur();
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:              //cas d'utilisation de la souris
                    //cout <<mus.x<<"*****************"<<mus.y<<endl;
                    //cout<<event.button.x<<"_____________"<<event.button.y<<endl;
                    if(event.button.x>= mus.x -30 &&event.button.x<=mus.x +50 && event.button.y>=mus.y-80&&event.button.y<=mus.y-40){
                        J1.deplacementsouhaite.direction=0;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;

                        }
                        break;
                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y-50 &&event.button.y<=mus.y-30){
                        J1.deplacementsouhaite.direction=4;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y+30 &&event.button.y<=mus.y+50){
                        J1.deplacementsouhaite.direction=2;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y+1;;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=6;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x+1][place.y +1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                    else if(event.button.x>= mus.x +25 &&event.button.x<=mus.x +60 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=1;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=7;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y+30 &&event.button.y<=mus.y+50){
                        J1.deplacementsouhaite.direction=3;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y-50 &&event.button.y<=mus.y-30){
                        J1.deplacementsouhaite.direction=5;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x-1][place.y -1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                case SDL_KEYDOWN:         //cas d'utilisation du clavier
                    switch(event.key.keysym.sym){
                    case SDLK_1:
                        J1.deplacementsouhaite.direction=0;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                            Unplateau.afficheToi();
                        }
                        else{
                            Unplateau.afficheToi();
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                            //Unplateau.afficheToi();

                            }
                        break;

                    case SDLK_2:
                        J1.deplacementsouhaite.direction=4;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_3:
                        J1.deplacementsouhaite.direction=2;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y+1;;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_4:
                        J1.deplacementsouhaite.direction=6;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y +1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_5:
                        J1.deplacementsouhaite.direction=1;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_6:
                        J1.deplacementsouhaite.direction=7;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_7:
                        J1.deplacementsouhaite.direction=3;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_8:
                        J1.deplacementsouhaite.direction=5;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x-1][place.y -1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                case SDL_QUIT:
                    program_launghed = SDL_FALSE;
                    break;
                default:
                    break;
                }
        SDL_RenderPresent(renderer); //Affichage
        SDL_RenderClear(renderer);
        }
    }
    }
    else if(J1.tour == police){
        etatCourant.unPlateau = Unplateau; etatCourant.tour=J1.tour;
        noeudCourant->monEtat=etatCourant;
        noeudCourant->precedent=nullptr;
        minimax ab(etatCourant);
        Unplateau=ab.joueurMinmax(noeudCourant,1,nbrEx,nbrGe).unPlateau;
        ab.viderListeNoeud();
        J1.update();
        DessinerForme(T_background,R_background);
        DessinerForme(texture,plat);
        DessinerForme(texture2,mus);
        DessinerVoleurs(Unplateau,texture3,destrect);
        SDL_RenderPresent(renderer);
        J1.tour = voleur;
        }
    }
    if(Unplateau.nombrePoliciers<=4){
        program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_win,R_win);
            switch(event.type){
            case SDL_MOUSEMOTION:
                SDL_Delay(2000);
                program_launghed=SDL_FALSE;
            case SDL_QUIT:
                program_launghed=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);
            }
    }
    }
    else{
        SDL_bool program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            int x,y;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_lose,R_lose);
            switch(event.type){
            case SDL_MOUSEMOTION:
                x=event.motion.x;y=event.motion.y;
                if((x>=250 && x <=490 && y>=500 && y<=550))DessinerForme(T_tryAgain,R_tryAgain);
                else if (x>=580 && x <=740 && y>=580 && y<=630)DessinerForme(T_exit,R_exit);
                else DessinerForme(T_lose,R_lose);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(((x>=250 && x <=490 && y>=500 && y<=550))){
                        JeuGraphique();
                        }
                else if (x>=580 && x <=740 && y>=580 && y<=630){
                    SDL_Quit();
                }
            case SDL_QUIT:
                program_launghed=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);
            }
    }
}
}

void SDL::CaseMinimax_meduim(){
    plateau Unplateau;
    deplacement d;
    player J1;
    minimax ab;
    int nbrEx=0,nbrGe=0;

        etat etatCourant;
    noeud* noeudCourant = new noeud[sizeof(noeud)];
    SDL_Surface* plateau = IMG_Load("src/GRILLE1.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,plateau);

    SDL_Surface* musashi = IMG_Load("src/musashi2.png");
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer,musashi);

    SDL_Surface* policier = IMG_Load("src/police1.png");
    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer,policier);

    SDL_Surface* background = IMG_Load("src\\images\\background.png");
    SDL_Texture* T_background=SDL_CreateTextureFromSurface(renderer,background);

    SDL_Surface* win = IMG_Load("src\\images\\win.png");
    SDL_Texture* T_win = SDL_CreateTextureFromSurface(renderer,win);

    SDL_Surface* lose = IMG_Load("src\\images\\lose.png");
    SDL_Texture* T_lose = SDL_CreateTextureFromSurface(renderer,lose);

    SDL_Surface* tryAgain = IMG_Load("src\\images\\tryAgain.png");
    SDL_Texture* T_tryAgain = SDL_CreateTextureFromSurface(renderer,tryAgain);

    SDL_Surface* exit = IMG_Load("src\\images\\exit2.png");
    SDL_Texture* T_exit = SDL_CreateTextureFromSurface(renderer,exit);

	SDL_Rect mus=getMusashi(Unplateau); //rectangle pour le musashi
    SDL_Rect plat; //rectangle pour le plateau
    plat.h = 600;
    plat.w =800;
    plat.x = 35;
    plat.y = 30;
    SDL_Rect destrect; //rectangle pour le policier

    SDL_FreeSurface(background);
    SDL_Rect R_background;
    R_background.w=20;R_background.h=13;R_background.x=0;R_background.y=0;

    SDL_Rect R_win;
    R_win.w=20;R_win.h=13;R_win.x=0;R_win.y=0;

    SDL_Rect R_lose;
    R_lose.w=20;R_lose.h=13;R_lose.x=0;R_lose.y=0;

    SDL_Rect R_tryAgain;
    R_tryAgain.w=20;R_tryAgain.h=13;R_tryAgain.x=0;R_tryAgain.y=0;

    SDL_Rect R_exit;
    R_exit.w=20;R_exit.h=13;R_exit.x=0;R_exit.y=0;

    SDL_bool program_launghed = SDL_TRUE;
    J1.tour = voleur;
    while(!(Unplateau.etatfinale()) && !(Unplateau.gameOver())){
        if(J1.tour == voleur){
        program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_background,R_background);
            DessinerForme(texture,plat);
            destrect.w=20;destrect.h=20;destrect.w=20;destrect.h=20;
            destrect.x = 4;destrect.y = 356;
            DessinerVoleurs(Unplateau,texture3,destrect);
            DessinerForme(texture2,mus);
            position place = Unplateau.positionDuVoleur();
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:              //cas d'utilisation de la souris
                    //cout <<mus.x<<"*****************"<<mus.y<<endl;
                    //cout<<event.button.x<<"_____________"<<event.button.y<<endl;
                    if(event.button.x>= mus.x -30 &&event.button.x<=mus.x +50 && event.button.y>=mus.y-80&&event.button.y<=mus.y-40){
                        J1.deplacementsouhaite.direction=0;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;

                        }
                        break;
                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y-50 &&event.button.y<=mus.y-30){
                        J1.deplacementsouhaite.direction=4;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y+30 &&event.button.y<=mus.y+50){
                        J1.deplacementsouhaite.direction=2;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y+1;;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=6;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y +1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                    else if(event.button.x>= mus.x +25 &&event.button.x<=mus.x +60 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=1;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=7;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y+30 &&event.button.y<=mus.y+50){
                        J1.deplacementsouhaite.direction=3;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y-50 &&event.button.y<=mus.y-30){
                        J1.deplacementsouhaite.direction=5;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x-1][place.y -1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                case SDL_KEYDOWN:         //cas d'utilisation du clavier
                    switch(event.key.keysym.sym){
                    case SDLK_1:
                        J1.deplacementsouhaite.direction=0;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                            Unplateau.afficheToi();
                        }
                        else{
                            Unplateau.afficheToi();
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                            //Unplateau.afficheToi();

                            }
                        break;

                    case SDLK_2:
                        J1.deplacementsouhaite.direction=4;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_3:
                        J1.deplacementsouhaite.direction=2;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y+1;;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_4:
                        J1.deplacementsouhaite.direction=6;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y +1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_5:
                        J1.deplacementsouhaite.direction=1;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_6:
                        J1.deplacementsouhaite.direction=7;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_7:
                        J1.deplacementsouhaite.direction=3;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_8:
                        J1.deplacementsouhaite.direction=5;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x-1][place.y -1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                case SDL_QUIT:
                    program_launghed = SDL_FALSE;
                    break;
                default:
                    break;
                }
        SDL_RenderPresent(renderer); //Affichage
        SDL_RenderClear(renderer);

        }
    }

    }
    else if(J1.tour == police){
        etatCourant.unPlateau = Unplateau; etatCourant.tour=J1.tour;
        noeudCourant->monEtat=etatCourant;
        noeudCourant->precedent=nullptr;
        minimax ab(etatCourant);
        Unplateau=ab.joueurMinmax(noeudCourant,3,nbrEx,nbrGe).unPlateau;
        ab.viderListeNoeud();
        J1.update();
        DessinerForme(texture,plat);
        DessinerForme(texture2,mus);
        DessinerVoleurs(Unplateau,texture3,destrect);
        SDL_RenderPresent(renderer);
        J1.tour = voleur;

        }

    }

        if(Unplateau.nombrePoliciers<=4){
        program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_win,R_win);
            switch(event.type){
            case SDL_MOUSEMOTION:
                SDL_Delay(2000);
                program_launghed=SDL_FALSE;
            case SDL_QUIT:
                program_launghed=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);
            }
    }
    }
    else{
        SDL_bool program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            int x,y;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_lose,R_lose);
            switch(event.type){
            case SDL_MOUSEMOTION:
                x=event.motion.x;y=event.motion.y;
                if((x>=250 && x <=490 && y>=500 && y<=550))DessinerForme(T_tryAgain,R_tryAgain);
                else if (x>=580 && x <=740 && y>=580 && y<=630)DessinerForme(T_exit,R_exit);
                else DessinerForme(T_lose,R_lose);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(((x>=250 && x <=490 && y>=500 && y<=550))){
                        JeuGraphique();
                        }
                else if (x>=580 && x <=740 && y>=580 && y<=630){
                    SDL_Quit();
                }
            case SDL_QUIT:
                program_launghed=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);
            }
    }
}

}

void SDL::CaseAlphaBeta_hard(){
    plateau Unplateau;
    deplacement d;
    player J1;
    minimax ab;
    int nbrEx=0,nbrGe=0;

        etat etatCourant;
    noeud* noeudCourant = new noeud[sizeof(noeud)];
    SDL_Surface* plateau = IMG_Load("src/GRILLE1.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,plateau);

    SDL_Surface* musashi = IMG_Load("src/musashi2.png");
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer,musashi);

    SDL_Surface* policier = IMG_Load("src/police1.png");
    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer,policier);

    SDL_Surface* background = IMG_Load("src\\images\\background.png");
    SDL_Texture* T_background=SDL_CreateTextureFromSurface(renderer,background);

    SDL_Surface* win = IMG_Load("src\\images\\win.png");
    SDL_Texture* T_win = SDL_CreateTextureFromSurface(renderer,win);

    SDL_Surface* lose = IMG_Load("src\\images\\lose.png");
    SDL_Texture* T_lose = SDL_CreateTextureFromSurface(renderer,lose);

    SDL_Surface* tryAgain = IMG_Load("src\\images\\tryAgain.png");
    SDL_Texture* T_tryAgain = SDL_CreateTextureFromSurface(renderer,tryAgain);

    SDL_Surface* exit = IMG_Load("src\\images\\exit2.png");
    SDL_Texture* T_exit = SDL_CreateTextureFromSurface(renderer,exit);

	SDL_Rect mus=getMusashi(Unplateau); //rectangle pour le musashi
    SDL_Rect plat; //rectangle pour le plateau
    plat.h = 600;
    plat.w =800;
    plat.x = 35;
    plat.y = 30;
    SDL_Rect destrect; //rectangle pour le policier

    SDL_FreeSurface(background);
    SDL_Rect R_background;
    R_background.w=20;R_background.h=13;R_background.x=0;R_background.y=0;

    SDL_Rect R_win;
    R_win.w=20;R_win.h=13;R_win.x=0;R_win.y=0;

    SDL_Rect R_lose;
    R_lose.w=20;R_lose.h=13;R_lose.x=0;R_lose.y=0;

    SDL_Rect R_tryAgain;
    R_tryAgain.w=20;R_tryAgain.h=13;R_tryAgain.x=0;R_tryAgain.y=0;

    SDL_Rect R_exit;
    R_exit.w=20;R_exit.h=13;R_exit.x=0;R_exit.y=0;

    SDL_bool program_launghed = SDL_TRUE;
    J1.tour = voleur;
    while(!(Unplateau.etatfinale()) && !(Unplateau.gameOver())){
        if(J1.tour == voleur){
        program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_background,R_background);
            DessinerForme(texture,plat);
            destrect.w=20;destrect.h=20;destrect.w=20;destrect.h=20;
            destrect.x = 4;destrect.y = 356;
            DessinerVoleurs(Unplateau,texture3,destrect);
            DessinerForme(texture2,mus);
            position place = Unplateau.positionDuVoleur();
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:              //cas d'utilisation de la souris
                    //cout <<mus.x<<"*****************"<<mus.y<<endl;
                    //cout<<event.button.x<<"_____________"<<event.button.y<<endl;
                    if(event.button.x>= mus.x -30 &&event.button.x<=mus.x +50 && event.button.y>=mus.y-80&&event.button.y<=mus.y-40){
                        J1.deplacementsouhaite.direction=0;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;

                        }
                        break;
                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y-50 &&event.button.y<=mus.y-30){
                        J1.deplacementsouhaite.direction=4;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y+30 &&event.button.y<=mus.y+50){
                        J1.deplacementsouhaite.direction=2;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y+1;;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                    else if(event.button.x>= mus.x +110 &&event.button.x<=mus.x +140 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=6;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y +1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                    else if(event.button.x>= mus.x +25 &&event.button.x<=mus.x +60 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=1;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y+120 &&event.button.y<=mus.y+140){
                        J1.deplacementsouhaite.direction=7;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y+30 &&event.button.y<=mus.y+50){
                        J1.deplacementsouhaite.direction=3;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                    else if(event.button.x>= mus.x -60 &&event.button.x<=mus.x -36 && event.button.y>=mus.y-50 &&event.button.y<=mus.y-30){
                        J1.deplacementsouhaite.direction=5;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x-1][place.y -1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }

                case SDL_KEYDOWN:         //cas d'utilisation du clavier
                    switch(event.key.keysym.sym){
                    case SDLK_1:
                        J1.deplacementsouhaite.direction=0;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                            Unplateau.afficheToi();
                        }
                        else{
                            Unplateau.afficheToi();
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                            //Unplateau.afficheToi();

                            }
                        break;

                    case SDLK_2:
                        J1.deplacementsouhaite.direction=4;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;
                        J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x-1][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_3:
                        J1.deplacementsouhaite.direction=2;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y+1;;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                            Unplateau.monPlateau[place.x][place.y+1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_4:
                        J1.deplacementsouhaite.direction=6;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y+1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y +1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_5:
                        J1.deplacementsouhaite.direction=1;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_6:
                        J1.deplacementsouhaite.direction=7;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x+1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y+=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x+1][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_7:
                        J1.deplacementsouhaite.direction=3;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x][place.y-1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;

                    case SDLK_8:
                        J1.deplacementsouhaite.direction=5;
                        J1.deplacementsouhaite.posi.x = place.x;
                        J1.deplacementsouhaite.posi.y = place.y;
                        J1.deplacementsouhaite.posf.x = place.x-1;J1.deplacementsouhaite.posf.y=place.y-1;
                        if(J1.deplacementsouhaite.verifierMvt()&& J1.deplacementsouhaite.estVide(Unplateau)){
                            mus.y-=88;
                            mus.x-=88;
                            Unplateau.monPlateau[place.x][place.y] = vide;
                        Unplateau.monPlateau[place.x-1][place.y -1] = voleur;
                            Unplateau.mongePion(J1);
                            J1.tour = police;
                            program_launghed = SDL_FALSE;
                        }
                        else{
                            J1.tour = voleur;
                            program_launghed = SDL_TRUE;
                        }
                        break;
                    }
                case SDL_QUIT:
                    program_launghed = SDL_FALSE;
                    break;
                default:
                    break;
                }
        SDL_RenderPresent(renderer); //Affichage
        SDL_RenderClear(renderer);

        }
    }
    }
    else if(J1.tour == police){
        etatCourant.unPlateau = Unplateau; etatCourant.tour=J1.tour;
        noeudCourant->monEtat=etatCourant;
        noeudCourant->precedent=nullptr;
        minimax ab(etatCourant);
        Unplateau=ab.joueurMinmax(noeudCourant,1,nbrEx,nbrGe).unPlateau;
        ab.viderListeNoeud();
        J1.update();
        DessinerForme(texture,plat);
        DessinerForme(texture2,mus);
        DessinerVoleurs(Unplateau,texture3,destrect);
        SDL_RenderPresent(renderer);
        J1.tour = voleur;
        }
    }
    if(Unplateau.nombrePoliciers<=4){
        program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_win,R_win);
            switch(event.type){
            case SDL_MOUSEMOTION:
                SDL_Delay(2000);
                program_launghed=SDL_FALSE;
            case SDL_QUIT:
                program_launghed=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);
            }
    }
    }
    else{
        SDL_bool program_launghed = SDL_TRUE;
        while(program_launghed){
            SDL_Event event;
            int x,y;
            while(SDL_PollEvent(&event)){
            DessinerForme(T_lose,R_lose);
            switch(event.type){
            case SDL_MOUSEMOTION:
                x=event.motion.x;y=event.motion.y;
                if((x>=250 && x <=490 && y>=500 && y<=550))DessinerForme(T_tryAgain,R_tryAgain);
                else if (x>=580 && x <=740 && y>=580 && y<=630)DessinerForme(T_exit,R_exit);
                else DessinerForme(T_lose,R_lose);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(((x>=250 && x <=490 && y>=500 && y<=550))){
                        JeuGraphique();
                        }
                else if (x>=580 && x <=740 && y>=580 && y<=630){
                    SDL_Quit();
                }
            case SDL_QUIT:
                program_launghed=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);
            }
    }
}
}

void SDL::JeuGraphique(){

    SDL_Surface *openning=NULL;
    SDL_Texture *T_openning=NULL;

    SDL_Surface *menu=NULL,*play=NULL,*exit=NULL,*rules=NULL;
    SDL_Texture *T_menu=NULL,*T_play=NULL,*T_exit=NULL,*T_rules=NULL;

    SDL_Surface *RULES1=NULL;
    SDL_Texture *T_RULES1=NULL;
    SDL_Surface *RULES2=NULL;
    SDL_Texture *T_RULES2=NULL;

    SDL_Surface *level=NULL,*easy=NULL,*medium=NULL,*hard=NULL;
    SDL_Texture *T_level=NULL,*T_easy=NULL,*T_medium=NULL,*T_hard=NULL;

    openning=IMG_Load("src\\images\\openning.png");

    menu=IMG_Load("src\\images\\MenuPrincipale.png");
    play = IMG_Load("src\\images\\Play.png");
    exit = IMG_Load("src\\images\\Exit.png");
    rules = IMG_Load("src\\images\\Rules.png");

    RULES1 = IMG_Load("src\\images\\rulesDetails1.png");
    RULES2 = IMG_Load("src\\images\\rulesDetails2.png");

    level=IMG_Load("src\\images\\level.png");
    easy = IMG_Load("src\\images\\easy.png");
    medium = IMG_Load("src\\images\\medium.png");
    hard = IMG_Load("src\\images\\hard.png");

    T_openning=SDL_CreateTextureFromSurface(renderer,openning);

    T_menu=SDL_CreateTextureFromSurface(renderer,menu);
    T_play=SDL_CreateTextureFromSurface(renderer,play);
    T_exit=SDL_CreateTextureFromSurface(renderer,exit);
    T_rules=SDL_CreateTextureFromSurface(renderer,rules);

    T_RULES1=SDL_CreateTextureFromSurface(renderer,RULES1);
    T_RULES2=SDL_CreateTextureFromSurface(renderer,RULES2);

    T_level=SDL_CreateTextureFromSurface(renderer,level);
    T_easy=SDL_CreateTextureFromSurface(renderer,easy);
    T_medium=SDL_CreateTextureFromSurface(renderer,medium);
    T_hard=SDL_CreateTextureFromSurface(renderer,hard);

    SDL_FreeSurface(openning);
    SDL_FreeSurface(menu);SDL_FreeSurface(play);SDL_FreeSurface(exit);SDL_FreeSurface(rules);
    SDL_FreeSurface(level);SDL_FreeSurface(easy);SDL_FreeSurface(medium);SDL_FreeSurface(hard);
    SDL_FreeSurface(RULES1);SDL_FreeSurface(RULES2);

    SDL_Rect R_openning;
    SDL_Rect R_menu,R_play,R_exit,R_rules;
    SDL_Rect R_RULES1;SDL_Rect R_RULES2;
    SDL_Rect R_level,R_easy,R_medium,R_hard;


    R_openning.w=20;R_openning.h=13;R_openning.x=0;R_openning.y=0;

    R_menu.w=20;R_menu.h=13;R_menu.x=0;R_menu.y=0;
    R_play.w=20;R_play.h= 13;R_play.x=0;R_play.y=0;
    R_exit.w=20;R_exit.h=13;R_exit.x=0;R_exit.y=0;
    R_rules.w=20;R_rules.h= 13;R_rules.x=0;R_rules.y=0;

    R_RULES1.w=20;R_RULES1.h=13;R_RULES1.x=0;R_RULES1.y=0;
    R_RULES2.w=20;R_RULES2.h=13;R_RULES2.x=0;R_RULES2.y=0;

    R_level.w=20;R_level.h=13;R_level.x=0;R_level.y=0;
    R_easy.w=20;R_easy.h= 13;R_easy.x=0;R_easy.y=0;
    R_medium.w=20;R_medium.h=13;R_medium.x=0;R_medium.y=0;
    R_hard.w=20;R_hard.h= 13;R_hard.x=0;R_hard.y=0;




    DessinerForme(T_menu,R_menu);
    //DessinerForme(T_level,R_level);

    SDL_bool program_lanched = SDL_TRUE;

    while(program_lanched){
        DessinerForme(T_openning,R_openning);
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type)
            case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_SPACE){
                    program_lanched = SDL_FALSE;
                }
        }
        SDL_Delay(1000);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    program_lanched = SDL_TRUE;
    while (program_lanched){
        SDL_Event event;
        int x,y;

        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_MOUSEMOTION:
                x=event.motion.x;y=event.motion.y;
                if((x>=265 && x <=580 && y>=175 && y<=230))DessinerForme(T_play,R_play);
                else if (x>=280 && x <=570 && y>=310 && y<=385)DessinerForme(T_rules,R_rules);
                else if (x>=255 && x <=545 && y>=470 && y<=545)DessinerForme(T_exit,R_exit);
                else DessinerForme(T_menu,R_menu);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if((x>=265 && x <=580 && y>=175 && y<=230))goto evenement2;
                else if (x>=280 && x <=570 && y>=310 && y<=385)goto evenement3;
                else if (x>=255 && x <=545 && y>=470 && y<=545) {}
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
    DessinerForme(T_level,R_level);
    program_lanched = SDL_TRUE;
    while (program_lanched){
        SDL_Event event;
        int x,y;

        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_MOUSEMOTION:
                x=event.motion.x;y=event.motion.y;
                if((x>=265 && x <=580 && y>=175 && y<=230))DessinerForme(T_easy,R_easy);
                else if (x>=280 && x <=570 && y>=310 && y<=385)DessinerForme(T_medium,R_medium);
                else if (x>=255 && x <=545 && y>=470 && y<=545)DessinerForme(T_hard,R_hard);
                else DessinerForme(T_level,R_level);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(((x>=265 && x <=580 && y>=175 && y<=230))){
                        CaseMinimax_easy();}
                else if (x>=280 && x <=570 && y>=310 && y<=385){
                        CaseMinimax_meduim();
                }
                else if (x>=255 && x <=545 && y>=470 && y<=545){
                        CaseAlphaBeta_hard();
                }
            case SDL_QUIT:
                program_lanched=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);


        }
    }

    evenement3:
    DessinerForme(T_RULES1,R_RULES1);
    program_lanched = SDL_TRUE;
    while (program_lanched){
        SDL_Event event;
        int x,y;
        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_MOUSEMOTION:
                x=event.motion.x;y=event.motion.y;
                cout<<x<<"         "<<y<<endl;
                if((x>=500 && x <=800 && y>=580 && y<=650))DessinerForme(T_RULES2,R_RULES2);
                else DessinerForme(T_RULES1,R_RULES1);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(((x>=500 && x <=800 && y>=580 && y<=650)))goto evenement2;
            case SDL_QUIT:
                program_lanched=SDL_FALSE;
                break;
            default:
                break;
            }
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);
        }
    }



    SDL_DestroyTexture(T_menu);SDL_DestroyTexture(T_play);SDL_DestroyTexture(T_rules);SDL_DestroyTexture(T_exit);
}

