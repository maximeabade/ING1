package com.LaTourInfernale;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.animation.FadeTransition;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.util.Duration;

/**
 * Controller de la page d'histoire
 * 
 * @author 4TOne
 * @version 1.0
 *
 */
public class SceneStoryOneController implements Initializable{
	
	@FXML
	private Group rootStory;
	
	@FXML
	private TextField nomPlayer;
	
	@FXML
	private Button goLobby;
	
	
	/**
	 * Event Listener on Button[#goLobby].onAction
	 * 
	 * @param event
	 */
	@FXML
	public void getPlayerNameLoadNextScene(ActionEvent event) {
		
		goLobby.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {
				
				Stage primaryStage = (Stage) rootStory.getScene().getWindow();
				
				// Initialisation du group et de la scène
				Group root0 = new Group();


				Scene scene0 = new Scene(root0, 1800, 1000);
						

				
				try {
				
				Joueur j = new Joueur(nomPlayer.getText(),16,13, 20, 60);
//				j.setArgent(110000);
//					Item PM = new Item(0);
//					Item PP = new Item(1);
//					Item P = new Item(2);
//					j.ajouterItem(PP);
//					j.ajouterItem(PP);
//					j.ajouterItem(PP);
//					j.ajouterItem(PM);
//					j.ajouterItem(PM);
//					j.ajouterItem(P);
//					j.ajouterItem(PM);

				
				
				
				
				Label nomJoueur = new Label(j.getNom());
				nomJoueur.setId("nomJoueur");
				
			

				//Boutique
				
				
				Label infosBoutique = new Label("Bienvenue dans la boutique! \n Voici les différents items : \n 1.Potion Magique \n 2.Potion basique");
					
				
				
				Lobby lobby = new Lobby(1800/50	,1000/50);
				//Ajout du lobby a la scène
				root0.getChildren().addAll(lobby.getDonnees());
				
				
				//Creation de l'étage
				Labyrinthe niveau1 = new Labyrinthe(1800/50	, 1000/50,1);
						
			
			

				
				Etage_Boss niveau3 = new Etage_Boss(1800/50, 1000/50);			


				/*TEST BOSS 
				root0.getChildren().clear();
				root0.getChildren().add(niveau3.getDonnees());
				
				//on place le joueur en debut de labyrinthe
				j.reinitialiserCoordBoss();
				
				//on permet au joueur de se déplacer
				niveau3.seDeplacerBoss(j,niveau1,lobby,scene0,root0,primaryStage);
				*/
				
				lobby.seDeplacer(lobby,niveau1,scene0,j,root0,primaryStage);
					
				primaryStage.setScene(scene0);
				//Affichage de la fenetre
				primaryStage.show();
				
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			
		});
	}
	
	/**
	 * @param location
	 * @param resources
	 */
	@Override
	public void initialize(URL location, ResourceBundle resources) {
		
		
		rootStory.setOpacity(0);
		
		makeFadeIn();
		
	}
	
	/**
	 * Transition vers le lobby
	 */
	private void makeFadeIn() {
		
		FadeTransition fadeTransitionIn = new FadeTransition();
			
		fadeTransitionIn.setDuration(Duration.millis(1000));
		
		fadeTransitionIn.setNode(rootStory);
		
		fadeTransitionIn.setFromValue(0);
		
		fadeTransitionIn.setToValue(1);
		
		fadeTransitionIn.play();
	}
	

}
