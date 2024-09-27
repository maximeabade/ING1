package com.LaTourInfernale;

import java.io.IOException;
import java.nio.file.Paths;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.stage.Stage;
import javafx.util.Duration;
/**
 * Classe enfant de Grille 
 * 
 * Permet d'afficher la carte du Lobby
 * 
 * @see Grille
 * 
 * @author 4TOne 
 * @version 1.0
 *
 */
public class Lobby extends Grille{
	
	/**
	 * Image source du lobby
	 * 
	 * @see Lobby#getImageLobby()
	 */
	private Image[] imageLobby;
	/**
	 * Lecteur de la musique
	 */
	private MediaPlayer mediaPlayer;
	/**
	 * Constructeur de l'objet Lobby
	 * 
	 * @param width
	 * @param height
	 */
	public Lobby(double width, double height) {
		super(width, height);
		this.imageLobby = getImageLobby();
		this.donnees = initLobby();
	}
	
	/**
	 * Contient les images sources de la carte
	 * 
	 * @return images source du lobby
	 */
	public Image[] getImageLobby() {
		Image[] imageLobby 	= new Image[10];
		Image arbre 		= new Image(getClass().getResourceAsStream("arbre_vert.png"), 50, 50, false, false);
		Image herbe 		= new Image(getClass().getResourceAsStream("herbe.png"), 50, 50, false, false);
		Image escalier 		= new Image(getClass().getResourceAsStream("escalier.png"), 100, 100, false, false);
		Image hero_avant 	= new Image(getClass().getResourceAsStream("hero_avant.png"), 50, 50, false, false);
		Image hero_dos 		= new Image(getClass().getResourceAsStream("hero_dos.png"), 50, 50, false, false);
		Image hero_gauche 	= new Image(getClass().getResourceAsStream("hero_gauche.png"), 50, 50, false, false);
		Image hero_droite 	= new Image(getClass().getResourceAsStream("hero_droit.png"), 50, 50, false, false);
		Image boutique 		= new Image(getClass().getResourceAsStream("shop.png"), 100, 100, false, false);
		Image tour 			= new Image(getClass().getResourceAsStream("tour.png"), 200, 200, false, false);
		Image dojo 			= new Image(getClass().getResourceAsStream("dojo.png"), 100, 100, false, false);

		imageLobby[0] = arbre;
		imageLobby[1] = herbe;
		imageLobby[2] = escalier;
		imageLobby[3] = hero_avant;
		imageLobby[4] = hero_dos;
		imageLobby[5] = hero_gauche;
		imageLobby[6] = hero_droite; 
		imageLobby[7] = boutique; 
		imageLobby[8] = tour; 		
		imageLobby[9] = dojo;
		return imageLobby;
}

