<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Supprimer joueur</title>
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
		<h1>Supprimer un joueur</h1>
	</div>



	<form method='post' action='enregistrerSuppJoueur.php' class="formulaire">

		<h4>Sélectionnez un joueur *</h4>

    <?php
    /*Fonction pour récupérer les nom et prénom du joueur dans le infoJoueurs.csv*/
    function construireTabJoueurs(){
      $row = 1;
      $tabJoueurs = array(); // tableau dans lequel sera stocké tous les noms et prénoms des joueurs
			// on ouvre le fichier
      if (($handle = fopen("../csv/infoJoueurs.csv", "r")) !== FALSE) {
        while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
          $num = count($data);
          for ($c=0; $c < $num; $c++) {
            $array = explode(";", $data[$c]);
						// pour chaque ligne, on stocke le nom et le prénom dans le tableau
            $tabJoueurs += [$array[0] => $array[1]];
          }
          $row++;
        }
				// on ferme le fichier
        fclose($handle);
      }
      return($tabJoueurs);
    }

    $tabJoueurs = construireTabJoueurs();
		// on affiche une liste déroulante avec le nom et prénom de tous les joueurs
    echo("
    <select size='5' name='joueur'>");
    foreach ($tabJoueurs as $nom => $prenom) {
      echo("<option value='".$nom.";".$prenom."'>".$nom." ".$prenom."</option>");
    }
    ?>
    </select>

    <p><input type='submit' value='Valider' class='btn'/></p>

  </form>

	<div class='affichage'>
		<p>(*) : champs obligatoires</p>
		<?php
		// s'affiche seulement si l'utilisateur n'a pas sélectionné de joueur
		if(!empty($_GET)){
			echo("<h4>Veuillez sélectionner un joueur</h4>");
		}
		?>
		<br/>
		<a href="./gererJoueurs.php">Retour à la page précédente</a>
	</div>


</body>
