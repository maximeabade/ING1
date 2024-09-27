// Ici, on récupère la base de données en NoSQL
let usersFromStorage;

fetch("./noSQL/users.JSON")
.then(response => response.json())
.then(data => {
    usersFromStorage = data.users;
})
.catch(error => console.error(error));

// Initialisation des variables
let user;
let connected = false;
let userOnLogs = [];

// Fonction pour lire les informations de connexion saisies dans le formulaire
function setUserEntering() {
    let usernameEntered = document.getElementById("usernameEntered").value;
    let passwordEntered = document.getElementById("passwordEntered").value;
    userOnLogs = [usernameEntered , passwordEntered];
    return(userOnLogs);
}

// Fonction pour comparer les informations de connexion avec celles stockées en base de données
function compareUser() {
    let foundUser = false;
    for(let i=0 ; i<usersFromStorage.length ; i++){
        if(userOnLogs[0] === usersFromStorage[i].username && userOnLogs[1] === usersFromStorage[i].password){
            foundUser = true;
            user = usersFromStorage[i];
        }
    }
    // Affichage du message d'erreur si les informations de connexion sont incorrectes
    if(!foundUser){
        document.getElementById("connexionError").style.display = "block";
        setTimeout(function() {
            document.getElementById("connexionError").style.display = "none";
        }, 5000);
    }
    return foundUser;
}




// Fonction à appeler pour lancer la comparaison sur le submit du formulaire
function submitUser() {
  setUserEntering();
  connected = compareUser();
  if (connected) {
    //console.log("you are now connected");
    setCookie("username", userOnLogs[0], 1); // Créer un cookie pour le nom d'utilisateur et définissez sa durée de vie à 1 jour
    setCookie("isAdmin", user.isAdmin, 1); // Créer un cookie pour isAdmin et définissez sa durée de vie à 1 jour
    checkUserStatus(); // Vérifier le statut de connexion de l'utilisateur
  }
  else {
    //console.log("you are not connected");
    setCookie("username", "", 1); // Supprimer le cookie username
    setCookie("isAdmin", "", 1); // Supprimer le cookie isAdmin
    checkUserStatus(); // Vérifier le statut de connexion de l'utilisateur
  }
}

function disconnect() {
  setCookie("username", "", 1); // Supprimer le cookie username
  setCookie("isAdmin", "", 1); // Supprimer le cookie isAdmin
  checkUserStatus(); // Vérifier le statut de connexion de l'utilisateur
}

// Fonction pour définir un cookie
function setCookie(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime() + exdays * 24 * 60 * 60 * 1000);
    var expires = "expires=" + d.toUTCString();
    document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
  }
  // Fonction pour obtenir la valeur d'un cookie
function getCookie(cname) {
  var name = cname + "=";
  var decodedCookie = decodeURIComponent(document.cookie);
  var ca = decodedCookie.split(";");
  for (var i = 0; i < ca.length; i++) {
    var c = ca[i];
    while (c.charAt(0) == " ") {
      c = c.substring(1);
    }
    if (c.indexOf(name) == 0) {
      return c.substring(name.length, c.length);
    }
  }
  return "";
}

// Fonction pour vérifier si l'utilisateur est connecté
function checkUserStatus() {
  var username = getCookie("username");
  if (username != "") {
    //console.log("Welcome " + username);
    document.getElementById("user-info-username").textContent = "Nom d'utilisateur : " + username;
    document.getElementById("user-info-is-admin").textContent = "Statut Admin : " + getCookie("isAdmin");
    document.getElementById("userInfos").style.display = "block";
    document.getElementById("log-out").style.display = "block";
    document.getElementById("log-in").style.display = "none";
    //on veut en plus fermer le modal
    $('#connexionModal').modal('hide');
  } else {
    //console.log("Not connected");
  }
}

function setUserStatus() {
  if (user) {
    setCookie("username", user.username, 1);
    setCookie("isAdmin", user.isAdmin, 1);
  } else {
    deleteCookie("username");
    deleteCookie("isAdmin");
  }
}
function deleteCookie(cname) {
  document.cookie = cname + '=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;';
}

function submitUser() {
  setUserEntering();
  connected = compareUser();
  if (connected) {
    //console.log("you are now connected");
    user = usersFromStorage.find(u => u.username === userOnLogs[0]);
    setUserStatus();
    checkUserStatus();
    $('#connexionModal').modal('hide');
    document.getElementById("submitButton").setAttribute("data-dismiss", "modal");
  } else {
    //console.log("you are not connected");
    user = null;
    setUserStatus();
    checkUserStatus();
    //garder ouvert le modal et donc bloquerble data-dismiss sur le submit
    document.getElementById("submitButton").setAttribute("data-dismiss", "");
  }
}

function disconnect() {
  user = null;
  deleteCookie("username");
  deleteCookie("isAdmin");
  checkUserStatus();
}
// Appeler la fonction checkUserStatus() lors du chargement de la page pour vérifier si l'utilisateur est connecté
window.onload = function() {
  checkUserStatus();
}();

