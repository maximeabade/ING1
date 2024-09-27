library(methods)

geometrique <- setRefClass("Loi geometrique", fields = list(p = "numeric"), methods = list(
  esp = function() #Donne l'espérance
  {
    return(1/p)
  },
  var = function() #Donne la variance
  {
    return((1-p)/(p*p))
    
  },
  simulation = function(r) #on simule une loi géométrique avec une loi de bernoulli
  {
    j=1
    c=1
    result <- integer(r)
    bernoulli_approach <- bernoulli(p=p)
    bernoulli_list = bernoulli_approach$simulation(r)
    for(i in 0:r)
    {
      c=0
      while(bernoulli_list[j]==0&&j<r)#On compte le nombre d'échec avant un succès
      {
        c=c+1
        j=j+1
      }
      result[i] = c
      c=1
      j=1
      bernoulli_list = bernoulli_approach$simulation(r)
    }
    return(result)
  },
  simu_proba = function(r)
  {
    print(table(simulation(r))/r)
  }
))
geom = geometrique(p=0.3)
geom$simulation(100)