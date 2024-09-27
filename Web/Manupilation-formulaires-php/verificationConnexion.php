<!DOCTYPE html>
<html>
<head>
    <title>Vérification connexion</title>
</head>
<body>
  <?php

  /*Fonction pour récupérer les informations dans infoEleves.csv*/
  function recupInfoEleves(){
    $row = 1;
    $tabEleves = array();
    if (($handle = fopen("infoEleves.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          $array = explode(";", $data[$c]);
          $tabEleves += [$array[5] => $array[6]];
        }
        $row++;
      }
      fclose($handle);
    }
    return($tabEleves);
  }

  /*Fonction pour récupérer les informations dans infoProfesseurs.csv*/
  function recupInfoProfs(){
    $row = 1;
    $tabProfs = array();
    if (($handle = fopen("infoProfesseurs.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          $array = explode(";", $data[$c]);
          $tabProfs += [$array[3] => $array[4]];
        }
        $row++;
      }
      fclose($handle);
    }
    return($tabProfs);
  }

  /*Fonction pour récupérer les informations dans infoAdmin.csv*/
  function recupInfoAdmin(){
    $row = 1;
    $tabAdmin = array();
    if (($handle = fopen("infoAdmin.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          $array = explode(";", $data[$c]);
          $tabAdmin += [$array[2] => $array[3]];
        }
        $row++;
      }
      fclose($handle);
    }
    return($tabAdmin);
  }

  /*Fonction pour vérifier si l'identifiant et le mot de passe saisie correspondent à ceux inscrits dans infoEleves.csv*/
  function verificationEleves(){
    $tabEleves = recupInfoEleves();
    $ligne = -1;
    $i = 0;
    foreach ($tabEleves as $login => $mdp) {
      if($_POST["identifiant"] == $login  &&  $_POST["mdp"] == $mdp) {
        $ligne = $i;
      }
      $i ++;
    }
    return($ligne);
  }

  /*Fonction pour vérifier si l'identifiant et le mot de passe saisie correspondent à ceux inscrits dans infoProfesseurs.csv*/
  function verificationProfs(){
    $tabProfs = recupInfoProfs();
    $ligne = -1;
    $i = 0;
    foreach ($tabProfs as $login => $mdp) {
      if($_POST["identifiant"] == $login  &&  $_POST["mdp"] == $mdp) {
        $ligne = $i;
      }
      $i ++;
    }
    return($ligne);
  }

  /*Fonction pour vérifier si l'identifiant et le mot de passe saisie correspondent à ceux inscrits dans infoAdmin.csv*/
  function verificationAdmin(){
    $tabAdmin = recupInfoAdmin();
    $ligne = -1;
    $i = 0;
    foreach ($tabAdmin as $login => $mdp) {
      if($_POST["identifiant"] == $login  &&  $_POST["mdp"] == $mdp) {
        $ligne = $i;
      }
      $i ++;
    }
    return($ligne);
  }

  /*Fonction pour récupérer toutes les informations relatives à l'élève connecté*/
  function remplirInfoEleve($ligne) {
    $row = 1;
    session_start();
    if (($handle = fopen("infoEleves.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          if($row == $ligne+1){
            $array = explode(";", $data[$c]);
            $_SESSION["statut"]= "élève";
            $_SESSION["nom"]= $array[0];
            $_SESSION["prenom"]= $array[1];
            $_SESSION["date"]= $array[2];
            $_SESSION["maison"]= $array[3];
            $_SESSION["points"]= $array[4];
            $_SESSION["login"]= $array[5];
          }
        }
        $row++;
      }
      fclose($handle);
    }
  }

  /*Fonction pour récupérer toutes les informations relatives au professeur connecté*/
  function remplirInfoProfs($ligne) {
    session_start();
    $row = 1;
    if (($handle = fopen("infoProfesseurs.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          if($row == $ligne+1){
            $array = explode(";", $data[$c]);
            $_SESSION["statut"]= "professeur";
            $_SESSION["nom"]= $array[0];
            $_SESSION["prenom"]= $array[1];
            $_SESSION["matiere"]= $array[2];
            $_SESSION["login"]= $array[3];
          }
        }
        $row++;
      }
      fclose($handle);
    }
  }

  /*Fonction pour récupérer toutes les informations relatives à l'administrateur connecté*/
  function remplirInfoAdmin($ligne) {
    session_start();
    $row = 1;
    if (($handle = fopen("infoAdmin.csv", "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        for ($c=0; $c < $num; $c++) {
          if($row == $ligne+1){
            $array = explode(";", $data[$c]);
            $_SESSION["statut"]= "admin";
            $_SESSION["nom"]= $array[0];
            $_SESSION["prenom"]= $array[1];
          }
        }
        $row++;
      }
      fclose($handle);
    }
  }


  $estValide = 0;
  $ligneEleve = verificationEleves();
  $ligneProf = verificationProfs();
  $ligneAdmin = verificationAdmin();
  if($ligneEleve != -1){
    $estValide = 1;
    remplirInfoEleve($ligneEleve);
  } else {
    if($ligneProf != -1){
      $estValide = 1;
      remplirInfoProfs($ligneProf);
    } else {
      if($ligneAdmin != -1)
      $estValide = 1;
      remplirInfoAdmin($ligneAdmin);
    }
  }

  switch ($estValide) {
    case '0':
      header('Location: index.php?erreur=erreur');
      exit();
      break;
    case '1':
      header('Location: accueil.php?connexion=ok');
      exit();
      break;
      echo("erreur");
      break;
  }


  ?>
</body>
</html>
