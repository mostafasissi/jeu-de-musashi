#include "../include/musacshi.h"



void UnInterface::affiche(string str){

    ifstream fichier(str, ios::in);
    if(fichier){
        system("cls");
        char caractere;
        while(fichier.get(caractere) )  // tant que l'on peut mettre la ligne dans "contenu"
        {
            afficheColor(caractere);
                cout << caractere ;  // on l'affiche
        }
        fichier.close();
    }else{
         cout << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void afficheColor(char c){
    switch (c) {
    case '$':
        Color(10,0);
        break;
    case '-':
        Color(11,0);
        break;
    case 'P':
        Color(6,0);
        break;
    case 'V':
        Color(15,0);
    default:
        Color(9,0);
    }

}
void UnInterface::afficheInterface(){

    this->affiche("fichierText\\opening.txt");// l'interface principale
    Sleep(1000);
    CHOIX_MENU:
    this->affiche("fichierText\\menu.txt");
    //lire le choix du user
    this->setChoixMenu();
    if(choixMenu==1){// choix de jouer
        CHOIX_LEVEL:
        this->affiche("fichierText\\level.txt");
        //choix du level
        this->setChoixLevel();
        if (!(choixLevel>=1 && choixLevel<=3))goto CHOIX_LEVEL;
    }
    else if(choixMenu==2){// choix de voire les regles
        this->affiche("fichierText\\rules.txt");
        char choix;
        cout << endl<< "\tDo you want to start playing (y/n) :";
        cin >> choix;
        if(choix=='y'){choixMenu=1;goto CHOIX_LEVEL;}
        else goto CHOIX_MENU;
    }
    else if(choixMenu==3){// choix de sortir
        system("cls");
    }else goto CHOIX_MENU;
}
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
