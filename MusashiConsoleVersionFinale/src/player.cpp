#include "../include/musacshi.h"

using namespace std;


player::player(){
    tour = voleur;// le voleur est celui qui commence le jeu
}
void player::getdeplacement(const plateau& plat){

    deplacementsouhaite.posi.x= plat.positionDuVoleur().x;
    deplacementsouhaite.posi.y= plat.positionDuVoleur().y;
    do{
    Color(11,0);
    cout <<  "\n\t\t\t\tEntrer la direction SVP :";
    Color(12,0);
    cin >>deplacementsouhaite.direction;
    deplacementsouhaite.tour = tour;
    deplacementsouhaite.posf = deplacementsouhaite.positionSuivant();
    }while (!(deplacementsouhaite.verifierMvt()));



}

void player::update(){
    if(tour == police) tour = voleur;
    else tour = police;
}
void player::afficheTour(){
    Color(11,0);
    if(tour == police){ cout << "\t\t\t\tLe tour du " ; Color(12,0); cout << "policier";}
    else {cout << "\t\t\t\tLe tour du " ; Color(12,0);cout <<  "voleur ";}
}