	/**
	 * Création du lobby
	 * 
	 * @return la carte
	 */
	private GridPane initLobby() {
		music();
		mediaPlayer.setVolume(0.04);
		//Création de la GridPane
		GridPane grid = new GridPane();
		
		//this.height = HFenetre/HImageView soit le nombre total de ligne de grid
		for(int i = 0; i < this.height; i++) {
	
			//this.width = WFenetre/WImageView soit le nombre total de colonne de grid
			for(int j = 0; j < this.width; j++) {
										
				// Ajout de l'herbe dans la GidPane
				if(i > 5 && j > 8 && i <14 && j < 27) {
					// Nouvelle instance  ImageView
					ImageView herbe = new ImageView(imageLobby[1]);
					
					//Ajout de de l'image dans grid
					grid.add(herbe,j,i);
				}
				
				//Ajout des arbres a la GridPane
				else {
					// Nouvelle instance  ImageView
					ImageView arbre = new ImageView(imageLobby[0]);
					
					//Ajout de de l'image dans grid
					grid.add(arbre,j,i);
				}
			}
		}
		
		//Ajout de la tour
		ImageView tour 		= new ImageView(imageLobby[8]);
		
		for(int i= 16; i < 20; i++) {
			for(int j=1; j < 5; j++) {
				ImageView herbe = new ImageView(imageLobby[1]);
				grid.add(herbe,i,j,1,1);
			}
		}
		
		//Ajout de de l'image dans gride
		
		
		grid.add(tour,16,1, 4,4);
		
		ImageView herbe8 = new ImageView(imageLobby[1]);
		ImageView herbe9 = new ImageView(imageLobby[1]);
		grid.add(herbe8,18,5,1,1);
		grid.add(herbe9,17,5,1,1);
		
		//Ajout de la face avant du hero a la GridPane
		ImageView hero_avant = new ImageView(imageLobby[3]);
		
		
		//Ajout de de l'image dans grid
		grid.add(hero_avant,16,13, 1,1);
		
		//Ajout de la boutique a la GridPane
		ImageView boutique = new ImageView(imageLobby[7]);
		
		ImageView herbe = new ImageView(imageLobby[1]);
		ImageView herbe1 = new ImageView(imageLobby[1]);
		ImageView herbe2 = new ImageView(imageLobby[1]);
		ImageView herbe3 = new ImageView(imageLobby[1]);
		
		//Ajout de de l'image dans grid
		
		grid.add(herbe,27,5,1,1);
		grid.add(herbe1,28,5,1,1);
		grid.add(herbe2,27,6,1,1);
		grid.add(herbe3,28,6,1,1);
		grid.add(boutique,27,5, 2,2);
		//grid.add(herbe,31,6,2,2); 

		//Ajout du dojo a la GridPane
		ImageView dojo = new ImageView(imageLobby[9]);
		
		ImageView herbe4 = new ImageView(imageLobby[1]);
		ImageView herbe5 = new ImageView(imageLobby[1]);
		ImageView herbe6 = new ImageView(imageLobby[1]);
		ImageView herbe7 = new ImageView(imageLobby[1]);
		//Ajout de de l'image dans grid
		grid.add(herbe4,7,5,1,1);
		grid.add(herbe5,7,6,1,1);
		grid.add(herbe6,8,5,1,1);
		grid.add(herbe7,8,6,1,1);

		grid.add(dojo,7,5,2,2);
	/*	grid.add(dojo,8,6,2,2);
		grid.add(dojo,7,6,2,2);
		grid.add(dojo,8,6,2,2);*/
		//Initialisation de la l'attribut donnée
		
		
		
		
		return grid;
	}
	
	/**
	 * Verifie si le joueur peut entre dans la tour
	 * 
	 * @param coordX
	 * @param coordY
	 * @return true si le joueur peut entrer, false sinon
	 */
	public boolean entrerTour(int coordX, int coordY) {
		
		boolean verif = false; 
		
		//coordonnées porte de la tour 		
		if ( ((coordX == 18) && (coordY-1==4)) || ((coordX == 17) && (coordY-1==4)) ){
			verif = true;
		}
		
		return verif;
	}
	
	/**
	 * Verifie si le joueur peut entre dans la boutique
	 * 
	 * @param coordX
	 * @param coordY
	 * @return true si le joueur peut entrer, false sinon
	 */
	public boolean entrerBoutique(int coordX, int coordY) {
		
		boolean verif = false; 
		
		//coordonnées porte de la tour 		
		if ((coordX+1 > 27) && (coordY==6) ){
			verif = true;
		}
		
		return verif;
	}	
	
	/**
	 * Verifie si le joueur peut entre dans le dojo
	 * 
	 * @param coordX
	 * @param coordY
	 * @returntrue si le joueur peut entrer, false sinon
	 */
	public boolean entrerDojo(int coordX, int coordY) {
		
		boolean verif = false; 
		
		//coordonnées porte de la tour 		
		if ((coordX < 9) && (coordY==6) ){
			verif = true;
		}
		
		return verif;
	}	
	
