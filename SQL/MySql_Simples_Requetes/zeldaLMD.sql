/*Requêtes de la base de donnée zelda*/

/*Quels sont les sanctuaires commençant par la lettre T ?*/
SELECT * 
FROM Sanctuaire 
WHERE nom LIKE 'T%';

/*Nombre de combat contre les créatures divines*/
SELECT COUNT(*) 
AS nbCombats
FROM Combattre;

/*Niveau de Sanctuaire le plus bas*/
SELECT MIN(niveau)
FROM Sanctuaire;

/*Les joueurs par ordre décroissant de niveau et croissant de pseudo*/
SELECT *
FROM Joueur
ORDER BY niveauEndurance DESC, pseudo ASC;

/*Afficher les plats dont la puissance est suppérieure à 2*/
SELECT nom 
FROM Plat
WHERE puissance > 2;