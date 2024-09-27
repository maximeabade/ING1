package com.LaTourInfernale;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * Classe enfant de Ennemi
 * 
 * Objet de l'ennmi de type Sage
 * 
 * @see Ennemi
 * 
 * @author 4TOne
 * @version 1.0
 * 
 */
public class Sage extends Ennemi {
	
	private String enigme;
	private String reponseEnigme;
	private ArrayList<String> reponse;
	private String explication;
	private HashMap<Integer,String> enigmes;
	private HashMap<Tuple<Integer, Integer>, String> reponses;
	private HashMap<Integer,String> explications;
	private HashMap<Integer,String> reponseEnigmes;

	public Sage(String nom, int coordX, int coordY) {
		super(nom, coordX, coordY);
		Random rand = new Random();
		int index = 1+rand.nextInt(10);
		//initialise la vie à 10000
		this.vie = 10000;
		//initialise l'attaque a 0
		this.atk = 0;
		setEnigmes();
		setEnigme(index);
		setReponses();
		setReponse(index);
		setReponseEnigmes();
		setReponseEnigme(index);
		setExplications();
		setExplication(index);
	}

	/**
	 * Getter de l'enigme 
	 * @return enigme
	 */
	public String getEnigme() {
		return enigme;
	}

	/**
	 * Getter de  la reponse a l'enigme
	 * @return
	 */
	public String getReponseEnigme() {
		return reponseEnigme;
	}




	/**
	 * Getter des reponses a l'enigme
	 * @return Map des reponses
	 */
	public ArrayList<String> getReponse() {
		return reponse;
	}

	/**
	 * Getter de l'explication de l'enigme
	 * @return explication de l'enigme
	 */
	public String getExplication() {
		return explication;
	}


	/**
	 * Initialise l'explication de toutes les enigmes dans une map
	 */
	private void setExplications() {
		HashMap<Integer, String> explications = new HashMap<Integer,String>();
		
		explications.put(1 ,"50 menteurs\n1 personne sur deux ne ment jamais et 1 sur 2 ment toujours.");
		explications.put(2 ,"Si une des deux pièces ne vaut pas 1€, l'autre le peut. Par exemple, si la première pièce ne vaut pas 1€, on ne dit pas que la deuxième ne vaut pas 1€. \nLa réponse est donc 1€ et 50c.");
		explications.put(3 ,"Il en reste 7 car toutes meurent sauf 7.");
		explications.put(4 ,"Vous prenez le premier cachet tout de suite, le 2e 30 min après, le 3 après 1 h... On obtient 2 heures.");
		explications.put(5 ,"C'était bien sûr Toto.");
		explications.put(6 ,"\"Un homme averti en vaut deux\". Donc le pont cède, et naturellement, l'homme tombe");
		explications.put(7 ,"Est ce que la réponse necessite vraiment une explication ? :*");
		explications.put(8 ,"Il fallait regarder le nom de famille de Mr Cochetou. Cochetou= Cochetout . Il fallait donc tout cocher !");
		explications.put(9 ,"Pas compliqué, il suffit de marcher à côté des bananes ! C'était ça le piège ! ");
		explications.put(10 ,"8760 heures, 365 jours, 12 mois et une année.");
		explications.put(11 ,"La première lettre et la dernière du nombre qui précède. Exemple : 768 = Sept- cent-soixante-huit = ST");
		
		this.explications = explications;
	}

	/**
	 * Selectionne l'explication correspondant à l'enigme choisie
	 * @param randIndex
	 */
	private void setExplication(int randIndex) {
		this.explication = this.explications.get(randIndex);
	}
	
