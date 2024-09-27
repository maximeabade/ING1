exponentielleInversion <- function(n, lambda){
  i = 0
  expo = array()
  while (i < n) {
    u = runif(1)
    # Fonction inverse de la fonction de répartition de la loi exponantielle
    expo[i] = -log(1-u)/lambda 
    i = i+1
  }
  hist(expo, breaks=50, probability = TRUE, main="Loi exponentielle par inversion", xlab="x", ylab="Valeurs prises par x", freq=F)
}

n = 5000
lambda = 0.5
exponentielleInversion(n, lambda)