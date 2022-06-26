#include "musacshi.h"

using namespace std;

plateau::plateau(){
    nombrePoliciers=16;//à l'etat initail on 16 policiers
    for(int i=0;i<HAUTEUR;i++){
        for(int j=0;j<LARGEUR;j++){
            if((i==0 || j==0 || i==4 || j==4)&& i<5){
                monPlateau[i][j]=police;
            }
            else if(i==2 && j==2){
                monPlateau[i][j]=voleur;
            }
            else {
                monPlateau[i][j]=vide;
            }
        }
    }
}

void plateau::afficheToi(){
    cout << "     ";
    for (int t=0;t<LARGEUR;t++)
        cout << "   "<<t;

    cout << endl <<"     " << setw(24) << setfill('_') << "\n" ;
    cout << "    (" << setw(25) << setfill(' ') << ")\n" ;


    for(int i=0;i<HAUTEUR;i++){


        if (i<HAUTEUR-2){
            for(int j=0;j<LARGEUR;j++){

                if(j==0)cout << "  "<< i <<" |   ";//! cadre

                if (j!=LARGEUR-1)cout << monPlateau[i][j] << "---";
                else cout << monPlateau[i][j] << "   |" << endl ;

            }//! for


            if (i!=HAUTEUR-3){
                for(int t=0;t<LARGEUR-1;t++){

                    if(t==0)cout << "    |   ";//! cadre

                    if ((i+t)%2==0)cout << "| \\ ";
                    if ((i+t)%2!=0) cout << "| / ";

                }
            cout << "|   |" << endl;
            }
            else { //!(i==HAUTEUR-3)

                cout <<"    (___" ; //! cadre

                cout <<"      / | \\" ;
                cout <<"      ___)"<< endl;
            }

        } //! if(i<HAUTEUR-2)

        else if (i==HAUTEUR-2){
            cout << "      " << i << " /   ";
            for(int j=1;j<LARGEUR-1;j++){
                if (j!=LARGEUR-2)cout << monPlateau[i][j] << "---";
                else  cout << monPlateau[i][j] << "   \\" << endl ;
            }
        } //! if(i==HAUTEUR-2)

        else {//! (i==HAUTEUR-1)

             for(int t=0;t<LARGEUR-1;t++){
                if(t==0) cout <<"       /" << "  / ";
                else if(t==LARGEUR-2)cout << "| \\  \\";
                else if ((i+t)%2==0)cout << "| \\ ";
                else if  ((i+t)%2!=0) cout << "| / ";
            }//!!!!!!!!!

        cout << endl << "    "<<i<<" / ";
            for(int j=0;j<LARGEUR;j++){
            if (j!=LARGEUR-1)
                cout << monPlateau[i][j] << "---";
            else  cout << monPlateau[i][j] << " \\" << endl ;

            }
            cout << "     (_____________________)" << endl;
        }

    }
    cout << "le nombre de Policiers est : " << nombrePoliciers << endl;

}

void plateau::updatePlateau(const player& J){
    monPlateau[J.deplacementsouhaite.posi.x][J.deplacementsouhaite.posi.y]=vide;
    monPlateau[J.deplacementsouhaite.posf.x][J.deplacementsouhaite.posf.y]=J.tour;
}


/* plateau::deplacerPolicier(const player& J){

}*/

