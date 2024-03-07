#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct carte {
    char couleur[10];
    char nom[10];
    int valeur;
    int tiree;      // à implémenter pour ne pas tirer deux fois la même carte
} Carte;



typedef struct paquet {
    Carte cartes[52];
    int taille;
} Paquet;


void afficher_carte(Carte carte) {
    printf("%s de %s (\e[33m%d\e[0m)\n", carte.nom, carte.couleur, carte.valeur);
}


void afficher_paquet(Paquet paquet) {
    printf("\nAffichage du paquet : \n\n");

    for (int i = 0; i < paquet.taille; i++) {
        afficher_carte(paquet.cartes[i]);
    }
}


void reinitialiser_paquet(Paquet paquet) {

    printf("\nReinitialisation du paquet de cartes tirees\n");
    for (int i = 0; i < paquet.taille - 1; i++) {
            paquet.cartes[i].tiree = 0;
        }
}


int carte_hasard(Paquet paquet)
{
    // Cette fonction tire une carte du paquet au hasard, et la marque comme telle
    // Elle appelle l'affichage et renvoie la valeur de la carte.

    int hasard;
    do
    {
        hasard = rand()%52;
    }
    while (paquet.cartes[hasard].tiree != 0);
    paquet.cartes[hasard].tiree = 1;
    afficher_carte(paquet.cartes[hasard]);
    return paquet.cartes[hasard].valeur;
}


void menu_joueur()
{
       // Affichage complet des possibilités du joueur.

       srand(time(NULL));

       printf("\n");
       printf("\e[33m");
       printf("*********************\n");
       printf("* A vous de jouer ! *\n");
       printf("*********************\n");
       printf("\e[0m");
       printf("\n");
       printf("1 - Je tire une carte\n");
       printf("2 - Je m'arrete pour cette main\n");

       printf("0 - Quitter\n");
       printf("\n");
}

int banque_tirer_des_cartes(Paquet paquet)
{
    // Cette fonction tire deux cartes, puis en tire jusqu'à ce que la valeur dépasse 17.

    printf("\n");
    printf("\e[34m");
    printf("*******************************\n");
    printf("* La banque tire des cartes ! *\n");
    printf("*******************************\n");
    printf("\e[0m");
    printf("\n");

    int valeur_banque = 0;

    valeur_banque+=carte_hasard(paquet);
    valeur_banque+=carte_hasard(paquet);

    while (valeur_banque <= 16)
    {
        valeur_banque += carte_hasard(paquet);
    }
    return valeur_banque;
}


void partie_initialiser(Paquet paquet, int &val_banque , int &val_joueur )
{
    // Cette fonction initialise un jeu de carte

        printf("Initialisation du jeu\n\n");

        reinitialiser_paquet(paquet);
        val_joueur = 0;
        val_banque = banque_tirer_des_cartes(paquet);


        // S'il s'avère que la banque a perdu d'entrée de jeu,
        // On notifie sa victoire au jeu et on rappelle à nouveau la fonction.

        if (val_banque > 21)
        {
           printf("\n");

           printf("\e[32m");
           printf(" ***********************\n");
           printf(" * LA BANQUE A PERDU ! *\n");
           printf(" ***********************\n");
           printf("\e[0m");

           printf("\n");

           partie_initialiser(paquet, val_banque, val_joueur);   // et on relance une autre partie.
        }
}




int main()
{
       printf("\n");
       printf("\e[35m");
       printf("******************************\n");
       printf("* Black Jack Benjamin MOREAU *\n");
       printf("******************************\n");
       printf("\e[0m");
       printf("\n");


       // Créer un paquet de cartes

        char couleurs[][10] = {"Pique", "Coeur", "Carreau", "Trefle"};
        char noms[][10] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi"};
        int valeurs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

        Paquet paquet;
        paquet.taille = 52;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                strcpy(paquet.cartes[i * 13 + j].couleur, couleurs[i]);
                strcpy(paquet.cartes[i * 13 + j].nom, noms[j]);
                paquet.cartes[i * 13 + j].valeur = valeurs[j];
                paquet.cartes[i* 13 +j ].tiree = 0;
            }
        }

        // Afficher le paquet
        afficher_paquet(paquet);

      int valeur_croupier=0;
      int valeur_joueur=0;
      partie_initialiser(paquet, valeur_croupier, valeur_joueur);


  printf("Somme de la valeur des cartes du croupier : %d\n",valeur_croupier);

  menu_joueur();
 char choix;


  do
  {
    {


        printf("\n\nReste %d points pour atteindre 21 \n\n", 21-valeur_croupier-valeur_joueur);
    }

    printf("Votre choix ? (1 : Tirer / 2 : Arreter / 0 : Quitter) : ");
    choix = getch();
    printf("\n");
      switch (choix) {
         case '1':
          //int valeur = carte_hasard(paquet);
          printf("On tire la carte : ");
          valeur_joueur += carte_hasard(paquet);
          printf("Somme des cartes deja tirees : %d\n",valeur_joueur);

          if (valeur_croupier + valeur_joueur == 21)
          {
               printf("\e[32m");

               printf("  *************\n");
               printf("  * GAGNE !!! *\n");
               printf("  *************\n");
                printf("\e[0m");

               partie_initialiser(paquet, valeur_croupier, valeur_joueur);
          }
          else
          {
              if (valeur_croupier + valeur_joueur > 21)
              {
               printf("\e[31m");
               printf("  *************\n");
               printf("  * PERDU !!! *\n");
               printf("  *************\n");
                printf("\e[0m");
               partie_initialiser(paquet, valeur_croupier, valeur_joueur);
              }
          }

          break;
        case '2':
               printf("\e[36m");
               printf("  *************\n");
               printf("  * ARRET !!! *\n");
               printf("  *************\n");
               printf("\e[0m");

               partie_initialiser(paquet, valeur_croupier, valeur_joueur);
            break;

        case '0':
          printf("Merci d'avoir joue au black jack !\n");
          break;
        default:
          printf("Le choix %c est incorrect.\n", choix);
          menu_joueur();

      }
  } while (choix != '0');

  return 0;
}


