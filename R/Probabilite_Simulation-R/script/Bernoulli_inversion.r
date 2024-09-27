# Loi de Bernoulli X~B(p)
bernoulliInversion <- function(p){
  u = runif(1) # loi uniforme entre 0 et 1
  # fonction inverse de la fonction de répartition de Bernoulli
  if(u<1-p){
    binom = 0
  } else {
    binom = 1
  }
  binom
}

p = 0.5
bernoulliInversion(p)