-- Création de la table
CREATE TABLE Batteries (
    id VARCHAR(2) PRIMARY KEY,
    Name VARCHAR(50),
    Image VARCHAR(100),
    Details VARCHAR(200),
    Price DECIMAL(10, 2),
    Stock INT
);

-- Insertion des données
INSERT INTO Batteries (id, Name, Image, Details, Price, Stock)
VALUES ('B1', 'PearlEXX705NBR', './img/batteries/PearlEXX705NBR.png', 'Gross Caisse, Tom10X07, Tom12X08, StandTom 14X14, caisse claire 14X5.5, livrée sans siège', 1100.00, 5);

INSERT INTO Batteries (id, Name, Image, Details, Price, Stock)
VALUES ('B2', 'Startone', './img/batteries/Startone.png', 'Grosse Caisse, Tom10X08, Tom12X09, StandTom 14X14, caisse claire 14X5.5, livrée avec siège', 270.00, 5);

INSERT INTO Batteries (id, Name, Image, Details, Price, Stock)
VALUES ('B3', 'YamahaRYDEEN', './img/batteries/YamahaRYDEEN.png', 'Grosse Caisse, Tom10X07, Tom12X08, StandTom 14X13, caisse claire 14X5.5, livrée sans siège', 750.00, 5);

INSERT INTO Batteries (id, Name, Image, Details, Price, Stock)
VALUES ('B4', 'Efnote 3 E-Drum', './img/batteries/efnote3.png', 'Grosse Caisse Aluminium, Tom10X3.5 (x2), Tom12X04, StandTom 14X14, caisse claire 14X5.5, livrée sans siège', 2330.00, 5);

INSERT INTO Batteries (id, Name, Image, Details, Price, Stock)
VALUES ('B5', 'Millenium Rookie E-Drum', './img/batteries/milleniumRookie.png', 'Caisse claire 07, Tom10X07 (x3), livrée sans siège', 189.00, 5);
