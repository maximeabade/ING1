var guitaresTabObject;
var microsTabObject;
var batteriesTabObject;

fetch("./noSQL/guitares.JSON")  
    .then(response => response.json())
    .then(jsonData => {
    guitaresTabObject = jsonData;
    })
    .catch(error => console.error(error));

fetch("./noSQL/micros.JSON")
    .then(response => response.json())
    .then(jsonData => {
    microsTabObject = jsonData;
    })
    .catch(error => console.error(error));

fetch("./noSQL/batteries.JSON")
    .then(response => response.json())
    .then(jsonData => {
    batteriesTabObject = jsonData;
    })
    .catch(error => console.error(error));

//ICI FAIRE L UPDATE DE CART EN FONCTION DE SI T ES CONNECTE OU PAS
var cart = [];
var idToSendForCart= "";

 //fonction qui update le total du panier
function updateCartTotal(cart) {
    var cartTotal = 0;
    for (var i = 0; i < cart.length; i++) {
        cartTotal += Number(cart[i].price)*Number(cart[i].qty);
    }
    //document.getElementById("cartTotal").innerHTML = cartTotal;      ==> pour afficher le total dans le panier
    return cartTotal;
}


//fonction qui supprime les doublons dans le panier
function cartCleaner(cart) {
    var cartTotal = 0;
    var cartCopy = cart.slice(); // make a copy of the cart
    var cartTabToSend = [];
    //console.log("cartCopy: ",cartCopy);
    // iterate over the cart from the end to the beginning
    for (var i = cartCopy.length - 1; i >= 0; i--) {
        var found = false;
        // check if the current item is already in the cartTabToSend
        for (var j = 0; j < cartTabToSend.length; j++) {
            if (cartCopy[i].id === cartTabToSend[j].id) {
                found = true;
                break;
            }
        }
        if (!found) {
            // if the current item is not found, add it to cartTabToSend
            cartTabToSend.push(cartCopy[i]);
        }
    }
    // reverse the cartTabToSend to match the original cart order
    cartTabToSend.reverse();
    cart = cartTabToSend;
    //console.log(cart);
    //update cartTotal
    cartTotal = updateCartTotal(cart);
    //console.log(cartTotal);
    //ICI SI ON EST CONNECTE ON UPDATE LE CART EN BDD DE users.JSON
    
    return cart;
}


//vide les tableaux du panier, des guitares, des micros et des batteries, et on verifie si le user est admin pour laisser la possibilité d'afficher les stocks
function removeChildren(){
    var cartContainer = document.getElementById("cartContainer");
    var guitaresContainer = document.getElementById("guitaresContainer");
    var microsContainer = document.getElementById("microsContainer");
    var batteriesContainer = document.getElementById("batteriesContainer");
    //now we remove every of its child
    if(guitaresContainer.hasChildNodes()) {
        while (guitaresContainer.firstChild) {
            guitaresContainer.removeChild(guitaresContainer.firstChild);
        }
    }else if(microsContainer.hasChildNodes()) {
        while (microsContainer.firstChild) {
            microsContainer.removeChild(microsContainer.firstChild);
        }
    }else if(batteriesContainer.hasChildNodes()) {
        while (batteriesContainer.firstChild) {
            batteriesContainer.removeChild(batteriesContainer.firstChild);
        }
    }else if(cartContainer.hasChildNodes()) {
        while (cartContainer.firstChild) {
            cartContainer.removeChild(cartContainer.firstChild);
        }
    }
    cartCleaner(cart);  
};






