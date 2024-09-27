x1 = c()
n = 20000
##Calcul de la loi
x = runif(n, min = 0, max = 1)
## esperance de la série
esp = mean(x)
## variance de la série
sigmacarre = mean(x^2) - esp^2
##Def de Sn
Sn = cumsum(x)
N = seq(1, n, by = 1)
##Def de Zn
Zn = (sqrt(N) / sqrt(sigmacarre)) * ((Sn / N) - esp)
plot(Zn,main = "Convergence de Zn avec une loi Uniforme")