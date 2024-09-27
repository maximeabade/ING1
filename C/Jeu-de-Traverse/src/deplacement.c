/*!
 * \file deplacement.c
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief fonctions relatives aux déplacements d'un pion
 *
 *
 */

// Inclusion des librairies
#include "deplacement.h"



// Codes des fonctions

/*Fonction pour déplacer un pion*/
void deplacerPion(s_pion** tab, s_coord pion1, int joueur, s_coord pion2){
  //la case où le pion se déplace prend la valeur et l'appartenance du pion
  tab[pion2.ligne][pion2.colonne].valeur = tab[pion1.ligne][pion1.colonne].valeur;
  tab[pion2.ligne][pion2.colonne].joueur = joueur;
  //l'ancienne case est maintenant vide
  tab[pion1.ligne][pion1.colonne].valeur = 0;
  tab[pion1.ligne][pion1.colonne].joueur = 0;
}

/*Fonction qui cherche s'il un pion peut se déplacer*/
int deplacementsPossibles(s_pion** tab, s_coord pion){
  int estPossible; //variable booléenne qui indique si un déplacement est possible
  int estSaut; //variable booléenne qui indique si un déplacement avec saut est possible
  int estSimple; //variable booléenne qui indique si un déplacement simple est possible
  estSaut = deplacementPossiblesSaut(tab, pion);
  estSimple = deplacementsPossiblesSimples(tab, pion);
  if(estSaut ||  estSimple){
    estPossible = 1;
  } else {
    estPossible = 0;
  }
  return(estPossible);
}

/*Fonction qui cerche si un pion peut effectuer un déplacement simple*/
int deplacementsPossiblesSimples(s_pion** tab, s_coord pion){
	int estPossible; //variable booléenne qui indique si un déplacement simple est possible
	estPossible = 0;
	switch (tab[pion.ligne][pion.colonne].valeur) {
	case 1 :
    //dans le cas d'un carré
		if (deplacementsPossiblesSimplesCarre(tab, pion)){
			estPossible = 1;
		}
		break;
	case 2 :
    //dans le cas d'un triangle
		if (deplacementsPossiblesSimplesTriangle(tab, pion)){
			estPossible = 1;
		}
		break;
	case 3 :
    //dans le cas d'un losange
		if (deplacementsPossiblesSimplesLosange(tab, pion)){
			estPossible = 1;
		}
		break;
	case 4 :
    //dans le cas d'un cercle
		if (deplacementsPossiblesSimplesCercle(tab, pion)){
			estPossible = 1;
		}
		break;
	default :
		break;
	}
	return(estPossible);
}

/*Fonction qui cerche si un pion peut effectuer un déplacement avec saut*/
int deplacementPossiblesSaut(s_pion** tab, s_coord pion){
  int estPossible; //variable booléenne qui indique si un déplacement avec saut est possible
	estPossible = 0;
	switch (tab[pion.ligne][pion.colonne].valeur) {
	case 1 :
    //dans le cas d'un carré
		if (deplacementsPossiblesSautCarre(tab, pion)){
			estPossible = 1;
		}
		break;
	case 2 :
    //dans le cas d'un triangle
		if (deplacementsPossiblesSautTriangle(tab, pion)){
			estPossible = 1;
		}
		break;
	case 3 :
    //dans le cas d'un losange
    if (deplacementsPossiblesSautLosange(tab, pion)){
			estPossible = 1;
		}
		break;
	case 4 :
    //dans le cas d'un cercle
		if (deplacementsPossiblesSautCercle(tab, pion)){
			estPossible = 1;
		}
		break;
	default :
		break;
	}
	return(estPossible);
}

/*Fonction qui cherche tous les déplacement possibles simples pour un carré*/
int deplacementsPossiblesSimplesCarre(s_pion** tab, s_coord pion){
	int estPossible; //variable booléenne qui indique si un déplacement simple pour un carré est possible
	estPossible = 0;
	//déplacement en haut
	if (pion.ligne > 0  &&  tab[pion.ligne-1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne].valeur = -1;
	}
	//déplacement en bas
	if (pion.ligne < N-1	 &&  tab[pion.ligne+1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne].valeur = -1;
	}
	//déplacement à droite
	if (pion.colonne < N-2  &&  tab[pion.ligne][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne+1].valeur = -1;
	}
	//déplacement à gauche
	if (pion.colonne > 1	&&  tab[pion.ligne][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne-1].valeur = -1;
	}
	return(estPossible);
}