///////////////////////////////////////--AJOUTS AU PANIER--///////////////////////////////////////
//fonction addGuitareToCart(id, qty)
function addGuitareToCart(id, qty) {
    cartCleaner(cart);
    //console.log(id);
    //console.log(qty);
    //on va chercher la guitare en fonction de l'id
    for(var i=0; i<guitaresTabObject.length; i++) {
        if(guitaresTabObject[i].id == id) {
            //console.log(guitaresTabObject[i]);
            //on crée un objet guitare qui contient les infos de la guitare
            var guitareCart = {
                "id": guitaresTabObject[i].id,
                "name": guitaresTabObject[i].Name,
                "image": guitaresTabObject[i].Image,
                "price": guitaresTabObject[i].Price,
                "qty": qty
            }
           // console.log(guitareCart.id , id);
            
            //on va vérifier si la guitare est déjà présente dans le panier
            if(cart.length == 0) {
                cart.push(guitareCart);
                //console.log("le panier est vide, on ajoute l elt");
            }

            else {                 //sinon, on va vérifier si la guitare est déjà présente dans le panier
                //pour chaque objet du panier(boucle sur j), on compare l'id de l'objet avec l'id de la guitare, qui est le meme que celui rentré en paramètre
                //console.log(cart.length, id);
                for(var j=0; j<cart.length; j++) {
                    if(cart[j].id == id && cart[j].qty != guitareCart.qty) {
                        //console.log(id , cart[j].id);
                        //si la guitare est déjà présente dans le panier, on compare les qty et on update la qty dans l'objet du panier sans en rajouter un nouveau
                        cart[j].qty = guitareCart.qty;
                        //console.log("l elt est deja present mais on a changé sa qty");
                    }else if (cart[j].id != id){ //si la guitare n'est pas présente dans le panier, on l'ajoute
                        cart.push(guitareCart);
                    }
                }
            }
            //console.log(cart);
        }
    }
    //console.log(cartTotal);

    // create and show popup
    var popup = document.createElement("div");
    popup.setAttribute("class", "popup");
    popup.setAttribute("style", "background-color: green; color: white; padding: 10px; border-radius: 5px; position: fixed; top: 50%; left: 50%; transform: translate(-50%, -50%); z-index: 9999; font-size: 16px;");
    popup.innerHTML = "L'objet a été ajouté au panier";

    document.body.appendChild(popup);

    // close popup after 2 seconds and on click
    popup.onclick = function() {
        popup.parentNode.removeChild(popup);
    };

    setTimeout(function() {
        if(popup){
            popup.parentNode.removeChild(popup);
        }
    }, 1000);



    cart = cartCleaner(cart);
    //console.log(cart);
}
//fonction addMicroToCart(id, qty)
function addMicroToCart(id, qty) {
    cartCleaner(cart);
    //console.log(id);
    //console.log(qty);
    //on va chercher la guitare en fonction de l'id
    for(var i=0; i<microsTabObject.length; i++) {
        if(microsTabObject[i].id == id) {
            //console.log(guitaresTabObject[i]);
            //on crée un objet guitare qui contient les infos de la guitare
            var microCart = {
                "id": microsTabObject[i].id,
                "name": microsTabObject[i].Name,
                "image": microsTabObject[i].Image,
                "price": microsTabObject[i].Price,
                "qty": qty
            }
           // console.log(guitareCart.id , id);
            
            //on va vérifier si la guitare est déjà présente dans le panier
            if(cart.length == 0) {
                cart.push(microCart);
                console.log("le panier est vide, on ajoute l elt");
            }

            else {                 //sinon, on va vérifier si la guitare est déjà présente dans le panier
                //pour chaque objet du panier(boucle sur j), on compare l'id de l'objet avec l'id de la guitare, qui est le meme que celui rentré en paramètre
                //console.log(cart.length, id);
                for(var j=0; j<cart.length; j++) {
                    if(cart[j].id == id && cart[j].qty != microCart.qty) {
                        console.log(id , cart[j].id);
                        //si la guitare est déjà présente dans le panier, on compare les qty et on update la qty dans l'objet du panier sans en rajouter un nouveau
                        cart[j].qty = microCart.qty;
                        console.log("l elt est deja present mais on a changé sa qty");
                    }else if (cart[j].id != id){ //si la guitare n'est pas présente dans le panier, on l'ajoute
                        cart.push(microCart);
                    }
                }
            }
            //console.log(cart);
        }
    }
    // create and show popup
    var popup = document.createElement("div");
    popup.setAttribute("class", "popup");
    popup.setAttribute("style", "background-color: green; color: white; padding: 10px; border-radius: 5px; position: fixed; top: 50%; left: 50%; transform: translate(-50%, -50%); z-index: 9999; font-size: 16px;");
    popup.innerHTML = "L'objet a été ajouté au panier";

    document.body.appendChild(popup);

    // close popup after 2 seconds and on click

    popup.onclick = function() {
        popup.parentNode.removeChild(popup);
    };

    setTimeout(function() {
        if(popup){
            popup.parentNode.removeChild(popup);
        }
    }, 1000);



    cart = cartCleaner(cart);
    //actualiser le total du panier

    cart = cartCleaner(cart);
}
//fonction addBatterieToCart(id, qty)
function addBatterieToCart(id, qty) {
    cartCleaner(cart);
    //console.log(id);
    //console.log(qty);
    //on va chercher la batterie en fonction de l'id
    for(var i=0; i<batteriesTabObject.length; i++) {
        if(batteriesTabObject[i].id == id) {
            //console.log(batteriesTabObject[i]);
            //on crée un objet batterie qui contient les infos de la batterie
            var batterieCart = {
                "id": batteriesTabObject[i].id,
                "name": batteriesTabObject[i].Name,
                "image": batteriesTabObject[i].Image,
                "price": batteriesTabObject[i].Price,
                "qty": qty
            }
            //console.log(batterieCart.id , id);
            
            //on va vérifier si la batterie est déjà présente dans le panier
            if(cart.length == 0) {
                cart.push(batterieCart);
                //console.log("le panier est vide, on ajoute l elt");
            } else {                 //sinon, on va vérifier si la batterie est déjà présente dans le panier
                //pour chaque objet du panier(boucle sur j), on compare l'id de l'objet avec l'id de la batterie, qui est le meme que celui rentré en paramètre
                //console.log(cart.length, id);
                var found = false;
                for(var j=0; j<cart.length; j++) {
                    if(cart[j].id == id && cart[j].qty != batterieCart.qty) {
                        //console.log(id , cart[j].id);
                        //si la batterie est déjà présente dans le panier, on compare les qty et on update la qty dans l'objet du panier sans en rajouter un nouveau
                        cart[j].qty = batterieCart.qty;
                        //console.log("l elt est deja present mais on a changé sa qty");
                        found = true;
                        break;
                    } else if (cart[j].id == id) {
                        found = true;
                        break;
                    }
                }
                if (!found) { //si la batterie n'est pas présente dans le panier, on l'ajoute
                    cart.push(batterieCart);
                }
            }
            //console.log(cart);
        }
    }

    // create and show popup
    var popup = document.createElement("div");
    popup.setAttribute("class", "popup");
    popup.setAttribute("style", "background-color: green; color: white; padding: 10px; border-radius: 5px; position: fixed; top: 50%; left: 50%; transform: translate(-50%, -50%); z-index: 9999; font-size: 16px;");
    popup.innerHTML = "L'objet a été ajouté au panier";

    document.body.appendChild(popup);

    // close popup after 2 seconds and on click

    popup.onclick = function() {
        popup.parentNode.removeChild(popup);
    };

    setTimeout(function() {
        if(popup){
            popup.parentNode.removeChild(popup);
        }
    }, 1000);

    //actualiser le total du panier
    cart = cartCleaner(cart);
}



