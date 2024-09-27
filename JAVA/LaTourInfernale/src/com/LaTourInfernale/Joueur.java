package com.LaTourInfernale;

import java.util.ArrayList;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressBar;

/**
 * Classe enfant de Element
 * Classe relative aux informations et actions du joueur
 * 
 * @see Element
 * 
 * @author 4TOne
 * @version 1.0
 *
 */
public class Joueur extends Element{	
	/**
	 * Nom du Joueur
	 * 
	 * @see Joueur#getNom()
	 */
	private String nom;
    
	/**
	 * Vie du joueur
	 * 
	 * @see Joueur#getVie()
	 * @see Joueur#setVie(int)
	 */
	private int vie;
    
	/**
	 * Vie max du Joueur
	 * 
	 * @see Joueur#getVieMax()
	 * @see Joueur#setVieMax(int)
	 */
    private int vieMax;
    
    /**
     * Sac du joueur
     * 
     * @see Joueur#getSac()
     */
	private ArrayList<Item> sac = new ArrayList<Item>();
	
	/**
	 * Equipement du joueur
	 * 
	 * @see Joueur#getEquipement()
	 */
	private ArrayList<Armure> equipement = new ArrayList<Armure>();
	
	/**
	 * Argent du joueur
	 * 
	 * @see Joueur#getArgent()
	 */
	private double argent;
    
	/**
	 * Force du joueur
	 * @see Joueur#getAtk()
	 */
	private int atk;
    
	/**
	 * Experience du joueur
	 * 
	 * @see Joueur#getXp()
	 */
    private float xp;
    
    /**
     * Experience maximale en fonction du niveau
     */
    private int xpMax;
    
    /**
     * Niveau du joueur
     */
    private int niveau;
    
    /**
     * Point experience du joueur 
     * 
     * @see Joueur#getptXp()
     */
    private int ptXp;
    
    /**
     * Nombre d'ennemis tué
     * 
     * @see Joueur#getKills()
     */
    private int kills;
  
    /**
     * Constructeur de l'objet joueur
     * @param nom
     * @param coordX
     * @param coordY
     * @param atk
     * @param vie
     */
	public Joueur(String nom, int coordX, int coordY, int atk, int vie) {
		super(coordX,coordY);
		this.nom = nom;
		//initialise la vie à 20
		this.vieMax = vie;
		this.vie = vie;
		this.argent = 0;
		this.atk = atk;
		this.xp = 1;
		this.niveau = 1;
		setXpMax();
		this.ptXp = 1;
        this.setKills(kills);
	}

	/**
	 * Getter kills 
	 * 
	 * @return Ennemis tué
	 */
	public int getKills() {
		return kills;
	}
	
	/**
	 * Setter de l'expérience maximale
	 */
	private void setXpMax() {
		if(this.niveau == 1) {
			this.xpMax = 100;
		}
		else {
			this.xpMax += 50;
		}
	}
	
	
	/**
	 * Setter de l'expérience du joueur
	 * @param xp
	 */
	public void setXp(float xp) {
		if(this.xp + xp >= this.xpMax) {
			this.xp = (this.xp + xp)%this.xpMax;
			this.niveau++;
			this.ptXp++;
			setXpMax();
		}
		else {
			System.out.println("Victoire : +" + xp +"Xp");
			this.xp += xp;
		}
		System.out.println(this.niveau + " : " + ((float)this.xp/this.xpMax)*100 + "%");
	}
	
	/**
	 * Setter des points d'expérience 
	 * 
	 * @param ptXp
	 */
	public void setPtXp(int ptXp) {
		this.ptXp = ptXp;
	}
	
	/**
	 * Getter de l'argent du joueur
	 * @return argent du joueur
	 */
	public double getArgent() {
		return argent;
	}

	
	/**
	 * Setter de l'argent du joueur
	 * 
	 * @param argent
	 */
	public void setArgent(double argent) {
		this.argent = argent;
	}

	/**
	 * Getter du nom du joueur
	 * 
	 * @return nom du joueur
	 */
	public String getNom() {
		return nom;
	}

	/**
	 * Getter de la vie du joueur
	 * 
	 * @return vie du joueur
	 */
	public int getVie() {
		return vie;
	}

	/**
	 * Setter de la vie du joueur
	 * @param vie
	 */
	public void setVie(int vie) {
		System.out.println(this.vie + "->" + vie);
		this.vie = vie;
	}

	/**
	 * Getter du sac du joueur
	 * 
	 * @return sac du joueur
	 */
	public ArrayList<Item> getSac() {
		return sac;
	}
	
	/**
	 * Getter de l'équipement du joueur
	 * 
	 * @return equipement du joueur
	 */
	public ArrayList<Armure> getEquipement() {
		System.out.println("coucou");
		System.out.println(sac);
		return equipement;
	}
	
	
	/**
	 * Getter de la force du joueur
	 * @return force du joueur
	 */
	public int getAtk() {
		return atk;
	}

	/**
	 * Setter de la force du joueur
	 * 
	 * @param atk
	 */
	public void setAtk(int atk) {
		this.atk = atk;
	}
	
