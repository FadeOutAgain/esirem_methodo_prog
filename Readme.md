Benjamin MOREAU 
Master M1 Cybersécurité - ESIREM

Black Jack


Le programme

* Initialise un paquet de cartes de façon séquentielle
* N'a pas besoin de mélanger pas le paquet. On tirera une des cartes 0..52 au hasard

Pour jouer

* La touche 1 permet de tirer une carte
* La touche 2 permet de mettre un terme à la partie
* La touche 0 permet de quitter le progamme
* Une autre touche déclenche un message d'erreur.

* Si la banque perd dès l'initialisation de la partie, une autre partie est initialisée


Nota : 

* Les cartes "gèrent" le fait qu'elles déjà été tirées ou non (attribut tiree = 0 ou 1)
* La fonction tirer une carte au hasard tient compte et refait une tentative
* Le code tel qu'il est tournerait en boucle si les 52 cartes avaient déjà été tirées.


Gestion de la valeur des AS :

Celle-ci n'est pas implémentée dans le temps imparti.
On pourrait imaginer deux fonctions de tirages de cartes différentes plutôt qu'une fonction carte_hasard(paquet) commune au joueur et à la banque.

Pour la banque :

Lors du tirage des cartes, on passe en paramètre la valeur déjà atteinte
SI la valeur est celle de l'AS (1), alors, on choisit la meilleure valeur de retour

Pour le joueur :

La fonction carte_hasard introduirait un choix pour demander au joueur si il préfère 1 ou 11 en valeur.