	/**
	 * Actualise la carte
	 * 
	 * @param typeMouvement
	 * @param nCoordX
	 * @param nCoordY
	 * @param aCoordX
	 * @param aCoordY
	 */
	public void actualiserGrille(int typeMouvement, int nCoordX, int nCoordY, int aCoordX, int aCoordY) {

		ImageView hero =  new ImageView(imageLobby[3]) ;
		ImageView sol = new ImageView(imageLobby[1]);

		switch(typeMouvement) {
		
		case 0: 
			//Ajout de la face avant du hero a la GridPane
			 hero = new ImageView(imageLobby[4]);
		break;	
		case 1: 
			//Ajout de la face bas du hero a la GridPane
			 hero = new ImageView(imageLobby[3]);
		break;	
		case 2: 
			//Ajout de la face gauche du hero a la GridPane
			 hero = new ImageView(imageLobby[5]);
		break;	
		case 3: 
			//Ajout de la face droite du hero a la GridPane
			 hero = new ImageView(imageLobby[6]);
		break;	
					
		default:
			break;
		}
		
		//effacer ancienne position du hero
		this.donnees.add(sol,aCoordX,aCoordY);
		//ajouter nouvelle position du hero
		this.donnees.add(hero,nCoordX,nCoordY);
		
	}
	
	/**
	 * Lance la musique
	 */
	public void music() {
		String s = "DarkCastle.mp3";
		Media h = new Media(Paths.get(s).toUri().toString());
		mediaPlayer = new MediaPlayer(h);
		 mediaPlayer.setOnEndOfMedia(new Runnable() {
		       public void run() {
		         mediaPlayer.seek(Duration.ZERO);
		       }	
		 });
		 mediaPlayer.play();
	}
	
