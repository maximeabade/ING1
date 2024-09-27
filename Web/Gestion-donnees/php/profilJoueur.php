<?php
session_start();
// seuls les joueurs peuvent accéder à cette page
if($_SESSION["profil"] != "joueur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Connexion</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<div id="navbar" class="navbar">
		<ul>
			<li><a class="active" href="profilJoueur.php">Profil</a></li>
			<li><a href="rechercherDesStatistiques.php">Rechercher des statistiques</a></li>
			<li style="float:right"><a href="./deconnexion.php?connexion=out">Déconexion</a></li>
		</ul>
	</div>


  <div class="titre">
    <?php
			echo("<h1>Bienvenue ".$_SESSION["identifiant"]." ! Vous êtes dans le profil joueur :</h1>");
		?>
  </div>

	<div class="affichage">
		<h4>Que voulez-vous faire ?</h4>
		<ul>
			<li><a href="./rechercherDesStatistiques.php">Rechercher les statistiques d'un joueur</a></li>
			<li><a href="./modifierProfil.php">Modifier le profil</a></li>
		</ul>
	</div>


</body>