/*Fonction qui cherche tous les déplacement possibles simples pour un triangle*/
int deplacementsPossiblesSimplesTriangle(s_pion** tab, s_coord pion){
	int estPossible; //variable booléenne qui indique si un déplacement simple pour un triangle est possible
	estPossible = 0;
	//déplacement en bas
	if (pion.ligne < N-1	 &&  tab[pion.ligne+1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne].valeur = -1;
	}
	//déplacement en haut à droite
	if (pion.ligne > 0  &&  pion.colonne < N-2	 &&  tab[pion.ligne-1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (pion.ligne > 0  &&  pion.colonne > 1 &&  tab[pion.ligne-1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne-1].valeur = -1;
	}
	return(estPossible);
}

/*Fonction qui cherche tous les déplacement possibles simples pour un losange*/
int deplacementsPossiblesSimplesLosange(s_pion** tab, s_coord pion){
	int estPossible; //variable booléenne qui indique si un déplacement simple pour un losange est possible
	estPossible = 0;
	//déplacement en haut à droite
	if (pion.ligne > 0  &&  pion.colonne < N-2	 &&  tab[pion.ligne-1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (pion.ligne > 0  &&  pion.colonne > 1 &&  tab[pion.ligne-1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne-1].valeur = -1;
	}
	//déplacement en bas à droite
	if (pion.ligne < N-1	 &&  pion.colonne < N-2  &&	tab[pion.ligne+1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne+1].valeur = -1;
	}
	//déplacement en bas à gauche
	if (pion.ligne < N-1	 &&  pion.colonne > 1 &&  tab[pion.ligne+1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne-1].valeur = -1;
	}
	return(estPossible);
}

/*Fonction qui cherche tous les déplacement possibles simples pour un cercle*/
int deplacementsPossiblesSimplesCercle(s_pion** tab, s_coord pion){
	int estPossible; //variable booléenne qui indique si un déplacement simple pour un cercle est possible
	estPossible = 0;
	//déplacement en haut
	if (pion.ligne > 0  &&  tab[pion.ligne-1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne].valeur = -1;
	}
	//déplacement en bas
	if (pion.ligne < N-1	 &&  tab[pion.ligne+1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne].valeur = -1;
	}
	//déplacement à droite
	if (pion.colonne < N-2  &&  tab[pion.ligne][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne+1].valeur = -1;
	}
	//déplacement à gauche
	if (pion.colonne > 1	&&  tab[pion.ligne][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne-1].valeur = -1;
	}
	//déplacement en haut à droite
	if (pion.ligne > 0  &&  pion.colonne < N-2	 &&  tab[pion.ligne-1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (pion.ligne > 0  &&  pion.colonne > 1 &&  tab[pion.ligne-1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne-1].valeur = -1;
	}
	//déplacement en bas à droite
	if (pion.ligne < N-1	 &&  pion.colonne < N-2  &&	tab[pion.ligne+1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne+1].valeur = -1;
	}
	//déplacement en bas à gauche
	if (pion.ligne < N-1	 &&  pion.colonne > 1 &&  tab[pion.ligne+1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne-1].valeur = -1;
	}
	return(estPossible);
}

/*Fonction qui cherche tous les déplacement possibles avec saut pour un carré*/
int deplacementsPossiblesSautCarre(s_pion** tab, s_coord pion){
  int estPossible; //variable booléenne qui indique si un déplacement avec saut pour un carré est possible
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  s_coord pion2; //case d'arrivée du premier saut
  estPossible = 0;
  //saut en haut
	if (pion.ligne > 1  &&  tab[pion.ligne-1][pion.colonne].valeur != 0 && tab[pion.ligne-1][pion.colonne].valeur != -1 && tab[pion.ligne-2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne].valeur = -1;
	}
	//saut en bas
	if (pion.ligne < N-2	 &&  tab[pion.ligne+1][pion.colonne].valeur != 0 && tab[pion.ligne+1][pion.colonne].valeur != -1 && tab[pion.ligne+2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne].valeur = -1;
	}
	//saut à droite
	if (pion.colonne < N-3  &&  tab[pion.ligne][pion.colonne+1].valeur != 0 && tab[pion.ligne][pion.colonne+1].valeur != -1 && tab[pion.ligne][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne+2].valeur = -1;
	}
	//saut à gauche
	if (pion.colonne > 2 &&  tab[pion.ligne][pion.colonne-1].valeur != 0 && tab[pion.ligne][pion.colonne-1].valeur != -1 && tab[pion.ligne][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne-2].valeur = -1;
	}
  //tant qu'on peut faire un saut on regarde si un autre saut est possible
  if(estPossible == 1){
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
        if(tab[i][j].valeur == -1){
          pion2.ligne = i;
          pion2.colonne = j;
          estPossible = deplacementsPossiblesSautCarre(tab, pion2);
        }
      }
    }
  }
  return(estPossible);
}

/*Fonction qui cherche tous les déplacement possibles avec saut pour un triangle*/
int deplacementsPossiblesSautTriangle(s_pion** tab, s_coord pion){
  int estPossible; //variable booléenne qui indique si un déplacement avec saut pour un triangle est possible
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  s_coord pion2; //case d'arrivée du premier saut
  estPossible = 0;
  //saut en bas
	if (pion.ligne < N-2	 &&  tab[pion.ligne+1][pion.colonne].valeur != 0 && tab[pion.ligne+1][pion.colonne].valeur != -1 && tab[pion.ligne+2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne].valeur = -1;
	}
	//saut en haut à droite
	if (pion.ligne > 1  &&  pion.colonne < N-3	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (pion.ligne > 1  &&  pion.colonne > 2	&&  tab[pion.ligne-1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (pion.ligne > 1  &&  pion.colonne == N-2  &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0  &&	tab[pion.ligne-1][pion.colonne+1].valeur != -1  && tab[pion.ligne-2][pion.colonne+1].valeur != 0 && tab[pion.ligne-2][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.ligne+2].valeur = -1;
	}
	//saut en haut à gauche vers la colonne extérieure gauche
	if (pion.ligne > 1  &&  pion.colonne == 1	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != 0  &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1  &&	tab[pion.ligne-1][pion.colonne-2].valeur != 0  &&	 tab[pion.ligne-1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
  //tant qu'on peut faire un saut on regarde si un autre saut est possible
  if(estPossible == 1){
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
        if(tab[i][j].valeur == -1){
          pion2.ligne = i;
          pion2.colonne = j;
          estPossible = deplacementsPossiblesSautTriangle(tab, pion2);
        }
      }
    }
  }
  return(estPossible);
}

/*Fonction qui cherche tous les déplacement possibles avec saut pour un losange*/
int deplacementsPossiblesSautLosange(s_pion** tab, s_coord pion){
  int estPossible; //variable booléenne qui indique si un déplacement avec saut pour un losange est possible
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  s_coord pion2; //case d'arrivée du premier saut
  estPossible = 0;
  //saut en haut à droite
	if (pion.ligne > 1  &&  pion.colonne < N-3	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (pion.ligne > 1  &&  pion.colonne > 2	&&  tab[pion.ligne-1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
	//saut en bas à droite
	if (pion.ligne < N-2	 &&  pion.colonne < N-3  &&	tab[pion.ligne+1][pion.colonne+1].valeur != 0  &&	 tab[pion.ligne+1][pion.colonne+1].valeur != -1  &&	tab[pion.ligne+2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne+2].valeur = -1;
	}
	//saut en bas à gauche
	if (pion.ligne < N-2	 &&  pion.colonne > 2	 &&  tab[pion.ligne+1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne+1][pion.colonne-1].valeur != -1  &&  tab[pion.ligne+2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (pion.ligne > 1  &&  pion.colonne == N-2  &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0  &&	tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+1].valeur  !=0  &&  tab[pion.ligne-2][pion.colonne+1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
  //saut en haut à gauche vers la colonne extérieure gauche
	if (pion.ligne > 1  &&  pion.colonne == 1	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != 0  &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1  &&	tab[pion.ligne-1][pion.colonne-2].valeur != 0  &&	 tab[pion.ligne-1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
  //saut en bas à droite vers la colonne extérieure droite
	if (pion.ligne < N-2	 &&  pion.colonne == N-2  &&	 tab[pion.ligne+1][pion.colonne+1].valeur != 0  &&  tab[pion.ligne+1][pion.colonne+1].valeur != -1	&& tab[pion.ligne+2][pion.colonne+1].valeur  != 0	&&  tab[pion.ligne+2][pion.colonne+1].valeur  != -1  &&  tab[pion.ligne+2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne+2].valeur = -1;
	}
  //saut en bas à gauche vers la colonne extérieure gauche
	if (pion.ligne < N-2	 &&  pion.colonne == 1  &&  tab[pion.ligne+1][pion.colonne-1].valeur != 0  &&	tab[pion.ligne+1][pion.colonne-1].valeur != -1  &&  tab[pion.ligne+1][pion.colonne-2].valeur != 0	 &&  tab[pion.ligne+1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne+2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne-2].valeur = -1;
	}
  //tant qu'on peut faire un saut on regarde si un autre saut est possible
  if(estPossible == 1){
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
        if(tab[i][j].valeur == -1){
          pion2.ligne = i;
          pion2.colonne = j;
          estPossible = deplacementsPossiblesSautLosange(tab, pion2);
        }
      }
    }
  }
  return(estPossible);
}

/*Fonction qui cherche tous les déplacement possibles avec saut pour un cercle*/
int deplacementsPossiblesSautCercle(s_pion** tab, s_coord pion){
  int estPossible; //variable booléenne qui indique si un déplacement avec saut pour un cercle est possible
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  s_coord pion2; //case d'arrivée du premier saut
  estPossible = 0;
  //saut en haut
	if (pion.ligne > 1  &&  tab[pion.ligne-1][pion.colonne].valeur != 0 && tab[pion.ligne-1][pion.colonne].valeur != -1 && tab[pion.ligne-2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne].valeur = -1;
	}
	//saut en bas
	if (pion.ligne < N-2	 &&  tab[pion.ligne+1][pion.colonne].valeur != 0 && tab[pion.ligne+1][pion.colonne].valeur != -1 && tab[pion.ligne+2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne].valeur = -1;
	}
	//saut à droite
	if (pion.colonne < N-3  &&  tab[pion.ligne][pion.colonne+1].valeur != 0 && tab[pion.ligne][pion.colonne+1].valeur != -1 && tab[pion.ligne][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne+2].valeur = -1;
	}
	//saut à gauche
	if (pion.colonne > 2 &&  tab[pion.ligne][pion.colonne-1].valeur != 0 && tab[pion.ligne][pion.colonne-1].valeur != -1 && tab[pion.ligne][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne-2].valeur = -1;
	}
	//saut en haut à droite
	if (pion.ligne > 1  &&  pion.colonne < N-3	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (pion.ligne > 1  &&  pion.colonne > 2	&&  tab[pion.ligne-1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
	//saut en bas à droite
	if (pion.ligne < N-2	 &&  pion.colonne < N-3  &&	tab[pion.ligne+1][pion.colonne+1].valeur != 0  &&	 tab[pion.ligne+1][pion.colonne+1].valeur != -1  &&	tab[pion.ligne+2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne+2].valeur = -1;
	}
	//saut en bas à gauche
	if (pion.ligne < N-2	 &&  pion.colonne > 2	 &&  tab[pion.ligne+1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne+1][pion.colonne-1].valeur != -1  &&  tab[pion.ligne+2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (pion.ligne > 1  &&  pion.colonne == N-2  &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0  &&	tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+1].valeur  !=0  &&  tab[pion.ligne-2][pion.colonne+1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
  //saut en haut à gauche vers la colonne extérieure gauche
	if (pion.ligne > 1  &&  pion.colonne == 1	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != 0  &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1  &&	tab[pion.ligne-1][pion.colonne-2].valeur != 0  &&	 tab[pion.ligne-1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
  //saut en bas à droite vers la colonne extérieure droite
	if (pion.ligne < N-2	 &&  pion.colonne == N-2  &&	 tab[pion.ligne+1][pion.colonne+1].valeur != 0  &&  tab[pion.ligne+1][pion.colonne+1].valeur != -1	&& tab[pion.ligne+2][pion.colonne+1].valeur  != 0	&&  tab[pion.ligne+2][pion.colonne+1].valeur  != -1  &&  tab[pion.ligne+2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne+2].valeur = -1;
	}
  //saut en bas à gauche vers la colonne extérieure gauche
	if (pion.ligne < N-2	 &&  pion.colonne == 1  &&  tab[pion.ligne+1][pion.colonne-1].valeur != 0  &&	tab[pion.ligne+1][pion.colonne-1].valeur != -1  &&  tab[pion.ligne+1][pion.colonne-2].valeur != 0	 &&  tab[pion.ligne+1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne+2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne-2].valeur = -1;
	}
  //tant qu'on peut faire un saut on regarde si un autre saut est possible
  if(estPossible == 1){
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
        if(tab[i][j].valeur == -1){
          pion2.ligne = i;
          pion2.colonne = j;
          estPossible = deplacementsPossiblesSautCercle(tab, pion2);
        }
      }
    }
  }
  return(estPossible);
}
