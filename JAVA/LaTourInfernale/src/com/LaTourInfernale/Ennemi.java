package com.LaTourInfernale;
/**
 * Classe mère de tous les ennemis
 * Classe enfant de la classe Element
 * 
 * @see Element
 * @see Guerrier
 * @see Voleur
 * @see Boss
 * @see Sage
 * 
 * @author 4TOne
 * @version 1.0
 */
public class Ennemi extends Element{
	
	
	/**
	 * Nom de l'ennemi
	 * 
	 * @see Ennemi#getNom() 
	 */
	private String nom;
	
	/**
	 * Point de vie courrant de l'ennemi
	 * 
	 * @see Ennemi#getVie()
	 * @see Ennemi#setVie(int)
	 */
	int vie;
	
	/**
	 * Point de vie maximum de l'ennemi
	 * 
	 * @see Ennemi#getVieMax()
	 * @see Ennemi#setVieMax(int)
	 */
    int vieMax;
    
    /**
     * Point d'attaque de l'ennemi
     * 
     * @see Ennemi#getAtk()
     */
    int atk;
	
    /**
     * Constructeur de l'oobje Ennemi 
     * 
     * @param nom
     * @param coordX
     * @param coordY
     * 
     * @see Element#Element(int, int)
     */
	public Ennemi(String nom, int coordX, int coordY) {
		super(coordX,coordY);
		this.nom = nom;
	}

	/**
	 * Getter du nom de l'ennemi
	 * 
	 * @return nom de l'ennemi
	 */
	public String getNom() {
		return nom;
	}

	/**
	 * Getter de la vie de l'ennemi
	 * @return vie de l'ennemi
	 */
	public int getVie() {
		return vie;
	}
	
	/**
	 * Getter de la vie max de l'ennemi
	 * 
	 * @return vie max de l'ennemi
	 */
	public int getVieMax() {
		return this.vieMax;
	}

	/**
	 * Setter de la vie max de l'ennemi
	 * 
	 * @param vieMax
	 */
	public void setVieMax(int vieMax) {
		this.vieMax = vieMax;
	}
	
	/**
	 * Setter de la vie de l'ennemi
	 * @param vie
	 */
	public void setVie(int vie) {
		this.vie = vie;
	}

	/**
	 * Getter des point d'attaque de l'ennemi
	 * @return attaque de l'ennemi 
	 */
	public int getAtk() {
		return atk;
	}

	/**
	 * Permet d'appliquer les effets de la potion de poison sur le joueur s'il sagit d'un Voleur ou du Boss
	 * 
	 * @param item
	 * @param joueur
	 * 
	 * @see Item
	 * @see Joueur
	 */
	public void consommerPotionPoison(Item item, Joueur j) {
		
		if (item.getType() == 2) { 

				if (this.vie - item.getEffet ()<0) {
					this.vie = 0;
				}else {
					this.vie = this.vie - item.getEffet();
				}

		}
			j.supprimerItem(item);
		
	}

	/**
	 * Methode toString
	 * 
	 * @return String de l'objet Ennemi
	 */
	@Override
	public String toString() {
		return "Ennemi [nom=" + nom + ", vie=" + vie + ", atk=" + atk + "]";
	}

	

}