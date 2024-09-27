// Fonction pour envoyer les information en AJAX
function selectJoueur(joueur){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("champFormulaire").innerHTML = this.responseText;
    }
  };
  xhttp.open("POST", "entrerModifJoueur.php", true);
  xhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
  xhttp.send("joueur="+joueur.id);
}
