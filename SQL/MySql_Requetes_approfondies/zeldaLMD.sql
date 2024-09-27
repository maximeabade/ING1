/*Requêtes de la base de donnée zelda*/

/*Quel est le nom du monde pour la créature divine “Vah Medoh”*/
SELECT Monde.nom
FROM Monde, CreatureDivine
WHERE Monde.idMonde = CreatureDivine.idMonde
AND CreatureDivine.nom = 'Vah Medoh';

/*Quelle est la moyenne de plat consommé par joueur ?*/
SELECT (count(idPlat) / count(distinct(idJoueur))) as moyenne
FROM Manger
GROUP BY idJoueur;

/*Quels sont les joueurs qui ont mangé plus de 3 plats ?*/
SELECT idJoueur
FROM Manger
GROUP BY idJoueur
HAVING count(idJoueur) > 3;