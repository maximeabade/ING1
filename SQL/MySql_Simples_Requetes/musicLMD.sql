/*Requêtes de la base de donnée music*/

/*Le titre et la durée de toutes les chansons*/
SELECT titre, duree 
FROM Chanson;

/*Les artistes dont le nom commence par la lettre L*/
SELECT nom 
FROM Artiste 
WHERE nom Like"L%";

/*Les titres commençant par la lettre C et I"*/
SELECT titre 
FROM Chanson 
WHERE titre LIKE"C%" 
OR titre LIKE"I%";

/*La date de sortie de l'album "Physical Graffiti"*/
SELECT dateDeSortie 
FROM Album 
WHERE titre="Physical Graffiti";

/*Combien de chansons possède l'album "help!"*/
SELECT COUNT(*) 
AS nbChansons 
FROM Chanson, Album 
WHERE Chanson.idAlbum = Album.idAlbum 
AND Album.titre="help!";

/*Quel est l'album qui possède le plus de compositeurs ?*/
SELECT ArtisteComposer.idAlbum, COUNT(ArtisteComposer.idArtiste) 
AS total 
FROM Artiste, ArtisteComposer
GROUP BY ArtisteComposer.idAlbum;