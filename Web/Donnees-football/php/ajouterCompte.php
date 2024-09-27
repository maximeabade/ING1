<html>
<head>
	<title>Creer un compte</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<div class="titre">
		<h1>Creer un compte :</h1>
	</div>

  <form id="formulaire" method="post" action="enregistrerCompte.php" class="formulaire">
    <p>Identifiant * <input type="text" id="pseudo" name="pseudo"/></p>
    <p>Mot de passe * <input type="password" id="mdp" name="mdp"/></p>
		<p>Choisissez votre type de profil * </p>
    <div id='listeProfils' class="liste">
      <select size='3' name='profil'>
        <option value="entraineur">Entraineur</option>
        <option value="joueur">Joueur</option>
				<option value="admin">Administrateur</option>
      </select>
    </div>
  	<p><input type="submit" value="Valider" id="boutonValider" class="btn"/></p>
  </form>

	<div class=affichage>
		<p>(*) : champs obligatoires</p>
	</div>

	<?php
		// s'affiche seulement si il y a eu une erreur dans le remplissage du formulaire
		if(!empty($_GET)){
			echo("<div class=affichage>
				<p>Vous n'avez pas rempli tous les champs obligatoires...</p>
			</div>");
		}
	?>

	<div class='affichage'>
		<a href='../index.html'>Retour à l'accueil</a>
	</div>


</body>
