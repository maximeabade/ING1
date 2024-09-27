<!DOCTYPE html>
<html>
<head>
    <title>Inscription professeurs</title>
</head>
<body>
  <form id="formulaire" method="post" action="enregistrerProfesseurs.php">
    <p>Nom : <input type="text" id="nom" name="nom"/></p>
    <p>Prénom : <input type="text" id="prenom" name="prenom"/></p>
    <p>Matière : <input type="text" id="matiere" name="matiere"/></p>
    <p>Pseudo : <input type="text" id="pseudo" name="pseudo"/></p>
    <p>Mot de passe : <input type="password" id="mdp" name="mdp"/></p>
  	<p><input type="submit" value="Valider" id="boutonValider" class="btn"/></p>
  </form>
</body>
</html>
