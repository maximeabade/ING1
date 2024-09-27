/*!
\file pi.c
\brief le code des fonctions permettant de calculer la valeur de pi
\author Justine Ribas <ribasjusti@cy-tech.fr>
\version 0.1
\date 22 novembre 2021
*/

/*inclusion des entêtes de librairie*/
#include "pi.h"

/*code des fontions de calcul de pi*/

// fonction pour calculer la valeur de pi avec la methode de l'aire d'un cercle
float methodeAire(int int_n)
{
    //Déclaration des variables
    int int_r; //le rayon du cercle
    int int_aire; //l'aire du cercle
    float flt_x; //la valeur de x
    float flt_y; //la valeur de y
    int int_i; //la variable de boucle

    //Initialisation des variables
    int_aire = 0;
    int_r = 1;

    //On initialise la fonction rand
    srand(time(NULL));

    //Calcul de l'aire : pour n points on compte ceux qui sont dans le cercle
    for(int_i = 0; int_i < int_n; int_i++){   
        //on génère un point aléatoirement
        flt_x = (float)rand()/RAND_MAX;
        flt_y = (float)rand()/RAND_MAX;

        //on regarde si il est dans le cercle
        if(sqrt(pow(flt_x, 2) + pow(flt_y, 2)) <= int_r){
            int_aire++;
        } 
    }

    //On retourne de la valeur de pi
    return((float)4 * int_aire / int_n);      
}

// fonction pour calculer la valeur de pi avec la methode de Madhava de Sangamagrama
float methodeMadhava(int int_n)
{
    //Déclaration des variables
    int int_i; //la variable de boucle
    float flt_somme; //la valeur de la somme

    //Initialisation des variables
    flt_somme = 0;

    //Calcul de la somme jusqu'au int_n ième terme
    for(int_i = 0; int_i <= int_n; int_i++){
        flt_somme += pow(-1, int_i) / (2 * int_i + 1);
    }

    flt_somme *= 4;

    //On retourne la valeur de pi
    return(flt_somme);
}

// fonction pour calculer la valeur de pi avec la methode de John Wallis
float methodeWallis(int int_n)
{
    //Déclaration des variables
    int int_i; //la variable de boucle
    float flt_produit; //la valeur du produit

    //Initialisation des variables
    flt_produit = 1;

    //Calcul du produit jusqu'au int_n ième terme
    for(int_i = 1; int_i <= int_n; int_i++){
        flt_produit *= pow(2*int_i, 2) / (pow(2*int_i, 2) - 1);
    }

    flt_produit *= 2;

    //On retourne la valeur de pi
    return(flt_produit);
}

// fonction qui affiche le menu de choix de la methode de calcul de pi
void menuPi(void)
{
    //Déclaration des variables
    int int_choix; //le choix de l'utilisateur dans le menu
    int int_n; //la précision de l'approximation, plus n est grand, plus l'approximation est précise
    float flt_pi; //la valeur de pi

    // Saisie de int_n
    do {
        printf("Entrez la précision de l'approximation de pi. On a besoin d'un entier positif.(plus ce nombre sera grand, plus l'aproximation sera précise)\n");
        int_n = saisirEntier();
    } while(int_n < 0);
    

    // Affichage du menu
    printf("\nQuelle méthode voulez-vous utiliser pour calculer une approximation de pi ?\n\t1- l'aire d’un disque par quadrillage\n\t2- la méthode Madhava de Sangamagrama\n\t3- la méthode John Wallis\n");

    // Saisie du choix
    int_choix = saisirEntier();

    // On effectue l'interraction correspondant au choix
    switch (int_choix) {
        case 1:
            flt_pi = methodeAire(int_n);
            break;
        case 2:
            flt_pi = methodeMadhava(int_n);
            break;
        case 3:
            flt_pi = methodeWallis(int_n);
            break;
        default :
            printf("Choix invalide\n");
            break;
    }

    printf("Pi vaudrait : %f\n", flt_pi);
}