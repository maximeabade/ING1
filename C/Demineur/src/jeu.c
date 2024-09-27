/*!
* \file jeu.c
*
* \brief le code des fonction relavtives au jeu
*
* \author Justine Ribas <ribasjusti@cy-tech.fr>
* \version 0.1
* 
* \date 09 décembre 2021
*/

/*inclusion des entêtes de librairie*/
#include "jeu.h"


/*code des fonctions*/

// Fonction qui initialise le plateau de jeu
void initPlateau(struct_case** ppcase_plateau, int int_n, int int_nbMines)
{
  // Déclaration des variables
  int int_i; //iterrateur de boucle
  int int_j; //iterrateur de boucle
  int int_x; // indice de la ligne
  int int_y; // indice de la colonne

  // On initialise le plateau de jeu
  for(int_i = 0; int_i < int_n; int_i ++){
    for(int_j = 0; int_j < int_n; int_j ++){
      // toutes les cases sont non découvertes
      ppcase_plateau[int_i][int_j].int_etat = 0;
      // toutes les cases sont vides
      ppcase_plateau[int_i][int_j].int_nature = 0;
    }
  }

  // On place les mines au hasard
  srand(time(NULL));
  
  for(int_i = 0; int_i < int_nbMines; int_i ++){
    // On place une mine
    do{
      int_x = rand()%(int_n);
      int_y = rand()%(int_n);
    } while(ppcase_plateau[int_x][int_y].int_nature == -1);
    ppcase_plateau[int_x][int_y].int_nature = -1;
  }
  

  // On calcule les natures des autres cases / on leur donne le chiffre correspondant au nombre de mines autour
  chiffrerCases(ppcase_plateau, int_n);
}

// Fonction qui permet d'attribuer à chaque case, le nombre de mines qui l'entourrent
void chiffrerCases(struct_case** ppcase_plateau, int int_n)
{
    // Déclaration des variables
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle

    // Parcours du tableau : centre du plateau
    for(int_i = 0; int_i < int_n; int_i++){
        for(int_j = 0; int_j < int_n; int_j++){
            // On regarde si la case est une mine
            if(ppcase_plateau[int_i][int_j].int_nature == -1){
                // Si on est tombé sur une mine, on incrémente les cases chiffres autour
                
                if(int_i > 0 && int_j > 0 && ppcase_plateau[int_i - 1][int_j - 1].int_nature != -1){
                    ppcase_plateau[int_i - 1][int_j - 1].int_nature += 1;
                }

                if(int_i > 0 && ppcase_plateau[int_i - 1][int_j].int_nature != -1){
                    ppcase_plateau[int_i - 1][int_j].int_nature += 1;
                }

                if(int_j < int_n -1 && int_i > 0 && ppcase_plateau[int_i - 1][int_j + 1].int_nature != -1){
                    ppcase_plateau[int_i - 1][int_j + 1].int_nature += 1;
                }

                if(int_j < int_n - 1 && ppcase_plateau[int_i][int_j + 1].int_nature != -1){
                    ppcase_plateau[int_i][int_j + 1].int_nature += 1;
                }

                if(int_i < int_n - 1 && int_j < int_n - 1 && ppcase_plateau[int_i + 1][int_j + 1].int_nature != -1){
                    ppcase_plateau[int_i + 1][int_j + 1].int_nature += 1;
                }

                if(int_i < int_n - 1 && ppcase_plateau[int_i + 1][int_j].int_nature != -1){
                    ppcase_plateau[int_i + 1][int_j].int_nature += 1;
                }

                if(int_i < int_n - 1 && int_j > 0 && ppcase_plateau[int_i + 1][int_j - 1].int_nature != -1){
                    ppcase_plateau[int_i + 1][int_j - 1].int_nature += 1;
                }

                if(int_j > 0 && ppcase_plateau[int_i][int_j - 1].int_nature != -1){
                    ppcase_plateau[int_i][int_j - 1].int_nature += 1;
                }
            }
        }
    }
}

