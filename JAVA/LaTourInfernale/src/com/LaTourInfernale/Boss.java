package com.LaTourInfernale;


import java.util.ArrayList;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;


/**
 *  Boss permet de créer le boss de fin
 * Un Boss est caractérisé par :
 * <ul>
 * 	<li> Les caractéristiques d'un ennemis </li>
 *  <li> Un sac pour récupérer les objets du joueur</li>
 * </ul>
 * 
 * @author 4TOne
 * @version 1.0
 */
public class Boss extends Guerrier {
	
	/**
	 * Sac contenant les objets du joueur
	 * 
	 * @see Boss#getSacBoss()
	 * @see Boss#VolerItems(Joueur)
	 * @see Boss#setSacBoss(ArrayList)
	 */
	private ArrayList<Item> sacBoss;
	
	/**
	 * Constructeur de l'objet Boss 
	 * Statisques:
	 * <ul>
	 * <li> Vie: 100</li>
	 * <li> Force: 30</li>
	 * </ul>
	 * 
	 * @param nom du boss
	 * @param coordonnée X
	 * @param coordonnée Y
	 * 
	 * @see Guerrier#Guerrier(String, int, int)
	 * @see Boss#sacBoss
	 */
	public Boss(String nom, int coordX, int coordY) {
		super(nom, coordX, coordY);
		//initialise la vie à 35
		this.vie = 100;
		//initialise l'attaque a 10
		this.atk = 30;
		this.setSacBoss(new ArrayList<Item>());
	}
	

	/**
	 * Enlève Item du sac (Boss)
	 * 
	 * @param item a supprimer
	 */
	public void supprimerItem(Item item){
		this.sacBoss.remove(item);
	}
	
	
	/**
	 * Fonction pour rechercher un item dans le sac.
	 * 
	 * @param item
	 * @return true si l'item a été trouvé, false sinon
	 */
	public boolean chercherItem(Item item) {
	
	//déclaration variables	
	boolean verif;
	
	//cas où l'item n'est pas trouvé
	verif = false;
	
		for (Item i :  sacBoss) {		
			//cas où l'élève avec le même nom est trouvé dans la liste
			if(i.equals(item)) {			
			  verif = true;		
			}
		}
		/* retourne l'élève recherché ou  null */
		return(verif);
	}
	
	
	/**
	 * Permet d'utiliser un item
	 */
	public void utiliserItem() {
		
		if(this.chercherItem(this.getSacBoss().get(0))) {
			this.vie = this.vie + this.getSacBoss().get(0).getEffet();
			this.supprimerItem(this.getSacBoss().get(0));
		}
	}
	
	
	/**
	 * Vole tous les items du joueur j et les mets dans son sac
	 * 
	 * @param joueur
	 */
	public void VolerItems(Joueur joueur) {
		
		int i = 0;
		while (!(joueur.getSac().isEmpty()))  {

			this.sacBoss.add(joueur.getSac().get(i));
			joueur.supprimerItem(joueur.getSac().get(i));
			i++;
			
		}
	}
		
		
		
		
		
	/**
	 * Methode toString
	 * 
	 * @return String de l'objet Boss
	 */
	@Override
	public String toString() {
		return "Boss [sacBoss=" + sacBoss + "]";
	}


	/**
	 * Lance le combat entre le joueur et Boss
	 * 
	 * @param primaryStage
	 * @param sceneLobby
	 * @param rootLobby
	 * @param laby
	 * @param lobby
	 * @param joueur
	 * 
	 * @see EspaceCombat
	 */
	public void lancerCombat(Stage primaryStage, Scene sceneLobby,Group rootLobby,Labyrinthe laby, Lobby lobby,Joueur joueur) {
		new EspaceCombat(1850, 1000, primaryStage,sceneLobby,rootLobby,laby,lobby, this, joueur,5);
	}

	/**
	 * Getter pour le sac du Boss
	 * 
	 * @return sac du boss
	 */
	public ArrayList<Item> getSacBoss() {
		return sacBoss;
	}

	/**
	 * Setter pour le sac du Boss
	 * 
	 * @param sacBoss
	 */
	public void setSacBoss(ArrayList<Item> sacBoss) {
		this.sacBoss = sacBoss;
	}

}
