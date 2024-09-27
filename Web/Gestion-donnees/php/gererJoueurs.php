<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Gérer joueurs</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<div id="navbar" class="navbar">
		<ul>
		  <li><a href="profilEntraineur.php">Profil</a></li>
		  <li><a class="active" href="gererJoueurs.php">Gérer les joueurs</a></li>
		  <li><a href="gererStatistiques.php">Gérer les statistiques</a></li>
		  <li style="float:right"><a href="./deconnexion.php?connexion=out">Déconexion</a></li>
		</ul>
	</div>

	<div class="titre">
		<h1>Gérer les joueurs</h1>
	</div>

	<div class="affichage">
		<h4>Que voulez-vous faire ?</h4>
		<ul>
			<li><a href="ajouterJoueur.php">Ajouter un joueur</a></li>
			<li><a href="modifierJoueur.php">Modifier un joueur</a></li>
			<li><a href="supprimerJoueur.php">Supprimer un joueur</a></li>
		</ul>
	</div>

	<?php

	/*Fonction pour récupérer les info dans le infoJoueurs.csv*/
	function construireTabJoueurs(){
		$row = 1;
		$tabJoueurs = array(); // tableau dans lequel sera stocké toutes les informations des joueurs
		// on ouvre le fichier
		if (($handle = fopen("../csv/infoJoueurs.csv", "r")) !== FALSE) {
			while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
				$num = count($data);
				for ($c=0; $c < $num; $c++) {
					$array = explode(";", $data[$c]);
					// pour chaque ligne, on stocke les info dans le tableau
					array_push($tabJoueurs, array($array[0], $array[1], $array[2], $array[3], $array[4]));
				}
				$row++;
			}
			// on ferme le fichier
			fclose($handle);
		}
		return($tabJoueurs);
	}
	

	/*Fonction pour afficher le tableau de tous les élèves*/
	function afficherTabJoueurs(){
		$tabJoueurs = construireTabJoueurs();
		echo("<div class='affichage'><h4>Joueurs inscrits :</h4>");
		echo("<table border=1><tr><th>Nom</th><th>Prénom</th><th>Date de naissance</th><th>Poste</th><th>Club</th></tr>");
		foreach ($tabJoueurs as $joueur) {
			echo("<tr>");
			foreach ($joueur as $value) {
				echo("<td>". $value ."</td>");
			}
			echo("</tr>");
		}
		echo("</table></div>");
	}

	//on affiche les joueurs inscrits
	afficherTabJoueurs();

	?>


</body>