// Fonction qui permet d'afficher un tableau de cases à deux dimensions
void afficherPlateau(struct_case** ppcase_plateau, int int_n)
{
  // Déclaration des variables
  int int_i; // compteur de boucle
  int int_j; // compteur de boucle

  // On affiche les indice horizontaux du plateau
  printf("    ");
  for(int_i = 0; int_i < int_n; int_i++){
    printf(" %d  ", int_i);
  }
  afficheDelimitation(int_n);

  // On affiche chaque case avec son symbole correspondant
  for(int_i = 0; int_i < int_n; int_i++){
    // A chaque début de ligne on met l'indice vertical
    printf(" %d |", int_i);
    for(int_j = 0; int_j < int_n; int_j++){
      switch(ppcase_plateau[int_i][int_j].int_etat) {
        // case découverte
        case 1 : 
          afficherCaseDecouverte(ppcase_plateau[int_i][int_j].int_nature);
          break;
        // case marqué
        case -1 :
          printf(" F |");
          break;
        // case découverte
        case 0 :
          printf("   |");
          break;
        default : 
          printf("Erreur des valeurs du plateau\n");
          break;
      }
    }
    afficheDelimitation(int_n);
    }
}

// Fonction qui permet d'afficher une case découverte avec une bonne couleur
void afficherCaseDecouverte(int int_valeur)
{
    switch(int_valeur) {
        case -1 :
            printf("\033[0;31m X\033[0m |");
            break;
        case 0 :
            printf(" . |");
            break;
        case 1 :
            printf("\033[0;37m %d \033[0m|", int_valeur);
            break;
        case 2 :
            printf("\033[0;33m %d \033[0m|", int_valeur);
            break;
        case 3 :
            printf("\033[0;32m %d \033[0m|", int_valeur);
            break;
        case 4 :
            printf("\033[0;36m %d \033[0m|", int_valeur);
            break;
        case 5 :
            printf("\033[0;34m %d \033[0m|", int_valeur);
            break;
        case 6 :
            printf("\033[0;35m %d \033[0m|", int_valeur);
            break;
        case 7 :
            printf("\033[0;31m %d \033[0m|", int_valeur);
            break;
        case 8 :
            printf("\033[0;31m %d \033[0m|", int_valeur);
            break;
        default :
            printf("Erreur des valeurs du plateau\n");
            break;
    }
}

// Fonction pour afficher les délimitation du plateau de jeu
void afficheDelimitation(int int_n)
{
    // Déclaration des variables
    int int_i; // compteur de boucle

    // On affiche la délimitation suppérieure du tableau
    printf("\n   +");
    for(int_i = 0; int_i < int_n; int_i++){
        printf("---+");
    }
    printf("\n");
}

// Fonction qui permet de dérouler le jeu
void deroulePartie(struct_case** ppcase_plateau, int int_n, int int_nbMines)
{
    // Déclaration des variables
    int int_aGagne; // variable pour savoir si le joueur a gagné ou perdu

    // Initialisation des variables
    int_aGagne = 0;
    initPlateau(ppcase_plateau, int_n, int_nbMines);

    // Boucle de jeu
    while(int_aGagne == 0){
        int_aGagne = jouer(ppcase_plateau, int_n);

        // Affichage de l'état du plateau
        system("clear");
        afficherPlateau(ppcase_plateau, int_n);
        printf("\nIl reste %d mines à découvrir.\n", compteMines(ppcase_plateau, int_n));

        // si on a pas perdu, on vérifie si on a gagné
        if(int_aGagne == 0){
            int_aGagne = verifaGagne(ppcase_plateau, int_n);
            if(int_aGagne == 1){
                revelePlateau(ppcase_plateau, int_n);
                // Affichage du plateau final
                system("clear");
                afficherPlateau(ppcase_plateau, int_n);
                printf("Bravo, vous avez gagné !\n");
            }
        } else {
            revelePlateau(ppcase_plateau, int_n);
            // Affichage du plateau final
            system("clear");
            afficherPlateau(ppcase_plateau, int_n);
            printf("Dommage, vous avez perdu !\n");
        }
    }
}

