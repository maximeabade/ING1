package com.LaTourInfernale;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Stack;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

/**
 * Classe enfant de Grille 
 * 
 * Cette classe permet d'obtenir la carte du labyrinthe
 *
 * @see Grille
 * @author 4TOne
 * @version 1.0
 */
public class Labyrinthe extends Grille {
	/**
	 * Image source de la carte
	 */
	private Image[] imageEtage;
	
	/**
	 * Contient le tableau 2D d'entier de la carte 
	 */
	private int[][] tabLaby;
	
	/**
	 * Numero du niveau
	 * 
	 * @see Labyrinthe#getNumeroNiveau()
	 */
	private int numeroNiveau;
	
	private Map<Tuple<Integer, Integer>, Ennemi> listeEnnemis;
	
	/**
	 * Constructeur de l'objet Labyrinthe
	 * 
	 * @param width
	 * @param height
	 * @param numeroNiveau
	 */
	public Labyrinthe(double width, double height, int numeroNiveau) {
		super(width, height);
		this.imageEtage = getImageEtage();
		this.donnees = initEtage();
		this.numeroNiveau = numeroNiveau;
	}
	
	
	/**
	 * Initialise les images de la carte
	 * 
	 * @return images de la carte
	 */
	private Image[] getImageEtage() {
		Image[] imageEtage 	= new Image[10];
		Image sol 			= new Image(getClass().getResourceAsStream("sol.png"), 50, 50, false, false);
		Image roche			= new Image(getClass().getResourceAsStream("roche.png"), 50, 50, false, false);
		Image escalier 		= new Image(getClass().getResourceAsStream("escalier.png"), 50, 50, false, false);
		Image hero_avant 	= new Image(getClass().getResourceAsStream("hero_avant.png"), 50, 50, false, false);
		Image hero_dos 		= new Image(getClass().getResourceAsStream("hero_dos.png"), 50, 50, false, false);
		Image hero_droit 	= new Image(getClass().getResourceAsStream("hero_droit.png"), 50, 50, false, false);
		Image hero_gauche 	= new Image(getClass().getResourceAsStream("hero_gauche.png"), 50, 50, false, false);
		Image voleur		= new Image(getClass().getResourceAsStream("voleur.png"), 50, 50, false, false);
		Image sage			= new Image(getClass().getResourceAsStream("sage.png"), 50, 50, false, false);
		Image guerrier		= new Image(getClass().getResourceAsStream("guerrier_3.png"), 50, 50, false, false);
		
		imageEtage[0] = sol;
		imageEtage[1] = roche;
		imageEtage[2] = guerrier;			
		imageEtage[3] = sage;
		imageEtage[4] = voleur;
		imageEtage[5] = escalier;
		imageEtage[6] = hero_avant;
		imageEtage[7] = hero_dos;
		imageEtage[8] = hero_droit;
		imageEtage[9] = hero_gauche;

		
		
		return imageEtage;
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
		

		ImageView hero =  new ImageView(this.imageEtage[6]) ;
		ImageView sol = new ImageView(this.imageEtage[0]);

		switch(typeMouvement) {
		
		case 0: 
			//Ajout de la face avant du hero a la GridPane
			 hero = new ImageView(this.imageEtage[7]);
		break;	
		case 1: 
			//Ajout de la face bas du hero a la GridPane
			 hero = new ImageView(this.imageEtage[6]);
		break;	
		case 2: 
			//Ajout de la face gauche du hero a la GridPane
			 hero = new ImageView(this.imageEtage[9]);
		break;	
		case 3: 
			//Ajout de la face droite du hero a la GridPane
			 hero = new ImageView(this.imageEtage[8]);
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
	 * Création du tableau d'entier 20x36 source du Labyrinthe
	 * 
	 * @return tableau 2D d'enier de la carte
	 */
	private int[][] initLaby() {
		
		int[][] tab = new int[20][36];
		for(int i = 0; i < this.height; i++) {
			for(int j = 0; j <this.width; j++) {
				
				if(i%2 ==1 || j%2 == 1) {
					tab[i][j] = -1;
				}
				else {
					tab[i][j] = 0;
				}
				
			}
		}
		return tab;
	}
	
	/**
	 * <pre>
	 * Donne la direction de la prochaine case à utiliser dans l'algo
	 *  si pas de probleme:   1    sinon return 42 (pour pas de voisin)
	 *                      4 + 2	
	 *                        3	
	 * </pre>
	 * 
	 * @param tab
	 * @param posX
	 * @param posY
	 * @param x
	 * @param y
	 * @return code de direction
	 */				 
	private int trouverNouvelleDir(int[][] tab, Stack<Integer> posX, Stack<Integer> posY, int x, int y) {
		// Liste des directions possibles
		List<Integer> dir = new ArrayList<Integer>();

		//Aller en Haut
		try {
			if(tab[y  - 2][x	] == 0) {dir.add(1);}
		}
		catch (Exception e) {		}
		
		//Aller a Droite
		try {
			if(tab[y	][x	+	2] == 0) {dir.add(2);}
		}
		catch (Exception e) {		}
		
		//Aller en Bas
		try {
			if(tab[y  + 2][x	] == 0) {dir.add(3);}
		}
		catch (Exception e) {		}
		
		//Aller a Gauche
		try {
			
			if(tab[y     ][x - 2] == 0) {dir.add(4);}
		}
		catch (Exception e) {		}
		
		if(dir.size() > 0) {
			Random rand = new Random();
			return dir.get(rand.nextInt(dir.size()));
		}
		else {			
			return 42;
		}
	}
	
	/**
	 * Actualisation de la pile des y avec la prochaine coordonnée
	 * 
	 * @param tab
	 * @param posY
	 * @param y
	 * @param dir
	 * @return la nouvelle coordonnée en y
	 */
	private int suivantY(int[][] tab, Stack<Integer> posY, int y, int dir) {
		if(dir == 1) {
			posY.push(y-2);
			return y-2;
		}
		else if(dir == 3){
			posY.push(y+2);
			return y+2;
		}
		else {
			posY.push(y);
			return y;
		}
	}
	
	/**
	 * Actualisation de la pile des x avec la prochaine coordonnée
	 * 
	 * @param tab
	 * @param posX
	 * @param x
	 * @param dir
	 * @return la nouvelle coordonnee en x
	 */
	private int suivantX(int[][] tab, Stack<Integer> posX, int x, int dir) {
		if(dir == 2) {
			posX.push(x+2);
			return x+2;
		}
		else if(dir == 4){
			posX.push(x-2);
			return x+2;
		}
		else {
			posX.push(x);
			return x;
		}
	}
	
	/**
	 * Effectue le deplacement et renvoie la prochaine coordonnée
	 * 
	 * @param tab
	 * @param posX
	 * @param posY
	 * @param x
	 * @param y
	 * @param dir
	 * @return les nouvelles coordonnées
	 */
	private ArrayList<Integer> suivant(int[][] tab, Stack<Integer> posX, Stack<Integer> posY, int x, int y, int dir){
		ArrayList<Integer> derniereCase = new ArrayList<Integer>();
		derniereCase.add(suivantX(tab, posX, x, dir));
		derniereCase.add(suivantY(tab, posY, y, dir));
		return derniereCase;

	}
	
	/**
	 * Reviens une case en arriere
	 * 
	 * @param posX
	 * @param posY
	 * @return les précédentes coordonnées
	 */
	private Tuple<Integer,Integer> precedent(Stack<Integer> posX, Stack<Integer> posY) {
		Tuple<Integer,Integer> derniereCase = new Tuple<Integer,Integer>(posX.peek(), posY.peek());
		
		posX.pop();
		posY.pop();
		
		return derniereCase;
	}
	
	
	/**
	 * convertie le tableau d'entier en GridPane d'ImageView
	 * 
	 * @param tab
	 * @return la GridPane de la carte
	 */
	private GridPane toGridPane(int[][] tab) {
		GridPane grid = new GridPane();
		
		for(int i = 0; i < this.height; i++) {
			
			for(int j = 0; j < this.width; j++) {
				
				if(tab[i][j] == -2) {
					ImageView escalier = new ImageView(this.imageEtage[5]);
					grid.add(escalier, j, i);
				}
				
				else if(tab[i][j] == 1) {
					ImageView sol = new ImageView(this.imageEtage[0]);
					grid.add(sol, j, i);
				}
				
				else if(tab[i][j] == 2) {
					ImageView sol = new ImageView(this.imageEtage[0]);
					grid.add(sol, j, i);
					ImageView guerrier = new ImageView(this.imageEtage[2]);
					grid.add(guerrier, j, i);
				}
				
				else if(tab[i][j] == 3) {
					ImageView sol = new ImageView(this.imageEtage[0]);
					grid.add(sol, j, i);
					ImageView sage = new ImageView(this.imageEtage[3]);
					grid.add(sage, j, i);
				}
				else if(tab[i][j] == 4) {
					ImageView sol = new ImageView(this.imageEtage[0]);
					grid.add(sol, j, i);
					ImageView voleur = new ImageView(this.imageEtage[4]);
					grid.add(voleur, j, i);
				}
				
				
				else if(tab[i][j] == -1) {
					ImageView roche = new ImageView(this.imageEtage[1]);
					grid.add(roche, j, i);
				}		
			}
		}
		ImageView hero =  new ImageView(new Image(getClass().getResourceAsStream("hero_avant.png"), 50, 50, false, false));
		grid.add(hero, 0, 0);
		return grid;
		
	}
	
	/**
	 * Fais la liaison entre deux cases
	 * @param tab
	 * @param posX
	 * @param posY
	 * @param x
	 * @param y
	 */
	private void construireLiaison(int[][] tab, Stack<Integer> posX, Stack<Integer> posY, int x, int y) {
		if(!posX.empty() && !posY.empty()) {
			
			posX.pop();
			int oldX = posX.peek();
			posX.push(x);
			
			posY.pop();
			int oldY = posY.peek();
			posY.push(y);
			
			int midX = (oldX + x) / 2;
			int midY = (oldY + y) / 2;
			
			tab[midY][midX] = 1;
		}
		
	}
	
	/**
	 * Création du labyrinthe
	 * @return la carte 
	 */
	@SuppressWarnings("unchecked")
	private GridPane initEtage() {
		int[][] laby = new int[20][36];
		Tuple<Integer,Integer> derniereCase = new Tuple<Integer,Integer>(0,0);
		Map<Tuple<Integer,Integer>, Integer> referenceLongueur = new HashMap<Tuple<Integer,Integer>, Integer>();
		referenceLongueur.put(derniereCase, 0);
		
		
		laby =initLaby();
//				afficherTableau(laby);
		
		Stack<Integer> posX = new Stack<Integer>();
		Stack<Integer> posY = new Stack<Integer>();
		
		//Initialisation en (0,0)
		int departX = 0;
		int departY = 0;
		posX.push(departX);
		posY.push(departY);
		
		suivant(laby, posX, posY, posX.peek(), posY.peek(), 2);
		
		int longueur = 0;
		
		// Recurence
		while(!posX.empty() && !posY.empty() ) {
			laby[posY.peek()][posX.peek()] = 1;
			int dir = trouverNouvelleDir(laby, posX, posY, posX.peek(), posY.peek());
			
			if(dir == 42) {
				longueur--;
				Tuple<Integer,Integer> candidat = precedent(posX, posY);
//						System.out.println(referenceLongueur.toString());
				int val = (int) referenceLongueur.values().toArray()[0];
				if(val < longueur) {
					referenceLongueur.clear();
					referenceLongueur.put(candidat, longueur);
				}
			}
			else {			
				longueur++;
				suivant(laby, posX, posY, posX.peek(), posY.peek(), dir);
				construireLiaison(laby, posX, posY, posX.peek(), posY.peek());
				
			}
		}
		
//				derniereCase = derniereCase(laby, 0, 0, 0, derniereCase);
		
		derniereCase = (Tuple<Integer, Integer>) referenceLongueur.keySet().toArray()[0]; 

		laby[derniereCase.getY()][derniereCase.getX()] = -2;
		
		this.listeEnnemis = genEnnemis(laby, derniereCase.getY(), derniereCase.getX());
		

		this.tabLaby = laby;
//				afficherTableau(laby);
		return toGridPane(laby);
	}
	
	
	/**
	 * Generation d'ennemis aléatoirement dans le tableau
	 * 
	 * @param tab
	 * @param derniereCaseX
	 * @param derniereCaseY
	 */
	public Map<Tuple<Integer, Integer>, Ennemi> genEnnemis(int[][] tab, int derniereCaseX, int derniereCaseY) {
		Map<Tuple<Integer,Integer>, Ennemi> listeEnnemis = new HashMap<Tuple<Integer,Integer>, Ennemi>();
		int cptEnnemis = 50;
		int nbVoleur = 0;
		int nbSage= 0;
		int nbStandard= 0;
		
		
		
		while(cptEnnemis > 0) {
			Random rand = new Random();
			int x = rand.nextInt((int) this.width-1);
			int y = rand.nextInt((int) this.height-1);
			float proba = rand.nextFloat();
			if(tab[y][x] == 1 && (x != 0 && y != 0) && (x != derniereCaseX && y != derniereCaseY)) {
				
				if(proba < 0.1) {
					nbVoleur++;
					Voleur voleur = new Voleur("Voleur" + nbVoleur, x,y);
					listeEnnemis.put(new Tuple<Integer, Integer>(x,y), voleur);
					//Voleur
					tab[y][x] = 4;
					cptEnnemis--;
				}
				else if(proba < 0.25) {
					//Sage
					nbSage++;
					Sage sage = new Sage("Sage"+nbSage,x,y);
					listeEnnemis.put(new Tuple<Integer, Integer>(x,y), sage);
					tab[y][x] = 3;
					cptEnnemis--;
				}
				else {						
					nbStandard++;
					Guerrier guerrier = new Guerrier("Guerrier" + nbStandard, x, y);
					listeEnnemis.put(new Tuple<Integer, Integer>(x,y), guerrier);
					tab[y][x] = 2;
					cptEnnemis--;
				}
			}				
		}
		System.out.println("Voleur: " + nbVoleur);
		System.out.println("Sage: " + nbSage);
		System.out.println("Standard: " + nbStandard);
		return listeEnnemis;
	}
	
	/**
	 * @return Tableau 2D de la carte
	 */
	public int[][] getTabLaby() {
		return tabLaby;
	}

	/**
	 * Setter des images de la carte
	 * @param imageEtage
	 */
	public boolean entrerCombat(int coordX, int coordY) {
		
		boolean verif = false; 
		
		//coordonnées porte de la tour 		
		if ((coordX-1 == 9) && (coordY==6)){
			verif = true;
		}
		
		return verif;
	}	
	
	/**
	 * Setter image source du labyrinthe
	 * 
	 * @param imageEtage
	 */
	public void setImageEtage(Image[] imageEtage) {
		this.imageEtage = imageEtage;
	}


	/**
	 * Getter listes des ennemis
	 * @return
	 */
	public Map<Tuple<Integer, Integer>, Ennemi> getListeEnnemis() {
		return listeEnnemis;
	}


	/**
	 * Verifie le deplacement du joueur
	 * @param coordX
	 * @param coordY
	 * @return true si le deplacement est possible, false sinon
	 */
	public boolean verifDeplacement(int coordX, int coordY ) {

		boolean verif = false;
		
		if (this.getTabLaby()[coordY][coordX] != -1) {
			verif = true;
		} 

		return verif;
		
	}
	
	/**
	 * Verifie si le joueur a atteint l'escalier
	 * 
	 * @param coordX
	 * @param coordY
	 * @return true si le joueur a atteint l'escalier, false sinon
	 */
	public boolean verifEscalier(int coordX, int coordY ) {
		
		boolean verif = false;
		
		if (this.getTabLaby()[coordY][coordX] == -2){
			verif = true;
		} 
		
		return verif;
		
	}
	
	/**
	 * Verifie si le joueur peut entrer en combat avec un ennemi
	 * 
	 * @param coordX
	 * @param coordY
	 * @return true si un combat est possible, false sinon
	 */
	public int verifCombat(int coordX, int coordY) {
		int typeEnnemi = 0;
		
		//ennemi guerrier
		if((this.getTabLaby()[coordY][coordX] == 2)) {
			typeEnnemi = 2;
		}
		//ennemi sage
		if((this.getTabLaby()[coordY][coordX] == 3)) {
			typeEnnemi = 3;
		}
		//ennemi voleur
		if((this.getTabLaby()[coordY][coordX] == 4)) {
			typeEnnemi = 4;
		}
		return typeEnnemi;
	}
	
	/**
	 * Actualise la derniere position d'un ennemi
	 * 
	 * @param CoordX
	 * @param CoordY
	 * @param typeEnnemi
	 */
	public void actualiserDernierePos(int CoordX, int CoordY,int typeEnnemi) {

		ImageView sol = new ImageView(imageEtage[0]);			
		ImageView hero = new ImageView(imageEtage[6]);			
		ImageView ennemi = new ImageView(imageEtage[typeEnnemi]);			

		this.donnees.add(hero,0,0);

		//effacer ancienne position du hero
		this.donnees.add(sol,CoordX,CoordY);
		this.donnees.add(ennemi,CoordX,CoordY);

		
		
	}
	
	/**
	 * Actualise la carte
	 * 
	 * @param grille
	 * @param typeMouvement
	 * @param nCoordX
	 * @param nCoordY
	 * @param aCoordX
	 * @param aCoordY
	 */
	public void actualiserGrille(Grille grille, int typeMouvement, int nCoordX, int nCoordY, int aCoordX, int aCoordY) {
		

		ImageView hero =  new ImageView(this.imageEtage[3]) ;
		ImageView sol = new ImageView(this.imageEtage[0]);

		switch(typeMouvement) {
		
		case 0: 
			//Ajout de la face avant du hero a la GridPane
			 hero = new ImageView(this.imageEtage[4]);
		break;	
		case 1: 
			//Ajout de la face bas du hero a la GridPane
			 hero = new ImageView(this.imageEtage[3]);
		break;	
		case 2: 
			//Ajout de la face gauche du hero a la GridPane
			 hero = new ImageView(this.imageEtage[6]);
		break;	
		case 3: 
			//Ajout de la face droite du hero a la GridPane
			 hero = new ImageView(this.imageEtage[5]);
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
	 * Getter du numero du niveau
	 * @return numero du niveau
	 */
	public int getNumeroNiveau() {
		return numeroNiveau;
	}
	
	/**
	 * Setter du numero du niveau
	 * @param numeroNiveau
	 */
	public void setNumeroNiveau(int numeroNiveau) {
		this.numeroNiveau = numeroNiveau;
	}
	
	/**
	 * Affiche un nouveau niveau
	 * @param niveau
	 * @param lobby
	 * @param j
	 * @param primaryStage
	 * @param sceneLobby
	 * @param rootLobby
	 * @param numeroNiveau
	 */
	public void creerNiveau(Labyrinthe niveau,Lobby lobby, Joueur j, Stage primaryStage,Scene sceneLobby,Group rootLobby, int numeroNiveau) {
		
		/* Affichage */
		Label infosJoueur = new Label( " Nom du joueur : " +j.getNom() + "\n Vie : " +j.getVie()+ "\n Argent : " +j.getArgent() + "\n Sac : " +j.getSac() );

		Label niveauETAGE = new Label( "Niveau ="+ this.numeroNiveau);
		niveauETAGE.setLayoutX(250);;
					
		
		switch(numeroNiveau) {
				
		case(2):
			
		//création des groupes
	

				
		//création des labyrinthes
		Labyrinthe niveau2 = new Labyrinthe(1800/50, 1000/50, numeroNiveau);
				
		rootLobby.getChildren().clear();
		rootLobby.getChildren().addAll(niveau2.getDonnees(),niveauETAGE);

		//on place le joueur en debut de labyrinthe
		j.reinitialiserCoord();
		
		//on permet au joueur de se déplacer
		niveau2.seDeplacerLab(niveau2,lobby,j, sceneLobby,rootLobby,primaryStage);
			
		//Titre de la fenêtre
		primaryStage.setTitle("Niveau 2");
		
		//Affichage de la fenetre
		primaryStage.show();
		
		break;
		
		case(3):
			
		//création des labyrinthes
		Etage_Boss niveau3 = new Etage_Boss(1800/50, 1000/50);			
							
						
		rootLobby.getChildren().clear();
		rootLobby.getChildren().addAll(niveau3.getDonnees(),niveauETAGE);
		
		//on place le joueur en debut de labyrinthe
		j.reinitialiserCoordBoss();
		
		//on permet au joueur de se déplacer
		niveau3.seDeplacerBoss(j,niveau,lobby,sceneLobby,rootLobby,primaryStage);
		
		primaryStage.setTitle("Boss");
	
		
		//Affichage de la fenetre
		primaryStage.show();
		
		break;			
		
		
		default:
			
			System.out.println(numeroNiveau);
			break;
			
		
		
		}


		
		
	}
		
		
	
	/**
	 * Permet au joueur de se deplacer dans le labyrinthe
	 * @param laby
	 * @param lobby
	 * @param j
	 * @param sceneLobby
	 * @param rootLobby
	 * @param primaryStage
	 */
	public void seDeplacerLab(Labyrinthe laby,Lobby lobby,Joueur j,Scene sceneLobby,Group rootLobby, Stage primaryStage) {


	numeroNiveau = laby.numeroNiveau;
	//touche clavier	
	sceneLobby.setOnKeyPressed(e->{
		
		
	if(rootLobby.getChildren().contains(laby.getDonnees())) {

		try {

			//deplacement en haut
			if((e.getText().toUpperCase().equals("8"))){	

					int typeEnnemi = verifCombat(j.coordX, j.coordY-1);

					if(verifEscalier(j.coordX,j.coordY-1)) {
						numeroNiveau++;
						creerNiveau(laby,lobby,j,primaryStage,sceneLobby,rootLobby, numeroNiveau);							
					}
					else if(typeEnnemi!=0) { // Bloque le Deplacement tant que le joueur n'a pas gagné le combat
						//changement de "scene"
						rootLobby.getChildren().clear();
						//on enlève le monstre du labyrinthe
						this.getTabLaby()[j.coordY-1] [j.coordX] = 1;
						//le joueur avance
						j.coordY--;

						//Recuperation de l'objet Ennemi (Voleur / Guerrier / Sage)
						switch (typeEnnemi) {
						
						case(2):		
							//création guerrier
							Guerrier guerrier = new Guerrier("Guerrier", j.coordX, j.coordY-1);
							guerrier.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
						break;	
						
						case(3):		
							//création Sage
		
							Sage sage = new Sage("Sage", j.coordX, j.coordY-1);
							sage.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
						break;		
						
						case(4):		
							//création voleur
							Voleur voleur = new Voleur("Voleur", j.coordX, j.coordY-1);
							voleur.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
						break;		
						
						}
						//on actualise la grille
						this.actualiserGrille(0,j.coordX,j.coordY,j.coordX,j.coordY+1);	
						primaryStage.show();
						
						//Lancement de la fonction LancerCombat avec l'objet Ennemi recupérer
						System.out.println("Combat");
					}
					
					else if(verifDeplacement(j.coordX,j.coordY-1)) {
						j.coordY--;
						this.actualiserGrille(0,j.coordX,j.coordY,j.coordX,j.coordY+1);	
					 
					}
			}
		}
			catch(Exception error) { 	}
			
		
		//deplacement en bas
		try {
			if((e.getText().toUpperCase().equals("2"))){
				
				int typeEnnemi = verifCombat(j.coordX, j.coordY+1);

				if(verifEscalier(j.coordX,j.coordY+1)) {
					numeroNiveau++;								
					creerNiveau(laby,lobby,j,primaryStage, sceneLobby,rootLobby,numeroNiveau);							
				}	
				
				else if(typeEnnemi!=0) {
					//changement de "scene"
					rootLobby.getChildren().clear();
					//on enlève le monstre du labyrinthe
					this.getTabLaby()[j.coordY+1] [j.coordX] = 1;
					//le joueur avance
					j.coordY++;						
					//Recuperation de l'objet Ennemi (Voleur / Guerrier / Sage)
					switch (typeEnnemi) {
					
					case(2):
						//création guerrier
						Guerrier guerrier = new Guerrier("Guerrier", j.coordX, j.coordY+1);
						//lancement de combat
						guerrier.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
					break;	
					case(3):
						//création 
						Sage sage = new Sage("Sage", j.coordX, j.coordY+1);
						//lancement de combat
						sage.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
					break;	
					case(4):
						//création 
						Voleur voleur = new Voleur("Voleur", j.coordX, j.coordY+1);
						//lancement de combat
						voleur.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
					break;	

					}
					
					//on actualise la grille
					this.actualiserGrille(1,j.coordX,j.coordY,j.coordX,j.coordY-1);	
					primaryStage.show();
				}
				else if(verifDeplacement(j.coordX,j.coordY+1)) {
					j.coordY++;
					this.actualiserGrille(1,j.coordX,j.coordY,j.coordX,j.coordY-1);	
				}
			}	
		
		}
		catch (Exception error) {	}			
		
		//deplacement à gauche
        try {
            if((e.getText().toUpperCase().equals("4"))){

				int typeEnnemi = verifCombat(j.coordX-1, j.coordY);

                if(verifEscalier(j.coordX-1,j.coordY)) {
                    numeroNiveau++;
					creerNiveau(laby,lobby,j,primaryStage,sceneLobby,rootLobby, numeroNiveau);							
                }
                else if(typeEnnemi!=0) {
                	//changement de "scene"
					rootLobby.getChildren().clear();
					//on enlève le monstre du labyrinthe									
					this.getTabLaby()[j.coordY] [j.coordX-1] = 1; 
                    j.coordX--;
					//Recuperation de l'objet Ennemi (Voleur / Guerrier / Sage)                            	
                    switch(typeEnnemi) {
                    
                    case(2):
						//création guerrier
                    	Guerrier guerrier = new Guerrier("Guerrier", j.coordX-1, j.coordY);
                		//lancement de combat
						guerrier.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
					break;
                    
                    case(3):
						//création sage
                    	Sage sage = new  Sage("Sage", j.coordX-1, j.coordY);
                		//lancement de combat
                    	sage.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
					break;
					
                    
                    case(4):
						//création 
                    	Voleur voleur = new Voleur("Voleur", j.coordX-1, j.coordY);
                		//lancement de combat
                    	voleur.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
					break;
					

                   }
					//on actualise la grille
                    this.actualiserGrille(2,j.coordX,j.coordY,j.coordX+1,j.coordY);
		
                	primaryStage.show();

                }

                else if(verifDeplacement(j.coordX-1,j.coordY)) {
                    j.coordX--;
                    this.actualiserGrille(2,j.coordX,j.coordY,j.coordX+1,j.coordY);
                }
            }

        }
        catch (Exception error) {	}			
		//deplacement à droite
		try {
			if((e.getText().toUpperCase().equals("6"))){
				
				int typeEnnemi = verifCombat(j.coordX+1, j.coordY);

				
				if(verifEscalier(j.coordX+1,j.coordY)) {
					numeroNiveau++;									
					creerNiveau(laby,lobby,j,primaryStage,sceneLobby,rootLobby, numeroNiveau);							
				}	

				else if(typeEnnemi!=0) {
					//changement de "scene"
					rootLobby.getChildren().clear();
					//on enlève le monstre du labyrinthe
					this.getTabLaby()[j.coordY] [j.coordX+1] = 1;
					//le joueur avance
					j.coordX++;
					
					//Recuperation de l'objet Ennemi (Voleur / Guerrier / Sage)
					switch(typeEnnemi) {
					
						case(2):
							//création guerrier
							Guerrier guerrier = new Guerrier("Guerrier", j.coordX+1, j.coordY);
							//lancement de combat
							guerrier.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
						break;	
						
						case(3):
							//création guerrier
							Sage sage = new Sage("Sage", j.coordX+1, j.coordY);
							//lancement de combat
							sage.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
						break;	
						
						case(4):
							//création guerrier
							Voleur voleur = new Voleur("Voleur", j.coordX+1, j.coordY);
							//lancement de combat
							voleur.lancerCombat(primaryStage,sceneLobby,rootLobby,laby,lobby, j);
						break;							
					}	
						
						
						//on actualise la grille
						this.actualiserGrille(3,j.coordX,j.coordY,j.coordX-1,j.coordY);	
						primaryStage.show();
						
						
					
				}
				
				else if(verifDeplacement(j.coordX+1,j.coordY)) {
					j.coordX++;
					this.actualiserGrille(3,j.coordX,j.coordY,j.coordX-1,j.coordY);
					
				}
				
			} 				
		
		}
		catch (Exception error) {	}
	}
	

		
	});

			
		
	
	}

}