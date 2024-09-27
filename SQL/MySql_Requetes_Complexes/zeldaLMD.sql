/*Requêtes de la base de donnée zelda*/

/* Les joueurs qui n'ont jamais mangé de plat */
SELECT idJoueur
FROM Joueur
WHERE idJoueur NOT IN (SELECT idJoueur FROM Manger);

SELECT DISTINCT(idJoueur)
FROM  Joueur
NATURAL LEFT JOIN Manger
WHERE Manger.idJoueur is null;

/* Le joueur qui a consommé le plus de plats */
SELECT idJoueur, count(*) as nbPlats
From Manger
GROUP BY idJoueur 
ORDER BY nbPlats DESC limit 1;

SELECT idJoueur, count(*) as nbPlats
FROM Manger
GROUP BY idJoueur HAVING nbPlats = (SELECT max(total) 
                                    FROM (SELECT count(*) as total 
                                          FROM Manger 
                                          GROUP BY idJoueur
                                          ) as TAB
                                    );


/* Le plat qui contient le plus d'ingrédients différents */
SELECT idPlat, count(*) as nbIngredient
From Composer
GROUP BY idPlat 
ORDER BY nbIngredient DESC limit 1;

SELECT idPlat, count(*) as nbIngredient
FROM Composer
GROUP BY idPlat HAVING nbIngredient = (SELECT max(total) 
                                       FROM (SELECT count(*) as total 
                                            FROM Composer 
                                            GROUP BY idPlat
                                            ) as TAB
                                        );