void plateau::mongePion(const player& J){
    // on a 4 cas
  if(monPlateau[J.deplacementsouhaite.posf.x][J.deplacementsouhaite.posf.y] == voleur){

    if((J.deplacementsouhaite.posf.x>0&&J.deplacementsouhaite.posf.x<6) && !((J.deplacementsouhaite.posf.x==4 || J.deplacementsouhaite.posf.x ==5) && (J.deplacementsouhaite.posf.y ==1 || J.deplacementsouhaite.posf.y==3)) && monPlateau[J.deplacementsouhaite.posf.x - 1][J.deplacementsouhaite.posf.y] == police && monPlateau[J.deplacementsouhaite.posf.x + 1][J.deplacementsouhaite.posf.y] == police){

        monPlateau[J.deplacementsouhaite.posf.x-1][J.deplacementsouhaite.posf.y]=vide;
        monPlateau[J.deplacementsouhaite.posf.x+1][J.deplacementsouhaite.posf.y]=vide;
        nombrePoliciers -= 2;
    }
    else if ((J.deplacementsouhaite.posf.y>0&&J.deplacementsouhaite.posf.y<4) && monPlateau[J.deplacementsouhaite.posf.x][J.deplacementsouhaite.posf.y-1] == police && monPlateau[J.deplacementsouhaite.posf.x][J.deplacementsouhaite.posf.y+1] == police){
        monPlateau[J.deplacementsouhaite.posf.x][J.deplacementsouhaite.posf.y-1]=vide;
        monPlateau[J.deplacementsouhaite.posf.x][J.deplacementsouhaite.posf.y+1]=vide;
        nombrePoliciers -= 2;
    }
    else if((J.deplacementsouhaite.posf.x+J.deplacementsouhaite.posf.y)%2 == 0 && (J.deplacementsouhaite.posf.x>0&&J.deplacementsouhaite.posf.x<6) && (J.deplacementsouhaite.posf.y>0&&J.deplacementsouhaite.posf.y<4) ){
        if (monPlateau[J.deplacementsouhaite.posf.x-1][J.deplacementsouhaite.posf.y+1] == police && monPlateau[J.deplacementsouhaite.posf.x+1][J.deplacementsouhaite.posf.y-1] == police){
            monPlateau[J.deplacementsouhaite.posf.x-1][J.deplacementsouhaite.posf.y+1]=vide;
            monPlateau[J.deplacementsouhaite.posf.x+1][J.deplacementsouhaite.posf.y-1]=vide;
            nombrePoliciers -= 2;
        }
        else if (monPlateau[J.deplacementsouhaite.posf.x+1][J.deplacementsouhaite.posf.y+1] == police && monPlateau[J.deplacementsouhaite.posf.x-1][J.deplacementsouhaite.posf.y-1] == police){
            monPlateau[J.deplacementsouhaite.posf.x-1][J.deplacementsouhaite.posf.y-1]=vide;
            monPlateau[J.deplacementsouhaite.posf.x+1][J.deplacementsouhaite.posf.y+1]=vide;
            nombrePoliciers -= 2;
        }
    }
 }
}


bool plateau::capturePossible(){
    deplacement d;
    for(int i=0;i<HAUTEUR;i++){
        for(int j=0;j<LARGEUR;j++){
            if(!(i==5 && (j==0 || j==4))){
                if(monPlateau[i][j]==voleur){
                    for(int dir=0;dir<8;dir++){
                        d.posi.x=i,d.posi.y=j,d.direction=dir;
                        d.posf=d.positionSuivant();
                        if(d.verifierMvt() && d.estVide(*this)){
                            return true;
                        }

                    }
                }
            }
        }
    }
    return false;
}

plateau::plateau(plateau& unPlateau){
    nombrePoliciers=unPlateau.nombrePoliciers;
    for(int i=0;i<HAUTEUR;i++){
        for(int j=0;j<LARGEUR;j++){
            monPlateau[i][j]=unPlateau.monPlateau[i][j];
        }
    }
}

position plateau::positionDuVoleur()const{
    position pos;
    for (int i=0;i<7;i++){
        for(int j=0;j<5;j++){
            if(monPlateau[i][j]==voleur){
                    pos.x=i;pos.y=j;
                    return pos;
        }
       }
    }
}

bool plateau::gameOver(){
    if (nombrePoliciers<=4){
        return true;
    }
        return false;
}
bool plateau::etatfinale(){
        if (this->capturePossible())return false;
        return true;
    }
bool plateau::operator== (const plateau P){
       for (int i=0;i<7;i++){
        for(int j=0;j<5;j++){
            if(!(i==5 && (j==0 || j==4))){
                if(monPlateau[i][j]!=P.monPlateau[i][j])return false;
            }
        }
       }
       return true;
}


position deplacement::positionSuivant(){
    position posf;
    switch (direction)
    {
    case HAUT :
        posf.x = posi.x - 1;
        posf.y = posi.y;
        break;
    case BAS :
        posf.x = posi.x + 1;
        posf.y = posi.y;
        break;
    case DROITE :
        posf.x = posi.x;
        posf.y = posi.y + 1;
        break;
    case GAUCHE :
        posf.x = posi.x;
        posf.y = posi.y - 1;
        break;
    case HAUT_DROITE :
        posf.x = posi.x - 1;
        posf.y = posi.y + 1;
        break;
    case HAUT_GAUCHE :
        posf.x = posi.x - 1;
        posf.y = posi.y - 1;
        break;
    case BAS_DROITE :
        posf.x = posi.x + 1;
        posf.y = posi.y + 1;
        break;
    case BAS_GAUCHE :
        posf.x = posi.x + 1;
        posf.y = posi.y - 1;
        break;
    }
    return posf;

}

