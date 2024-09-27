/*! \file menu.c
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 17/11/2021
 *  \brief Programme pour l'exercice "Programme un peu plus grand"
 */

 /* Inclusion des entetes de librairie */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*! \fn int saisirEntier(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 11/12/2019
 *
 *  \brief vide le buffer
 * 
 *
 * \return l'entier saisi
 *
 * \remarks 
 */
void viderBuffer(void)
{
  char char_saisie; //le caracère courant dans le buffer
  scanf("%c", &char_saisie);
  while (char_saisie!='\n') {
    scanf("%c", &char_saisie);
  }
}



/*! \fn int saisirEntier(void)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 11/12/2019
 *
 *  \brief vérifie la saisie d'un entier
 * 
 *
 * \return l'entier saisi
 *
 * \remarks 
 */

int saisirEntier(void)
{
  int int_nbrSaisi; //le nombre qui sera saisie
  while (!scanf("%d", &int_nbrSaisi)) {
    //on vide le buffer pour eviter une boucle infini
    viderBuffer();
    printf("Erreur lors de la saisie ! Veuillez saisir un entier :");
  }
  return(int_nbrSaisi);
}



/*! \fn void affichageTriangle(int n);
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 17/11/2021
 *
 *  \brief Procédure qui affiche un triangle de int_n lignes
 * 
 *
 * \param int_n : nombre de lignes du triangle
 *
 * \remarks 
 */

void affichageTriangle(int int_n)
{
// Déclaration des variables
int int_i; //Compteur de boucle
int int_j; //Compteur de boucle

// Affichage du triangle
printf("\n\nTriangle de %d lignes :\n\n", int_n);

for(int_i = 1; int_i <= int_n; int_i++){
    // Affichage des espaces avant les étoiles
    for(int_j = 1; int_j <= (int_n - int_i + 1); int_j++){
        printf(" ");
    }
    // Affichage des étoiles
    for(int_j = (int_n - int_i + 2); int_j <= (int_n - int_i + int_i*2); int_j++){
        printf("*");
    }
    // Affichage des espaces après les étoiles
    for(int_j = (int_i*2 + 2); int_j <= (int_n*2 - 1); int_j++){
        printf(" ");
    }
    printf("\n");
}
printf("\n");

}



/*! \fn void tableMultiplication(int int_n);
*  \author Justine Ribas <ribasjusti@cy-tech.fr>
*  \version 0.1
*  \date 17/11/2021
*
*  \brief Procédure qui affiche la table de pultiplication de int_n
* 
*
* \param int_n : nombre pour lequel on calcule la table de multiplication
*
* \remarks 
*/
void tableMultiplication(int int_n)
{
    // Déclaration des variables
    int int_i; //Compteur de boucle

    // Affichage de la table de multiplication
    printf("\n\nTable de multiplication de %d :\n\n", int_n);
    for(int_i = 1; int_i <= 10; int_i++){
        printf("\t%d x %d = %d\n", int_n, int_i, int_n*int_i);
    }
    printf("\n");

}



/*! \fn int calculTailleNb(int int_n);
*  \author Justine Ribas <ribasjusti@cy-tech.fr>
*  \version 0.1
*  \date 17/11/2021
*
*  \brief Fonction qui calcule la taille d'un nombre
* 
*
* \param int_n : nombre pour lequel on calcule la taille
* \return int_taille : taille du nombre
*
* \remarks 
*/

int calculTailleNb(int int_n)
{
    // Déclaration des variables
    int int_taille; //taille du nombre

    // Intialisation des variables
    int_taille = 0;

    // Calcul de la taille du nombre
    while(int_n != 0){
        int_n = int_n / 10;
        int_taille++;
    }

    // On retourne la taille du nombre
    return(int_taille);
}



/*! \fn void estArmstrong(int int_n);
*  \author Justine Ribas <ribasjusti@cy-tech.fr>
*  \version 0.1
*  \date 17/11/2021
*
*  \brief Procédure qui affiche la table de pultiplication de int_n
* 
*
* \param int_n : nombre pour lequel on calcule la table de multiplication
*
* \remarks 
*/
void estArmstrong(int int_n)
{
    // Déclaration des variables
    int int_somme; //Somme des carrés des chiffres du nombre
    int int_taille; //Taille du nombre
    int int_nbr; //Copie du nombre pour l'affichage du résultat

    // Initialisation des variables
    int_somme = 0;
    int_nbr = int_n;
    int_taille = calculTailleNb(int_n);

    // Calcul de la somme des carrés des chiffres du nombre
    while(int_n > 0){
        int_somme += pow((int_n % 10), int_taille);
        int_n /= 10;
    }

    // Affichage du résultat
    if(int_somme == int_nbr){
        printf("\n\nLe nombre %d est un nombre Armstrong\n\n", int_nbr);
    } else {
        printf("\n\nLe nombre %d n'est pas un nombre Armstrong\n\n", int_nbr);
    }

}



/*! \fn int main (int argc, char** argv)
 *  \author Justine Ribas <ribasjusti@cy-tech.fr>
 *  \version 0.1
 *  \date 17/11/2021
 *
 *  \brief Fonction principale
 * 
 *
 * \param argc : Nombre d'argument
 * \param argv : Tableau des arguments
 * \return 0   : le programme doit se terminer normalement
 *
 * \remarks 
 */

 int main(int argc, char** argv)
 {
     //Déclaration des variables
    int int_choix; //le choix de l'utilisateur dans le menu
    int int_nb; //le nombre qui sera saisie

    // Demande à l'utilisateur de saisir un entier
    printf("Veuillez saisir un entier : ");
    int_nb = saisirEntier();

    // Affichage du menu
    printf("Que voulez-vous faire ?\n\t1-Afficher un triangle de %d lignes\n\t2-Afficher une table de multiplication de %d\n\t3-Vérifier si %d est un nombre d'Amstrong\n", int_nb, int_nb, int_nb);

    // Saisie du choix
    int_choix = saisirEntier();

    // On effectue l'interraction correspondant au choix
    switch (int_choix) {
        case 1:
            affichageTriangle(int_nb);
            break;
        case 2:
            tableMultiplication(int_nb);
            break;
        case 3:
            estArmstrong(int_nb);
            break;
        default :
            printf("Choix non reconnu\n");
            break;
    }

    // On retourne 0 pour indiquer que le programme s'est bien terminé
    return(0);
 }