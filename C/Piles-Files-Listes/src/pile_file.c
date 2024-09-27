/*!
 * \file pile_file.c
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 05 avril 2020
 *
 * \brief les fonctions relatives aux piles et aux files
 *
 *
 */



/*Partie 2 : Question 1*/

/*! \struct s_elementF
 * Structure qui défini chaque élément de la file associé au pointeur de l'élément précédent
 */
typedef struct s_elementF s_elementF;
struct s_elementF
{
	int valeur; /*!< la valeur l'élément de la file */
	s_elementF* precedent; /*!< le pointeur vers l'élément précédent */
};

/*! \struct s_file
 * Structure qui défini une file avec les pointeurs des éléments
 */
typedef struct
{
	s_elementF* tete; /*!< le pointeur de l'élément en tête de la file */
} s_file;

/**
 *\fn int estEgale(s_file* file1, s_file* file2)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 05 avril 2020
 *
 *\brief permet de savoir si deux files sont égales
 *
 *
 *\param file1 la première file à comparer
 *\param file2 la deuxième file à comparer
 *\return 1 si elles sont égales, 0 sinon
 *
 */
int estEgale(s_file* file1, s_file* file2);

int estEgale(s_file* file1, s_file* file2)
{
  s_elementF* actuel1; //l'élément actuel de la file 1
  s_elementF* actuel2; //l'élément actuel de la file 2
  int sontEgales; //varaible booléenne
  if (estVide(file1) && estVide(file2)){
    sontEgales = 1;
  } else {
    if ( (estVide(file1) && !estVide(file2)) || (!estVide(file1) && estVide(file2))){
      sontEgales = 0;
    } else {
      actuel1 = tete(file1);
      actuel2 = tete(file2);
      sontEgales = 1;
      while (!estVide(file1)  &&  !estVide(file2)){
        if (actuel1->valeur != actuel2->valeur){
          sontEgales = 0;
        }
        defiler(file1);
        actuel1 = tete(file1);
        defiler(file2);
        actuel2 = tete(file2);
      }
      if (!estVide(file1)  ||  !estVide(file2)){
        sontEgales = 0;
      }
    }
  }
  return(sontEgales);
}





/*Partie 2 : Question 2*/

/*! \struct s_elementP
 * Structure qui défini chaque élément de la file associé au pointeur de l'élément précédent
 */
typedef struct s_elementP s_elementP;
struct s_elementP
{
	int valeur; /*!< la valeur l'élément de la pile */
	s_elementP* suivant; /*!< le pointeur vers l'élément précédent */
};

/*! \struct s_pile
 * Structure qui défini une pile avec les pointeurs des éléments
 */
typedef struct
{
	s_elementP* sommet; /*!< le pointeur de l'élément en tête de la pile */
} s_pile;

/**
 *\fn s_pile* ajoutFond(s_pile* file, int x)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 05 avril 2020
 *
 *\brief permet d'ajouter un élément au fond de la pile
 *
 *
 *\param pile la pile dans laquelle on ajoute un élément
 *\param x la valeur à ajouter
 *\return la nouvelle pile
 *
 */
s_pile* ajoutFond(s_pile* file, int x);

s_pile* ajoutFond(s_pile* file, int x)
{
  s_pile* stock; //la pile où l'ont conserve les valeur dépilées
  if (estVide(pile)){
    empiler(pile, x);
  } else {
    stock = pileVide();
    while(!estVide(pile)){
      empile(stock, sommet(pile));
      depiler(pile);
    }
    empiler(pile, x);
    while (!estVide(stock)) {
      empile(pile, sommet(stock));
      depiler(stock);
    }
  }
  return(pile);
}
