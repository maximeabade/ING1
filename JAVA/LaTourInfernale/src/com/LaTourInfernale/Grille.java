package com.LaTourInfernale;

import javafx.scene.layout.GridPane;

/**
 * Classe mère de toutes les cartes
 * 
 * @see Etage_Boss
 * @see Labyrinthe
 * @see Lobby
 * @see EspaceCombat
 * 
 * @author 4TOne
 * @version 1.0
 */
public class Grille {
	
	/**
	 * Largeur de la carte 
	 */
	protected double width;
	
	/**
	 * Hauteur de la carte
	 */
	protected double height;
	
	/**
	 * Contenu de la carte
	 */
	protected GridPane donnees;
	
	/**
	 * Construsteur de l'objet Grille
	 * 
	 * @param width
	 * @param height
	 * 
	 * @see Grille#getDonnees()
	 */
	public Grille(double width, double height) {
		this.width = width;
		this.height = height;
		this.donnees = this.getDonnees();
		
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
	
	
	
	
	
	
	
	
	
	
	

	
	