	/**
	 * Initialise les reponses a toutes les questions
	 */
	private void setReponses() {
		HashMap<Tuple<Integer, Integer>,String> reponses = new HashMap<Tuple<Integer, Integer>,String>();
		reponses.put(new Tuple<Integer, Integer>(1,1), "Tous");
		reponses.put(new Tuple<Integer, Integer>(1,2), "50");
		reponses.put(new Tuple<Integer, Integer>(1,3), "Aucun");
		
		reponses.put(new Tuple<Integer, Integer>(2,1), "10c");
		reponses.put(new Tuple<Integer, Integer>(2,2), "20c");
		reponses.put(new Tuple<Integer, Integer>(2,3), "50c");
		reponses.put(new Tuple<Integer, Integer>(2,4), "1€");
		reponses.put(new Tuple<Integer, Integer>(2,5), "On ne peut pas / Autre");
		
		reponses.put(new Tuple<Integer, Integer>(3,1), "5");
		reponses.put(new Tuple<Integer, Integer>(3,2), "7");
		reponses.put(new Tuple<Integer, Integer>(3,3), "12");
		reponses.put(new Tuple<Integer, Integer>(3,4), "14");
		
		reponses.put(new Tuple<Integer, Integer>(4,1), "30 min");
		reponses.put(new Tuple<Integer, Integer>(4,2), "1 h");
		reponses.put(new Tuple<Integer, Integer>(4,3), "1 h 30min");
		reponses.put(new Tuple<Integer, Integer>(4,4), "2 h");
		
		reponses.put(new Tuple<Integer, Integer>(5,1), "Poum");
		reponses.put(new Tuple<Integer, Integer>(5,2), "Pum");
		reponses.put(new Tuple<Integer, Integer>(5,3), "Paf");
		reponses.put(new Tuple<Integer, Integer>(5,4), "Autre");
		
		reponses.put(new Tuple<Integer, Integer>(6,1), "Rien");
		reponses.put(new Tuple<Integer, Integer>(6,2), "Il tombe");
		reponses.put(new Tuple<Integer, Integer>(6,3), "Le pont cède");
		reponses.put(new Tuple<Integer, Integer>(6,4), "Il retourne sur ses pas");

		reponses.put(new Tuple<Integer, Integer>(7,1), "Blanc");
		reponses.put(new Tuple<Integer, Integer>(7,2), "Noir");
		reponses.put(new Tuple<Integer, Integer>(7,3), "Marron");
		reponses.put(new Tuple<Integer, Integer>(7,4), "Bleu à pois rose");
		
		reponses.put(new Tuple<Integer, Integer>(8,1), "Oui");
		reponses.put(new Tuple<Integer, Integer>(8,2), "Non");
		reponses.put(new Tuple<Integer, Integer>(8,3), "Rien");
		
		
		reponses.put(new Tuple<Integer, Integer>(9,1), "10 min");
		reponses.put(new Tuple<Integer, Integer>(9,2), "1 h 10 min");
		reponses.put(new Tuple<Integer, Integer>(9,3), "Une éternité");
		
		reponses.put(new Tuple<Integer, Integer>(10,1), "0");
		reponses.put(new Tuple<Integer, Integer>(10,2), "1");
		reponses.put(new Tuple<Integer, Integer>(10,3), "77");
		
		reponses.put(new Tuple<Integer, Integer>(11,1), "ME");
		reponses.put(new Tuple<Integer, Integer>(11,1), "MF");
		reponses.put(new Tuple<Integer, Integer>(11,1), "MT");
		
		this.reponses = reponses;
	}
	
