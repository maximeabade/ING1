-- Création de la table
CREATE TABLE Micros (
    id VARCHAR(2) PRIMARY KEY,
    Name VARCHAR(50),
    Image VARCHAR(100),
    Details VARCHAR(200),
    Price DECIMAL(10, 2),
    Stock INT
);

-- Insertion des données
INSERT INTO Micros (id, Name, Image, Details, Price, Stock)
VALUES ('M1', 'SENNHEISER E385 S', './img/micros/e385s.png', '40Hz-16kHz, -59dBV/Pa, 330g, 2.0m cable', 92.00, 5);

INSERT INTO Micros (id, Name, Image, Details, Price, Stock)
VALUES ('M2', 'R77', './img/micros/r77.png', '20Hz-18kHz, -55dBV/Pa, 860g, 1.5m cable', 290.00, 5);

INSERT INTO Micros (id, Name, Image, Details, Price, Stock)
VALUES ('M3', 'Shure S55', './img/micros/shureS55.png', '50Hz-15kHz, -58dBV/Pa, 624g, 3.5m cable', 185.00, 5);

INSERT INTO Micros (id, Name, Image, Details, Price, Stock)
VALUES ('M4', 'Slate Digital ML-1', './img/micros/slateDigital.png', 'Condensateur large membrane, 20Hz-20kHz, -38dBV/Pa, 1000g, 1.5m cable', 800.00, 5);

INSERT INTO Micros (id, Name, Image, Details, Price, Stock)
VALUES ('M5', 'Rode NT1-A', './img/micros/rodeNT1.png', 'Condenateur large membrane, 20Hz-20kHz, -38dBV/Pa, 1.5m cable', 166.00, 5);
