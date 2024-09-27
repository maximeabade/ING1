/*!
\file main.c
\brief le code de la fonction main
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 22 novembre 2021
*/

/*inclusion des entêtes de librairie*/
#include "main.h"


/*code de la fonction main*/

// fonction principale qui affaiche le menu
int main(int argc, char *argv[])
{
    //Déclaration des variables
    int int_choix; //le choix de l'utilisateur dans le menu

    // Affichage du menu
    printf("Que voulez-vous faire ?\n\t1- Afficher une approximation du nombre pi\n\t2- Afficher une approximation de racine(2)\n");

    // Saisie du choix
    int_choix = saisirEntier();

    // On effectue l'interraction correspondant au choix
    switch (int_choix) {
        case 1:
            menuPi();
            break;
        case 2:
            menuRacine();
            break;
        default :
            printf("Choix invalide\n");
            break;
    }

    // On retourne 0 pour indiquer que le programme s'est bien terminé
    return(0);
}