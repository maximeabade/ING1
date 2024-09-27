n = 1000 #Nombre d'essaie 
lambda = 6 #Parametre pour la loi exponentielle
esp = 1/lambda #Espérance des Xk
Xk = rexp(n,lambda)
Sn = cumsum(Xk) #Calcule de Sn
N = seq(1,n, by=1)
TgSn=Sn/N

plot(N,TgSn, col="green", main = "Suite des moyennes empiriques par rapport à n pour une loi exponentielle")
abline(h=esp, col="blue") #Tracer l'espérance sur le graphe