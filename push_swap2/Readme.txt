On va utiliser une liste chainée comprise uniquement de ses elements.
On va utiliser une struct qui a -> val(int), -> val2(qui contient une copie de val, cette valeur sera modifiée par les shifts, et on doit garder la valeur d'origine).

On a besoin de faire des operations sur les 2 listes (A et B): 
- Ajouter un element a la fin de la liste
- Insere un element dans la liste
- Supprimer un element de la fin de la liste (on return cet element)
- Supprimer un element debut de la liste (on return cet element)

On va coder les instructions à utiliser pour trier les nombres (sa, sb, ra, rb, rra ...)
Chaque instruction va afficher son nom quand elle est appelée

ALGORITHM
- On va trier les nombres selon les bits (il faut representer chaque nombre en binaire)
- Les bits de chaque nombre sont pris de la droite vers la gauche
- Pour un bit donné, on doit verifier tous les elements de A et envoyer vers B les nombres qui ont ce bit egale 0.
- Pour faire ca, et pour passer sur tous les elements de A on va utiliser l'argorithm suivant
int i = 0;
while (i < size de A)
{
	if (bit = 0)
		push to B (pb)
	else
		rotate A (ra)
	i++;
}
cela va mettre dans B les nombres les plus petits, selon la position du bit en cours
puis on remet tous les elements de B dans A, et on passe au bit suivant ( vers la gauche )
- Pour verifier le bit d'un nombre, on va faire shift right (>>), cela MODIFIE la valeur du nombre. Donc avant de faire cette operation, on copie le nombre de val vers val2, et on fait shift right sur val2

- Pour les listes de nombres de taille 1, 2, 3, 4 et 5, on va coder un algorithme speciale (optimisé) pour chacun.

- Avant de faire toutes ces etapes, il faut valider les nombres recus en arguments: pas de doublons, int min et int max, pas autres que chiffres.

INSTRUCTIONS: 
(Dans une pile, le premier element est en bas, et le dernier est en haut(donc c'est le head de la liste)) 
Si on a une pile vide, et on ajoute 3 elements a, b et c, la pile deviendra
c - head
b
a 

-SA: Intervertit les 2 premiers éléments au sommet de la pile a.  
b
c
a

PA: Prend le premier élément au sommet de b et le met sur a.
 c		3
 b		2
 a		1
[A]		[B]	

devient:
 3
 c		
 b		2
 a		1
[A]		[B]	

RA:  Décale d’une position vers le haut tous les élements de la pile a
c
b
a
devient:
b
a
c
donc le head devient en bas

RRA:  Décale d’une position vers le bas tous les élements de la pile a
c
b
a
devient
a
c
b
donc le dernier element devient le head





