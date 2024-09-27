-- Création de la table
CREATE TABLE Guitares (
    id VARCHAR(2) PRIMARY KEY,
    Name VARCHAR(50),
    Image VARCHAR(100),
    Details VARCHAR(200),
    Price DECIMAL(10, 2),
    Stock INT
);

-- Insertion des données
INSERT INTO Guitares (id, Name, Image, Details, Price, Stock)
VALUES ('G1', 'Harley Benton', './img/guitares/HarleyBenton.png', 'Corps en peuplier, manche en érable, touche en Roseacer, 22 frettes, 2 micros double bobinage, cordes .010-.046', 148.00, 5);

INSERT INTO Guitares (id, Name, Image, Details, Price, Stock)
VALUES ('G2', 'Jackson JS22', './img/guitares/JacksonJS22.png', 'Corps en peuplier, manche en érable, touche en amarante, 24 frettes, 2 micros double bobinage', 229.00, 5);

INSERT INTO Guitares (id, Name, Image, Details, Price, Stock)
VALUES ('G3', 'Jackson JS32 King V', './img/guitares/JacksonJS32KingV.png', 'Corps en peuplier, manche en érable, touche en amarante, 24 frettes, 3 micros double bobinage, cordes .009-.042', 359.00, 5);

INSERT INTO Guitares (id, Name, Image, Details, Price, Stock)
VALUES ('G4', 'ESP E-II HORIZON-III FM RDB', './img/guitares/espHorizon.png', 'Corps en aulne, manche en érable, touche en ébène, 24 frettes, 2 micros double bobinage, cordes .009-.042', 2320.00, 5);

INSERT INTO Guitares (id, Name, Image, Details, Price, Stock)
VALUES ('G5', 'Harley Benton BS-20BK Rock Series', './img/guitares/harleyBentonBS20.png', 'Corps en tilleul, manche en érable canadien, touche en Roseacer, 24 frettes, 2 micros double bobinage, cordes .009-.042', 130.00, 5);
