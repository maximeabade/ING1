package com.LaTourInfernale;

import java.io.IOException;
import java.util.ArrayList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressBar;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;

/**
 * Classe enfant de la classe grille
 * 
 * L'objet EspaceCombat permet de créer les interfaces et mécanique de combat
 * 
 * @see Grille
 * 
 * @author 4TOne
 * @version 1.0
 * 
 * 
 */
public class EspaceCombat extends Grille{
	/**
	 * Contient les images nécessaires à l'affichage des combats
	 */
	private Image[] imageCombat;
	
	/**
	 * Contstructeur de l'objet Espace combat
	 * 
	 * @param width
	 * @param height
	 * @param primaryStage
	 * @param sceneLobby
	 * @param rootLoby
	 * @param laby
	 * @param lobby
	 * @param en
	 * @param j
	 * @param typeEn
	 */
	public EspaceCombat(double width, double height, Stage primaryStage,Scene sceneLobby,Group rootLoby,Labyrinthe laby,Lobby lobby, Ennemi en, Joueur joueur, int typeEn) {
		super(width, height);
		this.imageCombat = getImageCombat();
		initEspaceCombat(sceneLobby,rootLoby, primaryStage,laby,lobby, en , joueur, typeEn);

	}
	
	/**
	 * Getter des images de combats
	 * 
	 * @return Image de combat
	 */
	private Image[] getImageCombat() {
		
		Image[] imageCombat = new Image[5];

		Image hero = new Image(getClass().getResourceAsStream("hero_dos.png"), 500, 500, false, false);
		Image guerrier = new Image(getClass().getResourceAsStream("guerrier_3.png"), 300, 300, false, false);
		
		imageCombat[0] = hero;
		imageCombat[1] = guerrier;
		
		return imageCombat;
		
	}
	
