package com.LaTourInfernale;


/**
 * <b> Armure permet de créer des Armures</b>
 * Une Armure est caractérisée par :
 * <ul>
 * 	<li> Un nom </li>
 *  <li> Un type : bottes, jambieres, plastron ou casque</li>
 *  <li> Un prix</li>
 *  <li> Un effet</li>
 * </ul>
 * @author 4TOne
 * @version 1.0
 */


public class Armure {
	
	/**
	 * Nom de l'armure
	 * 
	 * @see Armure#getNom()
	 * @see Armure#Armure(int)
	 */
	private String nom;			
	
	/**
	 * Type de l'armure
	 * 
	 * @see Armure#getType()
	 * @see Armure#Armure(int)
	 */
	private int type;			
	
	/**
	 * Prix de l'armure
	 * 
	 * @see Armure#getPrix()
	 */
	private double prix;		
	
	/**
	 * Effet de l'armure
	 * 
	 * @see Armure#getEffet()
	 */
	private int effet;			

	/**
	 * Constructeur de l'objet Armure en fonction de son type : bottes, jambieres, plastron ou casque.
	 * 
	 * @param type de l'armure
	 * 
	 * @see Armure#effet
	 * @see Armure#nom
	 * @see Armure#prix
	 * @see Armure#type
	 */
	public Armure(int type) {
		
		if(type==0) {
			this.nom= "casque";
			this.prix = 300.0;
			this.effet = 7;
		}
		if(type==1) {
			this.nom= "plastron";
			this.prix = 600.0;
			this.effet = 13;
		}
		if(type==2) {
			this.nom= "jambiere";
			this.prix = 400;
			this.effet = 10;
		}
		
		if(type==3) {
			this.nom= "bottes";
			this.prix = 300;
			this.effet = 6;
		}
		
		
		this.type = type;
		
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////    SETTERS / GETTERS      //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/** getter de nom
	 * 
	 * @return nom de l'armure
	 */
	public String getNom() {
		return nom;
	}
	

	/**
	 * getter du type 
	 * 
	 * @return type de l'armure
	 */
	public int getType() {
		return type;
	}
	

	
	/*
	 * getter du prix
	 * 
	 * @return prix de l'armure
	 */
	public double getPrix() {
		return prix;
	}
	
	
	/**
	 * getter de l'effet
	 * 
	 * @return effet de l'armure
	 */
	public int getEffet() {
		return effet;
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////        METHODES        //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	
	/**
	 * Methode toString
	 * 
	 * @return String de l'objet Armure
	 */
	@Override
	public String toString() {
		return "Armure [nom=" + nom + ", type=" + type + ", prix=" + prix + ", effet=" + effet + "]";
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
		Armure other = (Armure) obj;
		if (effet != other.effet)
			return false;
		if (nom == null) {
			if (other.nom != null)
				return false;
		} else if (!nom.equals(other.nom))
			return false;
		if (Double.doubleToLongBits(prix) != Double.doubleToLongBits(other.prix))
			return false;
		if (type != other.type)
			return false;
		return true;
	}
	

}