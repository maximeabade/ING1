// Fonction pour envoyer les information en AJAX
function rechercher(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("affichage").innerHTML = this.responseText;
    }
  };
  xhttp.open("POST", "afficherStatistiques.php", true);
  xhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
  xhttp.send("nom="+document.getElementById("nom").value+"&prenom="+document.getElementById("prenom").value);
}
