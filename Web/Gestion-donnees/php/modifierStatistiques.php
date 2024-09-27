<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Modifier statistiques</title>
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

	<div class="titre">
		<h1>Modifier des statistiques</h1>
	</div>

  <form method="post" action="enregistrerModifStatistiques.php" class="formulaire" id="formulaire">
		<h4>Voici tous les joueurs qui ont des statistiques. Choisissez le joueur dont vous voulez modifier les statistiques</h4>
		<?php
		/*Fonction pour récupérer les nom et prénom du joueur dans le infoJoueurs.csv*/
		function construireTabJoueurs(){
			$row = 1;
			$tabJoueurs = array(); // tableau dans lequel sera stocké le nom et le prénom des joueurs possédant des statistiques
			// on ouvre le fichier
			if (($handle = fopen("../csv/infoJoueurs.csv", "r")) !== FALSE) {
				while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
					$num = count($data);
					for ($c=0; $c < $num; $c++) {
						$array = explode(";", $data[$c]);
						// pour chaque ligne on récupère le nom et le prénom des joueurs
						if(file_exists("../csv/".$array[0].$array[1].".csv")){
								// si le joueur possède des statistiques, on stocke les info dans le tableau
								$tabJoueurs += [$array[0] => $array[1]];
						}
					}
					$row++;
				}
				// on ferme le fichier
				fclose($handle);
			}
			return($tabJoueurs);
		}

		$tabJoueurs = construireTabJoueurs();
		// on affiche une liste déroulante contenant le nom et le prénom des joueur possédant des statistiques
		echo("
		<select size='5' name='joueur'>");
		foreach ($tabJoueurs as $nom => $prenom) {
			echo("<option id='".$nom.";".$prenom."' value='".$nom.";".$prenom."' onclick='selectJoueur(this)'>".$nom." ".$prenom."</option>");
		}
		?>
		</select>

		<div id="affichage"></div>

		<p><input type="submit" value="Valider" id="boutonValider" class="btn"/></p>
	</form>

	<?php
		if(!empty($_GET)){
			// s'affiche seulement si l'utilisateur n'a pas sélectionné de joueurs
			echo("<div class='affichage'><h4>Veuillez sélectionner un joueur</h4></div>");
		}
	?>


	<div class="affichage">
		<a href="gererStatistiques.php">Retour à la page précédente</a>
	</div>


	<script type="text/javascript" src="../js/modifierStatistiques.js"></script>
</body>
