/*!
 * \file jeu.c
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief fonctions relatives au déroulement d'une partie
 *
 *
 */

// Inclusion des librairies
#include "jeu.h"


// Codes des fonctions

/*Fonction qui déroule une partie "Joueur-Joueur"*/
void partieJJ(void){
  s_pion*** jeu; //l'ensembles des plateaux du jeu depuis le début de la partie
  s_pion** plateau; //le plateau du jeux actuel
  int tour; //le nombre de tours depuis le début de la partie
  tour = 0;
  plateau = creerTab2D();
  initTab(plateau);
  jeu = creerTab3D(1);
  do {
    //on déroule le tour du joueur 1
    system("clear");
    afficherTab(plateau);
    printf("\nNuméro du tour : %d\nC'est au tour du Joueur 1 (rouge) de jouer :\n\n", tour);
    joueurJoue(plateau, 1);
    if(tour > 1){
      jeu = agrandiTab(jeu, tour);
    }
    tour ++;
    jeu[tour-1] = copieTab2D(plateau);
    if (aGagne(plateau, tour) == 0   &&   !matchNul(jeu, tour)){
      //on déroule le tour du joueur 2
      system("clear");
      afficherTab(plateau);
      printf("\nNuméro du tour : %d\nC'est au tour du Joueur 2 (bleu) de jouer :\n\n", tour);
      joueurJoue(plateau, 2);
      jeu = agrandiTab(jeu, tour);
      tour ++;
      jeu[tour-1] = copieTab2D(plateau);;
    }
  } while(aGagne(plateau, tour) == 0  &&  !matchNul(jeu, tour));
  if(aGagne(plateau, tour) != 0){
    printf("Le joueur %d a gagné !\n", aGagne(plateau, tour));
  } else {
    printf("Match nul, c'est la troisième fois que l'on a cette disposition de plateau\n");
  }
  freeTab2D(plateau);
  freeTab3D(jeu, tour);
}

/*Fonction qui déroule une partie "Joueur-Ordinateur"*/
void partieJO(void){
  s_pion*** jeu; //l'ensembles des plateaux du jeu depuis le début de la partie
  s_pion** plateau; //le plateau du jeux actuel
  int tour; //le nombre de tours depuis le début de la partie
  tour = 0;
  plateau = creerTab2D();
  initTab(plateau);
  jeu = creerTab3D(1);
  do {
    //on déroule le tour du joueur 1
    system("clear");
    afficherTab(plateau);
    printf("\nC'est au tour du Joueur 1 (en haut) de jouer :\n\n");
    joueurJoue(plateau, 1);
    if(tour > 1){
    }
    tour ++;
    jeu[tour-1] = copieTab2D(plateau);
    if (aGagne(plateau, tour) == 0  &&  !matchNul(jeu, tour)){
      //on déroule le tour du joueur 2
      system("clear");
      afficherTab(plateau);
      ordiJoue(plateau, jeu, tour, 2);
      jeu = agrandiTab(jeu, tour);
      jeu = agrandiTab(jeu, tour);
      tour ++;
      jeu[tour-1] = copieTab2D(plateau);
    }
  } while(aGagne(plateau, tour) == 0   &&   !matchNul(jeu, tour));
  if(aGagne(plateau, tour) != 0){
    printf("Le joueur %d a gagné !\n", aGagne(plateau, tour));
  } else {
    printf("Match nul, c'est la troisième fois que l'on a cette disposition de plateau\n");
  }
  freeTab2D(plateau);
  freeTab3D(jeu ,tour);
}