// Fonction qui permet de dévoiler ou marquer une case
int jouer(struct_case** ppcase_plateau, int int_n)
{
    // Déclaration des variables
    int int_ligne; // ligne de la case
    int int_colonne; // colonne de la case
    int int_choix; // choix du joueur
    int int_res; // état de la case

    // Initialisation des variables
    int_res = 0;

    // On demande à l'utilisateur de choisir une case
    do{
        printf("\nVeuillez entrer les coordonnées d'une case non dévoilée (ligne puis colonne) :\n");
        int_ligne = saisirEntier();
        int_colonne = saisirEntier();
    } while(int_ligne < 0 || int_ligne >= int_n || int_colonne < 0 || int_colonne >= int_n || ppcase_plateau[int_ligne][int_colonne].int_etat == 1);
    // Cas où la case est non dévoilée et non marquée
    if(ppcase_plateau[int_ligne][int_colonne].int_etat == 0){
        // On demande à l'utilisateur s'il veut dévoiler ou marquer la case
        do {
            printf("\nVoulez vous dévoiler (saisir 0) ou marquer (saisir 1) cette case ? ");
            int_choix = saisirEntier();
        } while(int_choix != 0 && int_choix != 1);
        // Cas où la case est marquée
    } else {
        // On demande à l'utilisateur s'il veut dévoiler ou dé-marquer la case
        do {
            printf("\nVoulez vous dévoiler (saisir 0) ou enlever le marquage (saisir -1) de cette case ? ");
            int_choix = saisirEntier();
        } while(int_choix != 0 && int_choix != -1);
    }

    if(int_choix == 0){
        // Si le joueur veut dévoiler la case
        ppcase_plateau[int_ligne][int_colonne].int_etat = 1;
        // Si la case est une mine, le joueur perd
        if(ppcase_plateau[int_ligne][int_colonne].int_nature == -1){
            int_res = -1;
        }
        // Si la case vaut 0, on dévoile les cases adjacentes tant qu'il n'y a pas de mines autour
        if(ppcase_plateau[int_ligne][int_colonne].int_nature == 0){
            reveleZoneLibre(ppcase_plateau, int_n, int_ligne, int_colonne);
        }
    } else {
        if(int_choix == -1){
            // Si le joueur veut démarquer la case
            ppcase_plateau[int_ligne][int_colonne].int_etat = 0;
        } else {
            // Si le joueur veut marquer la case
            ppcase_plateau[int_ligne][int_colonne].int_etat = -1;
        }
    } 

    return(int_res);
}

// Fonction qui permet de vérifier si le joueur a gagné
int verifaGagne(struct_case** ppcase_plateau, int int_n)
{
    // Déclaration des variables
    int int_res; // variable pour savoir si le joueur a gagné ou non
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle

    // Initialisation des variables
    int_res = 1;

    // On parcours le plateau
    for(int_i = 0; int_i < int_n; int_i++){
        for(int_j = 0; int_j < int_n; int_j++){
            // si on trouve une mine non dévoilée, on a pas gagné
            if(ppcase_plateau[int_i][int_j].int_etat == 0 && ppcase_plateau[int_i][int_j].int_nature == -1){
                int_res = 0;
            }
        }
    }

    return(int_res);
}

// Fonction qui permet de compter le nombre de mines restantes
int compteMines(struct_case** ppcase_plateau, int int_n)
{
    // Déclaration des variables
    int int_res; // variable pour le nombre de mines restantes
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle

    // Initialisation des variables
    int_res = 0;

    // On parcours le plateau
    for(int_i = 0; int_i < int_n; int_i++){
        for(int_j = 0; int_j < int_n; int_j++){
            // si on trouve une mine non découverte, on incrémente le compteur
            if(ppcase_plateau[int_i][int_j].int_nature == -1 && ppcase_plateau[int_i][int_j].int_etat == 0){
                int_res++;
            }
        }
    }

    return(int_res);
}

