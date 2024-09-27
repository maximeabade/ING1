# Loi Géométrique X~G(lambda)
geometriqueInversion <- function(n, lambda){
  i = 0
  geom = array()
  while (i < n) {
    u = runif(1)
    # Fonction inverse de la fonction de répartition d'une loi géométrique 
    geom[i] = floor(log(1-u)/log(1-lambda))+1
    i = i+1
  }
  hist(geom, breaks=50, probability = TRUE, main="Loi géométrique par inversion", xlab="x", ylab="Valeurs prises par x", freq=F)
}

n = 5000
lambda = 0.2
geometriqueInversion(n, lambda)