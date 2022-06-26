#include "../include/musacshi.h"
using namespace std;

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