/*Fonction qui déroule une partie "Ordinateur-Ordinateur"*/
void partieOO(void){
  s_pion*** jeu; //l'ensembles des plateaux du jeu depuis le début de la partie
  s_pion** plateau; //le plateau du jeux actuel
  int tour; //le nombre de tours depuis le début de la partie
  tour = 0;
  plateau = creerTab2D();
  initTab(plateau);
  jeu = creerTab3D(1);
  do {
    //on déroule le tour du joueur 1
    system("clear");
    afficherTab(plateau);
    printf("\nNombre de tours : %d\n", tour);
    ordiJoue(plateau, jeu, tour, 1);
    if(tour > 1){
      jeu = agrandiTab(jeu, tour);
    }
    tour ++;
    jeu[tour-1] = copieTab2D(plateau);
    usleep(200000);
    if (aGagne(plateau, tour) == 0  &&  !matchNul(jeu, tour)){
      //on déroule le tour du joueur 2
      system("clear");
      afficherTab(plateau);
      printf("\nNombre de tours : %d\n", tour);
      ordiJoue(plateau, jeu, tour, 2);
      jeu = agrandiTab(jeu, tour);
      tour ++;
      jeu[tour-1] = copieTab2D(plateau);
      usleep(200000);
    }
  } while(aGagne(plateau, tour) == 0   &&   !matchNul(jeu, tour));
  system("clear");
  afficherTab(plateau);
  printf("\nNombre de tours : %d\n", tour);
  if(aGagne(plateau, tour) != 0){
    printf("Le joueur %d a gagné !\n", aGagne(plateau, tour));
  } else {
    printf("Match nul, c'est la troisième fois que l'on a cette disposition de plateau\n");
  }
  freeTab2D(plateau);
  freeTab3D(jeu ,tour);
}

/*Fonction qui fait jouer un joueur*/
void joueurJoue(s_pion** tab, int joueur){
  s_coord pion; //le pion que le joueur va déplacer
  int estPossible; //variable booléenne qui indique si un déplacement est possible
  s_coord pionTemp; //variable temporaire
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  estPossible = 0;
  //on regarde si un déplacement est possible
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      if (tab[i][j].joueur == joueur){
        pionTemp.ligne = i;
        pionTemp.colonne = j;
        if (deplacementsPossibles(tab, pionTemp)){
          estPossible = 1;
          enleveCroix(tab);
        }
      }
    }
  }
  if (estPossible){
    do{
      //le joueur choisi son pion
      pion = choixPion(tab, joueur);
      //le pion doit pouvoir se déplacer
      estPossible = tourJoueur(tab, pion, joueur);
    } while(!estPossible);
  }
}

/*Fonction qui fait jouer un ordi*/
void ordiJoue(s_pion** tab, s_pion*** jeu, int tour, int joueur){
  s_coord* pionDeb = malloc(sizeof(s_coord)); //le pion à déplacer
  s_coord* pionFin = malloc(sizeof(s_coord)); //la case où on le déplace
  s_coord pionTemp; //variable temporaire
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int estPossible; //variable bouléenne qui indique si un déplacement est possible
  int gain; //gain retourné par minMax
  estPossible = 0;
  //on regarde si un déplacement est possible
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      if (tab[i][j].joueur == joueur){
        pionTemp.ligne = i;
        pionTemp.colonne = j;
        if (deplacementsPossibles(tab, pionTemp)){
          estPossible = 1;
          enleveCroix(tab);
        }
      }
    }
  }
  if (estPossible){
    //le pion à déplacer et son déplacement son choisi selon minMax
    gain = minMax(tab, jeu, tour, 2, pionDeb, pionFin, joueur, 1);
    deplacerPion(tab, *pionDeb, joueur, *pionFin);
    gain++;
  }
  enleveCroix(tab);
}

/*Fonction qui permet le tour d'un joueur*/
int tourJoueur(s_pion** tab, s_coord pion, int joueur){
	int estDeplace; //variable booléenne qui indique si le pion est déplacé
  s_coord pion2; //la future case du pion si il est déplacé
	estDeplace = 0;
  //on regarde si un déplacement est possible
	if (deplacementsPossibles(tab, pion)) {
    estDeplace = 1;
    system("clear");
    afficherTab(tab);
    //on choisi la future case du pion
    pion2 = choixCase(tab);
    //on déplace le pion
    deplacerPion(tab, pion, joueur, pion2);
    enleveCroix(tab);
  }
	return(estDeplace);
}

