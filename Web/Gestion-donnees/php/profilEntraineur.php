<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Profil Entraineur</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<div id="navbar" class="navbar">
		<ul>
		  <li><a class="active" href="profilEntraineur.php">Profil</a></li>
		  <li><a href="gererJoueurs.php">Gérer les joueurs</a></li>
		  <li><a href="gererStatistiques.php">Gérer les statistiques</a></li>
		  <li style="float:right"><a href="./deconnexion.php?connexion=out">Déconexion</a></li>
		</ul>
	</div>

	<div class="titre">
		<?php
			echo("<h1>Bienvenue ".$_SESSION["identifiant"]." ! Vous êtes dans le profil entraineur :</h1>");
		?>
	</div>

	<div class="affichage">
		<h4>Que voulez-vous faire ?</h4>
		<ul>
			<li><a href="gererJoueurs.php">Gérer les joueurs</a></li>
			<li><a href="gererStatistiques.php">Gérer les statistiques</a></li>
			<li><a href="modifierProfil.php">Modifier le profil</a></li>
		</ul>


	</div>

</body>
