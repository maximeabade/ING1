<!DOCTYPE html>
<html>
<head>
    <title>Inscription élèves</title>
</head>
<body>
  <form id="formulaire" method="post" action="enregistrerEleves.php">
    <p>Nom : <input type="text" id="nom" name="nom"/></p>
    <p>Prénom : <input type="text" id="prenom" name="prenom"/></p>
    <p>Date de naissance : <input type="date" id="date" name="date"/></p>
    <p>Maison : <input type="text" id="maison" name="maison"/></p>
    <p>Total de points : <input type="text" id="points" name="points"/></p>
    <p>Pseudo : <input type="text" id="pseudo" name="pseudo"/></p>
    <p>Mot de passe : <input type="password" id="mdp" name="mdp"/></p>
  	<p><input type="submit" value="Valider" id="boutonValider" class="btn"/></p>
  </form>
</body>
</html>
