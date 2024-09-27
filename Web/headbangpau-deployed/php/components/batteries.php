<div id="batteries" class="container-fluid bg-simpleP" style="color:rgb(255, 255, 255)">
            <div class="row">
                <div class="col-sm-12">
                    <h2>BATTERIES</h2><br>
                    <h3>Notre gamme de batteries est composée de 3 modèles exclusifs de nos marques certifiées. Nous vous proposons des batteries allant du niveau débutant à expert prêt à partir en tournée.</h3><br>
                </div>
                <!--BOUTON POUR DÉROULER LE TABLEAU CONTENANT LES IMAGES DES GUITARES, LEUR PRIX, LEURS DÉTAILS ET SPÉCIFICITÉS, ET UN BOUTON D AJOUT AU PANIER -->
                <div class="col-sm-4">
                    <button type="button" class="btn btn-info btn-lg" data-toggle="modal" data-target="#myModalBat" onclick="batterieChilds()" >VOIR LES BATTERIES</button>
                    <!-- Modal -->
                    <div class="modal fade" id="myModalBat" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
                        <div class="modal-dialog" role="document">
                            <div class="modal-content">
                                <div class="modal-header">
                                    <h1 class="modal-title" id="myModalLabel"><strong>Nos batteries</strong></h1>
                                    <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                                        <span aria-hidden="true">&times;</span>
                                    </button>
                                </div>
                                <div class="modal-body" id="batteriesContainer"></div>
                            </div>
                        </div>
                    </div>

                </div>
                    
            </div> 
        </div>
