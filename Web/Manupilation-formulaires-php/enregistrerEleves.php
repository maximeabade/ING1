<!DOCTYPE html>
<html>
<head>
    <title>Enregistrer élèves</title>
</head>
<body>
  <?php
    //on ouvre le csv et on rentre les informations à l'intérieur
    $fp = fopen('./infoEleves.csv', 'a+');
    fputcsv($fp, $_POST,";");
    fclose($fp);
  ?>
  <h2>L'élève a bien été enregistré</h2>
  <a href="index.php">Revenir à la page précédente</a>
</body>
</html>
