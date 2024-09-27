<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Routing\Annotation\Route;
use App\Entity\Entreprise;
use App\Entity\Formation;
use App\Entity\Adresse;
use App\Entity\Stage;

class ProstageController extends AbstractController
{
    /**
     * @Route("/", name="prostage_accueil")
     */
    public function index()
    {
        return $this->render('prostage/index.html.twig', [
            'controller_name' => 'ProstageController'
        ]);
    }

    /**
     * @Route("/filtrer/entreprises", name="prostage_filtre_entreprises")
     */
    public function afficherFiltreEntreprises()
    {
      //Recuperer le repository de l'entité entreprises
      $repositoryEntreprise = $this->getDoctrine()->getRepository(Entreprise::class);
      //Recuperer les entreprises enregistrées en BD
      $entreprises = $repositoryEntreprise->findAll();

        return $this->render('prostage/affichageFiltreEntreprises.html.twig', [
            'controller_name' => 'ProstageController',
            'entreprises' => $entreprises
        ]);
    }

    /**
     * @Route("/filtrer/formations", name="prostage_filtre_formations")
     */
    public function afficherFiltreFormations()
    {
      //Recuperer le repository de l'entité formations
      $repositoryFormation = $this->getDoctrine()->getRepository(Formation::class);
      //Recuperer les formations enregistrées en BD
      $formations = $repositoryFormation->findAll();
        return $this->render('prostage/affichageFiltreFormations.html.twig', [
            'controller_name' => 'ProstageController',
            'formations' => $formations
        ]);
    }

    /**
     * @Route("/resultatRecherche/entreprises/{id}", name="prostage_resultatRecherche_entreprises")
     */
    public function afficherResultatRechercheEntreprises($id)
    {
        //Recuperer le repository de l'entité entreprises
        $repositoryEntreprise = $this->getDoctrine()->getRepository(Entreprise::class);
        //Recuperer l'entreprise enregistrées en BD
        $entreprise = $repositoryEntreprise->find($id);
        return $this->render('prostage/affichageResultatRechercheEntreprises.html.twig', [
            'controller_name' => 'ProstageController',
            'entreprise' => $entreprise
        ]);
    }

    /**
     * @Route("/resultatRecherche/formations/{id}", name="prostage_resultatRecherche_formations")
     */
    public function afficherResultatRechercheFormations($id)
    {
        //Recuperer le repository de l'entité formations
        $repositoryFormation = $this->getDoctrine()->getRepository(Formation::class);
        //Recuperer la formation enregistrées en BD
        $formation = $repositoryFormation->findAll($id);
        return $this->render('prostage/affichageResultatRechercheFormations.html.twig', [
            'controller_name' => 'ProstageController',
            'formation' => $formation
        ]);
    }

    /**
     * @Route("/stage/{id}", name="prostage_stage")
     */
    public function afficherStage($id)
    {
        return $this->render('prostage/affichageStage.html.twig', [
            'controller_name' => 'ProstageController',
            'idStage' => $id
        ]);
    }
}
