## f(x) correspond a une loi normale de paramètres N(μ,ø²)
x1 = c()
##esperance
esp = 1 / 2
##variance
sigmacarre = 1 / 12
n = 20000
tries = 100
#calcul loi uniforme
fsimu1 = function(echantillon) {
for (i in 1:echantillon) {
w = runif(1)
x1[i] = qunif(w)
}
x1
}
# on a effectué la simulation de la v.a.r. de densité f(x) sur n
SumZn = c()
for (j in 1:n) {
Sn = fsimu1(tries)
tmpZn = (sqrt(tries) / sqrt(sigmacarre)) * ((sum(Sn) / tries) - esp)
SumZn[j] = tmpZn
}
hist(SumZn,ylab = "Frequence", xlab = "Zn",main = "Zn sur 20000 test de
taille N = 100 pour la loi Uniforme", breaks = 30,col =
"red",probability = TRUE)
loiNormale <- seq(-5, 5, by = 0.01) # tracé de la loi normale
y <- dnorm(loiNormale)
lines(loiNormale, y, col = "blue")
