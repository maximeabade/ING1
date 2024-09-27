<?php
session_start();
?>
<html>
<head>
	<title>Modifier Joueur</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
  <link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>


  <?php
    /*Fonction pour récupérer les info du joueur sélectioné*/
    function rechercherInfosJoueur(){
      $row = 1;
      $joueur = explode(";", $_POST["joueur"]); // on récupère le nom et le prénom du joueur pour savoir quelle ligne modifier
      // on ouvre le fichier csv
      if (($handle = fopen("../csv/infoJoueurs.csv", "r")) !== FALSE) {
        while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
          $num = count($data);
          for ($c=0; $c < $num; $c++) {
            $array = explode(";", $data[$c]);
            // si on est à la ligne correspondant au joueur sélectionné
            if(($joueur[0] == $array[0]) && ($joueur[1] == $array[1])){
              $tabJoueur = $array;
            }
          }
          $row++;
        }
        // on ferme le fichier csv
        fclose($handle);
      }
      return($tabJoueur);
    }


    /*Fonction pour récupérer les clubs dans clubs.csv*/
	  function construireTabClubs(){
	    $row = 1;
	    $tabClubs = array();
	    if (($handle = fopen("../csv/clubs.csv", "r")) !== FALSE) {
	      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
	        $num = count($data);
	        for ($c=0; $c < $num; $c++) {
						array_push($tabClubs, $data[$c]);
	        }
	        $row++;
	      }
	      fclose($handle);
	    }
	    return($tabClubs);
	  }


    /*Fonction pour échanger deux cases d'un tableau*/
    function echangerCases($tabClubs, $clubJoueur){
      $i = 0;
      foreach ($tabClubs as $club) {
        if($club == $clubJoueur){
          $indice = $i;
        }
        $i ++;
      }
      $tmp = $tabClubs[$indice];
      $tabClubs[$indice] = $tabClubs[0];
      $tabClubs[0] = $tmp;

      return($tabClubs);
    }


    // on récupère les info du joueur pour "pré-remplir" le formulaire
    $tabJoueur = rechercherInfosJoueur();
    // on récupère les choix de clubs disponibles
    $tabClubs = construireTabClubs();
    // on échange deux case de tabClubs pour que la liste déroulante affiche en premier le club actuel du joueur
    $tabClubs = echangerCases($tabClubs, $tabJoueur[4]);
		// on affiche le formulaire pré rempli
    echo('<h4>Veuillez entrer vos modifications</h4>
    <p>Nom * <input type="text" name="nom" value="'.$tabJoueur[0].'"/></p>
    <p>Prénom * <input type="text" name="prenom" value="'.$tabJoueur[1].'"/></p>
    <p>Date de naissance <input type="date" name="date" value="'.$tabJoueur[2].'"/></p>
    <p>Poste <input type="text" name="poste" value="'.$tabJoueur[3].'"/></p>
    <p>Choisissez un club :<p>
    <select size="1" name="club">');
    foreach ($tabClubs as $club) {
	    echo("<option value='".$club."'>".$club."</option>");
	  }
  ?>

</body>