//////////////////////////////////////--SUPPRESSION DES ARTICLES DU PANIER--//////////////////////////////////////
function removeFromCartTab(id){
    //console.log(id);
    for(var i=0; i<cart.length; i++) {
        if(cart[i].id == id) {
            console.log("l'élément du tableau à supprimer est: " , cart[i]);
            cart.splice(i, 1);
        } 
    }
    document.getElementById(""+id+"div3").innerHTML = "";
    document.getElementById(""+id+"DIV").innerHTML = "";
    if(cart.length == 0) {
        document.getElementById("cartContainer").innerHTML = "Votre panier est vide";
    }
    updateCartTotal(cart);
    return cart;
}

function emptyCart(){
    cart = [];
    updateCartTotal(cart);
    cart = cartCleaner(cart);
    console.log("panier vidé");
    document.getElementById("cartContainer").innerHTML = "Votre panier est vide";
    return cart;
}


//////////////////////////////////////--GÉNÉRATION DES HTML DES PRODUITS + INTERACTIONS--//////////////////////////////////////
function guitareChilds() {
    
    removeChildren();
    var container = document.getElementById("guitaresContainer");
    var tableauDesId = [];
    for(var i=0; i<guitaresTabObject.length; i++) {
        //faire un tableau contenant les id des guitares
        var id = guitaresTabObject[i].id;
        tableauDesId.push(id);
        //console.log(tableauDesId);

        var guitare = guitaresTabObject[i];

        var div1 = document.createElement("div");
            div1.setAttribute("class", "row");
            div1.setAttribute("style", "margin-bottom: 20px;");
            div1.setAttribute("style", "border: none; color: black;");
            div1.setAttribute("id", guitare.id);
            //on hover, get id of the guitare
            div1.setAttribute("onmouseover", "idToSendForCart = this.id;");

        var popUpAddedToCart = document.createElement("div");
            popUpAddedToCart.setAttribute("class", "alert alert-success alert-dismissible");
            popUpAddedToCart.setAttribute("style", "position: fixed; display: none;");
            popUpAddedToCart.setAttribute("onclick", "this.style.display='none';");           
            popUpAddedToCart.setAttribute("id", "popUpAddedToCart"+id);
            popUpAddedToCart.innerHTML = "L'article a été ajouté au panier";

        
        var div2 = document.createElement("div");
            div2.setAttribute("class", "col-sm-4");    
        
        var img = document.createElement("img");
            img.setAttribute("id", id+"img");
            img.setAttribute("src", guitare.Image);
            img.setAttribute("class", "img-responsive");
            img.setAttribute("style", "width:100%; object-fit: contain; max-height: 150px;");
            //on hover zoom
            img.setAttribute("onmouseover", "this.style.transform='scale(1.2)';");
            img.setAttribute("onmouseout", "this.style.transform='scale(1)';");

        div2.appendChild(img);

        var div3 = document.createElement("div");
            div3.setAttribute("class", "col-sm-8");
            //we want to differentiate the divs for each product
            div3.setAttribute("id", guitare.id+"div");

        var h4 = document.createElement("h4");

        var Strong1 = document.createElement("strong");
            Strong1.innerHTML = guitare.Name;

        var p1 = document.createElement("p");
            p1.innerHTML = guitare.Details;

        var p2 = document.createElement("p");

        var Strong2 = document.createElement("strong");
            Strong2.innerHTML = guitare.Price+"€";

        p2.appendChild(Strong2);

        /*
        On veut mtnt un boutton moins, un affichage de la qté et un boutton plus
        */
        {var quantityInput = document.createElement("input");
        quantityInput.setAttribute("value", "1");
            quantityInput.setAttribute("type", "number");
            quantityInput.setAttribute("id", guitare.id+"quantity");
            quantityInput.setAttribute("placeholder", "1");
            quantityInput.setAttribute("max", guitare.Stock);
            quantityInput.setAttribute("style", "width: 50px; margin-left: 10px; margin-right: 10px; display: block; text-align: center; border: none; color: black; background-color: #f1f1f1;");
            quantityInput.setAttribute("onchange", "if(this.value > "+guitare.Stock+"){this.value = "+guitare.Stock+";}else if(this.value < 1){this.value = 1;}else{console.log(this.value);}");
            quantityInput.setAttribute("onkeyup", "if(this.value > "+guitare.Stock+"){this.value = "+guitare.Stock+";}else if(this.value < 1){this.value = 1;}else{this.value = this.value+1}");
            quantityInput.setAttribute("onkeydown", "if(this.value > "+guitare.Stock+"){this.value = "+guitare.Stock+";}else if(this.value < 1){this.value = 1;}else{this.value = this.value+1}");

        }

        {var buttonMoins = document.createElement("button");
            buttonMoins.setAttribute("type", "button");
            buttonMoins.setAttribute("class", "btn btn-primary");
            buttonMoins.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px; display: block;");
            buttonMoins.innerHTML = "-";
            buttonMoins.setAttribute("onclick", "if(document.getElementById('"+guitare.id+"quantity').value > 1){document.getElementById('"+guitare.id+"quantity').value = document.getElementById('"+guitare.id+"quantity').value - 1;}else{document.getElementById('"+guitare.id+"quantity').value = 1;}console.log(document.getElementById('"+guitare.id+"quantity').value);");
        }

        {var buttonPlus = document.createElement("button");
            buttonPlus.setAttribute("type", "button");
            buttonPlus.setAttribute("class", "btn btn-primary");
            buttonPlus.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px; display: block;");
            buttonPlus.innerHTML = "+";
            buttonPlus.setAttribute("onclick", "if(document.getElementById('"+guitare.id+"quantity').value < 5 ){document.getElementById('"+guitare.id+"quantity').value++;}else{document.getElementById('"+guitare.id+"quantity').value = 5;}console.log(document.getElementById('"+guitare.id+"quantity').value);" );
        }

        {var buttonStock = document.createElement("button");
            buttonStock.setAttribute("type", "button");
            buttonStock.setAttribute("id" , guitare.id+"stock");
            buttonStock.setAttribute("class", "btn btn-primary");
            buttonStock.setAttribute("style", "margin-top: 10px; margin-bottom: 30px;");
            buttonStock.innerHTML = "Voir le stock";
            //on hover on the button, show stock
            buttonStock.setAttribute("onmouseover", "this.innerHTML = 'Stock : '+(document.getElementById('" +  guitare.id + "quantity').value - " + guitare.Stock + ")*(-1);;");
            buttonStock.setAttribute("onmouseout", "this.innerHTML = 'Voir le stock';");
            if(getCookie('isAdmin') != 'true'){
                buttonStock.setAttribute("style", "display: none");
            }
        }

        {var ligneDeBouttons = document.createElement("div");
            ligneDeBouttons.setAttribute("style", "display: flex; flex-direction: row; justify-content: center; align-items: center; ");
            ligneDeBouttons.appendChild(buttonMoins);
            ligneDeBouttons.appendChild(quantityInput);
            ligneDeBouttons.appendChild(buttonPlus);
        }            


        {var button = document.createElement("button");
            button.setAttribute("type", "button");
            button.setAttribute("class", "btn btn-primary");
            button.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px;");
            button.innerHTML = "Ajouter au panier";
            button.setAttribute("onclick", "if((document.getElementById('"+guitare.id+"quantity').value) == ''){(document.getElementById('"+guitare.id+"quantity').value) = 1;}addGuitareToCart(idToSendForCart , document.getElementById('"+guitare.id+"quantity').value);");//mtnt on veut envoyer ces deux donnees dans une fonction qui va récupérer la guitare et la qty en parametres, et l ajouter au tableau d items du panier
        }
        
        {
            p2.appendChild(Strong2);
            h4.appendChild(Strong1);
            div3.appendChild(h4);
            div3.appendChild(p1);
            div3.appendChild(p2);
            div3.appendChild(button);
            div3.appendChild(buttonStock);
            div3.appendChild(ligneDeBouttons);
            div2.appendChild(popUpAddedToCart);
            div1.appendChild(div2);
            div1.appendChild(div3);
            container.appendChild(div1);
            //console.log(div1.id);
            }

    }

    cart = cartCleaner(cart);
}

