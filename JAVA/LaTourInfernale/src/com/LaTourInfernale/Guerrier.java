package com.LaTourInfernale;

import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
/**
 * Classe mere du Boss
 * Classe enfant de Ennemmi
 * 
 * Permet de créer un ennmi de type guerrier
 * 
 * @see Ennemi
 * @see Boss
 * 
 * @author 4TOne
 * @version 1.0
 */
public class Guerrier extends Ennemi {
	
	/**
	 * Constructeur de l'objet Guerrier
	 * Statistiques:
	 * <ul>
	 * <li>Vie: 72 </li>
	 * <li>Force: 13 </li>
	 * </ul>
	 * 
	 * @param nom
	 * @param coordX
	 * @param coordY
	 * 
	 * @see Ennemi#Ennemi(String, int, int)
	 */
	public Guerrier(String nom, int coordX, int coordY) {
		super(nom, coordX, coordY);
		//initialise la vie à 35
		this.vie = 72;
		this.vieMax = 72;
		//initialise l'attaque a 10
		this.atk = 13;
	}
	
	/**
	 * Methode toString
	 * 
	 * @return String de l'objet Guerrier
	 */
	@Override
	public String toString() {
		return "Guerrier [coordX=" + coordX + ", coordY=" + coordY + "]";
	}

	/**
	 * Inflige des dégats au joueur
	 * @param joueur
	 */
	public void InfligerDegats(Joueur joueur) {
		joueur.setVie(joueur.getVie() - this.getAtk());
	}
	
	/**
	 * Lance le combat contre le joueur
	 * 
	 * @param primaryStage
	 * @param sceneLobby
	 * @param rootLobby
	 * @param laby
	 * @param lobby
	 * @param joueur
	 */
	// Affichage de la scene
	public void lancerCombat(Stage primaryStage, Scene sceneLobby,Group rootLobby,Labyrinthe laby, Lobby lobby,Joueur joueur) {
		new EspaceCombat(1850, 1000, primaryStage,sceneLobby,rootLobby,laby,lobby, this, joueur,2);
	}
	
}