bool deplacement::verifierMvt(){

    if((posf.x >= HAUTEUR || posf.y >= LARGEUR ) || (posf.x < 0 || posf.y < 0)){

        return false;
    }


    if ((posi.x + posi.y)%2==1 && (direction == HAUT_DROITE || direction == HAUT_GAUCHE ||
                direction == BAS_DROITE || direction == BAS_GAUCHE)) return false;

    if (posf.x==5 && (posf.y == 0 || posf.y == 4)) return false;

    if ((posi.x ==5 && posi.y ==1) && (direction == HAUT || direction == GAUCHE || direction == HAUT_GAUCHE))return false;
    if ((posi.x ==5 && posi.y ==3) && (direction == HAUT || direction == DROITE || direction == HAUT_DROITE))return false;

    if ((posi.x==4 && posi.y == 0 && direction == BAS_DROITE) ||
         (posi.x==4 && posi.y == 4 && direction == BAS_GAUCHE) ||
         (posi.x==4 &&(posi.y == 1 || posi.y == 3) && direction == BAS)) return false;


    return true;

}
bool deplacement::estVide(const plateau& plat){
    if (plat.monPlateau[posf.x][posf.y]== vide) return true;
    else{
        return false;
    }

}

void deplacement::affichedep(){
    cout << "("<<posi.x<<" , "<<posi.y<<") ==> ("<<posf.x<<" , "<<posf.y<<") " << direction << endl;
}

bool deplacement::bonPion(const plateau& plat){
    if(plat.monPlateau[posi.x][posi.y] == tour)return true;
    else {
        cout << " ==> Mauvais choix du pion" << endl;
        return false;
    }
}


player::player(){
    tour = voleur;// le voleur est celui qui commence le jeu
}
void player::getdeplacement(const plateau& plat){

    deplacementsouhaite.posi.x= plat.positionDuVoleur().x;
    deplacementsouhaite.posi.y= plat.positionDuVoleur().y;
    do{
    cout <<  "\nEntrer la direction SVP :"; cin >>deplacementsouhaite.direction;
    deplacementsouhaite.tour = tour;
    deplacementsouhaite.posf = deplacementsouhaite.positionSuivant();
    }while (!(deplacementsouhaite.verifierMvt()) || !(deplacementsouhaite.estVide(plat)) || !(deplacementsouhaite.bonPion(plat)));



}

void player::update(){
    if(tour == police) tour = voleur;
    else tour = police;
}
void player::afficheTour(){
    if(tour == police) cout << "Le tour du policier";
    else cout << "Le tour du voleur ";
}


minimax::minimax(etat ET){
        listeNoeuds.sommet=nullptr;
        noeud* N = new noeud[sizeof(noeud)];
        N->monEtat = ET;
        N->precedent = listeNoeuds.sommet;
        listeNoeuds.sommet=N;
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
                            try {
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

                            }catch(std::bad_alloc eb){
                                cout << "Erreur d'allocation memoire en genersesseur " << endl;
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
            N->monEtat.h=M.Minimax(N,p,nbrDuNoeudEx,nbrDuNoeudGe);
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
etat alphaBeta::joueurAlphaBeta(noeud* unNoeud , int p,int& nbrDuNoeudEx,int& nbrDuNoeudGe){
        this->generersuccesseur(unNoeud->monEtat,nbrDuNoeudGe);
        etat et ;
        et.h = 10000;
        for (noeud* N = listeNoeuds.sommet;(!(N->monEtat.unPlateau == unNoeud->monEtat.unPlateau));N=N->precedent){
            nbrDuNoeudEx++;
            alphaBeta objalphabeta(N->monEtat);
            N->monEtat.h=objalphabeta.AlphaBeta(N,p,nbrDuNoeudEx,nbrDuNoeudGe);
           et = et.h > N->monEtat.h ? N->monEtat :et ;
        }
       return et ;
}


void alphaBeta::extraire(){
        if (listeNoeuds.sommet->precedent==NULL) listeNoeuds.sommet=NULL;
        else listeNoeuds.sommet=listeNoeuds.sommet->precedent;

}
void alphaBeta::generersuccesseur(etat ET,int& nombredeNoeud){
        for(int i=0;i<7;i++){
            for(int j=0;j<5;j++){
                if(ET.unPlateau.monPlateau[i][j]==ET.tour){
                  for(int dir=0;dir<8;dir++){
                        player P ; P.deplacementsouhaite.posi.x=i, P.deplacementsouhaite.posi.y=j,P.deplacementsouhaite.direction=dir;P.deplacementsouhaite.posf=P.deplacementsouhaite.positionSuivant();P.tour=ET.tour;
                        if(P.deplacementsouhaite.verifierMvt() && P.deplacementsouhaite.estVide(ET.unPlateau)){
                            try {
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

                            }catch(std::bad_alloc eb){
                                cout << "Erreur d'allocation memoire en genersesseur " << endl;
                             }

                        }
                    }
                }
            }
        }

}

int alphaBeta::heuristique(plateau& P){
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
void alphaBeta::viderListeNoeud(){
    listeNoeuds.sommet=nullptr;
    nombreDuNoeud=0;
}