function microChilds() {
    removeChildren();
    var container = document.getElementById("microsContainer");
    var tableauDesId = [];
    for(var i=0; i<microsTabObject.length; i++) {
        //faire un tableau contenant les id des guitares
        var id = microsTabObject[i].id;
        tableauDesId.push(id);
        //console.log(tableauDesId);

        var micro = microsTabObject[i];
        var div1 = document.createElement("div");
            div1.setAttribute("class", "row");
            div1.setAttribute("style", "margin-bottom: 20px;");
            div1.setAttribute("style", "border: none; color: black;");
            div1.setAttribute("id", micro.id);
            //on hover, get id of the micro
            div1.setAttribute("onmouseover", "idToSendForCart = this.id;");
        
        var div2 = document.createElement("div");
            div2.setAttribute("class", "col-sm-4");    
        
        var img = document.createElement("img");
            img.setAttribute("src", micro.Image);
            img.setAttribute("class", "img-responsive");
            img.setAttribute("style", "width:100%; object-fit: contain; max-height: 150px;");
            //on hover zoom
            img.setAttribute("onmouseover", "this.style.transform='scale(1.2)';");
            img.setAttribute("onmouseout", "this.style.transform='scale(1)';");

        div2.appendChild(img);

        var div3 = document.createElement("div");
            div3.setAttribute("class", "col-sm-8");
            //we want to differentiate the divs for each product
            div3.setAttribute("id", micro.id+"div");

        var h4 = document.createElement("h4");

        var Strong1 = document.createElement("strong");
            Strong1.innerHTML = micro.Name;

        var p1 = document.createElement("p");
            p1.innerHTML = micro.Details;

        var p2 = document.createElement("p");

        var Strong2 = document.createElement("strong");
            Strong2.innerHTML = micro.Price+"€";

        p2.appendChild(Strong2);

        /*
        On veut mtnt un boutton moins, un affichage de la qté et un boutton plus
        */
        {var quantityInput = document.createElement("input");
            quantityInput.setAttribute("type", "number");
            quantityInput.setAttribute("id", micro.id+"quantity");
            quantityInput.setAttribute("placeholder", "1");
            quantityInput.setAttribute("max", micro.Stock);
            quantityInput.setAttribute("style", "width: 50px; margin-left: 10px; margin-right: 10px; display: block; text-align: center; border: none; color: black; background-color: #f1f1f1;");
            quantityInput.setAttribute("onchange", "if(this.value > "+micro.Stock+"){this.value = "+micro.Stock+";}else if(this.value < 1){this.value = 1;}else{console.log(this.value);}");
            quantityInput.setAttribute("onkeyup", "if(this.value > "+micro.Stock+"){this.value = "+micro.Stock+";}else if(this.value < 1){this.value = 1;}else{this.value = this.value+1}");
            quantityInput.setAttribute("onkeydown", "if(this.value > "+micro.Stock+"){this.value = "+micro.Stock+";}else if(this.value < 1){this.value = 1;}else{this.value = this.value+1}");

        }

        {var buttonMoins = document.createElement("button");
            buttonMoins.setAttribute("type", "button");
            buttonMoins.setAttribute("class", "btn btn-primary");
            buttonMoins.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px; display: block;");
            buttonMoins.innerHTML = "-";
            buttonMoins.setAttribute("onclick", "if(document.getElementById('"+micro.id+"quantity').value > 1){document.getElementById('"+micro.id+"quantity').value = document.getElementById('"+micro.id+"quantity').value - 1;}else{document.getElementById('"+micro.id+"quantity').value = 1;}console.log(document.getElementById('"+micro.id+"quantity').value);");
        }

        {var buttonPlus = document.createElement("button");
            buttonPlus.setAttribute("type", "button");
            buttonPlus.setAttribute("class", "btn btn-primary");
            buttonPlus.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px; display: block;");
            buttonPlus.innerHTML = "+";
            buttonPlus.setAttribute("onclick", "if(document.getElementById('"+micro.id+"quantity').value < 5 ){document.getElementById('"+micro.id+"quantity').value++;}else{document.getElementById('"+micro.id+"quantity').value = 5;}console.log(document.getElementById('"+micro.id+"quantity').value);" );
        }

        {var buttonStock = document.createElement("button");
            buttonStock.setAttribute("type", "button");
            buttonStock.setAttribute("id" , micro.id+"stock");
            buttonStock.setAttribute("class", "btn btn-primary");
            buttonStock.setAttribute("style", "margin-top: 10px; margin-bottom: 30px;");
            buttonStock.innerHTML = "Voir le stock";
            //on hover on the button, show stock
            buttonStock.setAttribute("onmouseover", "this.innerHTML = 'Stock : '+(document.getElementById('" +  micro.id + "quantity').value - " + micro.Stock + ")*(-1);;");
            buttonStock.setAttribute("onmouseout", "this.innerHTML = 'Voir le stock';");
            if(getCookie('isAdmin') != 'true'){
                buttonStock.setAttribute("style", "display: none");
            }
        }

        {var ligneDeBouttons = document.createElement("div");
            ligneDeBouttons.setAttribute("style", "display: flex; flex-direction: row; justify-content: center; align-items: center; ");
            ligneDeBouttons.appendChild(buttonMoins);
            ligneDeBouttons.appendChild(quantityInput);
            ligneDeBouttons.appendChild(buttonPlus);
        }            


        {var button = document.createElement("button");
            button.setAttribute("type", "button");
            button.setAttribute("class", "btn btn-primary");
            button.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px;");
            button.innerHTML = "Ajouter au panier";
            button.setAttribute("onclick", "if((document.getElementById('"+micro.id+"quantity').value) == ''){(document.getElementById('"+micro.id+"quantity').value) = 1;}console.log(document.getElementById('"+micro.id+"quantity').value + ' en qty de ' + idToSendForCart);addMicroToCart(idToSendForCart , document.getElementById('"+micro.id+"quantity').value)");//mtnt on veut envoyer ces deux donnees dans une fonction qui va récupérer la micro et la qty en parametres, et l ajouter au tableau d items du panier
        }

        {
        p2.appendChild(Strong2);
        h4.appendChild(Strong1);
        div3.appendChild(h4);
        div3.appendChild(p1);
        div3.appendChild(p2);
        div3.appendChild(button);
        div3.appendChild(buttonStock);
        div3.appendChild(ligneDeBouttons);
        div1.appendChild(div2);
        div1.appendChild(div3);
        container.appendChild(div1);
        //console.log(div1.id);
        }
    }
    cart = cartCleaner(cart);

}

