<?php

namespace App\DataFixtures;

use Doctrine\Bundle\FixturesBundle\Fixture;
use Doctrine\Common\Persistence\ObjectManager;
use App\Entity\Adresse;
use App\Entity\Formation;
use App\Entity\Entreprise;
use App\Entity\Stage;
class AppFixtures extends Fixture
{
    public function load(ObjectManager $manager)
    {
      //Création d'un générateur de données Faker
      $faker = \Faker\Factory::create('fr_FR');

      $nbrEntreprises = 10;

      $adresse1 = new Adresse();
      $adresse1->setVille($faker->city());
      $adresse1->setCodePostal($faker->postcode());
      $adresse1->setAdresse($faker->numberBetween($min = 1, $max = 999) . ", " . $faker->streetName());
      $adresse2 = new Adresse();
      $adresse2->setVille($faker->city());
      $adresse2->setCodePostal($faker->postcode());
      $adresse2->setAdresse($faker->numberBetween($min = 1, $max = 999) . ", " . $faker->streetName());
      $adresse3 = new Adresse();
      $adresse3->setVille($faker->city());
      $adresse3->setCodePostal($faker->postcode());
      $adresse3->setAdresse($faker->numberBetween($min = 1, $max = 999) . ", " . $faker->streetName());
      $adresse4 = new Adresse();
      $adresse4->setVille($faker->city());
      $adresse4->setCodePostal($faker->postcode());
      $adresse4->setAdresse($faker->numberBetween($min = 1, $max = 999) . ", " . $faker->streetName());
      $adresse5 = new Adresse();
      $adresse5->setVille($faker->city());
      $adresse5->setCodePostal($faker->postcode());
      $adresse5->setAdresse($faker->numberBetween($min = 1, $max = 999) . ", " . $faker->streetName());
      $adresse6 = new Adresse();
      $adresse6->setVille($faker->city());
      $adresse6->setCodePostal($faker->postcode());
      $adresse6->setAdresse($faker->numberBetween($min = 1, $max = 999) . ", " . $faker->streetName());
      $adresse7 = new Adresse();
      $adresse7->setVille($faker->city());
      $adresse7->setCodePostal($faker->postcode());
      $adresse7->setAdresse($faker->numberBetween($min = 1, $max = 999) . ", " . $faker->streetName());
      $adresse8 = new Adresse();
      $adresse8->setVille($faker->city());
      $adresse8->setCodePostal($faker->postcode());
      $adresse8->setAdresse($faker->numberBetween($min = 1, $max = 999) . ", " . $faker->streetName());
      $tabAdresses = array($adresse1, $adresse2, $adresse3, $adresse4, $adresse5, $adresse6, $adresse7, $adresse8);
      foreach ($tabAdresses as $uneAdresse) {
        $manager->persist($uneAdresse);
      }

      $formationDUTInfo = new Formation();
      $formationDUTInfo->setNom("DUT Informatique");
      $formationDUTInfo->setNomCourt("DUT Info");
      $manager->persist($formationDUTInfo);
      $formationLPM = new Formation();
      $formationLPM->setNom("Licence Pro Mouais");
      $formationLPM->setNomCourt("LPM");
      $manager->persist($formationLPM);
      $formationDUTIC = new Formation();
      $formationDUTIC->setNom("DU Technique industriel de commercialisation");
      $formationDUTIC->setNomCourt("DU TIC");
      $manager->persist($formationDUTIC);

      for ($i=1 ; $i<=$nbrEntreprises ; $i++){
        $uneEntreprise = new Entreprise();
        $uneEntreprise->setNom($faker->word());
        $uneEntreprise->setDomaine($faker->realText($maxNbChars = 200, $indexSize = 2));
        $manager->persist($uneEntreprise);
        for ($t=1 ; $t<=$faker->numberBetween($min = 1, $max = 3) ; $t++){
          $unStage = new Stage();
          $unStage->setNom($faker->realText($maxNbChars = 80, $indexSize = 2));
          $unStage->setDescription($faker->realText($maxNbChars = 200, $indexSize = 2));
          $unStage->setEMail($faker->email());
          $unStage->setDateAjout($faker->dateTimeBetween($startDate = '-6 months', $endDate = 'now', $timezone = 'Europe/Paris'));
          $unStage->setEntreprise($uneEntreprise);
          $unStage->setAdresse($tabAdresses[$faker->numberBetween($min = 0, $max = 7)]);
          $n = $faker->numberBetween($min = 1, $max = 6);
          switch ($n) {
            case 1:
                $unStage->addFormation($formationDUTInfo);
                break;
            case 2:
                $unStage->addFormation($formationLPM);
                break;
            case 3:
                $unStage->addFormation($formationDUTIC);
                break;
            case 4:
                $unStage->addFormation($formationDUTInfo);
                $unStage->addFormation($formationLPM);
                break;
            case 5:
                $unStage->addFormation($formationDUTInfo);
                $unStage->addFormation($formationDUTIC);
                break;
            case 6:
                $unStage->addFormation($formationDUTInfo);
                $unStage->addFormation($formationDUTIC);
                $unStage->addFormation($formationLPM);
                break;
          }
          $manager->persist($unStage);
        }
      }


        $manager->flush();
    }
}
