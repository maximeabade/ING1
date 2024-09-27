CREATE DATABASE IF NOT EXISTS monPetitChat;
USE monPetitChat;

CREATE TABLE IF NOT EXISTS Animal (
    idAnimal INT NOT NULL AUTO_INCREMENT,
    appelation VARCHAR(30) NOT NULL,
    type VARCHAR(30) NOT NULL,
    CONSTRAINT pk_id PRIMARY KEY (idAnimal)
);

CREATE TABLE IF NOT EXISTS Chat (
    idChat INT NOT NULL AUTO_INCREMENT,
    prenom VARCHAR(30) NOT NULL,
    robe VARCHAR(30) NOT NULL,
    idAnimal INT NOT NULL,
    CONSTRAINT pk_id PRIMARY KEY (idChat),
    CONSTRAINT fk_idAnimal FOREIGN KEY (idAnimal) REFERENCES Animal(idAnimal)
);

INSERT INTO Animal VALUES(NULL, "chat", "domestique");
INSERT INTO Animal VALUES(NULL, "linx", "sauvage");
INSERT INTO Animal VALUES(NULL, "léopard", "sauvage");
INSERT INTO Animal VALUES(NULL, "chien", "domestique");

INSERT INTO Chat VALUES(NULL, "Lizzy", "noire", 1);
INSERT INTO Chat VALUES(NULL, "Pounette", "isabelle", 1);
INSERT INTO Chat VALUES(NULL, "Leia", "grise", 1);
INSERT INTO Chat VALUES(NULL, "Misty", "tigrée", 1);
INSERT INTO Chat VALUES(NULL, "Miaoumix", "grise", 1);