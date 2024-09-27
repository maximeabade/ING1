<?php
session_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Accueil</title>
</head>
<body>
    <?php
      /*Fonction pour récupérer les info dans le infoEleves.csv*/
      function construireTabEleves(){
        $row = 1;
        $tabEleves = array();
        if (($handle = fopen("infoEleves.csv", "r")) !== FALSE) {
          while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
            $num = count($data);
            for ($c=0; $c < $num; $c++) {
              $array = explode(";", $data[$c]);
              array_push($tabEleves, array($array[0], $array[1], $array[2], $array[3], $array[4], $array[5], $array[6]));
            }
            $row++;
          }
          fclose($handle);
        }
        return($tabEleves);
      }

      /*Fonction pour récupérer les info dans le infoProfesseurs.csv*/
      function construireTabProfs(){
        $row = 1;
        $tabProfs = array();
        if (($handle = fopen("infoProfesseurs.csv", "r")) !== FALSE) {
          while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
            $num = count($data);
            for ($c=0; $c < $num; $c++) {
              $array = explode(";", $data[$c]);
              array_push($tabProfs, array($array[0], $array[1], $array[2], $array[3], $array[4]));
            }
            $row++;
          }
          fclose($handle);
        }
        return($tabProfs);
      }

      /*Fonction pour afficher le tableau de tous les élèves*/
      function afficherTabEleves(){
        $tabEleves = construireTabEleves();
        echo("<h4>Informations sur les élèves :</h4>");
        echo("<table border=1><tr><th>Nom</th><th>Prénom</th><th>Date de naissance</th><th>Maison</th><th>Nombre de points</th><th>Login</th><th>Mot de passe</th></tr>");
        foreach ($tabEleves as $eleve) {
          echo("<tr>");
          foreach ($eleve as $value) {
            echo("<td> $value </td>");
          }
          echo("</tr>");
        }
        echo("</table><br/>");
      }

      /*Fonction pour afficher le tableau de tous les professeurs*/
      function afficherTabProfs(){
        $tabProfs = construireTabProfs();
        echo("<h4>Informations sur les professeurs :</h4>");
        echo("<table border=1><tr><th>Nom</th><th>Prénom</th><th>Matière</th><th>Login</th><th>Mot de passe</th></tr>");
        foreach ($tabProfs as $prof) {
          echo("<tr>");
          foreach ($prof as $value) {
            echo("<td> $value </td>");
          }
          echo("</tr>");
        }
        echo("</table><br/>");
      }

      if($_GET["connexion"] == "ok") {
        echo("<h2>Profil ".$_SESSION["statut"]."</h2>");
        echo("<h4>Bienvenue ".$_SESSION["prenom"]." ".$_SESSION["nom"]."</h4>");
        if($_SESSION["statut"] == "élève"){
          echo("<p>Vous êtes né le : ".$_SESSION["date"]."</p><p>Vous êtes dans la maison ".$_SESSION["maison"]."</p><p>Vous avez actuellement ".$_SESSION["points"]." points</p><p>Votre pseudo est : ".$_SESSION["login"]."</p>");
        } else {
          if($_SESSION["statut"] == "professeur"){
            echo("<p>Vous enseignez la matières ".$_SESSION["matiere"]."</p><p>Votre pseudo est : ".$_SESSION["login"]."</p>");
          } else {
            afficherTabEleves();
            afficherTabProfs();
          }
        }
        echo("<form method='POST' action='index.php'><input type='submit' name='OUT' value='déconnexion'/></form>");
      } else {
        echo("Vous ne vous êtes pas connecté ...");
        echo("<br/><a href='index.php'>Conectez-vous<a>");
      }
    ?>



</body>
</html>