// Fonction qui permet de révéler toutes les cases du plateau
void revelePlateau(struct_case** ppcase_plateau, int int_n)
{
    // Déclaration des variables
    int int_i; // compteur de boucle
    int int_j; // compteur de boucle

    // On parcours le plateau
    for(int_i = 0; int_i < int_n; int_i++){
        for(int_j = 0; int_j < int_n; int_j++){
            // on dévoile la case
            ppcase_plateau[int_i][int_j].int_etat = 1;
        }
    }
}

// Fonction qui permet révéler les cases tant qu'il n'y a pas de mines autour
void reveleZoneLibre(struct_case** ppcase_plateau, int int_n, int int_ligne, int int_colonne)
{
    // On vérifie si il y a des mines sinon on révéle les cases autour
    if(int_ligne > 0 && int_colonne > 0 && ppcase_plateau[int_ligne - 1][int_colonne - 1].int_nature != -1 && ppcase_plateau[int_ligne - 1][int_colonne - 1].int_etat == 0){
        ppcase_plateau[int_ligne - 1][int_colonne - 1].int_etat = 1;
        reveleZoneLibre(ppcase_plateau, int_n, int_ligne - 1, int_colonne - 1);
    }

    if(int_ligne > 0 && ppcase_plateau[int_ligne - 1][int_colonne].int_nature != -1 && ppcase_plateau[int_ligne - 1][int_colonne].int_etat == 0){
        ppcase_plateau[int_ligne - 1][int_colonne].int_etat = 1;
        reveleZoneLibre(ppcase_plateau, int_n, int_ligne - 1, int_colonne);
    }

    if(int_colonne < int_n -1 && int_ligne > 0 && ppcase_plateau[int_ligne - 1][int_colonne + 1].int_nature != -1 && ppcase_plateau[int_ligne - 1][int_colonne + 1].int_etat == 0){
        ppcase_plateau[int_ligne - 1][int_colonne + 1].int_etat = 1;
        reveleZoneLibre(ppcase_plateau, int_n, int_ligne - 1, int_colonne + 1);
    }

    if(int_colonne < int_n - 1 && ppcase_plateau[int_ligne][int_colonne + 1].int_nature != -1 && ppcase_plateau[int_ligne][int_colonne + 1].int_etat == 0){
        ppcase_plateau[int_ligne][int_colonne + 1].int_etat = 1;
        reveleZoneLibre(ppcase_plateau, int_n, int_ligne, int_colonne + 1);
    }

    if(int_ligne < int_n - 1 && int_colonne < int_n - 1 && ppcase_plateau[int_ligne + 1][int_colonne + 1].int_nature != -1 && ppcase_plateau[int_ligne + 1][int_colonne + 1].int_etat == 0){
        ppcase_plateau[int_ligne + 1][int_colonne + 1].int_etat = 1;
        reveleZoneLibre(ppcase_plateau, int_n, int_ligne + 1, int_colonne + 1);
    }

    if(int_ligne < int_n - 1 && ppcase_plateau[int_ligne + 1][int_colonne].int_nature != -1 && ppcase_plateau[int_ligne + 1][int_colonne].int_etat == 0){
        ppcase_plateau[int_ligne + 1][int_colonne].int_etat = 1;
        reveleZoneLibre(ppcase_plateau, int_n, int_ligne + 1, int_colonne);
    }

    if(int_ligne < int_n - 1 && int_colonne > 0 && ppcase_plateau[int_ligne + 1][int_colonne - 1].int_nature != -1 && ppcase_plateau[int_ligne + 1][int_colonne - 1].int_etat == 0){
        ppcase_plateau[int_ligne + 1][int_colonne - 1].int_etat = 1;
        reveleZoneLibre(ppcase_plateau, int_n, int_ligne + 1, int_colonne - 1);
    }

    if(int_colonne > 0 && ppcase_plateau[int_ligne][int_colonne - 1].int_nature != -1 && ppcase_plateau[int_ligne][int_colonne - 1].int_etat == 0){
        ppcase_plateau[int_ligne][int_colonne - 1].int_etat = 1;
        reveleZoneLibre(ppcase_plateau, int_n, int_ligne, int_colonne - 1);
    }
    
}