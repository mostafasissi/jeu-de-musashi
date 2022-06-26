#include <string>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <iomanip>
#define voleur 'V'
#define tourMax 'V'
#define police 'P'
#define tourMin 'P'
#define vide ' '
#define HAUTEUR 7
#define LARGEUR 5
#include "SDL_image.h"
#include "SDL_mixer.h"
#define Window_width 900
#define Window_height 700
using namespace std;

struct position {
    int x,y;
};
enum direction {HAUT, BAS, DROITE, GAUCHE, HAUT_DROITE, HAUT_GAUCHE, BAS_DROITE, BAS_GAUCHE};


class plateau;
class player;
class deplacement;


class deplacement {
public:
    position posi,posf;
    int  direction;
    char tour;//!!!!!!!!!!!!!


    deplacement(){};

    deplacement(int ,int ,int );
    position positionSuivant();
    bool verifierMvt();
    void messageserror(int );
    bool estVide(const plateau& );// verifié si la position finale est vide
    //===============
    void affichedep();
    // ==============
    friend class player;
    friend class plateau;
    friend class minimax;
    friend class alphaBeta;
    friend class SDL;
};

class plateau {
public:
    char monPlateau[7][5];
    int nombrePoliciers;

    plateau();
    plateau(plateau&);
    void afficheToi();
    void updatePlateau(const player&);
    void mongePion(const player&);
    bool capturePossible();// c'est pour détecter si le voleur a encours une possibilité de joué
    bool gameOver();
    bool etatfinale();
    bool operator== (const plateau);
    position positionDuVoleur()const;

    friend class deplacement;
    friend class player;
    friend class minimax;
    friend class alphaBeta;
     friend class SDL;

};

class player {
public:
    char tour;
    deplacement deplacementsouhaite;


    player();
    void getdeplacement(const plateau& );// lire le déplacement souhaité + valider ou non ?
    void update(); // changer le joueur courant
    void afficheTour(); // afficher quelle le joueur courant
    char getTour(){
        return tour;
    }

    friend class plateau;
    friend class deplacement;
      friend class minimax;
      friend class alphaBeta;
       friend class SDL;

};

typedef struct etat {
    plateau unPlateau;
    int h;
    char tour;
    int profondeur;
} etat;
typedef struct Noeud {
    etat monEtat;
    Noeud* precedent ;
}noeud;
typedef struct {
    noeud* sommet;
}liste;
class minimax {
 public:
    liste listeNoeuds;
    int nombreDuNoeud;

    minimax(etat);
    minimax();
    ~minimax();
    int heuristique(plateau&);
    int Minimax(noeud*  , int , int& ,int& );
    void generersuccesseur(etat,int&);
    void afficheToi();
    void extraire();
    etat& joueurMinmax(noeud*, int,int&,int&);
    void viderListeNoeud();
     friend class SDL;

};

class alphaBeta:public minimax {
public:
    alphaBeta(etat);
    alphaBeta();
    int AlphaBeta(noeud*,int,int& ,int&,int=-1000,int=1000);
    etat& joueurAlphaBeta(noeud*, int,int&,int&);
    ~alphaBeta(){
        delete[] listeNoeuds.sommet;
    }
     friend class SDL;

};

class UnInterface{
    int choixMenu,choixLevel;
public:
    void setChoixMenu(){
        cout << endl << endl << " \tPlease enter your choice : ";
        cin >> choixMenu ;
    }
    void affiche(string);
    void afficheInterface();
    void setChoixLevel(){
        cout << endl << endl<< " \tPlease enter your choix  : ";
        cin >> choixLevel;
    }
    int  getChoixLevel(){
        return choixLevel;
    }
};

void afficheColor(char c);
void Color(int couleurDuTexte,int couleurDeFond);






class SDL{
public :
    SDL();
    ~SDL();
    void SDL_ExitWithError(const char*);
    void DessinerForme(SDL_Texture*, SDL_Rect srcrect);
    void DessinerVoleurs(const plateau& Unplateau,SDL_Texture*, SDL_Rect srcrect);
    void CaseMinimax_easy();
    void CaseMinimax_meduim();
    void CaseAlphaBeta_hard();
    void JeuGraphique();
    void input(const plateau& Unplateau,SDL_Rect);
    SDL_Rect getMusashi(const plateau& Unplateau);
    SDL_Surface *icon,*ecran;
    friend class plateau;
    Mix_Music *music = NULL;
    Mix_Chunk *effect1=NULL,*effect2=NULL,*effect3=NULL,*effect4=NULL,*effect5=NULL;

private:
    int musicON=1,effectON=1;
    SDL_Window* window;
    SDL_Renderer* renderer;
};







