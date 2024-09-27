package com.LaTourInfernale;

import java.util.ArrayList;

import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * Classe enfant de Guerrier
 * 
 * Permet de créer un ennemi de type voleur
 * 
 * @author 4TOne
 * @version 1.0
 *
 */
public class Voleur extends Guerrier {
	/**
	 * Sac du voleur
	 * 
	 * @see Voleur#getSacVoleur()
	 */
	private ArrayList<Item> sacVoleur;
	
	/**
	 * Constructeur de l'objet Voleur
	 * 
	 * @param nom
	 * @param coordX
	 * @param coordY
	 */
	public Voleur(String nom, int coordX, int coordY) {
		super(nom, coordX, coordY);
		
		//initialise la vie à 20
		this.vie = 60;
		this.vieMax = 60;
		//initialise l'attauqe a 10
		this.atk = 11;
				
		this.setSacVoleur(new ArrayList<Item>());
				
	}
	
	/**
	 * Enlève Item du sac (attaque des voleurs)
	 * 
	 * @param item
	 */
	public void supprimerItem(Item item){
		this.sacVoleur.remove(item);
	}
	
	/**
	 * Fonction pour rechercher un item dans le sac
	 * 
	 * @param item
	 * @return true si l'item est trouvé, false sinon
	 */
	//
	public boolean chercherItem(Item item) {
	
	//déclaration variables	
	boolean verif;
	
	//cas où l'item n'est pas trouvé
	verif = false;
	
		for (Item i :  sacVoleur) {		
			//cas où l'élève avec le même nom est trouvé dans la liste
			if(i.equals(item)) {			
			  verif = true;		
			}
		}
		/* retourne l'élève recherché ou  null */
		return(verif);
	}
	
	/**
	 * Permet au voleur d'utiliser un item
	 */
	public void utiliserItem() {
		
		if(this.chercherItem(this.getSacVoleur().get(0))) {
			this.vie = this.vie + this.getSacVoleur().get(0).getEffet();
			this.supprimerItem(this.getSacVoleur().get(0));
		}
	}
	
	/**
	 * Permet au voleur de voler un Item au joueur
	 * @param j
	 */
	public void VolerItem(Joueur j) {
		
		//si le sac est rempli, on vole le 1er item
		if (j.getSac().size()>0) {

			this.sacVoleur.add(j.getSac().get(0));
			j.supprimerItem(j.getSac().get(0));
			
		}
		//sinon on vole de l'argent
		else if (j.getArgent()>=0){
			j.setArgent(j.getArgent()-50);
		}
		else {
			j.setVie(j.getVie() - 5);
		}
	}
	
	/**
	 * Getter du sac du voleur
	 * @return sac du voleur
	 */
	public ArrayList<Item> getSacVoleur() {
		return sacVoleur;
	}
	
	/**
	 * Initialise le sac du voleur
	 * 
	 * @param sacVoleur
	 */
	private void setSacVoleur(ArrayList<Item> sacVoleur) {
		this.sacVoleur = sacVoleur;
	}
	

	/**
	 * Lance le combat contre le voleur
	 * 
	 * @param primaryStage
	 * @param sceneLobby
	 * @param rootLobby
	 * @param laby
	 * @param lobby
	 * @param joueur
	 */
	public void lancerCombat(Stage primaryStage, Scene sceneLobby,Group rootLobby,Labyrinthe laby, Lobby lobby,Joueur j) {
		new EspaceCombat(1850, 1000, primaryStage,sceneLobby,rootLobby,laby,lobby, this, j,4);
	}
}