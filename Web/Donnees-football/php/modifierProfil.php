<?php
session_start();
?>
<html>
<head>
	<title>Modifier le profil</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<?php
		//pour la navbar on doit vérifier si on est sur un profil entraieur, joueur ou admin
		switch ($_SESSION["profil"]) {
			case 'entraineur':
				echo("<div id='navbar' class='navbar'>
					<ul>
						<li><a class='active' href='profilEntraineur.php'>Profil</a></li>
						<li><a href='gererJoueurs.php'>Gérer les joueurs</a></li>
						<li><a href='gererStatistiques.php'>Gérer les statistiques</a></li>
						<li style='float:right'><a href='./deconnexion.php?connexion=out'>Déconexion</a></li>
					</ul>
				</div>");
				break;
			case 'joueur' :
				echo("<div id='navbar' class='navbar'>
					<ul>
						<li><a class='active' href='profilJoueur.php'>Profil</a></li>
						<li><a href='rechercherDesStatistiques.php'>Rechercher des statistiques</a></li>
						<li style='float:right'><a href='./deconnexion.php?connexion=out'>Déconexion</a></li>
					</ul>
				</div>");
				break;
			case 'admin' :
				echo("<div id='navbar' class='navbar'>
					<ul>
					  <li><a class='active' href='profilAdmin.php'>Profil</a></li>
					  <li><a href='./gererClubs.php'>Gérer les clubs</a></li>
					  <li style='float:right'><a href='./deconnexion.php?connexion=out'>Déconexion</a></li>
					</ul>
				</div>");
				break;
			default:
				echo("Erreur");
				break;
		}
	?>

	<div class="titre">
		<h1>Modifier le profil :</h1>
	</div>

  <form method='post' action='enregistrerModifProfil.php' class="formulaire">
    <h4>Veuillez entrer vos modifications</h4>

		<?php
			// on pré-remplie le formulaire
			echo("<p>Identifiant * <input type='text' name='pseudo' value='".$_SESSION["identifiant"]."'/></p>
		   <p>Mot de passe <input type='password' name='mdp'/></p>
			 <p style='font-size: 12px'>Si vous ne saisissez rien dans le champ 'mot de passe', il restera inchangé</p>");
		?>

    <p><input type='submit' value='Valider' class='btn'/></p>
		<p>(*) : champs obligatoires</p>
  </form>

	<div class='affichage'>
	<?php
	// s'affiche seulement si l'utilisateur n'a pas rentré d'identifiant
	if(!empty($_GET)){
		echo("<h4>Veuillez saisir un identifiant</h4>");
	}
	// pour retourner à la page précédente, il faut vérifier sur quel profil se trouve l'utilisateur afin de le renvoyer sur la bonne page
	switch ($_SESSION["profil"]) {
		case 'entraineur':
			echo("<a href='profilEntraineur.php'>Retour à la page précédente</a>");
			break;
		case 'joueur' :
			echo("<a href='profilJoueur.php'>Retour à la page précédente</a>");
			break;
		case 'admin' :
			echo("<a href='profilAdmin.php'>Retour à la page précédente</a>");
			break;
		default:
			echo("Erreur");
			break;
	}
	?>
</div>


</body>
