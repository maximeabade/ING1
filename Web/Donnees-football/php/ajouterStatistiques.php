<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
    <title>Ajouter statistiques</title>
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
    <h1>Ajouter des statistiques</h1>
  </div>

  <form method='post' action='enregistrerStatistiques.php' class="formulaire">
    <div id="formulaire">
      <p>Nombre de Buts <input type='text' name='buts'/></p>
      <p>Temps de jeu (en min) <input type='text' name='temps'/></p>
    </div>

  <?php
  /*Fonction pour récupérer les nom et prénom du joueur dans le infoJoueurs.csv*/
  function construireTabJoueurs(){
    $row = 1;
    $tabJoueurs = array(); // tableau où seront stockés tous les noms et prénom des joueurs
		// on ouvre le fichier
    if (($handle = fopen("../csv/infoJoueurs.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
					// pour chaque ligne on récupère les information et on stocke le nom et le prénom dans le tableau
          $array = explode(";", $data[$c]);
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
	// on affiche le nom et le prénom de chaque joueur dans une liste déroulante
  echo("
  <div id='listeJoueurs'>
  <p>Sellectionnez un joueur *</p>
  <select size='5' name='joueur'>");
  foreach ($tabJoueurs as $nom => $prenom) {
    echo("<option value='".$nom.$prenom."'>".$nom." ".$prenom."</option>");
  }

  ?>
      </select>
    </div>
    <p><input type='submit' value='Valider' class='btn'/></p>
  </form>

  <div class="affichage">

    <?php
		// s'affiche seulement si l'utilisateur à valider l'envoi du formulaire sans sélèctionner de joueur
    if(!empty($_GET)){
      echo("<h4>Veuillez sélectionner un joueur</h4>");
    }
    ?>

  	<p>(*) : champs obligatoires</p><br/>
    <a href="gererStatistiques.php">Retour à la page précédente</a>
  </div>

</body>
</html>
