/*Requêtes de la base de donnée harrypotter*/

/* Nom, prénom et nbPoints des étudiants */

SELECT Eleve.nom, Eleve.prenom, sum(Points.nbPoints) as totalPoints
FROM Eleve, Points
WHERE Eleve.idEleve = Points.idEleve
GROUP BY Eleve.idEleve
ORDER BY totalPoints DESC;


/* Les élèves dont le nombre de points emporté est suppérieur à la moyenne */

SELECT Eleve.nom, Eleve.prenom, sum(Points.nbPoints) as totalPoints
FROM Eleve, Points
WHERE Eleve.idEleve = Points.idEleve
GROUP BY Eleve.idEleve HAVING totalPoints >= (SELECT avg(total)
                                              FROM (SELECT sum(nbPoints) as total 
                                                    FROM Points 
                                                    GROUP BY Points.idEleve
                                                    ) as TAB
                                            )
ORDER BY totalPoints DESC;


/* Le nom et le prénom des élèves qui ont "Serverus Rogue" */
SELECT nom, prenom
FROM Eleve
WHERE idEleve IN (SELECT idEleve FROM EleveSuitMatiere 
                WHERE idMatiere = (SELECT idMatiere FROM Matiere
                                    WHERE idProfesseur = (SELECT idProfesseur FROM Professeur WHERE nom = "Rogue" AND prenom = "Severus")
                                   )
                )
;

/* Le professeur qui a le plus utilisé le système de points et le nombre de fois où il a usé de son pouvoir */

SELECT nom, prenom
FROM Professeur
WHERE idProfesseur = (SELECT idProfesseur
                     FROM Points
                     GROUP BY idProfesseur HAVING count(*) = (SELECT max(total) 
                                                        FROM (SELECT count(*) as total 
                                                            FROM Points 
                                                            GROUP BY idProfesseur
                                                            ) as TAB
                                                        )
                    )
;
