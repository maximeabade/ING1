<?php
session_start();
// seuls les administrateurs peuvent accéder à cette page
if($_SESSION["profil"] != "admin"){
	header('Location: ../index.html');
}
?>
<html>
<head>
	<title>Charger fichier</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

	<div id="navbar" class="navbar">
		<ul>
		  <li><a href="profilAdmin.php">Profil</a></li>
		  <li><a class="active" href="./gererClubs.php">Gérer les clubs</a></li>
		  <li style="float:right"><a href="./deconnexion.php?connexion=out">Déconexion</a></li>
		</ul>
	</div>

	<div class="titre">
		<h1>Charger un fichier</h1>
	</div>

  <div class="affichage">

  <?php
    /*Fonction pour récupérer les clubs dans clubs.csv*/
    function construireTabClubs(){
      $row = 1;
      $tabClubs = array(); // tableau où seront stockés tous les clubs
			// on ouvre le fichier
      if (($handle = fopen("../csv/clubs.csv", "r")) !== FALSE) {
        while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
          $num = count($data);
          for ($c=0; $c < $num; $c++) {
						// pour chaque ligne, on stocke le club dans le tableau
            array_push($tabClubs, $data[$c]);
          }
          $row++;
        }
				// on ferme le fichier
        fclose($handle);
      }
      return($tabClubs);
    }


    /*Fonction pour afficher le tableau avec tous les clubs*/
    function afficherTabClubs(){
      $tabClubs = construireTabClubs();
      echo("<h4>Les clubs sont désormais :</h4>
      <ul>");
      foreach ($tabClubs as $club) {
        echo("<li>".$club."</li>");
      }
      echo("</ul><br/>");
    }


    /*Fonction pour vérifier que le fichier csv est au bon format*/
    function verifierBonFormat($fichier){
      $row = 1;
      $estBonFormat = 1; // bouléen qui indique si le fichier est au bon format (=1) ou non (=0)
			// on ouvre le fichier
      if (($handle = fopen($fichier, "r")) !== FALSE) {
        while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
          $num = count($data);
          for ($c=0; $c < $num; $c++) {
            $array = explode(";", $data[$c]);
						// si dans une ligne, il y a plus d'un club ou que la ligne est vide, le fichier n'est pas au bon format
            if((sizeof($array) != 1) || ($array[0] == "")){
              $estBonFormat = 0;
            }
          }
          $row++;
        }
				// on ferme le fichier
        fclose($handle);
      }
      return($estBonFormat);
    }


    $target_dir = "../csv/"; // le dossier dans lequel on va charger le fichier
    $target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]); // le nom du fichier
    $uploadOk = 1; // booléen qui indique si on peut tenter le charger le fichier (=1) ou non (=0)
    $fileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION)); // extension du fichier

		// on vérifie que l'utilisateur a bien chargé un fichier
    if (basename($_FILES["fileToUpload"]["name"]) == "") {
			echo("<h4>Vous n'avez sélectionné aucun fichier ...</h4>");
      $uploadOk = 0;
    }

    // on vérifie que le fichier n'a pas le même nom que l'ancien
    if (file_exists($target_file)) {
			// si c'est le cas on le renomme
      $target_file = $target_file."2";
    }

    // on vérifie qu'il n'est pas trop lourd
    if ($_FILES["fileToUpload"]["size"] > 500000) {
      echo("<h4>Le fichier est trop lourd ...</h4>");
      $uploadOk = 0;
    }

    // on vérifie que c'est bien un fichier .csv
    if($fileType != "csv") {
      echo("<h4>Nous n'acceptons que les fichier avec l'extension : .csv</h4>");
      $uploadOk = 0;
    }

    // on vérifie qu'il n'y a pas eu d'erreur
    if ($uploadOk == 0) {
      echo("<h4>Le fichier n'a pa pu être chargé...</h4>");
    // si tout est bon, on charge le fichier
    } else {
      if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
        // si le fichier a bien été chargé, on vérifie qu'il est au bon format
        if(verifierBonFormat($target_file)){
          echo("<h4>Le fichier ". htmlspecialchars( basename( $_FILES["fileToUpload"]["name"])). " a bien été chargé !</h4>");
          // on supprime l'ancien et on le remplace par le nouveau
          unlink("../csv/clubs.csv");
          rename($target_file, "../csv/clubs.csv");
          afficherTabClubs();
        } else {
					// si il n'est pas au bon format, on le supprime et on envoie un message d'erreur à l'utilisateur
          echo("<h4>Ce fichier n'est pas au bon format, il n'a pas pu être chargé...</h4>");
          unlink($target_file);
        }
      } else {
        echo("<h4>Il y a eu une erreur lors du chargement du fichier...</h4>");
      }
    }
  ?>

    <a href="gererClubs.php">Retour à la page précédente</a>
  </div>


</body>