function batterieChilds() {
    removeChildren();
    var container = document.getElementById("batteriesContainer");
    var tableauDesId = [];
    for(var i=0; i<batteriesTabObject.length; i++) {
        //faire un tableau contenant les id des guitares
        var id = batteriesTabObject[i].id;
        tableauDesId.push(id);
        //console.log(tableauDesId);

        var batterie = batteriesTabObject[i];
        var div1 = document.createElement("div");
            div1.setAttribute("class", "row");
            div1.setAttribute("style", "margin-bottom: 20px;");
            div1.setAttribute("style", "border: none; color: black;");
            div1.setAttribute("id", batterie.id);
            //on hover, get id of the batterie
            div1.setAttribute("onmouseover", "idToSendForCart = this.id;");
        
        var div2 = document.createElement("div");
            div2.setAttribute("class", "col-sm-4");    
        
        var img = document.createElement("img");
            img.setAttribute("src", batterie.Image);
            img.setAttribute("class", "img-responsive");
            img.setAttribute("style", "width:100%; object-fit: contain; max-height: 150px;");
            //on hover zoom
            img.setAttribute("onmouseover", "this.style.transform='scale(1.2)';");
            img.setAttribute("onmouseout", "this.style.transform='scale(1)';");

        div2.appendChild(img);

        var div3 = document.createElement("div");
            div3.setAttribute("class", "col-sm-8");
            //we want to differentiate the divs for each product
            div3.setAttribute("id", batterie.id+"div");

        var h4 = document.createElement("h4");

        var Strong1 = document.createElement("strong");
            Strong1.innerHTML = batterie.Name;

        var p1 = document.createElement("p");
            p1.innerHTML = batterie.Details;

        var p2 = document.createElement("p");

        var Strong2 = document.createElement("strong");
            Strong2.innerHTML = batterie.Price+"€";

        p2.appendChild(Strong2);

        /*
        On veut mtnt un boutton moins, un affichage de la qté et un boutton plus
        */
        {var quantityInput = document.createElement("input");
            quantityInput.setAttribute("type", "number");
            quantityInput.setAttribute("id", batterie.id+"quantity");
            quantityInput.setAttribute("placeholder", "1");
            quantityInput.setAttribute("max", batterie.Stock);
            quantityInput.setAttribute("style", "width: 50px; margin-left: 10px; margin-right: 10px; display: block; text-align: center; border: none; color: black; background-color: #f1f1f1;");
            quantityInput.setAttribute("onchange", "if(this.value > "+batterie.Stock+"){this.value = "+batterie.Stock+";}else if(this.value < 1){this.value = 1;}else{console.log(this.value);}");
            quantityInput.setAttribute("onkeyup", "if(this.value > "+batterie.Stock+"){this.value = "+batterie.Stock+";}else if(this.value < 1){this.value = 1;}else{this.value = this.value+1}");
            quantityInput.setAttribute("onkeydown", "if(this.value > "+batterie.Stock+"){this.value = "+batterie.Stock+";}else if(this.value < 1){this.value = 1;}else{this.value = this.value+1}");

        }

        {var buttonMoins = document.createElement("button");
            buttonMoins.setAttribute("type", "button");
            buttonMoins.setAttribute("class", "btn btn-primary");
            buttonMoins.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px; display: block;");
            buttonMoins.innerHTML = "-";
            buttonMoins.setAttribute("onclick", "if(document.getElementById('"+batterie.id+"quantity').value > 1){document.getElementById('"+batterie.id+"quantity').value = document.getElementById('"+batterie.id+"quantity').value - 1;}else{document.getElementById('"+batterie.id+"quantity').value = 1;}console.log(document.getElementById('"+batterie.id+"quantity').value);");
        }

        {var buttonPlus = document.createElement("button");
            buttonPlus.setAttribute("type", "button");
            buttonPlus.setAttribute("class", "btn btn-primary");
            buttonPlus.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px; display: block;");
            buttonPlus.innerHTML = "+";
            buttonPlus.setAttribute("onclick", "if(document.getElementById('"+batterie.id+"quantity').value < 5 ){document.getElementById('"+batterie.id+"quantity').value++;}else{document.getElementById('"+batterie.id+"quantity').value = 5;}console.log(document.getElementById('"+batterie.id+"quantity').value);" );
        }

        {var buttonStock = document.createElement("button");
            buttonStock.setAttribute("id" , batterie.id+"stock");
            buttonStock.setAttribute("type", "button");
            buttonStock.setAttribute("class", "btn btn-primary");
            buttonStock.setAttribute("style", "margin-top: 10px; margin-bottom: 30px;");
            buttonStock.innerHTML = "Voir le stock";
            //on hover on the button, show stock
            buttonStock.setAttribute("onmouseover", "this.innerHTML = 'Stock : '+(document.getElementById('" +  batterie.id + "quantity').value - " + batterie.Stock + ")*(-1);;");
            buttonStock.setAttribute("onmouseout", "this.innerHTML = 'Voir le stock';");
            if(getCookie('isAdmin') != 'true'){
                buttonStock.setAttribute("style", "display: none");
            }
        }

        {var ligneDeBouttons = document.createElement("div");
            ligneDeBouttons.setAttribute("style", "display: flex; flex-direction: row; justify-content: center; align-items: center; ");
            ligneDeBouttons.appendChild(buttonMoins);
            ligneDeBouttons.appendChild(quantityInput);
            ligneDeBouttons.appendChild(buttonPlus);
        }            


        {var button = document.createElement("button");
            button.setAttribute("type", "button");
            button.setAttribute("class", "btn btn-primary");
            button.setAttribute("style", "margin-top: 10px; margin-bottom: 30px; margin-right: 10px;");
            button.innerHTML = "Ajouter au panier";
            button.setAttribute("onclick", "if((document.getElementById('"+batterie.id+"quantity').value) == ''){(document.getElementById('"+batterie.id+"quantity').value) = 1;}console.log(document.getElementById('"+batterie.id+"quantity').value + ' en qty de ' + idToSendForCart);addBatterieToCart(idToSendForCart , document.getElementById('"+batterie.id+"quantity').value)");//mtnt on veut envoyer ces deux donnees dans une fonction qui va récupérer la batterie et la qty en parametres, et l ajouter au tableau d items du panier
        }

        {
        p2.appendChild(Strong2);
        h4.appendChild(Strong1);
        div3.appendChild(h4);
        div3.appendChild(p1);
        div3.appendChild(p2);
        div3.appendChild(button);
        div3.appendChild(buttonStock);
        div3.appendChild(ligneDeBouttons);
        div1.appendChild(div2);
        div1.appendChild(div3);
        container.appendChild(div1);
        //console.log(div1.id);
        }
    }
    cart = cartCleaner(cart);
}



