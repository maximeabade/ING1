/* Les requêtes de la Base de donnée marioKart */

/* Le nom et la date de naissance des personnages dont le nom commence par M */
SELECT nom, dateNaissance
FROM Personnage
WHERE nom LIKE 'M%';

/* Le nom de mario et le nom et la vitesse de ses voitures */
SELECT Personnage.nom, Voiture.nom, Voiture.vitesse
FROM Voiture INNER JOIN Personnage 
WHERE Voiture.idPerso = Personnage.id
AND Personnage.id = (SELECT id FROM Personnage WHERE nom = "Mario")
;

/* le nom du circuit et la datte à laquelle le personnage à courru le plus récemment */
SELECT Personnage.nom, Circuit.nom, RealiserUneCourse.date_realisee
FROM RealiserUneCourse, Personnage, Circuit
WHERE Circuit.id = RealiserUneCourse.idCircuit
AND RealiserUneCourse.idPerso = Personnage.id
AND RealiserUneCourse.date_realisee = (SELECT max(date_realisee) FROM RealiserUneCourse as TAB);

/* le nom des voitures dont le nom commence par B, M ou W */
SELECT nom 
FROM Voiture
WHERE nom Like 'B%'
OR nom Like 'M%'
OR nom Like 'W%';

/* les personnages qui n'ont pas de voitures dépassant les 5 km/h */
SELECT p.nom
FROM Personnage AS p
RIGHT JOIN Voiture AS v ON p.id = v.idPerso
WHERE p.id NOT IN (SELECT idPerso FROM Voiture WHERE vitesse > 5 AND idPerso != "NULL");

/* Le nom des personnages qui ont réalisé tous les circuits */
