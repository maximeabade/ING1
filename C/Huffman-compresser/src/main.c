/*! \file main.c
 *
 *  \author Amandine Legrand et Justine Ribas
 *  \version 0.1
 *  \date 06 Janvier 2020
 *
 *  \brief  contient la fonction principale
 *
 *
 */


// Inclusion des entêtes de librairies
#include "huffman.h"

int main(int argc, char** argv)
{
  //initialisation de l'ecran
  system("clear");

  //si l'utilisateur veut comporesser un fichier et respecte les conditions
  if(argc == 4 && !strcmp(argv[1], "-c")){
    compresser(argv[2], argv[3]);
  }
  else{
    //si l'utilisateur veut decomporesser un fichier et respecte les conditions
    if(argc == 4 && !strcmp(argv[1], "-d")){
      decompresser(argv[2], argv[3]);
    }
    else{
      //si l'utilisateur veut de l'aide
      if(argc == 2 && !strcmp(argv[1], "-h")){
        printf("Aide pour utiliser le programme de compression/décompression d'un fichier en utilisant la méthode de huffman.\n\nVeuillez appeler ./huffman avec les parametres suivants :\n\t-h\tPour afficher de l'aide.\n\t-c\tPour compresser un fichier, suivit du nom du fichier à compresser et du nom du nouveau fichier compressé qui sera créé.\n\t\t\texemple : ./huffman –c monfichier.txt monfichier.hfzip\n\t-d\tPour décompresser un fichier, suivit du nom du fichier compressé et du nom du nouveau fichier décompressé qui sera créé.\n\t\t\texemple : ./huffman –d monfichier.hfzip monfichier.txt\n\n");
      }
      //sinon, l'utilisateur c'est tompé dans les paramètres
      else{
        printf("Erreur d'appel.\nAfficher l'aide :\n\t./huffman -h\n\n");
      }
    }
  }
  return(0);
}
