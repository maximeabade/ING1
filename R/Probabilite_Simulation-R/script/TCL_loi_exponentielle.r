x2 = c()
lambda = 0.5
##Variance
sigmacarre = 1 / (lambda ^ 2)
##Esperance
esp = 1 / lambda
tries = 100
#calcul loi expo
fsimu2 = function(echantillon) {
for (i in 1:echantillon) {
w = runif(1)
x2[i] = qexp(w,lambda)
}
x2
}
SumZn = c()
for (j in 1:n) {
Sn = fsimu2(tries)
tmpZn = (sqrt(tries) / sqrt(sigmacarre)) * ((sum(Sn) / tries) - esp)
SumZn[j] = tmpZn
}
hist(SumZn,ylab = "Frequence", xlab = "Zn",main = "Simulation Zn sur
20000 tests de taille N = 100 pour la loi Exponentielle", breaks =
30,col = "red",probability = TRUE)
# tracé de la loi normale
loiNormale <- seq(-5, 5, by = 0.01)
y <- dnorm(loiNormale)
lines(loiNormale, y, col = "blue")
