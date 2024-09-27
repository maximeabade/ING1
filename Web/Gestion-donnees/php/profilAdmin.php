<?php
session_start();
// seuls les administrateurs peuvent accéder à cette page
if($_SESSION["profil"] != "admin"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Profil Administrateur</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<div id="navbar" class="navbar">
		<ul>
		  <li><a class="active" href="profilAdmin.php">Profil</a></li>
		  <li><a href="./gererClubs.php">Gérer les clubs</a></li>
		  <li style="float:right"><a href="./deconnexion.php?connexion=out">Déconexion</a></li>
		</ul>
	</div>

	<div class="titre">
		<?php
			echo("<h1>Bienvenue ".$_SESSION["identifiant"]." ! Vous êtes dans le profil Administrateur :</h1>");
		?>
	</div>

	<div class="affichage">
		<h4>Que voulez-vous faire ?</h4>
		<ul>
			<li><a href="./gererClubs.php">Gérer les clubs</a></li>
			<li><a href="./modifierProfil.php">Modifier le profil</a></li>
		</ul>


	</div>

</body>
