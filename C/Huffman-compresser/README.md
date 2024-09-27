# Projet Huffman

## COMPILATION

  Pour compiler le programme, il faut executer la commande suivante à la racine du projet:
    ``` 
    make
    ```

  Pour nettoyer les fichiers générés pendant la compilation, il faut executer la commande suivante à la racine du projet:
    ``` 
    make clean
    ```

## EXECUTION

  Pour executer le programme, et afficher l'aide, il faut executer la commande suivante :
    ``` 
    ./huffman 
    ```

  Pour compresser un fichier, il faut executer :
    ``` 
    ./huffman -c ./fichiers/textDecompresse.txt ./fichiers/textCompresse.hfzip 
    ```

  Sinon, pour decompresser un fichier, il faut executer la commande suivante :
    ``` 
    ./huffman -d ./fichiers/textCompresse.hfzip ./fichiers/textDecompresse.txt 
    ```

## DOCUMENTATION

  Pour générer la documentation doxygen, il faut executer la commande suivante à la racine du projet:
    ``` 
    make doc 
    ```

  Pour visualiser la documentaion, il faut ouvrir dans un navigateur, le fichier "doc/html/index.html"
