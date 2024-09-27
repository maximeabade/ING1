# Site gestion de donées : fichiers csv

## Présentation du projet :

  Le projet est un site web de statistiques de joueurs de football.

  Vous pouvez retrouver ce projet en ligne à l'adresse : https://football.justine-ribas.com
  Il sera au moins disponible jusqu'aux vacances d'été 2021.

  Vous pouvez aussi le retrouver sur gitLab grâce à l'url : https://gitlab.etude.eisti.fr/ribasjusti/tp_note_serveur.git



## Arborescence du projet :

  -Dossier "css" : là où se trouve tous le fichier .css
  chaque page aura le même style, j'ai donc créer un unique fichier css : "designGlobal.css"

  -Dossier "js" : là où se trouvent tous les fichiers .js
  chaque fichier .js porte le même nom que le fichier .php auquel il est associé
  chaque fichier .js est exclusivement utilisé pour l'AJAX

  -Dossier "img" : là où se trouvent toutes les images utilisées dans l'ensemble du projet
  On y trouve l'icône de ballon de foot (présente sur chaque onglet) que j'ai récupérée sur internet :
      - https://image.flaticon.com/icons/png/512/33/33736.png

  -Dossier "php" : là où se trouvent tous les fichiers .php



## Manuel utilisateur :

Pour commencer à naviguer sur le site, il faut accéder à la page index.html.
Vous verrez une page d'accueil avec 2 possibilités :

- 1ère possibilité : "Créer un compte"
Vous accéderez à une page contenant un formulaire pour créer un nouveau compte.
Chacun des champs du formulaire (identifiant, mot de passe, profil) sont obligatoires. Si vous en laissez un vide, le compte ne sera pas créer.
Lors de la validation de la création d'un compte, les informations sont stockées dans le fichier "identifiant.csv".
Vous pouvez ensuite créer un nouveau compte ou retourner à l'accueil

- 2ème possibilité : "Connexion"
Vous accéderez à un portail de connexion où vous devrez saisir votre identifiant et mot de passe.
Si les identifiant et / ou mot de passe sont incorrects, vous restez sur la page.


Une fois connecté, votre session s'ouvre et vous accédez à votre page profil :



### Profil "joueur" 

Vous avez accès à 3 onglets dans la barre de navigation : "Profil", "Rechercher des statistiques" et "Déconnexion"

- Onglet "Profil". Vous avez accès à un menu dont les choix sont :
  - "Modifier le profil"
    Vous pourrez modifier votre identifiant et / ou votre mot de passe
  - "Rechercher des statistiques"
    Vous accéderez à une page permettant de rechercher les caractéristiques de joueurs


- Onglet "Rechercher des statistiques". Vous avez accès à une page permettant de rechercher les caractéristiques de joueurs
  Vous pouvez rechercher un joueur avec son nom et son prénom.
  Si des statistiques lui sont attribuées, elle s'afficheront juste en dessous du formulaire


- Onglet "Déconnexion".
  Votre session sera fermée et vous serez redirigez vers la page d'accueil.


### Profil "entraineur"
Vous avez accès à 4 onglets dans la barre de navigation : "Profil", "Gérer les joueurs", "Gérer les statistiques" et "Déconnexion"


- Onglet "Profil". Vous avez accès à un menu dont les choix sont :
  - "Modifier le profil"
Vous pourrez modifier votre identifiant et / ou votre mot de passe
  - "Gérer les joueurs"
Vous accéderez à une page avec un autre menu avec les différentes actions à réaliser sur les joueurs
  - "Gérer les statistiques"
Vous accéderez à une page avec un autre menu avec les différentes actions à réaliser sur les statistiques


- Onglet "Gérer les joueurs". Vous pouvez visualisez un tableau avec tous les joueurs et vous avez accès à un menu dont les choix sont :
  - "Ajouter un joueur"
Vous accéderez à un formulaire où vous pourrez remplir les informations de votre nouveau joueur.
Le nom, le prénom et le club sont des champs obligatoires.
Une fois votre joueur créé, les informations sont stockées dans le fichier "infoJoueurs.csv".
Vous pourrez également visualiser les informations de votre nouveau joueur dans un petit tableau.
  - "Modifier un joueur"