/*Fonction pour choisir un pion à déplacer*/
s_coord choixPion(s_pion** tab, int joueur){
  s_coord pion; //le pion choisi
  do {
    do {
      printf("Veuillez entrer la case du pion que vous voulez déplacer (ligne puis colonne) : \n");
      pion.ligne = saisirEntier();
      pion.colonne = saisirEntier();
      //la case doit exister sur le plateau
    } while((pion.ligne < 0 || pion.ligne >= N) || (pion.colonne < 0 || pion.colonne >= N));
    //la case doit contenir un pion du joueur
  } while(tab[pion.ligne][pion.colonne].joueur != joueur);
  return(pion);
}

/*Fonction pour choisir la future case d'un pion à déplacer*/
s_coord choixCase(s_pion** tab){
  s_coord pion2; //la future case du pion si il est déplacé
  do {
    do {
      printf("Veuillez entrer la ligne puis la colonne de la case où vous voulez déplacer votre pion : \n");
      pion2.ligne = saisirEntier();
      pion2.colonne = saisirEntier();
      //la future case doit faire partie du plateau
    } while((pion2.ligne < 0 || pion2.ligne >= N) || (pion2.colonne < 0 || pion2.colonne >= N));
    //la future case doit être un déplacement possible
  } while(tab[pion2.ligne][pion2.colonne].valeur != -1);
  return(pion2);
}

/*Fonction pour vérifier si un des deux joueur a gagné*/
int aGagne(s_pion** tab, int tour)
{
	int int_i; //iterrateur de boucle
	int gagne1 = 1;  //variable booléenne qui indique si le joueur1 a gagné
	int gagne2 = 1; //variable booléenne qui indique si le joueur2 a gagné
  int aGagne; //variable qui indique quel joueur a gagné
  //un joueur n'a pas gagné si tous ses pions ne sont pas sur la ligne d'arrivé
	for (int_i = 1; int_i < N-1; int_i++)
	{
		if (tab[0][int_i].joueur != 2){
			gagne2 = 0;
		}
		if (tab[N-1][int_i].joueur != 1){
			gagne1 = 0;
		}
	}
  //si au tour 30 un joueur a des pions sur sa ligne de départ, l'adversaire gagne
  if (tour>30){
  	for (int_i = 1; int_i < N-1; int_i++)
  	{
  		if (tab[0][int_i].joueur == 1){
  			gagne2 = 1;
  		}
  		if (tab[N-1][int_i].joueur == 2){
  			gagne1 = 1;
  		}
  	}
  }
  if(gagne1){
    aGagne = 1;
  } else {
    if(gagne2){
      aGagne = 2;
    } else {
      aGagne = 0;
    }
  }
  return(aGagne);
}

/*Fonction pour vérifier si il y a un match nul*/
int matchNul(s_pion*** jeu, int tour)
{
	int int_i; //iterrateur de boucle
	int int_j; //iterrateur de boucle
	int int_k; //iterrateur de boucle
	int int_l; //iterrateur de boucle
	int identique; //vrai si deux plateau sont identiques
	int plat_identique; //le compteur de plateau identique
	int matchnul; //vrai si le match est nul
	matchnul = 0;

	for (int_i = 0; int_i < tour; int_i++){
		plat_identique = 0;
		for (int_j = 0; int_j < tour; int_j++){
      if (int_i != int_j) {
        //Verrifier si les deux plateaux courants sont identiques
  			identique = 1;
        int_k = 0;
  			while (identique == 1 && int_k < N){
          int_l = 0;
  				while (identique == 1 && int_l < N){
  					if ( (jeu[int_i][int_k][int_l].valeur != jeu[int_j][int_k][int_l].valeur)  || (jeu[int_i][int_k][int_l].joueur != jeu[int_j][int_k][int_l].joueur)){
  						identique = 0;
  					}
            int_l++;
  				}
          int_k++;
  			}
        //si ils sont identiques, augmenter le compteur
  			if (identique == 1){
  				plat_identique++;
  			}
      }
		}
    //si il y a plus de deux plateaux identiques, alors le match est nul
		if(plat_identique > 2){
			matchnul = 1;
		}
	}
	return(matchnul);
}

