-- Création de la table
CREATE TABLE Users (
    id INT PRIMARY KEY,
    username VARCHAR(50),
    password VARCHAR(50),
    isAdmin BOOLEAN
);

-- Insertion des données
INSERT INTO Users (id, username, password, isAdmin)
VALUES (1, 'max', 'max123', true);

INSERT INTO Users (id, username, password, isAdmin)
VALUES (2, 'ehsan', 'ehsan123', false);

INSERT INTO Users (id, username, password, isAdmin)
VALUES (3, 'bde', 'bde123', false);
