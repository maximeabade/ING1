library(methods)

binomiale <- setRefClass("Loi binomiale", fields = list(n="numeric", p = "numeric"), methods = list(
  esp = function() #Donne l'esperance
  {
    return(n*p)
  },
  var = function() #Donne la variance
  {
    return(n*p*(1-p))
    
  },
  simulation = function(r) #Génère un vecteur de r entier entre 0 et n en fonction des probabilités
  {
    probabilites = c(0:n) #on fait une liste pour les probabilités de chaque valeur
    for(k in 0:n)
    {
      probabilites[k+1] = (factorial(n)/(factorial(k)*factorial(n-k)))*(p^k*((1-p)^(n-k))) #on calcule ces probabilités
    }
    x=sample(seq(from =0, to=n, by=1),r,replace=T,prob=probabilites)#on crée notre vecteur 
    return(x)
  }
))

binom = binomiale(n=10,p=0.45)
binom$simulation(100)