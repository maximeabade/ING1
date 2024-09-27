<?php
session_start();
// seuls les entraineurs peuvent accéder à cette page
if($_SESSION["profil"] != "entraineur"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Modifier Joueur</title>
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
		<h1>Modifier le profil d'un joueur</h1>
	</div>

  <form method='post' action='enregistrerModifJoueur.php' class="formulaire" style="margin-top: 10px">
    <div id="blocsFormulaire">
      <h4>Veuillez sélectioner un joueur *</h4>
      <div id='listeJoueurs'>
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
							// pour chaque ligne on récupère le nom et le prénom et on les stocke dans le tableau
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
			// on affiche la liste déroulante de tous les joueurs
      echo("
      <select size='5' name='joueur'>");
      foreach ($tabJoueurs as $nom => $prenom) {
        echo("<option id='".$nom.";".$prenom."' value='".$nom.";".$prenom."' onclick='selectJoueur(this)'>".$nom." ".$prenom."</option>");
      }
      ?>
        </select>
      </div>
      <br/>

      <div id="champFormulaire"></div>

      <p><input type='submit' value='Valider' class='btn'/></p>
    </div>
		<p>(*) : champs obligatoires</p>
  </form>


	<?php
	// s'affiche seulement si il y a eu une erreur dans le remplissage du formulaire
	if(!empty($_GET)){
		echo("<div class=affichage>
			<p>Vous n'avez pas rempli tous les champs obligatoires... Veuillez recommencer</p>
		</div>");
	}
	?>

	<div class="affichage" style="margin-top: 1px">
		<a href="gererJoueurs.php">Retour vers la page précédente</a>
	</div>

	<script type="text/javascript" src="../js/modifierJoueur.js"></script>
</body>
