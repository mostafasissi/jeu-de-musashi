#include "../include/musacshi.h"
using namespace std;


alphaBeta::alphaBeta(etat ET){
    try {
         listeNoeuds.sommet=nullptr;
        noeud* N = new noeud[sizeof(noeud)];
        N->monEtat = ET;
        N->precedent = listeNoeuds.sommet;
        listeNoeuds.sommet=N;
    } catch(std::bad_alloc ba){
        cout << "Erreur d'allocation memoire en constructeur " << endl;
    }
}

int alphaBeta::AlphaBeta(noeud* unNoeud , int p ,int& nombreDuNoeudExp,int& nombreDuNoeudGen, int alpha,int beta){

    if (p==0 || unNoeud->monEtat.unPlateau.etatfinale()){
        this->extraire();
        nombreDuNoeudExp++;

        return unNoeud->monEtat.h;

    }
    else{
         this->generersuccesseur(unNoeud->monEtat,nombreDuNoeudGen);
         if(unNoeud->monEtat.tour==tourMax){
                int fils=0,v =-1000;
                for (noeud* N = listeNoeuds.sommet;(!(N->monEtat.unPlateau == unNoeud->monEtat.unPlateau));N=N->precedent){

                        fils=this->AlphaBeta(N,p-1,nombreDuNoeudExp,nombreDuNoeudGen,alpha,beta);
                        v = v < fils ? fils : v ;
                        if(v >= beta)return v;
                        alpha = v > alpha ? v : alpha;
                }
                unNoeud->monEtat.h = v;
                return v;
            }
            else if (unNoeud->monEtat.tour == tourMin){
                int fils=0,v=1000;
                for (noeud* N = listeNoeuds.sommet;(!(N->monEtat.unPlateau == unNoeud->monEtat.unPlateau));N=N->precedent){
                    fils=this->AlphaBeta(N,p-1,nombreDuNoeudExp,nombreDuNoeudGen,alpha,beta);
                    v = v > fils ? fils : v ;
                    if(v <= alpha)return v;
                    beta = v < beta ? v : beta;
                }
                unNoeud->monEtat.h = v;
                return v;
            }
    }
}
etat& alphaBeta::joueurAlphaBeta(noeud* unNoeud , int p,int& nbrDuNoeudEx,int& nbrDuNoeudGe){

        this->generersuccesseur(unNoeud->monEtat,nbrDuNoeudGe);
        noeud* noeudSuivant = new noeud[sizeof(noeud)];
        noeudSuivant->monEtat.h = 10000;
        for (noeud* N = listeNoeuds.sommet;(!(N->monEtat.unPlateau == unNoeud->monEtat.unPlateau));N=N->precedent){
            nbrDuNoeudEx++;
            alphaBeta objalphabeta(N->monEtat);
            N->monEtat.h=objalphabeta.AlphaBeta(N,p-2,nbrDuNoeudEx,nbrDuNoeudGe);
            noeudSuivant->monEtat = noeudSuivant->monEtat.h > N->monEtat.h ? N->monEtat : noeudSuivant->monEtat ;
        }
        return noeudSuivant->monEtat ;
}
