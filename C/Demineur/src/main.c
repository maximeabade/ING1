/*!
* \file main.c
*
* \brief le code de la fonction main
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* 
* \date 09 décembre 2021
*/

/*inclusion des entêtes de librairie*/
#include "main.h"


/*code de la fonction main*/

// fonction principale qui permet de saisir les paramètres de la partie puis de la lancer
int main(int argc, char *argv[])
{
    // Déclaration des variables
    struct_case** ppcase_plateau; // le plateau de jeu
    int int_n; // la taille du plateau
    int int_nbMines; // le nombre de mines sur le plateau

    // On demande à l'utilisateur la taille du plateau et le nombre de mine
    do{
        printf("\nSaisissez la taille du plateau (entre 4 et 20) : ");
        int_n = saisirEntier();
    } while(int_n < 4 || int_n > 20);
    do{
        printf("\nSaisissez le nombre de mînes contenues dans le plateau (entre 1 et %d) : ", (int_n * int_n)-1);
        int_nbMines = saisirEntier();
    } while(int_nbMines < 1 || int_nbMines > (int_n * int_n)-1);

    ppcase_plateau = creerPlateau(int_n);

    // Affichage de l'état du plateau
    system("clear");
    afficherPlateau(ppcase_plateau, int_n);
    printf("\nIl reste %d mines à découvrir.\n", int_nbMines);

    deroulePartie(ppcase_plateau, int_n, int_nbMines);

    freeTab2D(ppcase_plateau, int_n);


    // On retourne 0 pour indiquer que le programme s'est bien terminé
    return(0);
}