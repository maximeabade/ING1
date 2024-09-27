package com.LaTourInfernale;

import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
/**
 * Classe enfant de Grille
 * 
 * L'objet Etage_Boss contient l'affichage de la carte de l'étage du boss 
 * 
 * @see Grille
 * 
 * @author 4TOne
 * @version 1.0
 */
public class Etage_Boss extends Grille {
	
	/**
	 * Tableau 2D d'entier dont chacune des valeurs est associé à une ImageView de la carte
	 * 
	 * @see Etage_Boss#getTabBoss()
	 */
	private int[][] tabBoss;
	
	/**
	 * Tableau des Images source de la carte
	 * 
	 * @see Etage_Boss#getImageBoss()
	 */
	private Image[] imageBoss;
	
	/**
	 * Constructeur de l'objet Etage_Boss
	 * 
	 * @param width
	 * @param height
	 * 
	 * @see Grille#Grille(double, double)
	 */
	public Etage_Boss(double width, double height) {
		super(width, height);
		this.imageBoss = this.getImageBoss();
		this.tabBoss = initBoss();
		
	}
	
	/**
	 * Getter des Images sources de la carte
	 * 
	 * @return Images sources de la carte
	 */
	public Image[] getImageBoss() {
		Image[] imageBoss = new Image[9];
		Image sol 			= new Image(getClass().getResourceAsStream("solBoss.png"), 50, 50, false, false);
		Image roche			= new Image(getClass().getResourceAsStream("roche.png"), 50, 50, false, false);
		Image boss 			= new Image(getClass().getResourceAsStream("boss.png"), 150, 100, false, false);
		Image noir			= new Image(getClass().getResourceAsStream("noir.png"), 50, 50, false, false);
		Image hero_avant 	= new Image(getClass().getResourceAsStream("hero_avant.png"), 50, 50, false, false);
		Image hero_dos 		= new Image(getClass().getResourceAsStream("hero_dos.png"), 50, 50, false, false);
		Image hero_droit 	= new Image(getClass().getResourceAsStream("hero_droit.png"), 50, 50, false, false);
		Image hero_gauche 	= new Image(getClass().getResourceAsStream("hero_gauche.png"), 50, 50, false, false);
		Image lave 			= new Image(getClass().getResourceAsStream("lave.gif"), 50, 50, false, false);
		
		imageBoss[0] = sol;
		imageBoss[1] = roche;
		imageBoss[2] = boss;
		imageBoss[3] = noir;
		imageBoss[4] = hero_avant;
		imageBoss[5] = hero_dos;
		imageBoss[6] = hero_droit;
		imageBoss[7] = hero_gauche;
		imageBoss[8] = lave;
		return imageBoss;
	} 
	
	/**
	 * Getter du tableau 2D d'entier de la carte
	 * @return tableau 2D de la carte
	 */
	public int[][] getTabBoss() {
		return tabBoss;
	}

	/**
	 * Initialise la carte du Boss
	 * @return carte du Boss
	 */
	private int[][] initBoss(){
		
		int[][] labyBoss = new int[20][36];
		labyBoss = initTabBoss();
		
		this.donnees = toGridPaneBoss(labyBoss);
		return labyBoss;
		
	}
	
	/**
	 * Intialise le tableau 2D d'entier de la carte 
	 * 
	 * @return
	 */
	private int[][] initTabBoss(){
		int[][] tab = new int[20][36];
		
		for(int i = 0; i < this.height; i++) {
			for(int j = 0; j <this.width; j++) {
		
				
				if((i == 5 ) && !(j < 10 || j > 24) ) {
					
					//mur
					tab[i][j] = 0;
					
				}else if((i == 6 || i == 13) && ((j > 9 && j < 16) || j > 18 && j < 25) ) {
					
					//mur
					tab[i][j] = 0;
					
				}else if((i == 7 || i == 12) && ((j > 9 && j < 14) || j > 20 && j < 25) ) {
					
					//mur
					tab[i][j] = 0;
					
				}else if((i == 8 || i == 11) && ((j > 9 && j < 12) || (j > 22 && j < 25) || ((j == 16 || j == 17 || j == 18) && i == 8) || ((j == 15 || j == 19) && i == 11)) ) {
					
					//mur
					tab[i][j] = 0;
					
				}else if((i == 9 || i == 10) && ((j > 9 && j < 11) || j > 23 && j < 25 || ((j == 15 || j == 19) && i == 9) || (j == 14 || j == 20) && i == 10) ) {
					
					//mur
					tab[i][j] = 0;
						
				}else if( (i > 13) && (j == 16 || j == 17 || j == 18)) {
					
					//sol
					tab[i][j] = -1;
					
				}else if( (i > 13) && (j == 15 || j == 19)) {
					
					//mur
					tab[i][j] = 0;

					
				}else if( (i < 6) || (i > 13) || (j <10) || (j > 24)){
					//noir
					tab[i][j] = -2;
					
				}else {
					
					//sol
					tab[i][j] = -1;
					
				}
		

			}	
		}
		tab[9][16] = -8;
		tab[9][17] = -8;
		tab[9][18] = -8;
		tab[10][16] = -8;
		tab[10][17] = -8;
		tab[10][18] = -8;
		tab[19][17] = -1;
		
		tab[18][17] = 1;
		tab[18][18] = 1;
		tab[15][16] = 1;
		tab[14][18] = 1;
		tab[12][17] = 1;
		tab[6][16]	= 1;
		tab[6][18] 	= 1;
		tab[11][23]	= 1;
		tab[10][22]	= 1;
		tab[9][12]	= 1;
		
//		afficherTableau();
		
		 return tab;
		 
		
	}
	
