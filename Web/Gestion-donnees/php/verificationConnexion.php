<html>
<head>
	<title>Vérification Connexion</title>
	<meta charset="utf-8">
</head>
<body>

  <?php
  /*Fonction pour récupérer les nom et prénom du joueur dans le identifiant.csv*/
  function construireTabIdentifiants(){
    $row = 1;
    $tabIdentifiants = array(); // tableau contenant tous les identifiant et mot de passe
		// on ouvre le fichier
    if (($handle = fopen("../csv/identifiant.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          $array = explode(";", $data[$c]);
					// pour chaque ligne, on récupère les infos et on les stocke dans le tableau
          $tabIdentifiants += [$array[0] => $array[1]];
        }
        $row++;
      }
			// on ferme le fichier
      fclose($handle);
    }
    return($tabIdentifiants);
  }


	/*Fonction pour récupérer toutes les informations relatives à l'utilisateur connecté*/
	function remplirInfoUtilisateur(){
		// on ouvre la session de l'utilisateur
		session_start();
		$row = 1;
		// on ouvre le fichier
		if (($handle = fopen("../csv/identifiant.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          $array = explode(";", $data[$c]);
					// pour chaque ligne on vérifie si cela correspond à l'dentifiant et au mot de passe de l'utilisateur
          if($array[0] == $_POST["pseudo"]  &&  $array[1] == $_POST["mdp"]){
						// si c'est le cas on rempli les information le concernant
            $_SESSION["identifiant"] = $array[0];
            $_SESSION["mdp"] = $array[1];
						$_SESSION["profil"] = $array[2];
          }
        }
        $row++;
      }
			// on ferme le fichier
      fclose($handle);
    }
	}


  $estCorrect = 0;
  $tabIdentifiants = construireTabIdentifiants();
	// on compare les valeurs entrées par l'utilisateurs à tous les identifiants et mots de passe
  foreach ($tabIdentifiants as $pseudo => $mdp) {
    if($pseudo == $_POST["pseudo"]  &&  $mdp == $_POST["mdp"]){
			// si il y a un identifiant et un mot de passe correspondnat, on valide la connexion
      $estCorrect = 1;
    }
  }
	// si la connexion est correcte, on redirige l'utilisateur vers sa page profil
  if($estCorrect == 1){
		remplirInfoUtilisateur();
		switch ($_SESSION["profil"]) {
			case 'entraineur':
				header('Location: profilEntraineur.php');
				break;
			case 'joueur' :
				header('Location: profilJoueur.php');
				break;
			case 'admin' :
				header('Location: profilAdmin.php');
				break;
			default:
				echo("Erreur");
				break;
		}
  } else {
		// si la connexion n'est pas valide, on lui envoie un message d'erreur
    header('Location: connexion.php?LoginError=true');
  }

  ?>


</body>
