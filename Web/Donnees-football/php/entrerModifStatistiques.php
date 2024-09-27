<?php
session_start();
?>
<html>
<head>
	<title>Entrer modifications statistiques</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>

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
        fclose($handle);
      }
      return($tabStat);
    }


		$joueur = explode(";", $_POST["joueur"]);
  	$nomCsv = "../csv/".$joueur[0].$joueur[1].".csv";
		$i = 1;

		echo("<h4>Les statistiques du joueur ".$joueur[0]." ".$joueur[1]." sont les suivantes :</h4>");
		// on construit le tableau et on affiches toutes les statistiques
		$tabStat = construireTabStat($nomCsv);
		echo("<table><tr><th>Nombre de buts</th><th>Temps de jeu (min)</th></tr>");
		foreach ($tabStat as $match) {
			echo("<tr>
			<td><input type='text' name='buts".$i."' value='".$match[0]."'/></td>
			<td><input type='text' name='temps".$i."' value='".$match[1]."'/></td>
			</tr>");
			$i ++;
		}
		echo("</table>");
  ?>





</body>
