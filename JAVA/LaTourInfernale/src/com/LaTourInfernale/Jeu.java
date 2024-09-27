package com.LaTourInfernale;


import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * La classe de jeu permet de lancer les affichages graphique javafx
 * 
 * @author 4TOne
 * @version 1.0
 */
public class Jeu extends Application{	
	/**
	 * Hauteur de la fentre
	 */
	static final double heightGrille =  1800/50;
	
	/**
	 * Largeur de la fenetre
	 */
	static final double widthGrille =  1000/50;
	
	/**
	 * Lance l'affichage avec javafx
	 * 
	 * @param primaryStage
	 */
	@Override
	public void start(Stage primaryStage) throws Exception {
							
		// Initialisation de la fenetre
		primaryStage.setTitle("La Tour Infernale "); // Nom de la fenetre
		primaryStage.setWidth(1800); // Largeur de la fenetre
		primaryStage.setHeight(1030); // Hauteur de la fenetre 
		primaryStage.setResizable(false); // Empecher le redimensionnement de la fenetre
		
		// Initialisation du group et de la scène
		Group root0 = new Group();


		Scene scene0 = new Scene(root0, 1800, 1000);
		
		
		Parent debutJeu = FXMLLoader.load(getClass().getResource("SceneDebutJeu.fxml"));
		root0.getChildren().add(debutJeu);
		
		
		//création du joueur
				
	
		
		
		
		//Ajout de la scène a la fenetre
		primaryStage.setScene(scene0);
		//Affichage de la fenetre
		primaryStage.show();
		
		//Affiche au centre de l'ecran de la fenetre
		primaryStage.centerOnScreen();
	}

}