	/**
	 * Actualise la grille apres un déplacement
	 * 
	 * @param typeMouvement
	 * @param nCoordX
	 * @param nCoordY
	 * @param aCoordX
	 * @param aCoordY
	 */
	private void actualiserGrille(int typeMouvement, int nCoordX, int nCoordY, int aCoordX, int aCoordY) {

		ImageView hero =  new ImageView(this.imageBoss[3]) ;
		ImageView sol = new ImageView(this.imageBoss[0]);

		switch(typeMouvement) {
		
		case 0: 
			//Ajout de la face avant du hero a la GridPane
			 hero = new ImageView(this.imageBoss[5]);
		break;	
		case 1: 
			//Ajout de la face bas du hero a la GridPane
			 hero = new ImageView(this.imageBoss[4]);
		break;	
		case 2: 
			//Ajout de la face gauche du hero a la GridPane
			 hero = new ImageView(this.imageBoss[7]);
		break;	
		case 3: 
			//Ajout de la face droite du hero a la GridPane
			 hero = new ImageView(this.imageBoss[6]);
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
	 * Conversion du tableau 2D d'entier en GridPane
	 * @param tab
	 * @return GridPane correspondant à la carte
	 */
	private GridPane toGridPaneBoss(int[][] tab) {
		
		GridPane grid = new GridPane();
		
		for(int i = 0; i < this.height; i++) {
	
			for(int j = 0; j < this.width; j++) {
				
				
				if(tab[i][j]==0) {
					
					ImageView roche = new ImageView(imageBoss[1]);
					grid.add(roche, j, i, 1, 1);
					
				}else if((tab[i][j]==-1)||(tab[i][j]==-8)){
					
					ImageView sol = new ImageView(imageBoss[0]);
					grid.add(sol, j, i);
					
				} else if(tab[i][j]==-2) {
				
					ImageView noir = new ImageView(imageBoss[8]);
					grid.add(noir, j, i, 1, 1);
					
				}
				else if(tab[i][j]==1) {
					ImageView lave = new ImageView(imageBoss[8]);
					grid.add(lave, j, i, 1, 1);
				}
			
				
			}
		}
		
		//Ajout du boss
		ImageView boss = new ImageView(imageBoss[2]);
		
		grid.add(boss, 16, 9, 3, 2);
		
		
		//Ajout de la face avant du hero a la GridPane
		ImageView hero_avant = new ImageView(imageBoss[5]);
		
		
		//Ajout de de l'image dans grid
		grid.add(hero_avant,17,19, 1,1);
		return grid;
		
	}
		

	/**
	 * Verifie en fonction de la position du joueur si celui ci est prêt à se battre
	 * 
	 * @param coordX
	 * @param coordY
	 * @return true si le joueur est a coté du boss pour combattre; false sinon
	 */
	private boolean verifCombat(int coordX, int coordY) {
		
		boolean verif = false;
		
		if((this.getTabBoss()[coordY][coordX] == -8)) {
			
			verif = true;	
		}
	
		
		return verif;
	}

	/**
	 * Verifie si la case ou souhaite aller le joueur est valide
	 * 
	 * @param coordX
	 * @param coordY
	 * @return true si la case ou le joueur souhaite allé est valide, false sinon
	 */
	private boolean verifDeplacement(int coordX, int coordY ) {

		boolean verif = false;
		
		if (this.getTabBoss()[coordY][coordX] == -1) {
			verif = true;
		} 
		
		return verif;
		
	}
	
	/**
	 * Permet au joueur de se déplacer dans l'etage du boss
	 * 
	 * @param j
	 * @param laby
	 * @param lobby
	 * @param sceneLobby
	 * @param rootLobby
	 * @param primaryStage
	 */
	public void seDeplacerBoss(Joueur joueur,Labyrinthe laby, Lobby lobby, Scene sceneLobby,Group rootLobby, Stage primaryStage) {

		//touche clavier	
		sceneLobby.setOnKeyPressed(e->{
				
			System.out.println("X = "+joueur.getCoordX()+" Y =  "+joueur.getCoordY());

			//deplacement en haut
			if((e.getText().toUpperCase().equals("8"))){	
				
				if(verifCombat(joueur.coordX,joueur.coordY-1)) {
					Boss boss = new Boss("Boss", joueur.coordX, joueur.coordY-1);
					boss.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, joueur);
				}
				
				if(verifDeplacement(joueur.coordX,joueur.coordY-1)) {
					joueur.coordY--;
					this.actualiserGrille(0,joueur.coordX,joueur.coordY,joueur.coordX,joueur.coordY+1);	
				}	
				
			}
			//deplacement en bas
			if((e.getText().toUpperCase().equals("2"))){
				if(verifDeplacement(joueur.coordX,joueur.coordY+1)) {					
					joueur.coordY++;
					this.actualiserGrille(1,joueur.coordX,joueur.coordY,joueur.coordX,joueur.coordY-1);	
				}
			}	
								
			//deplacement à gauche
			if((e.getText().toUpperCase().equals("4"))){
				if(verifDeplacement(joueur.coordX-1,joueur.coordY)) {
					joueur.coordX--;
					this.actualiserGrille(2,joueur.coordX,joueur.coordY,joueur.coordX+1,joueur.coordY);
				}
			}
			//deplacement à droite
			if((e.getText().toUpperCase().equals("6"))){
				if(verifDeplacement(joueur.coordX+1,joueur.coordY)) {
					joueur.coordX++;
					this.actualiserGrille(3,joueur.coordX,joueur.coordY,joueur.coordX-1,joueur.coordY);
				}
			} 				
		});

	}
	
}