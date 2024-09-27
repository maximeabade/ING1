# kmeans
Dataset=read.table("Test_Clusters_Distincts.txt", header=T,sep=' ')

# a 2-dimensional example
A = matrix(rnorm(100,sd=0.3), ncol=2) # rnorm génère une matrice de réalisations d’une loi normale
B = matrix(rnorm(100,mean=1,sd=0.3), ncol=2)
x = rbind(A,B) # rbind concatène des matrices
plot(x)
x=scale(x) #centre et réduit
cl= kmeans(x,center=2,nstart=5) #clustering à 2 classes
print(cl) # affiche les résultats
plot(x, col = cl$cluster, main="Algorithme de kmeans sur le jeu de données 'Test_Clusters_Distincts.txt'", xlab="x", ylab="y") # affiche les points avec une couleur différente par classe
# indexée par le numéro de la classe
points(cl$centers, col = 1:2, pch = 8, cex = 2) # ajoute les centres des classes

# CAH
Dataset=read.table("Test_Clusters_Distincts.txt", header=T,sep=' ')

# a 2-dimensional example
A = matrix(rnorm(100,sd=0.3), ncol=2) # rnorm génère une matrice de
B = matrix(rnorm(100,mean=100,sd=10), ncol=2) # réalisations d’une loi normale
x = rbind(A,B) # rbind concatène des matrices
plot(x)
x=scale(x) #centre et réduit
distance=dist(x,"euclidean") #crée une structure de distance entre les individus
h=hclust(distance, "ward.D2") # crée l’arbre
plot(h$height) # affiche l’évolution du critère de dissimilarité entre classes
plot(h, main="Algorithme de CAH sur le jeu de données 'Test_Clusters_Distincts.txt'") # affiche le dendrogramme
rect.hclust(h,k=2) # ajoute les classes
c=cutree(h,k=2) # récupère les classes
plot(x, col = c) # affiche les points avec une couleur différente par classe indexée par le numéro de la classe