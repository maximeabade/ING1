<html>
<head>
	<title>enregistrer un compte</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="../css/designGlobal.css" />
	<link rel="icon" type="image/png" href="../img/icon.png">
</head>
<body>

  <?php

		// on vérifie que tous les champs du formulaire ont bien été remplis
		if(($_POST["pseudo"] != "") && ($_POST["mdp"] != "") && ($_POST["profil"] != "")){
			// on ouvre le fichier dans lequel se trouve tous les identifiants et on y ajoute les nouveaux
			$fp = fopen('../csv/identifiant.csv', 'a+');
	    fputcsv($fp, $_POST,";");
	    fclose($fp);

			echo("<div class='affichage'>
				<h4>Le compte a bien été enregistré</h4>
				<a href='./connexion.php'>Revenir à la page précédente</a><br/>
				<a href='../index.html'>Revenir à l'accueil</a>
			</div>");

		} else {
			// si l'utilisateur a mal rempli le formulaire on retourne sur la page en lui affichant un message d'erreur
			header('Location: ajouterCompte.php?FormError=true');
		}



  ?>





</body>
