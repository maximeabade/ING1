package com.LaTourInfernale;

/**
 * Classe mère des différents élément des cartes
 * 
 * @author 4TOne
 * @version 1.0
 * 
 * @see Joueur
 * @see Ennemi
 */
public class Element {
	
	/**
	 * Coordonnée en x de l'élément
	 * 
	 * @see Element#getCoordX()
	 */
	protected int coordX;
	
	/**
	 * Coordonnée en y de l'élément
	 * 
	 * @see Element#getCoordY()
	 */
	protected int coordY;
	
	/**
	 * Constructeur de l'objet Element
	 * 
	 * @param coordX
	 * @param coordY
	 */
	public Element(int coordX, int coordY) {
		this.coordX = coordX;
		this.coordY = coordY;
	}

	/**
	 * Getter de la coordonnée en x
	 * 
	 * @return coordX
	 */
	public int getCoordX() {
		return coordX;
	}

	/**
	 * Setter de la coordonnée en x
	 * 
	 * @param coordX
	 */
	public void setCoordX(int coordX) {
		this.coordX = coordX;
	}

	
	/**
	 * Getter de la coordonnée en y 
	 * @return
	 */
	public int getCoordY() {
		return coordY;
	}

	/**
	 * Setter de la coordonnée en y
	 * @param coordY
	 */
	public void setCoordY(int coordY) {
		this.coordY = coordY;
	}
	
	

	
	
	
	
}
