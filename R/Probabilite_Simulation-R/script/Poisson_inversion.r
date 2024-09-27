poissonInversion <- function(n, lambda){
  i = 0
  poiss = array()
  while (i < n) {
    # Fonction inverse de la fonction de répartition de la loi de Poisson
    p = 1
    x = 0
    while(p>=exp(-lambda)){
      u = runif(1)
      p = p*u
      x = x+1
    }
    poiss[i] = x
    i = i+1
  }
  poiss
}

n = 100
lambda = 0.5
poissonInversion(n, lambda)