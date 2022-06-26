#include "../include/musacshi.h"
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
    Color(11,0);
    cout << endl <<"    \t\t\t\t " << setw(24) << setfill('_') << "\n" ;
    cout << "   \t\t\t\t(" << setw(25) << setfill(' ') << ")\n" ;


    for(int i=0;i<HAUTEUR;i++){
        if (i<HAUTEUR-2){
            for(int j=0;j<LARGEUR;j++){

                if(j==0)cout << "\t\t\t\t|   ";//! cadre

                if (j!=LARGEUR-1){afficheColor(monPlateau[i][j]);cout << monPlateau[i][j]; Color(11,0);cout << "---";}
                else { afficheColor(monPlateau[i][j]); cout << monPlateau[i][j]; Color(11,0);cout << "   |" << endl ;}

            }//! for

            if (i!=HAUTEUR-3){
                for(int t=0;t<LARGEUR-1;t++){

                    if(t==0)cout << "\t\t\t\t|   ";//! cadre

                    if ((i+t)%2==0)cout << "| \\ ";
                    if ((i+t)%2!=0) cout << "| / ";

                }
            cout << "|   |" << endl;
            }
            else { //!(i==HAUTEUR-3)

                cout <<"\t\t\t\t(___" ; //! cadre

                cout <<"      / | \\" ;
                cout <<"      ___)"<< endl;
            }

        } //! if(i<HAUTEUR-2)

        else if (i==HAUTEUR-2){
            cout << "\t\t\t\t    /   ";
            for(int j=1;j<LARGEUR-1;j++){
                if (j!=LARGEUR-2){afficheColor(monPlateau[i][j]);cout << monPlateau[i][j]; Color(11,0);cout  << "---";}
                else{afficheColor(monPlateau[i][j]); cout<< monPlateau[i][j]; Color(11,0);cout << "   \\" << endl ;}
            }
        } //! if(i==HAUTEUR-2)

        else {//! (i==HAUTEUR-1)

             for(int t=0;t<LARGEUR-1;t++){
                if(t==0) cout <<"   \t\t\t\t   /" << "  / ";
                else if(t==LARGEUR-2)cout << "| \\  \\";
                else if ((i+t)%2==0)cout << "| \\ ";
                else if  ((i+t)%2!=0) cout << "| / ";
            }//!!!!!!!!!

        cout << endl << "   \t\t\t\t  / ";
            for(int j=0;j<LARGEUR;j++){
            if (j!=LARGEUR-1){afficheColor(monPlateau[i][j]);cout << monPlateau[i][j]; Color(11,0);cout  << "---";}
            else{afficheColor(monPlateau[i][j]);  cout << monPlateau[i][j];  Color(11,0);cout << " \\" << endl ;}

            }
            cout << "\t\t\t\t (_____________________)" << endl;
        }

    }
    cout << endl << "\t\t\t\tle nombre de Policiers est : ";
    Color(12,0);
    cout  << nombrePoliciers << endl;
    Color(15,0);

}

void plateau::updatePlateau(const player& J){
    monPlateau[J.deplacementsouhaite.posi.x][J.deplacementsouhaite.posi.y]=vide;
    monPlateau[J.deplacementsouhaite.posf.x][J.deplacementsouhaite.posf.y]=J.tour;
}

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