	/**
	 * Getter de l'experience du joueur
	 * @return
	 */
	public float getXp() {
		return xp;
	}
	
	/**
	 * Ajouter Item dans le sac
	 * 
	 * @param item
	 */
	public void ajouterItem(Item item){
		sac.add(item);
	}
	
	/**
	 * Ajouter equiement du joueur
	 * 
	 * @param armure
	 */
	public void ajouterEquipement(Armure armure){
		equipement.add(armure);
	}
	
	/**
	 * Acheter Item dans la boutique
	 * 
	 * @param item
	 */
	public void acheterItem(Item item) {
		if(this.argent >= item.getPrix()) {
			this.ajouterItem(item);
			this.argent = this.argent - item.getPrix() ;
		}
		else {	
			Alert alert = new Alert(AlertType.WARNING);
			alert.setHeaderText(null);
			alert.setTitle(null);
			alert.setContentText("Vous n'avez pas assez d'argent");
			alert.showAndWait();
		}
		
	}
	
	/**
	 * Acheter un equipement dans la boutique
	 * 
	 * @param armure
	 */
	public void acheterArmure(Armure armure) {
		if(this.argent >= armure.getPrix()) {
			this.ajouterEquipement(armure);
			this.argent = this.argent - armure.getPrix() ;
		}
		
	}
	
	/**
	 * Obtenir de l'argent à la fin des combats
	 * 
	 * @param montantArgent
	 */
	public void obtenirArgent(double montantArgent) {
		this.argent = this.getArgent() + montantArgent;
	}
	
	
	/**
	 * Enlève Item du sac (attaque des voleurs)
	 * 
	 * @param item
	 */
	public void supprimerItem(Item item){
		this.sac.remove(item);
	}

	
	/**
	 * Fonction pour vérifier qu'un item existe dans le sac.
	 * @param item
	 * @return true si le l'item est trouvé, false sinon
	 */
	public boolean chercherItem(Item item) {
	
	//déclaration variables	
	boolean verif;
	
	//cas où l'item n'est pas trouvé
	verif = false;
	
		for (Item i :  sac) {		
			//cas où l'élève avec le même nom est trouvé dans la liste
			if(i.equals(item)) {			
			  verif = true;		
			}
		}
		/* retourne l'élève recherché ou  null */
		return(verif);
	}
	
	/**
	 * Fonction pour vérifier qu'un equipement existe dans le sac.
	 * @param armure
	 * @return true si l'equipement est trouvé, false sinon
	 */
	public boolean chercherArmure(Armure armure) {
		
		//déclaration variables	
		boolean verif;
		
		//cas où l'armure n'est pas trouvé
		verif = false;
			System.out.println("----------\n");
			for (Armure i :  equipement) {		
				//cas où l'élève avec le même nom est trouvé dans la liste
				System.out.println(i + " et " + armure + " equals -> " + i.equals(armure));
				if(i.equals(armure)) {			
				  verif = true;		
				}
			}
			/* retourne l'élève recherché ou  null */
			System.out.println("verif = " + verif);
			return(verif);
		}
	
	/**
	 * Fonction pour rechercher la position d'un item dans le sac.
	 * 
	 * @param item
	 * @return position
	 */
	//
	public int chercherPosItem(Item item) {
	
		//déclaration variables	
		int pos=-1;
	
		if(chercherItem(item)) {
		
			pos = sac.indexOf(item);
			
		}	
		/* retourne la position de l'élément*/
		return(pos);
	}
	
	/**
	 * Renvoie la quantité d'un item donné dans le sac
	 * 
	 * @param item
	 * @return quantité
	 */
	public int compterNbItem(Item item) {
	
		int res;
		res = 0 ;
		for (Item i :  sac) {		
			
			if(i.equals(item)) {			
			  res ++;		
			}
		}
		return res;
		
	}
	
	
	/**
	 * Utilise un item
	 * 
	 * @param item
	 */
	public void utiliserItem(Item item) {
		
		if(this.chercherItem(item)) {
			
			if((item.getType()==0)||(item.getType()==1)) {
				this.vie = this.vie + item.getEffet();
				if (this.vie > this.vieMax) {
					this.vie=this.vieMax;
				}

			}
			this.supprimerItem(item);
		}
	}
	
	/**
	 * Inflige des degats a un ennemi
	 * @param e
	 */
	public void InfligerDegats(Ennemi e) {
		e.vie = e.getVie() - this.getAtk();
	}
	
	/**
	 * Inflige des degats à un ennemi avec l'ultime 
	 * 
	 * @param e
	 */
	public void Ultime(Ennemi e) {
		e.vie = e.getVie() - (this.getAtk()*2);
	}
	
	/**
	 * Reinitialise les coordonnée du joueur au point de départ dans le labyrinthe
	 */
	public void reinitialiserCoord() {
		this.coordX=0;
		this.coordY=0;
	}
	
	/**
	 * Reinitialise les coordonnée du joueur au point de départ dans le boss
	 */
	public void reinitialiserCoordBoss() {
		this.coordX=17;
		this.coordY=19;
	}
	
