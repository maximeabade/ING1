<?php
session_start();
?>
<html>
<head>
	<title>Afficher statistiques</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

  <?php

		/* Fonction pour récupérer toutes les statistiques d'un joueur */
		function construireTabStat($nomCsv){
	    $row = 1;
	    $tabStat = array(); //tableau dans lequel on va stocker les statistiques
			// on ouvre le fichier csv correspondant au joueur
	    if (($handle = fopen($nomCsv, "r")) !== FALSE) {
	      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
	        $num = count($data);
	        for ($c=0; $c < $num; $c++) {
						// pour chaque ligne, on récupère les données séparées par des ";"
	          $array = explode(";", $data[$c]);
						// on ajoute les statistiques au tableau
	          array_push($tabStat, array($array[0], $array[1]));
	        }
	        $row++;
	      }
				// on ferme le fichier
	      fclose($handle);
	    }
	    return($tabStat);
	  }


	  $nomCsv = "../csv/".$_POST["nom"].$_POST["prenom"].".csv";

		// on regarde si le joueur a un csv à son nom
	  if(file_exists($nomCsv)){
	    echo("<h4>Les statistiques du joueur ".$_POST["nom"]." ".$_POST["prenom"]." sont les suivantes :</h4>");
			// on construit le tableau et on affiches toutes les statistiques
			$tabStat = construireTabStat($nomCsv);
	    echo("<table><tr><th>Nombre de buts</th><th>Temps de jeu</th></tr>");
	    foreach ($tabStat as $match) {
	      echo("<tr>");
	      foreach ($match as $stat) {
	        echo("<td>". $stat ."</td>");
	      }
	      echo("</tr>");
	    }
	    echo("</table><br/>");
	  } else {
			// si le joueur n'a pas de fichier csv à son nom, on l'indique à l'utilisateur
	    echo("<h4>Il n'existe pas de fichier à ce nom...</h4>");
	  }


  ?>


</body>