	/**
	 * Initialise l'espace de combat 
	 * 
	 * @param sceneLobby
	 * @param rootLobby
	 * @param primaryStage
	 * @param Laby
	 * @param lobby
	 * @param en
	 * @param j
	 * @param typeEn
	 * 
	 * @see 
	 */
	private void initEspaceCombat(Scene sceneLobby,Group rootLobby, Stage primaryStage,Labyrinthe Laby,Lobby lobby, Ennemi en, Joueur j, int typeEn) {

		//Chargement de l'image de l'ennemi
        Image image2 = new Image(getClass().getResourceAsStream("guerrier_3.png"), 300, 300, false, false);
		  
		if (en instanceof Sage){			
			System.out.println("Sage");
			image2 = new Image(getClass().getResourceAsStream("sage.png"), 300, 300, false, false);
		}

		if (en instanceof Guerrier){
			System.out.println("Guerrier");
			image2 = new Image(getClass().getResourceAsStream("guerrier_3.png"), 300, 300, false, false);

		}
		if (en instanceof Voleur){
			System.out.println("Voleur");
			image2 = new Image(getClass().getResourceAsStream("voleur.png"), 300, 300, false, false);

		}
		
		if (en instanceof Boss){
			image2 = new Image(getClass().getResourceAsStream("boss.png"), 400, 400, false, false);

		}
		
	    //Initialisation de l'ImageView de l'ennemi
        final ImageView ennemi = new ImageView();   
        ennemi.setImage(image2);

        //Création des potions
		Item potionBasique = new Item(0);
        Item potionMagique = new Item(1);
        Item potionPoison = new Item(2);
        
        //Initialisation du décor de combat avec les images
		Group background = new Group();
		Group torch = new Group();
		
		final ImageView torche1 = new ImageView();  
        Image animatedTorch = new Image(getClass().getResourceAsStream("futur.gif"), 60, 60, false, false);
        torche1.setImage(animatedTorch);
        final ImageView torche2 = new ImageView();  
        Image animatedTorch2 = new Image(getClass().getResourceAsStream("futur.gif"), 60, 60, false, false);
        torche2.setImage(animatedTorch2);
		final ImageView bg = new ImageView();  
        Image bcg = new Image(getClass().getResourceAsStream("fight.png"), 1800, 1000, false, false);
        if(en instanceof Boss) {
            bcg = new Image(getClass().getResourceAsStream("fondBoss.png"), 1800, 1000, false, false);
   		}
        bg.setImage(bcg);
        
        
		//Image du joueur
		
		final ImageView you = new ImageView(new Image(getClass().getResourceAsStream("hero_dos.png"), 400, 400, false, false));  
        
        
       
        
    	//Partie informations ennemi
		AnchorPane infosEnnemi = null;
		try {
			infosEnnemi = FXMLLoader.load(getClass().getResource("infosEnnemi.fxml"));
		} catch (IOException e2) {
			e2.printStackTrace();
		}


	
		//On récupère les infos de l'ennemi
		Label typeEnnemi = (Label) infosEnnemi.lookup("#typeEnnemi");
		typeEnnemi.setText("Type : " + en.getNom());
		
		ProgressBar statusVie = (ProgressBar) infosEnnemi.lookup("#VieProgressEnnemi");
		statusVie.setProgress(en.getVie());		
		
		Label labelVieE = (Label) infosEnnemi.lookup("#vieE");
		labelVieE.setText(en.getVie()+"PV");

		Label statusAttaque =(Label) infosEnnemi.lookup("#eForce");
		statusAttaque.setText("Force : "+ en.getAtk());

		Label labelItemVole = (Label) infosEnnemi.lookup("#itemVole");
		labelItemVole.setText("");

		AnchorPane infosJoueur = null;
		try {
			 infosJoueur = FXMLLoader.load(getClass().getResource("CombatInfosJoueur.fxml"));
		} catch (IOException e2) {
			e2.printStackTrace();
		}

		
		//Recupération des informations sur le joueur
		Label nomJoueur =(Label) infosJoueur.lookup("#nomJoueur");
		nomJoueur.setText(j.getNom());
		
		ProgressBar joueurVie = (ProgressBar) infosJoueur.lookup("#VieProgressJoueur");
		joueurVie.setProgress((float) j.getVie()/j.getVieMax());

		Label labelVieJ = (Label) infosJoueur.lookup("#vieJ");
		labelVieJ.setText(j.getVie() + "PV");
		
		Label joueurForce =(Label) infosJoueur.lookup("#jForce");
		joueurForce.setText("Force : "+ j.getAtk());
	
		

		//Recupération des information du sac
		Label nPB =(Label) infosJoueur.lookup("#nPB");
		nPB.setText("x"+j.compterNbItem(potionBasique));
		Label nPM =(Label) infosJoueur.lookup("#nPM");
		nPM.setText("x"+j.compterNbItem(potionMagique));
		Label nPP =(Label) infosJoueur.lookup("#nPP");
		nPP.setText("x"+j.compterNbItem(potionPoison));
		
		
		
		// Recupération des équipement d'armure
		ImageView casque = new ImageView(new Image(getClass().getResourceAsStream("casque.png"), 50,50,false,false));
	    ImageView plastron = new ImageView(new Image(getClass().getResourceAsStream("plastron.png"), 50,50,false,false));
	    ImageView jambieres = new ImageView(new Image(getClass().getResourceAsStream("jambieres.png"), 50,50,false,false));
	    ImageView bottes = new ImageView(new Image(getClass().getResourceAsStream("bottes.png"), 50,50,false,false));
	   
	    HBox imgEquipement = new HBox(10);
	    Armure C= new Armure(0);
	    if (j.chercherArmure(C)) {
	    	imgEquipement.getChildren().add(casque);
	    }
	    Armure P= new Armure(1);
	    if (j.chercherArmure(P)) {
	    	imgEquipement.getChildren().add(plastron);
	    }
	    Armure J= new Armure(2);
	    if (j.chercherArmure(J)) {
	    	imgEquipement.getChildren().add(jambieres);
	    }
	    Armure B= new Armure(3);
	    if (j.chercherArmure(B)) {
	    	imgEquipement.getChildren().add(bottes);
	    }
		
	     //Affichage 
	 	HBox Sac = (HBox) infosJoueur.lookup("#sacEquipement");
	 	Sac.getChildren().add(imgEquipement);
	     
		//...affichage horizontal competences
		HBox buttonContainer = new HBox(10);
		
		
		// Interface pour un voleur
		if(en instanceof Voleur) {

            if(!(j.getSac().isEmpty()))  {

            	//On vole le premier item du joueur
                ((Voleur) en).VolerItem(j);
                
                //actualise affichage du sac
        		
        		nPB.setText("x"+j.compterNbItem(potionBasique));
        		nPM.setText("x"+j.compterNbItem(potionMagique));
        		nPP.setText("x"+j.compterNbItem(potionPoison));			
  
                //affichage du message de l'item volé
				labelItemVole.setText("Item volé : "+ ((Voleur) en).getSacVoleur().get(0));
                
             
                //utilisation de la potion de poison par le voleur
                if(((Voleur) en).getSacVoleur().get(0).getType()==2){

                    j.consommerPotionPoison(potionPoison, en);
                    if (j.getVie()<1) {
                        j.setVie(1);
                    }
                    joueurVie.setProgress((float) j.getVie()/j.getVieMax());
                    labelVieJ.setText(j.getVie() + "PV");
                    //Le joueur meurt
                    if (j.getVie()<1) {
                    	//Maintient de l'ennemis dans le labyrinthe
						Laby.getTabLaby()[j.coordY][j.coordX] = typeEn;
						Laby.actualiserDernierePos(j.coordX,j.coordY,typeEn);
						
						// Retour au lobby
						j.setVie(j.getVieMax());
						j.setKills(0);
						rootLobby.getChildren().clear();
						rootLobby.getChildren().add(lobby.getDonnees());
						j.reinitialiserCoordLobby();
						
						//Dans le cas de boss faire un nouveau labyrinthe
						if(en instanceof Boss) {
							Labyrinthe newLaby = new Labyrinthe(1800/50, 1000/50, 1);
							try {
								lobby.seDeplacer(lobby,newLaby,sceneLobby,j,rootLobby,primaryStage);
							} catch (IOException e1) {
								e1.printStackTrace();
							}
							lobby.actualiserGrille(0,j.coordX,j.coordY,j.coordX,j.coordY);
						}
						else {
							try {
								lobby.seDeplacer(lobby,Laby,sceneLobby,j,rootLobby,primaryStage);
							} catch (IOException e1) {
								e1.printStackTrace();
							}

							lobby.actualiserGrille(0,j.coordX,j.coordY,j.coordX,j.coordY);
						}

					}

                //utilisation d'un autre item par le voleur
                }else {
                	((Voleur) en).utiliserItem();

                }
                
                //actualise la vie de l'ennemi
                statusVie.setProgress((float) j.getVie()/j.getVieMax());
                labelVieE.setText(en.getVie() + "PV");
                
               
            }
        }
		
		// Interface pour le Boss
		if(en instanceof Boss) {
			//On vole le sac du joueur
            ((Boss) en).VolerItems(j);
        
            //actualise affichage du sac du joueur
    		nPB.setText("x"+j.compterNbItem(potionBasique));
    		nPM.setText("x"+j.compterNbItem(potionMagique));
    		nPP.setText("x"+j.compterNbItem(potionPoison));			
  
            //affichage du message de l'item vol�
            Label volerItem = new Label("Item volé: " +((Boss) en).getSacBoss());
            
            //design
            volerItem.setFont(new Font("BerenisADFPro-Regular", 24));
            volerItem.setTextFill(Color.web("black", 0.8));
            
            
            
            //utilisation de l'item par le voleur
            while (!(((Boss) en).getSacBoss().isEmpty()))  {
            	((Boss) en).supprimerItem(((Boss) en).getSacBoss().get(0));
            	en.setVie(en.getVie()+5);
            	en.setVieMax(en.getVie()+5);
            	
            
            //actualise la vie de l'ennemi
            statusVie.setProgress((float) en.getVie()/en.getVieMax());
            labelVieE.setText(en.getVie() + "PV");
            
          
            }
        }

		
		//Interface des bouttons d'actions dans tous les combats sauf contre le sage
		if (!(en instanceof Sage)){
		
		
			//Attaque du joueur
			Image imageAttack = new Image(getClass().getResourceAsStream("attack.png"), 30, 30, false, false);
			Button attack = new Button("Attaquer", new ImageView(imageAttack));
			attack.setOnAction(new EventHandler<ActionEvent>() {
				@Override
				public void handle(ActionEvent e) {
					
					j.InfligerDegats(en);
					statusVie.setProgress((float) en.getVie()/en.getVieMax());
					labelVieE.setText(en.getVie() + "PV");
					
					if (en.getVie()<1) {
						if (en instanceof Boss) {
							final ImageView bg2 = new ImageView(new Image(getClass().getResourceAsStream("win.png"), 1800, 1000, false, false)); 
							rootLobby.getChildren().add(bg2);
						}else {
							j.setArgent(j.getArgent()+50);
							j.setKills(j.getKills()+1);
							if(en instanceof Guerrier) {
								j.setXp(40);
							}else {
								j.setXp(80);
							
							}
							
							rootLobby.getChildren().clear();
							rootLobby.getChildren().add(Laby.getDonnees());
						}
						
						
						
					}
					//l'ennemi contre attaque
					else {
						j.setVie(j.getVie()-en.getAtk());
						
						if (j.getVie()<1) {
							Laby.getTabLaby()[j.coordY][j.coordX] = typeEn;
							Laby.actualiserDernierePos(j.coordX,j.coordY,typeEn);
							j.setVie(j.getVieMax());
							j.setKills(0);
							rootLobby.getChildren().clear();
							rootLobby.getChildren().add(lobby.getDonnees());
	
							j.reinitialiserCoordLobby();
							if(en instanceof Boss) {
								Labyrinthe newLaby = new Labyrinthe(1800/50, 1000/50, 1);
								try {
									lobby.seDeplacer(lobby,newLaby,sceneLobby,j,rootLobby,primaryStage);
								} catch (IOException e1) {
									e1.printStackTrace();
								}
								lobby.actualiserGrille(0,j.coordX,j.coordY,j.coordX,j.coordY);
							}
							else {
								try {
									lobby.seDeplacer(lobby,Laby,sceneLobby,j,rootLobby,primaryStage);
								} catch (IOException e1) {
									e1.printStackTrace();
								}

								lobby.actualiserGrille(0,j.coordX,j.coordY,j.coordX,j.coordY);
							}
	
						}
						joueurVie.setProgress((float) j.getVie()/j.getVieMax());
						labelVieJ.setText(j.getVie() + "PV");
					}
					
				}
			});
			
			// Utilisation de la potion Magique
			Image imagePM = new Image(getClass().getResourceAsStream("potionMagique.png"), 30, 30, false, false);
			Button utiliserPoitionM = new Button("Utiliser Potion Magique", new ImageView(imagePM));
			
			if(j.chercherItem(potionMagique)){
				buttonContainer.getChildren().add(utiliserPoitionM);

			}
			utiliserPoitionM.setOnAction(new EventHandler<ActionEvent>() {
	
				@Override
				public void handle(ActionEvent e) {
					if ((j.getSac().size()>0)) {
						
						
							//on récupère la position de la première potion Magique du sac
							int pos = j.chercherPosItem(potionMagique);
							//on utilise l'item 
							
							j.utiliserItem(j.getSac().get(pos));
					
							
							//on enlève le bouton
							if(!(j.chercherItem(potionMagique))) {
								buttonContainer.getChildren().remove(utiliserPoitionM);
							}

						
					}
					joueurVie.setProgress((float) j.getVie()/j.getVieMax());
					labelVieJ.setText(j.getVie() + "PV");
	        		nPM.setText("x"+j.compterNbItem(potionMagique));
	  				}
				
			});
			

			
			//Utilisation de la potion Basique
			Image imagePB = new Image(getClass().getResourceAsStream("potionBasique.png"), 30, 30, false, false);
			Button utiliserPotionB = new Button("Utiliser Potion Basique", new ImageView(imagePB));
			
			if(j.chercherItem(potionBasique)){
				buttonContainer.getChildren().add(utiliserPotionB);

			}
			utiliserPotionB.setOnAction(new EventHandler<ActionEvent>() {
	
				@Override
				public void handle(ActionEvent e) {
					if (j.getSac().size()>0) {
						
							//on récupère la position de la première potion Basique du sac
							int pos = j.chercherPosItem(potionBasique);
							
							j.utiliserItem(j.getSac().get(pos));
							
							//on enlève le bouton
							if(!(j.chercherItem(potionBasique))) {
								buttonContainer.getChildren().remove(utiliserPotionB);
							}
							
						
					}
					joueurVie.setProgress((float) j.getVie()/j.getVieMax());
					labelVieJ.setText(j.getVie() + "PV");
					nPB.setText("x"+j.compterNbItem(potionBasique));
	
	  				}
				
			});		
			
			//Utilisation de la potion de poison
			Image imagePP = new Image(getClass().getResourceAsStream("potionPoison.png"), 30, 30, false, false);
			Button utiliserPotionPoison = new Button("Utiliser Potion Poison", new ImageView(imagePP));

			if(j.chercherItem(potionPoison)){
				buttonContainer.getChildren().add(utiliserPotionPoison);

			}
			utiliserPotionPoison.setOnAction(new EventHandler<ActionEvent>() {
	
				@Override
				public void handle(ActionEvent e) {
					if (j.getSac().size()>0) {
						
							//on récupère la position de la première potion Basique du sac
							int pos = j.chercherPosItem(potionPoison);
							
							en.consommerPotionPoison(j.getSac().get(pos), j);
							if (en.getVie()<1) {
								if (en instanceof Boss) {
									final ImageView bg2 = new ImageView(); 
									System.out.println("testbon2");
									Image imgWin = new Image(getClass().getResourceAsStream("win.png"), 1800, 1000, false, false);
									bg2.setImage(imgWin);
									rootLobby.getChildren().add(bg2);
								}else {
									j.setArgent(j.getArgent()+50);
									j.setKills(j.getKills()+1);
									if(en instanceof Guerrier) {
										j.setXp(40);
									}else {
										j.setXp(80);
									
									}
									
									rootLobby.getChildren().clear();
									rootLobby.getChildren().add(Laby.getDonnees());
								}
							}		
							//on enlève le bouton
							if(!(j.chercherItem(potionPoison))) {
								buttonContainer.getChildren().remove(utiliserPotionPoison);
							}
							
						
					}
					statusVie.setProgress((float) en.getVie()/en.getVieMax());
					labelVieE.setText(en.getVie() + "PV");
					joueurVie.setProgress((float) j.getVie()/j.getVieMax());
					labelVieJ.setText(j.getVie() + "PV");
	        		nPP.setText("x"+j.compterNbItem(potionPoison));			
	  
				}
				
			});
			
			// Utilisation de l'attaque ultime
			Image imageUlt = new Image(getClass().getResourceAsStream("futur.gif"), 30, 30, false, false);
			Button attackUltime = new Button("Ultime", new ImageView(imageUlt));
			attackUltime.setOnAction(new EventHandler<ActionEvent>() {
	
				@Override
				public void handle(ActionEvent e) {
					j.Ultime(en);
					j.setKills(0);
					if(buttonContainer.getChildren().contains(attackUltime)) {
						buttonContainer.getChildren().remove(attackUltime);
					}
					statusVie.setProgress((float) en.getVie()/en.getVieMax());
					labelVieE.setText(en.getVie() + "PV");
					if (en.getVie()<1) {
						j.setKills(j.getKills()+1);
						j.setArgent(j.getArgent()+50);
						if (en instanceof Boss) {
							final ImageView bg2 = new ImageView(); 
							System.out.println("testbon2");
							Image imgWin = new Image(getClass().getResourceAsStream("win.png"), 1800, 1000, false, false);
							bg2.setImage(imgWin);
							rootLobby.getChildren().add(bg2);
						}else {
							if(en instanceof Guerrier) {

							j.setXp(40);
							}
							else {
							j.setXp(80);
							}
						rootLobby.getChildren().clear();
						rootLobby.getChildren().add(Laby.getDonnees());
						}
					}
					else {
						j.setVie(j.getVie()-en.getAtk());
						if (j.getVie()<1) {
							Laby.getTabLaby()[j.coordY][j.coordX] = typeEn;
							Laby.actualiserDernierePos(j.coordX,j.coordY,typeEn);
							j.setVie(j.getVieMax());
							j.setKills(0);
							rootLobby.getChildren().clear();
							rootLobby.getChildren().add(lobby.getDonnees());
	
							j.reinitialiserCoordLobby();
							lobby.actualiserGrille(0,j.coordX,j.coordY,j.coordX,j.coordY);
							try {
								lobby.seDeplacer(lobby,Laby,sceneLobby,j,rootLobby,primaryStage);
							} catch (IOException e1) {
								
								e1.printStackTrace();
							}
	
						}
						
						joueurVie.setProgress((float) j.getVie()/j.getVieMax());
						labelVieJ.setText(j.getVie() + "PV");
					}
				}
				
			});
			buttonContainer.getChildren().add(attack);
			//chargement de l'ultime
			if (j.getKills()>=3){
				buttonContainer.getChildren().add(attackUltime);
			}
			
			
			buttonContainer.setTranslateY(850);
			buttonContainer.setTranslateX(700);
		}
       
        //Affichage du décor
        background.getChildren().addAll(bg);
        torch.getChildren().addAll(torche1,torche2);
        torche1.setTranslateX(805);
        torche1.setTranslateY(150);
        torche2.setTranslateX(1640);
        torche2.setTranslateY(153);
        
        if(en instanceof Boss) {
        	
            torche1.setTranslateY(195);
            torche1.setTranslateX(810);

        }
    
        
        //Preparation a l'affichage des infos de l'ennemi
        VBox ennemy = new VBox();

        infosEnnemi.setTranslateY(-50);
        infosEnnemi.setTranslateX(-50);
        
        ennemy.setTranslateX(1300);
        ennemy.setTranslateY(150);
        ennemy.getChildren().addAll(infosEnnemi, ennemi);

        //Preparation a l'affichage des infos du joueur
        VBox joueur = new VBox();

        infosJoueur.setTranslateX(50);
       
        joueur.getChildren().addAll(infosJoueur, you);
        joueur.setTranslateY(350);
        joueur.setTranslateX(150);
        
        
        //Affichage de toute les informations
        rootLobby.getChildren().addAll(background,torch,ennemy,joueur,buttonContainer);
        
        
        
        // Affichage de l'interface de combat pour le sage
        if(en instanceof Sage) {
        	VBox vBoxenigme = new VBox(10);
        	Label enigme = new Label(((Sage) en).getEnigme());
        	enigme.setLayoutX(900);
        	enigme.setLayoutY(500);
        	enigme.setWrapText(true);
        	enigme.setFont(new Font("BerenisADFPro-Regular", 24));
        	enigme.setTextFill(Color.web("white", 0.8));
        	//enigme.setPadding(new Insets(16, 0, 0, 0));

        	
        	VBox checkBoxes = new VBox();
        	
//        	System.out.println(((Sage)en).getReponse());
        	for(int i = 0; i < ((Sage) en).getReponse().size(); i++) {
        		CheckBox rep = new CheckBox( ((Sage) en).getReponse().get(i));
        		
        		rep.setFont(new Font("BerenisADFPro-Regular", 24));
        		rep.setTextFill(Color.web("white", 0.8));
//        		rep.setAlignment(Pos.CENTER);
	        	checkBoxes.getChildren().add(rep);
        		
        	}
        	Button valider = new Button("Valider");
        	valider.setTranslateX(400);
        	valider.setTranslateY(0);
        	valider.setFont(new Font("BerenisADFPro-Regular", 24));
			valider.setOnAction(new EventHandler<ActionEvent>() {
				//((Sage) en).getReponse().get(i);
				@Override
				public void handle(ActionEvent e) {
				
					checkBoxes.getChildren();
					String reponseJoueur = "";
					ArrayList<String> reponseSage = ((Sage) en).getReponse();
					for (int i = 0; i<checkBoxes.getChildren().size();i++) {
						if (((CheckBox) checkBoxes.getChildren().get(i)).isSelected()) {
							reponseJoueur+=reponseSage.get(i)+",";
						}
					}
					vBoxenigme.getChildren().clear();
					if (reponseJoueur.equals(((Sage) en).getReponseEnigme())) {	
						j.setArgent(j.getArgent()+50);
						j.setXp(100);
						Label vraiFaux = new Label("Bonne reponse! voila un petit cadeau :)");
						vraiFaux.setFont(new Font("BerenisADFPro-Regular", 24));
						vraiFaux.setTextFill(Color.web("white", 0.8));
						vraiFaux.setAlignment(Pos.BASELINE_RIGHT);
						vBoxenigme.getChildren().add(vraiFaux);
					}
					//mauvaise reponse
					else {
						j.setArgent(j.getArgent()-30);
						Label vraiFaux = new Label("C'est FAUX! donnez moi votre argent!");
						vraiFaux.setFont(new Font("BerenisADFPro-Regular", 24));
						vraiFaux.setTextFill(Color.web("white", 0.8));
						vraiFaux.setAlignment(Pos.BASELINE_RIGHT);
						vBoxenigme.getChildren().add(vraiFaux);
					}
					
					Label solution = new Label("Explication : "+((Sage) en).getExplication());
					solution.setLayoutX(900);
		        	solution.setLayoutY(500);
		        	solution.setFont(new Font("BerenisADFPro-Regular", 24));
		        	solution.setTextFill(Color.web("white", 0.8));
		        	solution.setWrapText(true);
					Button continuer = new Button("Continuer");
					continuer.setFont(new Font("BerenisADFPro-Regular", 24));
					continuer.setAlignment(Pos.BASELINE_RIGHT);
					continuer.setOnAction(new EventHandler<ActionEvent>() {
						@Override
						public void handle(ActionEvent e) {
							rootLobby.getChildren().clear();
							rootLobby.getChildren().add(Laby.getDonnees());
						}
					});
					vBoxenigme.getChildren().addAll(solution,continuer);
				
				}
			});
        	checkBoxes.setSpacing(30);
        	
        	String cssLayoutS = "-fx-border-color: white;\n" +
                    "-fx-border-insets: 5;\n" +
                    "-fx-border-width: 3;\n" +
                    "-fx-border-style: dashed;\n" +
                    "-fx-background-color : black;\n";
        	
        	vBoxenigme.setStyle(cssLayoutS);
        	vBoxenigme.getChildren().addAll(enigme,checkBoxes,valider);
        	vBoxenigme.setTranslateX(660);
        	vBoxenigme.setTranslateY(250);
        	vBoxenigme.setPrefWidth(600);
        	vBoxenigme.setPrefHeight(400);
        	vBoxenigme.setBackground(new Background(new BackgroundFill(Color.WHITE, null, null)));
        	
        	
        	
        	rootLobby.getChildren().add(vBoxenigme);
        }
        
	}
}