/*Fonction pour optimiser les coups de l'IA*/
int minMax(s_pion** plateau, s_pion*** jeu, int tour, int profondeur, s_coord* pionDeb, s_coord* pionFin, int joueur, int evalMax){
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int k; //iterrateur de boucle
  int l; //iterrateur de boucle
  int gainCourant; //le gain de la branche courante
  int gainResultat; //le gain maximum
  s_pion** copiePlateau; //la copie du plateau
  s_pion*** copieJeu; //la copie du jeu
  s_coord* pionDebTemp = malloc(sizeof(s_coord)); //variable temporaires pour simuler les coups de l'adversaire
  s_coord* pionFinTemp = malloc(sizeof(s_coord)); //variable temporaires pour simuler les coups de l'adversaire
  gainResultat = -2000;
  enleveCroix(plateau);
  //condition d'arrêt
  if(profondeur == 0 || aGagne(plateau, tour) != 0 || matchNul(jeu, tour)){
    gainResultat = evaluerGain(plateau, jeu, tour, joueur);
  } else {
    //pour tous les pions de l'IA
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
        if(plateau[i][j].joueur == (evalMax ? joueur : (joueur == 1 ? 2 : 1))){
          enleveCroix(plateau);
          pionDebTemp->ligne = i;
          pionDebTemp->colonne = j;
          //Afficher les déplacements possibles
          if(deplacementsPossibles(plateau, *pionDebTemp)){
            //Pour chaque déplacement possible
            for(k=0; k<N; k++){
              for(l=0; l<N; l++){
                if(plateau[k][l].valeur == -1){
                  pionDebTemp->ligne = i;
                  pionDebTemp->colonne = j;
                  pionFinTemp->ligne = k;
                  pionFinTemp->colonne = l;
                  //on copie le plateau et le jeu
                  copiePlateau = copieTab2D(plateau);
                  copieJeu = copieTab3D(jeu, tour);
                  enleveCroix(copiePlateau);
                  //L'IA JOUE
                  deplacerPion(copiePlateau, *pionDebTemp, (evalMax ? joueur : (joueur == 1 ? 2 : 1)), *pionFinTemp);
                  if(tour > 1){
                    copieJeu = agrandiTab(copieJeu, tour);
                  }
                  copieJeu[tour] = copieTab2D(copiePlateau);
                  //on simule le coup de l'utilisateur
                  gainCourant = minMax(copiePlateau, copieJeu, tour+1, profondeur-1, pionDebTemp, pionFinTemp, joueur, !evalMax);
                  freeTab2D(copiePlateau);
                  freeTab3D(copieJeu, tour);
                  //on prend le maximum des gains de l'IA ou le minimum de son adversaire
                  if((evalMax && gainCourant > gainResultat) || (!evalMax && gainCourant < gainResultat) || gainResultat == -2000){
                    gainResultat = gainCourant;
                    pionDeb->ligne = i;
                    pionDeb->colonne = j;
                    pionFin->ligne = k;
                    pionFin->colonne = l;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  free(pionDebTemp);
  free(pionFinTemp);
  enleveCroix(plateau);
  return(gainResultat);
}


int evaluerGain(s_pion** plateau, s_pion*** jeu, int tour, int joueur){
  int gain; //le gain selon l'état du platau
  if (aGagne(plateau, tour) == joueur){
    gain = 1500;
  } else {
    if (aGagne(plateau, tour) != joueur  &&  aGagne(plateau, tour) != 0){
      gain = -1500;
    } else {
      if (matchNul(jeu, tour)){
        gain = 0;
      } else {
        gain = calculGain(plateau, joueur);
      }
    }
  }
  return(gain);
}


int calculGain(s_pion** plateau, int joueur){
  int somme; //la somme des distances
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  somme = 0;
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      //on ajoute les distance des pion de l'IA depuis sa ligne d'arrivée
      if (plateau[i][j].joueur == joueur){
        if (joueur == 1){
          somme += (i==0 ? -100 : i);
        } else {
          somme += (i==9 ? -100 : N - 1 - i);
        }
      }
      //on retire les distance des pion de l'adversaire depuis sa ligne d'arrivée
      if (plateau[i][j].joueur != joueur  &&  plateau[i][j].joueur != 0){
        if (joueur == 1){
          somme -= i;
        } else {
          somme -= N - 1 - i;
        }
      }
    }
  }
  return(somme);
}
