#include "../include/musacshi.h"
using namespace std;

minimax::minimax(etat ET){
    try {
        listeNoeuds.sommet=nullptr;
        noeud* N = new noeud[sizeof(noeud)];
        N->monEtat = ET;
        N->precedent = listeNoeuds.sommet;
        listeNoeuds.sommet=N;
        }catch(std::bad_alloc ba){
        cout << "Erreur d'allocation memoire en constructeur " << endl;
        }

}

int minimax::heuristique(plateau& P){
        int nbrDevide = 0;
        for(int i=0;i<7;i++){
            for(int j=0;j<5;j++){
                if(P.monPlateau[i][j]==voleur){
                        for (int dir=0;dir<8;dir++){
                            deplacement d ;
                            d.posi.x = i;
                            d.posi.y=j;
                            d.direction=dir;
                            d.posf = d.positionSuivant();
                            if(d.verifierMvt() && d.estVide(P)) nbrDevide++;}
                                                }
                            }

                                }
        return nbrDevide;
}

int minimax::Minimax(noeud* unNoeud , int p, int& nbrDuNoeudEx,int& nbrDuNoeudGe){

        if (p==0 || unNoeud->monEtat.unPlateau.etatfinale()){
                this->extraire();
                nbrDuNoeudEx++;
                return unNoeud->monEtat.h;
                }
        else {
            this->generersuccesseur(unNoeud->monEtat,nbrDuNoeudGe);

            if(unNoeud->monEtat.tour==tourMax){
                int fils=0,Max=-1000;
                for (noeud* N = listeNoeuds.sommet;(!(N->monEtat.unPlateau == unNoeud->monEtat.unPlateau));N=N->precedent){

                        fils=this->Minimax(N,p-1,nbrDuNoeudEx,nbrDuNoeudGe);
                        Max = Max < fils ? fils : Max ;
                }
                unNoeud->monEtat.h = Max;
                return Max;
            }
            else if (unNoeud->monEtat.tour == tourMin){
                int fils=0,Min=1000;
                for (noeud* N = listeNoeuds.sommet;(!(N->monEtat.unPlateau == unNoeud->monEtat.unPlateau));N=N->precedent){

                    fils=this->Minimax(N,p-1,nbrDuNoeudEx,nbrDuNoeudGe);
                    Min = Min > fils ? fils : Min ;
                }
                unNoeud->monEtat.h = Min;
                return Min;
            }
        }

}
void minimax::generersuccesseur(etat ET,int& nombredeNoeud){
        for(int i=0;i<7;i++){
            for(int j=0;j<5;j++){
                if(ET.unPlateau.monPlateau[i][j]==ET.tour){
                  for(int dir=0;dir<8;dir++){
                        player P ; P.deplacementsouhaite.posi.x=i, P.deplacementsouhaite.posi.y=j,P.deplacementsouhaite.direction=dir;P.deplacementsouhaite.posf=P.deplacementsouhaite.positionSuivant();P.tour=ET.tour;
                        if(P.deplacementsouhaite.verifierMvt() && P.deplacementsouhaite.estVide(ET.unPlateau)){
                            try{
                                noeud* N = new noeud[sizeof(noeud)];
                                N->monEtat.tour= ET.tour==police ? voleur : police ;
                                N->monEtat.unPlateau = ET.unPlateau;
                                N->monEtat.unPlateau.nombrePoliciers=ET.unPlateau.nombrePoliciers;
                                N->monEtat.profondeur=ET.profondeur-1;
                                N->monEtat.unPlateau.updatePlateau(P);
                                N->monEtat.unPlateau.mongePion(P);
                                N->monEtat.h = heuristique(N->monEtat.unPlateau);
                                N->precedent = listeNoeuds.sommet;
                                listeNoeuds.sommet= N;
                                 nombredeNoeud++;
                            }catch(std::bad_alloc ba){
                                    cout << "Erreur d'allocation memoire en genereSeccesseur " << endl;
                                }

                        }
                    }
                }
            }
        }

}
void minimax::afficheToi(){
        for(noeud* N = listeNoeuds.sommet;N!=nullptr;N=N->precedent){
            N->monEtat.unPlateau.afficheToi();
        }
}

void minimax::extraire(){
        if (listeNoeuds.sommet->precedent==NULL) listeNoeuds.sommet=NULL;
        else listeNoeuds.sommet=listeNoeuds.sommet->precedent;
}

etat& minimax::joueurMinmax(noeud* unNoeud , int p,int& nbrDuNoeudEx,int& nbrDuNoeudGe){

        this->generersuccesseur(unNoeud->monEtat,nbrDuNoeudGe);
        noeud* noeudSuivant = new noeud[sizeof(noeud)];
        noeudSuivant->monEtat.h = 10000;
        for (noeud* N = listeNoeuds.sommet;(!(N->monEtat.unPlateau == unNoeud->monEtat.unPlateau));N=N->precedent){
            minimax M(N->monEtat);
            nbrDuNoeudEx++;
            N->monEtat.h=M.Minimax(N,p-1,nbrDuNoeudEx,nbrDuNoeudGe);
            noeudSuivant->monEtat = noeudSuivant->monEtat.h > N->monEtat.h ? N->monEtat : noeudSuivant->monEtat ;
        }
        return noeudSuivant->monEtat ;
}

minimax::~minimax(){
        delete [] listeNoeuds.sommet;
    }

minimax::minimax(){
    listeNoeuds.sommet=nullptr;
}
void minimax::viderListeNoeud(){
    listeNoeuds.sommet=nullptr;
    nombreDuNoeud=0;
}