////////////////////////////////////--GÉNÉRATION HTML DU PANIER--////////////////////////////////////
//fonction qui crée le front du panier ==> A REPRENDRE
function createCartFront(cart) {
    removeChildren();
    /*
        SI USER EST CONNECTE, ON AFFICHE LE PANIER DU USER CONNECTE (on récupère le panier du user connecté) GRACE A AJAX ET PHP
            A CHAQUE AJOUT AU PANIER ON UPDATE LE PANIER DU USER CONNECTE
        SINON, ON AFFICHE LE PANIER DU USER NON CONNECTE
    */
    cart = cartCleaner(cart);
    var cartTotal = updateCartTotal(cart);
    //faire une fonction qui vide l'affichage du panier ==>
    var cartContainer = document.getElementById("cartContainer");
    //pour chaque objet du panier, on crée un div avec les infos de l'objet si le panier est non vide
    if(cart.length > 0) {
        for(var i=0; i<cart.length; i++) {
            //on veut afficher en une ligne l'image de l'élément du panier, son nom, la qty sélectionnée et son prix
            var divObject = document.createElement("div");
                divObject.setAttribute("class", "row");
                divObject.setAttribute("id", cart[i].id+'DIV');
                divObject.setAttribute("style", "margin-bottom: 50px;");
                divObject.setAttribute("style", "border: none; color: black;");
                divObject.setAttribute("onmouseover", "this.style.transform='scale(1.05)';");
                divObject.setAttribute("onmouseout", "this.style.transform='scale(1)';");

            var div2Object = document.createElement("div");
                div2Object.setAttribute("class", "col-sm-4"); 

            var imageObject = document.createElement("img");
                imageObject.setAttribute("src", cart[i].image);
                imageObject.setAttribute("class", "img-responsive");
                imageObject.setAttribute("style", "width:100%; object-fit: contain; max-height: 150px;");
            div2Object.appendChild(imageObject);

            var div3Object = document.createElement("div");
                div3Object.setAttribute("class", "col-sm-8");
                div3Object.setAttribute("id", cart[i].id+"div3");


            var h4 = document.createElement("h4");

            var Strong1Object = document.createElement("strong");
                Strong1Object.innerHTML = "Produit: "+cart[i].name+" ";

            var Strong2Object = document.createElement("strong");
                Strong2Object.innerHTML = "Prix Unitaire: "+cart[i].price+"€ ";

            var Strong3Object = document.createElement("strong");
                Strong3Object.innerHTML = "Quantité sélectionnée: x"+cart[i].qty;

            var p2Object = document.createElement("p");
                p2Object.appendChild(Strong2Object);
        
            var removalButton = document.createElement("button");
                removalButton.setAttribute("class", "btn btn-danger");
                removalButton.setAttribute("id", cart[i].id+"removalButton");
                removalButton.setAttribute("onclick", "removeFromCartTab('"+cart[i].id+"');updateCartTotal(cart);createCartFront(cart);");
                removalButton.innerHTML = "Supprimer du panier";

            {
                p2Object.appendChild(Strong2Object);
                div3Object.appendChild(Strong1Object);
                div3Object.appendChild(h4);
                div3Object.appendChild(p2Object);
                div3Object.appendChild(Strong3Object);
                div3Object.appendChild(h4);
                div3Object.appendChild(document.createElement("br"));
                div3Object.appendChild(document.createElement("br"));
                div3Object.appendChild(document.createElement("br"));
                div3Object.appendChild(removalButton);
                divObject.appendChild(div2Object);
                divObject.appendChild(div3Object);
                divObject.appendChild(h4);
                cartContainer.appendChild(divObject);
                cartContainer.appendChild(document.createElement("hr"));
                //console.log(div1.id);
            }
        }
            //affichage du total
            var total = document.createElement("Strong");
            total.setAttribute("id", "total");
            total.innerHTML = "Total: "+cartTotal+"€";
            cartContainer.appendChild(document.createElement("br"));
            cartContainer.appendChild(total);
        //bouton pour vider le panier
        var emptyCartButton = document.createElement("button");
            emptyCartButton.setAttribute("class", "btn btn-danger");
            emptyCartButton.setAttribute("style", "margin-right: 10px;");
            emptyCartButton.setAttribute("id", "emptyCartButton");
            emptyCartButton.setAttribute("onclick", "emptyCart()");
            emptyCartButton.innerHTML = "Vider le panier";
        cartContainer.appendChild(emptyCartButton);
        //bouton pour passer à la page de paiement
        var paymentButton = document.createElement("button");
            paymentButton.setAttribute("class", "btn btn-success");
            paymentButton.setAttribute("id", "paymentButton");
            paymentButton.innerHTML = "Confirmer le panier";
            paymentButton.addEventListener("click", function() {
                window.open("./html/fakePaymentTerminal.html", "Fake Terminal", "height=400,width=800");
            });

        cartContainer.appendChild(paymentButton);
    } else {
        var emptyCartMessage = document.createElement("Strong");
            emptyCartMessage.innerHTML = "Votre panier est vide";
        cartContainer.appendChild(emptyCartMessage);
    }
}