Vous aurez accès à une liste déroulante contenant tous les joueurs.
Lorsque vous cliquez sur un joueur, un formulaire apparaît. Vous pourrez ainsi modifier ses informations.
Une fois votre joueur modifié, les informations sont stockées dans le fichier "infoJoueurs.csv".
Vous pourrez également visualiser les nouvelles information de votre joueur dans un petit tableau.
  - "Supprimer un joueur"
Vous aurez accès à une liste déroulante contenant tous les joueurs.
Lorsque vous valider la suppression d'un joueur, les informations du joueur seront supprimées du fichier "infoJoueurs.csv".
De plus si le joueur avait un fichier avec ses statistiques, ce dernier sera également supprimé.


- Onglet "Gérer les joueurs". Vous avez accès à un menu dont les choix sont :
  - "Ajouter des statistiques"
Vous accéderez à un formulaire où vous pourrez remplir des statistiques et les associé à un joueur présent dans la liste déroulante.
Seul la sélection du joueur est obligatoire, vous pouvez laisser un nombre de but ou un temps de jeu vide.
Lors de la validation, un fichier "NomPrenom.csv" est créé.
    - "Rechercher des statistiques"
          Vous avez accès à une page permettant de rechercher les caractéristiques de joueurs
          Vous pouvez rechercher un joueur avec son nom et son prénom.
          Si des statistiques lui sont attribuées, elle s'afficheront juste en dessous du formulaire
    - "Modifier des statistiques"
          Vous avez accès à la liste déroulante contenant tous les joueurs qui possèdent des statistiques.
          Lorsque vous sélectionnez un joueur, le tableau contenant toutes les statistiques du joueur s'affiche.
          Dans chaque case, se trouve un champs pré-rempli que vous pouvez modifier.
          Lors de la validation, les nouvelles informations sont stockées dans "NomPrenom.csv".
    - "Supprimer des statistiques"
          Vous avez accès à la liste déroulante contenant tous les joueurs qui possèdent des statistiques.
          Lorsque vous sélectionnez un joueur, le tableau contenant toutes les statistiques du joueur s'affiche.
          Dans chaque ligne du tableau se trouve une case à cocher afin de supprimer cette ligne.
          Lors de la validation, les informations seront supprimées de "NomPrenom.csv".


  - Onglet "Déconnexion".
    Votre session sera fermée et vous serez redirigez vers la page d'accueil.




### Profil "administrateur"

Vous avez accès à 3 onglets dans la barre de navigation : "Profil", "Gérer les clubs" et "Déconnexion"


- Onglet "Profil". Vous avez accès à un menu dont les choix sont :
  - "Modifier le profil"
    Vous pourrez modifier votre identifiant et / ou votre mot de passe
  - "Gérer les clubs"
    Vous accéderez à une page pour modifier les clubs disponibles

- Onglet "Gérer les clubs". Vous pourrez visualiser une liste avec tous les clubs actuellement disponibles stockés dans le fichier "clubs.csv".
  Si vous le souhaitez, vous pouvez charger un nouveau fichier csv contenant d'autres clubs.
  Il vous suffit alors de sélectionner le bouton "choisir un fichier".
  
  Le fichier ne sera chargé que si il possède l'extension ".csv", si il n'est pas trop lourd et si il est au bon format.
  Pour être au bon format, il faut qu'il y ait exactement 1 club sur chaque ligne :

  "Chelsea
  PSG
  Liverpool"
                => bon format

  "Chelsea;PSG
  Liverpool"
              => mauvais format

  "Chelsea

  Liverpool"
              => mauvais format

  Si le fichier est bien chargé, il remplacera l'ancien.


- Onglet "Déconnexion".
Votre session sera fermée et vous serez redirigez vers la page d'accueil.



  /!\ Certaines pages ne peuvent être accessibles que par des entraîneurs, d'autres que par des administrateurs, d'autres par tous, ...
  Si vous tenter d'accéder à une page alors que vous n'êtes pas connecté avec le bon profil, vous serez rediriger vers l'accueil
