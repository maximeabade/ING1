<?php
session_start();
// seuls les entraineurs et les joueurs peuvent accéder à cette page
if($_SESSION["profil"] == "admin"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Rechercher des statistiques</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<?php
		//pour la navbar on doit vérifier si on est sur un profil entraieur ou joueur
		if($_SESSION["profil"]=="joueur"){
			echo("<div id='navbar' class='navbar'>
				<ul>
					<li><a href='profilJoueur.php'>Profil</a></li>
					<li><a class='active' href='rechercherDesStatistiques.php'>Rechercher des statistiques</a></li>
					<li style='float:right'><a href='./deconnexion.php?connexion=out'>Déconexion</a></li>
				</ul>
			</div>");
		} else {
			echo("<div id='navbar' class='navbar'>
				<ul>
					<li><a href='profilEntraineur.php'>Profil</a></li>
					<li><a href='gererJoueurs.php'>Gérer les joueurs</a></li>
					<li><a class='active' href='gererStatistiques.php'>Gérer les statistiques</a></li>
					<li style='float:right'><a href='./deconnexion.php?connexion=out'>Déconexion</a></li>
				</ul>
			</div>");
		}
	?>


	<div class="titre">
		<h1>Rechercher les statistiques du joueur :</h1>
	</div>

 	<div class="formulaire">
		<p>Nom : <input type="text" id="nom" name="nom"/></p>
	  <p>Prénom : <input type="text" id="prenom" name="prenom"/></p>
		<p><input type="submit" value="Valider" id="boutonValider" class="btn" onclick="rechercher()"/></p>
	</div>

  <div id="affichage" class="affichage"></div>

	<?php
		// seul un entraîneur peut retourner à la page précédente 
		if($_SESSION["profil"] == "entraineur"){
			echo('<div class="affichage">
				<a href="gererStatistiques.php">Retour à la page précédente</a>
			</div>');
		}
	?>


  <script type="text/javascript" src="../js/rechercherDesStatistiques.js"></script>
</body>
