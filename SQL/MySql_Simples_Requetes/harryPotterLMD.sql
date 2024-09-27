/*Requêtes de la base de donnée harrypotter*/

/*Quels élèves ont leur prénom commençant par un M*/
SELECT nom, prenom 
FROM Eleve 
WHERE prenom LIKE 'M%';

/*Quelles sont les couleurs de la maison serpentard*/
SELECT couleur
FROM Maison
WHERE nom = 'Serpentard';

/*Les élèves ayant rapportés le plus de points*/
SELECT idEleve
FROM Points
GROUP BY idEleve
ORDER BY SUM(nbPoints) DESC;

/*En moyenne, combien le professeur 01 e-t-il enlevé de points ?*/
SELECT AVG(nbPoints)
FROM Points
WHERE idProfesseur = '01'
AND nbPoints < 0;