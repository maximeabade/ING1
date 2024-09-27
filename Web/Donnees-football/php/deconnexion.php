<?php
session_start();
?>
<html>
<head>
	<title>Déconnexion</title>
	<meta charset="utf-8">
</head>
<body>

  <?php
    if($_GET["connexion"] == "out"){
			// on supprime la session de l'utilisateur
      session_destroy();
			$_SESSION = array();
    }
		// on redirige l'utilisateur vers l'accueil
    header('Location: ../index.html');
  ?>


</body>
