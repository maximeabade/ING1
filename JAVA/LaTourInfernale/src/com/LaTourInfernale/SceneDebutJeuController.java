package com.LaTourInfernale;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.animation.FadeTransition;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import javafx.util.Duration;
/**
 * Controller de l'écran d'accueil
 * 
 * @author ATOne
 * @version 1.0
 *
 */
public class SceneDebutJeuController implements Initializable{
	
	
	@FXML
	private Group rootGroup;
	
	@FXML
	private Button CommencerPartie;

	/**
	 * Event Listener on Button[#CommencerPartie].onAction
	 * 
	 * @param event
	 */

	@FXML
	public void nextSceneTwo(ActionEvent event) {
		
		makeFadeOut();
	}
	
	@Override
	public void initialize(URL location, ResourceBundle resources) {
	
		
	}
	
	/**
	 * Transition
	 */
	private void makeFadeOut() {
		
		FadeTransition fadeTransitionOut = new FadeTransition();
			
		fadeTransitionOut.setDuration(Duration.millis(1000));
		
		fadeTransitionOut.setNode(rootGroup);
		
		fadeTransitionOut.setFromValue(1);
		
		fadeTransitionOut.setToValue(0);
		
		fadeTransitionOut.setOnFinished((ActionEvent event) -> {
			loadNextScene();
		});
		
		fadeTransitionOut.play();
	}
	
	/**
	 * Passage a la page d'histoire
	 */
	private void loadNextScene() {
		
		Parent secondView;
		
		try {
			
			secondView = (Group) FXMLLoader.load(getClass().getResource("SceneStoryOne.fxml"));
			
			Scene newScene = new Scene(secondView);
			
			Stage CurrentStage = (Stage) rootGroup.getScene().getWindow();
			
			CurrentStage.setScene(newScene);
		
		} catch (IOException e) {
			
			e.printStackTrace();
		}
	}
	
}