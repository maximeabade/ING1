x1 = c()
n = 20000
##Calcul de la loi
x = rexp(n)
##Esperance de la série
esp = mean(x)
##Variance
sigmacarre = (1 / (1/esp)^2)
Sn = cumsum(x)
N = seq(1, n, by = 1)
Zn = (sqrt(N) / sqrt(sigmacarre)) * ((Sn / N) - esp)
plot(Zn,main = "Convergence de Zn avec une loi Exponentielle")
