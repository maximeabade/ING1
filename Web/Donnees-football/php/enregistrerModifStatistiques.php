<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Enregistrer modifications statistiques</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<div id="navbar" class="navbar">
		<ul>
		  <li><a href="profilEntraineur.php">Profil</a></li>
		  <li><a href="gererJoueurs.php">Gérer les joueurs</a></li>
		  <li><a class="active" href="gererStatistiques.php">Gérer les statistiques</a></li>
		  <li style="float:right"><a href="./deconnexion.php?connexion=out">Déconexion</a></li>
		</ul>
	</div>

  <div class="titre">
		<h1>Enregistrer modifications des statistiques</h1>
	</div>

  <div class="affichage">

  <?php

  /*Fonction pour modifier le fichier csv avec les nouvelles informations*/
  function modifierFichier($joueur){
    $row = 1;
    $donneesCsv = array(); // le tableau dans le quel on va stocker toutes les donées présentes dans le csv
    // on ouvre le fichier csv correspondant au joueur
    if (($handle = fopen("../csv/".$joueur[0].$joueur[1].".csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          // on récupère les données de chaque ligne
          $array = explode(";", $data[$c]);
					// on modifie les données à envoyer au nouveau fichier csv
					$array[0] = $_POST["buts".$row];
					$array[1] = $_POST["temps".$row];
          array_push($donneesCsv, array($array[0], $array[1]));
        }
        $row++;
      }
      // on ferme et on supprime l'ancien csv
      fclose($handle);
      unlink("../csv/".$joueur[0].$joueur[1].".csv");
    }
    // on crée un nouveau fichier csv, on y écrit toutes les nouvelles données
    $fp = fopen("../csv/".$joueur[0].$joueur[1].".csv", "a+");
    foreach ($donneesCsv as $ligne) {
      fputcsv($fp, $ligne, ";");
    }
    fclose($fp);
    return($donneesCsv);
  }


	// on vérifie que l'utilisateur a bien sélectionné un joueur
	if(!empty($_POST)){

		$joueur = explode(";", $_POST["joueur"]);
		$donneesCsv = modifierFichier($joueur);
		// on affiche dans un tableau, les nouvelles statistiques du joueur
	  echo("<h4>Désormais, les statistiques concernant le joueur ".$joueur[0]." ".$joueur[1]." sont :</h4>");
	  echo("<table border=1><tr><th>Nombre de buts</th><th>Temps de jeu (min)</th></tr>");
	  foreach ($donneesCsv as $ligne) {
	    echo("<tr>");
	    foreach ($ligne as $value) {
	      echo("<td>". $value ."</td>");
	    }
	    echo("</tr>");
	  }
	  echo("</table><br/>");
	} else {
		// si il n'a pas sélectionné de joueur, on le redirige vers la page modifierStatistiquesavec un message d'erreur
		header('Location: modifierStatistiques.php?FormError=true');
	}


  ?>

    <a href="./modifierStatistiques.php">Retour à la page précédente</a>

  </div>



</body>
