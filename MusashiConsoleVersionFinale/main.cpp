#include "include/musacshi.h"
using namespace std;

int main()
{
    // declaration des données
    deplacement d;
    plateau P;
    player J1;
    int nbrEx=0,nbrGe=0;
    etat etatCourant;
    noeud* noeudCourant = new noeud[sizeof(noeud)];
    int profondeur;

    // affiche de l'interface d'overture et du menue

    UnInterface F;
    F.afficheInterface();
    switch (F.getChoixLevel()){// choix du mode de jeu
    case 1:
        profondeur=2;
        goto GAME_MINIMAX;
        break;
    case 2:
        profondeur=4;
        goto GAME_MINIMAX;
        break;
    case 3:
        profondeur=5;
        goto GAME_ALPHABETA;
        break;
    }

GAME_MINIMAX:
    system("cls");
    do {
            if(J1.getTour()==voleur){
                P.afficheToi();
                J1.afficheTour();
                J1.getdeplacement(P);
                P.updatePlateau(J1);
                P.mongePion(J1);
                P.afficheToi();
            }
            else{
                etatCourant.unPlateau = P; etatCourant.tour=J1.getTour();
                noeudCourant->monEtat=etatCourant;
                noeudCourant->precedent=nullptr;
                minimax M(etatCourant);
                P=M.joueurMinmax(noeudCourant,profondeur,nbrEx,nbrGe).unPlateau;
                P.afficheToi();
                J1.afficheTour();
                M.viderListeNoeud();
            }
            J1.update();
    }while (!(P.etatfinale()) && !(P.gameOver()));

GAME_ALPHABETA:
        system("cls");
    do {
            if(J1.getTour()==voleur){
                P.afficheToi();
                J1.afficheTour();
                J1.getdeplacement(P);
                P.updatePlateau(J1);
                P.mongePion(J1);
                P.afficheToi();
            }
            else{
                etatCourant.unPlateau = P; etatCourant.tour=J1.getTour();
                noeudCourant->monEtat=etatCourant;
                noeudCourant->precedent=nullptr;
                alphaBeta ab(etatCourant);
                P=ab.joueurAlphaBeta(noeudCourant,profondeur,nbrEx,nbrGe).unPlateau;
                P.afficheToi();
                J1.afficheTour();
                ab.viderListeNoeud();
            }
            J1.update();
    }while (!(P.etatfinale()) && !(P.gameOver()));


/*
    cout << "aplhabeta -->"<< M.AlphaBeta(N,5,nbrdeNexA,nbrDeNgeA) << endl;
    cout << "nombre de noeuds  generer  :" <<nbrDeNgeA<<endl;
    cout << "nombre de noeuds  explorer  :" <<nbrdeNexA<<endl;


    cout << "minimax -->"<< T.Minimax(N,4,nbrDeNexpM,nbrDeNgeM) << endl;
    cout << "nombre de noeuds  generer  :" <<nbrDeNgeM<<endl;
    cout << "nombre de noeuds  explorer  :" <<nbrDeNexpM<<endl;

*/

    return 0;
}


