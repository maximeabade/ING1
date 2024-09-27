<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Enregistrer statistiques</title>
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

	<div class="affichage">

	  <?php
		// on vérifie que l'utilisateur a bien sélectionné un joueur
		if($_POST["joueur"] != ""){
			//ajout des statistiquesdans NomPrenom.csv
		  $nomCsv = $_POST["joueur"].".csv";
		  $fp = fopen("../csv/".$nomCsv, 'a+');
		  $array = array($_POST["buts"], $_POST["temps"]);
		  fputcsv($fp, $array, ";");
		  fclose($fp);
		  //affichage des statistiques
		  echo("<h4>Les statistiques suivantes viennent d'être sauvegardées :</h4>");
		  echo("<table border=1><tr><th>Joueur</th><th>Nombre de buts</th><th>Temps de jeu (min)</th></tr>");
		  echo("<tr><td>". $_POST["joueur"] ."</td><td>". $_POST["buts"] ."</td><td>". $_POST["temps"] ."</td></tr>");
		  echo("</table><br/>");
		} else {
			// si il n'a pas sélectionné de joueur, on le redirige vers la page ajouterStatistiquesavec un message d'erreur
			header('Location: ajouterStatistiques.php?FormError=true');
		}


	  ?>
	  <a href="ajouterStatistiques.php">Revenir à la page précédente</a>

	</div>

</body>