	/**
	 * Reinitialise les coordonnée du joueur au point de départ dans le lobby
	 */
	public void reinitialiserCoordLobby() {
		this.coordX=16;
		this.coordY=13;
	}	

	/**
	 * Affiche le sac du joueur
	 * @return
	 */
	public String afficherSac() {
		String chaine;
        
		Item potionBasique = new Item(0);
		Item potionMagique = new Item(1);
		Item potionPoison = new Item(2);

		
		int nbPM = this.compterNbItem(potionMagique);
		int nbPB = this.compterNbItem(potionBasique);
		int nbPP = this.compterNbItem(potionPoison);
    			
		chaine = "       x " + (nbPB)+ "      x " + (nbPM)+ "       x " + (nbPP)+ " ";							
								
		return chaine;
	}

	/**
	 * Getter des points d'expérience du joueur
	 * 
	 * @return point d'experience
	 */
	public int getptXp() {
		return this.ptXp;
	}
	
	/**
	 * Actualise les informations du joueur
	 * 
	 * @param scene
	 */
	public void actualiserInfosJoueur(Scene scene) {
		Label nom = (Label) scene.lookup("#nomJoueur");
		System.out.println(nom);
		nom.setText(this.nom);
		
		Label vie = (Label) scene.lookup("#VieLabel");
		vie.setText(this.vie+" PV");
		
		ProgressBar vieProgress = (ProgressBar) scene.lookup("#VieProgress");
		vieProgress.setProgress((float) (this.vie/this.vieMax));
		
		Label xp = (Label) scene.lookup("#XpLabel");
		xp.setText("Niveau " + this.niveau);
		
		ProgressBar xpProgress = (ProgressBar) scene.lookup("#XpProgress");
		xpProgress.setProgress( (float) (this.xp/this.xpMax));
		System.out.println(this.xp + "/" + this.xpMax + "="+ (float) (this.xp/this.xpMax));

		Label xpPoint = (Label) scene.lookup("#xpPointLabel");
		xpPoint.setText(this.ptXp+ " point XP");
		
		Label force = (Label) scene.lookup("#ForceLabel");
		force.setText(this.atk + "");
		
		Label argent = (Label) scene.lookup("#argentJoueur");
		argent.setText(this.argent + "€");
	}
	
	/**
	 * Actualise les informations du sac du joueur
	 * @param scene
	 */
	public void actualiserSac(Scene scene) {
		try {
			
		Item potionMagique = new Item(1);
		Label nbPM = (Label) scene.lookup("#nbPM");
		nbPM.setText("x" + this.compterNbItem(potionMagique));
		
		Item potionBasique = new Item(0);
		Label nbPB = (Label) scene.lookup("#nbPB");
		nbPB.setText("x" + this.compterNbItem(potionBasique));
		
		
		Item potionPoison = new Item(2);
		Label nbPP = (Label) scene.lookup("#nbPP");
		nbPP.setText("x" + this.compterNbItem(potionPoison));
		
		Armure casque = new Armure(0);
		Label nbCasque = (Label) scene.lookup("#nbCasque");	
		System.out.println(this.verifArmure(casque));
		nbCasque.setText("x" + this.verifArmure(casque));
		
		Armure	 plastron = new Armure(1);
		Label nbPlastron = (Label) scene.lookup("#nbPlastron");
		nbPlastron.setText("x" + this.verifArmure(plastron));
		
		Armure jambiere = new Armure(2);
		Label nbJambiere = (Label) scene.lookup("#nbJambiere");
		nbJambiere.setText("x" + this.verifArmure(jambiere));
		
		Armure bottes = new Armure(3);
		Label nbBottes = (Label) scene.lookup("#nbBottes");
		nbBottes.setText("x" + this.verifArmure(bottes));
		}
		catch(Exception e) {		}
	}
	/**
	 * Verife la quantité de l'équipement figurant dans le sac
	 * 
	 * @param typeEquipement
	 * @return quantité
	 */
	public int verifArmure(Armure typeEquipement) {
		int res;
		res = 0 ;
		for (Armure a :  equipement) {		
			
			if(a.equals(typeEquipement)) {			
			  res ++;		
			}
		}
		return res;
		
	}
	/**
	 * Getter des point de vie maximum du joueur
	 * @return
	 */
	public int getVieMax() {
		return this.vieMax;
	}
	
	/**
	 * Setter du nombre d'ennemi tué par le joueur
	 * @param kills
	 */
    public void setKills(int kills) {
		this.kills = kills;
	}

    /**
     * Setter des points de vie maximum du joueur
     * @param vieMax
     */
	public void setVieMax(int vieMax) {
		this.vieMax = vieMax;
		
	}
	
	
	/**
	 * Permet au joueur d'utilisert la fonction de poison
	 * @param item
	 * @param e
	 */
	public void consommerPotionPoison(Item item, Ennemi e) {
        if (item.getType() == 2) { 
                if (this.vie - item.getEffet() <0) {
                    this.vie = 0;
                }else {
                    this.vie = this.vie - item.getEffet();
                }
        }
    }

}
