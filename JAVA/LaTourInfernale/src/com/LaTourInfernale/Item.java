package com.LaTourInfernale;

/**
 * Classe Mere de tous les Items du jeu
 * 
 * @author 4TOne
 * @version 1.0
 */
public class Item {
	
	/**
	 * Nom de l'item
	 * 
	 * @see Item#getNom()
	 */
	private String nom;
	
	/**
	 * Type de l'item
	 * 
	 * @see Item#getType()
	 */
	private int type;
	
	/**
	 * Prix de l'item
	 * 
	 * @see Item#getPrix()
	 */
	private double prix;
	
	/**
	 * Effet de l'item
	 * 
	 * @see Item#getEffet()
	 */
	private int effet;
	
	
	/**
	 * Constructeur de l'objet Item
	 * 
	 * @param type
	 */
	public Item(int type) {
		
		if(type==0) {
			this.nom= "potionBasique";
			this.prix = 10.0;
			this.effet = 5;
		}
		if(type==1) {
			this.nom= "potionMagique";
			this.prix = 50.0;
			this.effet = 20;
		}
		if(type==2) {
			this.nom= "potionPoison";
			this.prix = 15.0;
			this.effet = 15;
		}
		
		
		this.type = type;
	
	}
	

	/**
	 * Getter du prix de l'item
	 * 
	 * @return prix de l'item
	 */
	public double getPrix() {
		return prix;
	}

	/**
	 * Getter de l'effet de l'item
	 *  
	 * @return effet de l'item
	 */
	public int getEffet() {
		return effet;
	}
	
	/**
	 * Getter du type de l'item
	 * @return
	 */
	public int getType() {
		return type;
	}


	



	/**
	 * Methode toString
	 * 
	 * @return String de l'objet Item
	 */
	@Override
	public String toString() {
		return nom ;
	}
	
	/**
	 * Methode equals
	 * 
	 * @param obj que l'on souhaite comparer
	 * @return true si les objets sont equivalent, false sinon
	 */
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Item other = (Item) obj;
		if (type != other.type)
			return false;
		return true;
	}
	

}