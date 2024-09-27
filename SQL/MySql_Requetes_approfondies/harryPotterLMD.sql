/*Requêtes de la base de donnée harrypotter*/

/*Quels sont les élèves qui appartiennent à la maison “Gryffondor” ? Dans le résultat, affichez le nom, et le prénom de l’élève*/
SELECT Eleve.nom, Eleve.prenom
FROM Eleve INNER JOIN Maison 
ON Eleve.idMaison = Maison.idMaison
WHERE Maison.nom = 'Gryffondor';

/*Quelle matière enseigne le professeur dont le prénom est “Minerva” et son nom est “McGonagall” ?*/
SELECT Matiere.intitule
FROM Matiere INNER JOIN Professeur
ON Matiere.idProfesseur = Professeur.idProfesseur
WHERE Professeur.nom = "McGonagall"
AND Professeur.prenom = "Minerva";

/*Combien d’élèves n’ont jamais obtenu ou perdu de points pour leur maison ? Afficher dans le résultat le nom et le prénom de l'élève.*/
SELECT nom, prenom
FROM Eleve
WHERE idEleve NOT IN ( SELECT distinct idEleve FROM Points);

/*Quels sont les élèves qui suivent toutes les matières ?*/
SELECT idEleve, count(idMatiere) as nbMatiere
FROM EleveSuitMatiere
GROUP BY idEleve 
HAVING nbMatiere = (SELECT count(idMatiere) FROM Matiere);
