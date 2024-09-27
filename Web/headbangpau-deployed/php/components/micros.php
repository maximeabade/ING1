<div id="micros" class="container-fluid bg-metallica" style="color:white">
            <div class="row">
                <div class="col-sm-12">
                    <h2>MICROS</h2><br>
                    <h3>Notre gamme de micros est composée de 3 modèles exclusifs de nos marques certifiées. Nous vous proposons des micros allant de l'apprenti recorder au chanteur prêt à partir en tournée.</h3><br>
                </div>
                <!--BOUTON POUR DÉROULER LE TABLEAU CONTENANT LES IMAGES DES GUITARES, LEUR PRIX, LEURS DÉTAILS ET SPÉCIFICITÉS, ET UN BOUTON D AJOUT AU PANIER -->
                <div class="col-sm-4">
                    <button type="button" class="btn btn-info btn-lg" data-toggle="modal" data-target="#myModalMic" onclick="microChilds()">VOIR LES MICROS</button>
                    <!-- Modal -->
                    <div class="modal fade" id="myModalMic" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
                        <div class="modal-dialog" role="document">
                            <div class="modal-content">
                                <div class="modal-header">
                                    <h1 class="modal-title" id="myModalLabel"><strong>Nos micros</strong></h1>
                                    <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                                        <span aria-hidden="true">&times;</span>
                                    </button>
                                </div>
                                <div class="modal-body" id="microsContainer"></div>
                            </div>
                        </div>
                    </div>

                </div>
                    
            </div>
        </div>