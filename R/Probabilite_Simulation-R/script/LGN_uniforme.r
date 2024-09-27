n = 1000 #Nombre d'essaie 
esp = 1/2 #Espérance des Xk
Xk= runif(n,min=0,max=1)
Sn= cumsum(Xk) #Calcule de Sn
N = seq(1,n, by=1)
TgSn = Sn/N

plot(N,TgSn, col="red", main = "Suite des moyennes empiriques par rapport à n pour une loi uniforme")
abline(h=esp, col = "blue") #Tracer l'espérance sur le graphe 