	/**
	 * Actualise la derniere position
	 * 
	 * @param CoordX
	 * @param CoordY
	 */
	public void actualiserDernierePos(int CoordX, int CoordY) {

	
		ImageView sol = new ImageView(imageLobby[1]);
		
		
		//effacer ancienne position du hero
		this.donnees.add(sol,CoordX,CoordY);
		
		
	}

	
	/**
	 * Permet au joueur de se deplacer dans le lobby
	 * 
	 * @param niveau0
	 * @param niveau1
	 * @param scene0
	 * @param j
	 * @param root0
	 * @param primaryStage
	 * @throws IOException
	 */
	public void seDeplacer(Lobby niveau0, Labyrinthe niveau1, Scene scene0, Joueur j, Group root0, Stage primaryStage) throws IOException {
	
		AnchorPane sac = FXMLLoader.load(getClass().getResource("sac.fxml"));
		
		AnchorPane boutique = FXMLLoader.load(getClass().getResource("boutique.fxml"));
		
		AnchorPane dojo = FXMLLoader.load(getClass().getResource("dojo.fxml"));
		
		AnchorPane infosJoueur = FXMLLoader.load(getClass().getResource("infosJoueur.fxml"));
		infosJoueur.setLayoutX(0);
		infosJoueur.setLayoutY(800);
		root0.getChildren().add(infosJoueur);
		j.actualiserInfosJoueur(scene0);
		
	
		//touche clavier
		scene0.setOnKeyPressed(e->{
				
		
			//deplacement en haut
			if((e.getText().toUpperCase().equals("8"))){	
				if (( j.coordY-1 > 5) || (j.coordY-1 == 5 && (j.coordX == 17 || j.coordX == 18)) || (this.entrerTour(j.coordX, j.coordY))) {
					j.coordY--;
					
					//passage de porte
					if (this.entrerTour(j.coordX, j.coordY+1)) {

							
						//effacer ancienne position du hero
						actualiserDernierePos(j.coordX,j.coordY+1);
						
						root0.getChildren().remove(niveau0.getDonnees());
						
						root0.getChildren().add(niveau1.getDonnees());
					
						j.reinitialiserCoord();
																			
						niveau1.seDeplacerLab(niveau1,niveau0,j, scene0,root0,primaryStage);
						
						//Titre de la fenêtre
						primaryStage.setTitle("Niveau 1");
						
						//Affichage de la fenetre
						primaryStage.show();
					}else {

						this.actualiserGrille(0,j.coordX,j.coordY,j.coordX,j.coordY+1);
					
					}
					
					
					//cas où on sort de la boutique
					if (root0.getChildren().contains(boutique)) {
						root0.getChildren().remove(boutique);
					}
		
					
				}
			}
		
		
		//deplacement en bas
		if((e.getText().toUpperCase().equals("2"))){
			if(j.coordY+1 < 14) {
				j.coordY++;
				this.actualiserGrille(1,j.coordX,j.coordY,j.coordX,j.coordY-1);
			}
			
			
			//cas où on sort de la boutique
			if (root0.getChildren().contains(boutique)) {
				root0.getChildren().remove(boutique);
			}
			
			if (root0.getChildren().contains(dojo)) {
				root0.getChildren().remove(dojo);
			}
			
		}

		//deplacement à gauche
		if((e.getText().toUpperCase().equals("4"))){	
			if(((j.coordX-1 > 8 && j.coordY != 5) && j.coordY != 5) || (j.coordY == 5 && (j.coordX-1 == 17))) {
				j.coordX--;
				this.actualiserGrille(2,j.coordX,j.coordY,j.coordX+1,j.coordY);
			}
		
			
			//cas où on sort de la boutique
			if (root0.getChildren().contains(boutique)) {
				root0.getChildren().remove(boutique);
			}
			
			if(this.entrerDojo(j.coordX-1, j.coordY)) {
				try {						
					root0.getChildren().add(dojo);
					dojo.setLayoutX(650);
					dojo.setLayoutY(250);
	
					Label bonusForce = (Label) scene0.lookup("#bonusForce");
					bonusForce.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

						@Override
						public void handle(MouseEvent event) {
							if(j.getptXp()> 0) {
								j.setAtk(j.getAtk()+4);								
								j.setPtXp(j.getptXp()-1);
								j.actualiserInfosJoueur(scene0);				
							}
							else {
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous n'avez pas assez de point d'expérience");
								alert.showAndWait();

							}
						}
						
					});
					Label bonusVie = (Label) scene0.lookup("#bonusVie");
					bonusVie.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

						@Override
						public void handle(MouseEvent event) {
							if(j.getptXp()> 0) {									
								j.setVie(j.getVie()+7);	
								j.setVieMax(j.getVieMax()+7);	
								j.setPtXp(j.getptXp()-1);
								j.actualiserInfosJoueur(scene0);
							}
							else {
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous n'avez pas assez de point d'expérience");
								alert.showAndWait();

							}
						}
						
					});
				}
				catch(Exception error) {	}
			}
		}
		//deplacement à droite			
		if((e.getText().toUpperCase().equals("6"))){	
			
			if( (((j.coordX+1 < 27) || this.entrerBoutique(j.coordX, j.coordY)) && j.coordY != 5) || (j.coordY == 5 && (j.coordX+1 == 18))){	
				j.coordX++;
				this.actualiserGrille(3,j.coordX,j.coordY,j.coordX-1,j.coordY);
			}
			
			
			//cas où on entre de la boutique
			if (this.entrerBoutique(j.coordX+1, j.coordY)) {
				try {
					root0.getChildren().add(boutique);
					boutique.setLayoutX(380);
					boutique.setLayoutY(250);
					j.getSac();
					
					Button acheterPM = (Button) scene0.lookup("#acheterPM");
					acheterPM.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

						@Override
						public void handle(MouseEvent event) {
							Item potionMagique = new Item(1);
							j.acheterItem(potionMagique);	
							j.actualiserSac(scene0);
							j.actualiserInfosJoueur(scene0);
							
						}
						
					});
					
					Button acheterPB = (Button) scene0.lookup("#acheterPB");
					acheterPB.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
						
						@Override
						public void handle(MouseEvent event) {
							Item potionBasique= new Item(0);
							j.acheterItem(potionBasique);		
							j.actualiserSac(scene0);
							j.actualiserInfosJoueur(scene0);
						}
						
					});
					
					Button acheterPP = (Button) scene0.lookup("#acheterPP");
					System.out.println(acheterPP);
					acheterPP.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

						@Override
						public void handle(MouseEvent event) {
							Item potionPoison= new Item(2);
							j.acheterItem(potionPoison);		
							j.actualiserSac(scene0);
							j.actualiserInfosJoueur(scene0);
						}
						
					});						
					Button acheterC = (Button) scene0.lookup("#acheterC");
					System.out.println(acheterPP);
					acheterC.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

						@Override
						public void handle(MouseEvent event) {
							
							Armure casque= new Armure(0);
							if (!(j.chercherArmure(casque)) && j.getArgent() >= casque.getPrix()) {
								j.acheterArmure(casque);	
								j.setVie(j.getVie()+casque.getEffet());
								j.setVieMax(j.getVieMax()+casque.getEffet());
								j.actualiserSac(scene0);
								j.actualiserInfosJoueur(scene0);
							
							}
							else if (j.getArgent() < casque.getPrix()){
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous n'avez pas assez d'argent");
								alert.showAndWait();
							}
							else{
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous avez déjà cet équipement");
								alert.showAndWait();
							}
						}
						
					});	
					Button acheterP = (Button) scene0.lookup("#acheterP");
					System.out.println(acheterP);
					acheterP.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

						@Override
						public void handle(MouseEvent event) {
							
							Armure plastron= new Armure(1);
							if (!(j.chercherArmure(plastron))  && j.getArgent() >= plastron.getPrix()) {
								j.acheterArmure(plastron);	
								j.setVie(j.getVie()+plastron.getEffet());
								j.setVieMax(j.getVieMax()+plastron.getEffet());
								j.actualiserSac(scene0);
								j.actualiserInfosJoueur(scene0);
							}
							else if (j.getArgent() < plastron.getPrix()){
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous n'avez pas assez d'argent");
								alert.showAndWait();
							}
							else{
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous avez déjà cet équipement");
								alert.showAndWait();
							}
						}
						
					});	
					Button acheterJ = (Button) scene0.lookup("#acheterJ");
					System.out.println(acheterJ);
					acheterJ.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

						@Override
						public void handle(MouseEvent event) {
							
							Armure jambieres= new Armure(2);
							if (!(j.chercherArmure(jambieres))  && j.getArgent() >= jambieres.getPrix()) {
								j.acheterArmure(jambieres);	
								j.setVie(j.getVie()+jambieres.getEffet());
								j.setVieMax(j.getVieMax()+jambieres.getEffet());
								j.actualiserSac(scene0);
								j.actualiserInfosJoueur(scene0);
							}
							else if (j.getArgent() < jambieres.getPrix()){
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous n'avez pas assez d'argent");
								alert.showAndWait();
							}
							else{
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous avez déjà cet équipement");
								alert.showAndWait();
							}
						}
						
					});	
					Button acheterB = (Button) scene0.lookup("#acheterB");
					System.out.println(acheterB);
					acheterB.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

						@Override
						public void handle(MouseEvent event) {
							
							Armure bottes= new Armure(3);
							if (!(j.chercherArmure(bottes))  && j.getArgent() >= bottes.getPrix()) {
								j.acheterArmure(bottes);	
								j.setVie(j.getVie()+bottes.getEffet());
								j.setVieMax(j.getVieMax()+bottes.getEffet());
								j.actualiserSac(scene0);
								j.actualiserInfosJoueur(scene0);
							}
							
							else if (j.getArgent() < bottes.getPrix()){
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous n'avez pas assez d'argent");
								alert.showAndWait();
							}
							else{
								Alert alert = new Alert(AlertType.WARNING);
								alert.setHeaderText(null);
								alert.setTitle(null);
								alert.setContentText("Vous avez déjà cet équipement");
								alert.showAndWait();
							}
							
						}
						
					});	
				}
				catch(Exception error) {	}
			}
			if (root0.getChildren().contains(dojo)) {
				root0.getChildren().remove(dojo);
			}
		}	
		
		//affichage du sac
		if((e.getText().toUpperCase().equals("S"))){	
			
		
			//cas où on appuie sur S pour quitter le sac
			if (root0.getChildren().contains(sac)) {
				root0.getChildren().remove(sac);
			//cas où on appuie sur S pour voir le sac	
			}else {
				root0.getChildren().add(sac);
				sac.setLayoutX(j.coordX);
				sac.setLayoutY(j.coordY);
				
				j.actualiserSac(scene0);
				
				
			}
		}
		
		
		
	});
	
	}

	
	/**
	 * Getter du contenu de la carte
	 * 
	 * @return Contenu de la carte
	 */
	public GridPane getDonnees() {
		return donnees;
	}
	
}
