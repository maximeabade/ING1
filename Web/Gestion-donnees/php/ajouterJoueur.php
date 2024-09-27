<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Ajouter Joueur</title>
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
		<h1>Ajouter un joueur</h1>
	</div>

  <form id="formulaire" method="post" action="enregistrerJoueurs.php" class="formulaire">
    <p>Nom * <input type="text" id="nom" name="nom"/></p>
    <p>Prénom * <input type="text" id="prenom" name="prenom"/></p>
    <p>Date de naissance <input type="date" id="date" name="date"/></p>
    <p>Poste <input type="text" id="poste" name="poste"/></p>

		<?php
	  /*Fonction pour récupérer les clubs dans clubs.csv*/
	  function construireTabClubs(){
	    $row = 1;
	    $tabClubs = array(); //tableau où sera stocké tous les clubs
			// on ouvre le fichier
	    if (($handle = fopen("../csv/clubs.csv", "r")) !== FALSE) {
	      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
	        $num = count($data);
	        for ($c=0; $c < $num; $c++) {
						// pour chaque ligne, on ajoute le club dans le tableau
						array_push($tabClubs, $data[$c]);
	        }
	        $row++;
	      }
				// on ferme le fichier
	      fclose($handle);
	    }
	    return($tabClubs);
	  }


	  $tabClubs = construireTabClubs();
		// on affiche tous les clubs dans une liste déroulante
	  echo("
	  <div id='listeClubs'>
			<p>Choisissez un club *<p>
		  <select size='5' name='club'>");
	  foreach ($tabClubs as $club) {
	    echo("<option value='".$club."'>".$club."</option>");
	  }

	  ?>
	      </select>
	    </div>
  	<p><input type="submit" value="Valider" id="boutonValider" class="btn"/></p>
  </form>

	<div class=affichage>
		<p>(*) : champs obligatoires</p>
		<?php
		// s'affiche seulement si il y a eu une erreur dans le remplissage du formulaire
		if(!empty($_GET)){
			echo("<p>Vous n'avez pas rempli tous les champs obligatoires...</p>");
		}
		?>
		<br/>
		<a href="gererJoueurs.php">Retour à la page précédente</a>
	</div>




</body>