	/**
	 * Selectionne la reponse correspondant à l'enigme choisie
	 * 
	 * @param randIndex
	 */
	private void setReponse(int randIndex){
		ArrayList<String> reponses = new ArrayList<String>();
		
		for(int i = 0; i < 5; i++) {
			
			String rep = this.reponses.get(new Tuple<Integer, Integer>(randIndex, i));
			
			if(rep != null) {
				reponses.add(rep);
			}
		}
		
		
		this.reponse = reponses;
		
		
		
	}
	/**
	 *  Initialise toutes les enigmes
	 */
	private void setEnigmes() {
		HashMap<Integer,String> enigmes = new HashMap<Integer,String>();
		
		enigmes.put(1, 	"Sur une île de 100 habitants vivant le long d'un cercle, touss ont le même dicours: "+"\n\t- Je ne mens jamais mais mon voisin de gauche ment toujours\n"+"Combien y-a-t'il de menteurs?");
		enigmes.put(2, 	"Dans ma main, j'ai 2 pièces dont la somme vaut 1€50. Une des deux ne vaut pas 1€. Quelles valeurs ont ces pièces ?");
		enigmes.put(3, 	"Un berger a 21 brebis. Suite à une maladie, toutes meurent sauf 7. Combien de brebis reste-t-il à ce berger ?");
		enigmes.put(4, 	"Vous êtes malade et devez prendre 1 cachet toutes les 30 min. En combien de temps minimum prendrez-vous 5 cachets ?");
		enigmes.put(5, 	"La mère de Toto a 3 enfants : Pim, Pam et... .");
		enigmes.put(6, 	"Un homme de 50 kgs s'engage sur un pont et voit inscrit sur un panneau : 'max. 70 kgs'. Il est seul sur le pont. Que se passe-t-il ?");
		enigmes.put(7, 	"le cheval blanc d'Henri IV est...");
		enigmes.put(8, 	"Mr Cochetou, directeur d'une grande entreprise, vient de vous embaucher. Il vous demande de répondre à sa question. Qu'est-ce que vous allez lui répondre ?");
		enigmes.put(9, 	"Je dois marcher un long chemin avec 12 bananes devant moi. Il me faut 10 minutes en temps normal. Chaque banane me fait retarder de 5 minutes. Combien de temps vais-je mettre pour passer ce chemin ?");
		enigmes.put(10,	"Complète cette suite logique : 8760-365-12- ?");
		enigmes.put(11, "144-CE-16-SE-9-NF-1000- ? Quelles sont les lettres manquantes ?");
		this.enigmes = enigmes;
	}
	
	/**
	 * Getter pour les reponses aux enigmes
	 *  
	 * @return reponses aux enigmes
	 */
	public HashMap<Integer, String> getReponseEnigmes() {
		return reponseEnigmes;
	}

	private void setReponseEnigmes() {
		
		HashMap<Integer,String> reponseEnigmes = new HashMap<Integer,String>();
		
		reponseEnigmes.put(1, "50,");
		reponseEnigmes.put(2, "50c,1€,");
		reponseEnigmes.put(3, "7,");
		reponseEnigmes.put(4, "2 h,");
		reponseEnigmes.put(5, "Autre,");
		reponseEnigmes.put(6, "Il tombe,Le pont cède,");
		reponseEnigmes.put(7, "Blanc,");
		reponseEnigmes.put(8, "Oui,Non,Rien,");
		reponseEnigmes.put(9, "10 min,");
		reponseEnigmes.put(10, "1,");
		reponseEnigmes.put(11, "ME,");
		
		this.reponseEnigmes = reponseEnigmes;
		
	}


	/**
	 * Selectionne la reponse à l'enigme
	 * 
	 * @param index
	 */
	private void setReponseEnigme(int index) {
		this.reponseEnigme = this.getReponseEnigmes().get(index);
		
	}
	
	/**
	 * Selectionne l'enigme
	 * 
	 * @param randIndex
	 */
	private void setEnigme(int randIndex){
		this.enigme = this.enigmes.get(randIndex);
	}
	
	/**
	 * Verifie la reponse du joueur
	 * @param reponseJoueur
	 * @param reponse
	 * @return true si le joueur a juste, false sinon
	 */
	public Boolean verifierReponseJoueur(String reponseJoueur, String reponse) {
		if(reponseJoueur.equals(reponse)) {
			
			return true;
		}
		return false;
	}
	
	/**
	 * Lance le combat avec le sage
	 * 
	 * @param primaryStage
	 * @param sceneLobby
	 * @param rootLobby
	 * @param laby
	 * @param lobby
	 * @param j
	 */
	public void lancerCombat(Stage primaryStage, Scene sceneLobby,Group rootLobby,Labyrinthe laby, Lobby lobby,Joueur joueur) {
        new EspaceCombat(1850, 1000, primaryStage,sceneLobby,rootLobby,laby,lobby, this, joueur,3);
    }
	


}
