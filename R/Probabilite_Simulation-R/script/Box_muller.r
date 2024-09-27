n=5000
Xn= c() # Suite de VAR Xn
Yn= c() #Suite de VAR Yn
for (i in 1:n) {
U=runif(1) #Variable aléatoire U
R= sqrt(-2*log(U)) #valeur de R
V=runif(1) #Variable aléatoire V
teta=2*pi*V
X= R*cos(teta)
Y=R*sin(teta)
Xn[i]=X
Yn[i]=Y
}
#loi normale
normale=rnorm(n)
sortie=c(Xn, Yn, normale)
traceLoiNormale <- seq(-4,4,by=0.05)
y<-dnorm(traceLoiNormale, mean=0, sd=1)
#representation histogramme
hist(sortie, main="histogramme de la densité", ylab= "Densité", xlab=
"Valeurs", probability = TRUE)
#representation fonction gaussienne
lines(traceLoiNormale, y, col="red")
