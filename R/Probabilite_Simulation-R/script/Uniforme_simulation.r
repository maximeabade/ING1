library(methods)

uniforme_11 <- setRefClass("Loi uniforme sur [-1,1]", methods = list(
  esp = function() #Donne l'espérance
  {
    return((-1+1)/2)
  },
  var = function() #Donne la variance
  {
    return(1/12)
    
  },
  graph = function(n) #on affiche sur un même graph la densité et l'histogramme de la loi
  {
    x = runif(n,-1,1)
    hist(x, main="Loi uniforme sur [-1;1]", breaks=20, xlab = "X", ylab = "valeurs", probability = TRUE, xlim = c(-1,1), ylim = c(0,1))
    abline(h = 1/2, col="blue")
  }
))
uni = uniforme_11()
uni$graph(100)
uni$graph(1000)
uni$graph(10000)
uni$graph(100000)