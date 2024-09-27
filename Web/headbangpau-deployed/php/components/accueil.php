 <!--ON VEUT METTRE UN BOUTTON ROND AVEC UNE ICONE DE PANIER EN BAS A DROITE DE L ECRAN EN FIXE ET EN MODAL, SUR LE CLICK AFFICHER LE CONTENU DU PANIER GéRé EN JS -->
 <button class="cart-button" onclick="createCartFront(cart)" data-toggle="modal" data-target="#myModalCart"><i class="fas fa-shopping-cart"></i></button>
     <!-- Modal -->
     <div class="modal fade" id="myModalCart" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
        <div class="modal-dialog" role="document">
            <div class="modal-content">
                <div class="modal-header">
                    <h1 class="modal-title" id="myModalLabel"><strong>Panier</strong></h1>
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                </div>
                <div class="modal-body" id="cartContainer"></div>
            </div> 
        </div>
    </div>

    


    
        <div id="myPage" class=" text-center headingPic container-fluid" style="background-color: black;">
            <h3 style="color: rgba(0, 0, 0, 0)">Coucou, je maintiens de la distance</h3>
            <h1 style="color: rgb(255, 255, 255); width:80%;" class:"titleHead" >HEADBANG PAU</h1><br>
            <h2 style="color: rgb(255, 255, 255); right: 0">Votre équipement spécialisé ROCK</h2>
        </div>


        <!-- Container (About Section) -->
        <div id="who" class="container-fluid bg-rammstein" style="color:white">
            <div class="col-sm-12">
                <h2>QUI SOMMES-NOUS?</h2>
                <h3>
                    <p>Headbang Pau est une boutique spécialisée dans l'équipement de musique rock fraîchement implantée près de CY-Tech. Nous proposons des guitares, des batteries, des micros et bientôt d'autres accessoires pour musiciens de tout niveau.</p>
                    <p>Notre équipe est composée de musiciens professionnels qui vous conseilleront et vous guideront dans vos choix.</p>
                </h3>
            </div>
        </div>

        <div id="whofor" class="container-fluid bg-iron" style="color:white">
            <div class="col-sm-12">
                <h2>POUR QUI?</h2><br>
                <h3>
                    <p>Notre boutique est destinée à tous les musiciens, qu'ils soient débutants ou confirmés.</p>
                    <p>De l'apprentissage au concert on vous accompagne dans vos choix!</p>    
                </h3>
            </div>
        </div>