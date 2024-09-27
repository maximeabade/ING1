library(methods)

bernoulli <- setRefClass("Loi de Bernoulli", fields = list(p = "numeric"), methods = list(
  esp = function() #Donne l'esperance
  {
    return(p)
  },
  var = function() #Donne la variance
  {
    return(p*(1-p))
    
  },
  simulation = function(n) #Génère une liste de taille n de 0 et 1 en fonction de la probabilité p donné
  {
    x=sample(c(0,1),n,replace=T,prob=c(1-p,p))
    return(x)
  },
  simu_proba = function(n) #Retrouve une approximation de P a partir d'un vecteur généré avec la fonction simulation
  {
    print(table(simulation(n))/n)
  }
))
ber = bernoulli(p=0.5)
ber$simulation(100)