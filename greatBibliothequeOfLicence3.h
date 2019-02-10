#ifndef __GBOL3__
#define __GBOL3__

//------------------- ALGO------------------------
typedef enum {Faux , Vrai} Booleen;

//Liste chaine
typedef struct celluleDeListeChaine
{
  int Valeur;
  struct celluleDeListeChaine * Suivant;
}*ListeChaine;

typedef struct cellule
{
  struct cellule suivant;
  int valeur;
}*File;
/*
typedeft struct cellule
{
  int Adj
  Telement valeur;
  struct cellule *suivant;
}*ListeChaine;
typedef struct
{
int nbdom;
ListeChaine* tab;
}ListeChaineAdjascence;

{}
parcoursProfondeur()
{


}
*/
ListeChaine Creer_ListeChaine(void) ;
ListeChaine Obtenir_i (ListeChaine L, int i);
ListeChaine Creer_Cellule (void);
ListeChaine Inserer_En_Tete(ListeChaine L,  int x);
Booleen ListeChaine_Vide(ListeChaine L);
ListeChaine Inserer_En_Queue(ListeChaine L,  int x);
//ListeChaine Inserer_ListeChaine_Triee(ListeChaine L,  int x);
Booleen Appartient(ListeChaine L,  int x);
ListeChaine Supprimer(ListeChaine L,  int x);
int Long(ListeChaine L);
ListeChaine Inverser_ListeChaine(ListeChaine L);
ListeChaine Inverser1_ListeChaine(ListeChaine L, ListeChaine Dernier);
ListeChaine Inverser(ListeChaine L);
void Afficher(ListeChaine L);


//--------------------- GRAPHES --------------------------------


typedef struct//Matrice d'Adjacence
{
  int nbSom;
  int **mat;
  int *value;
  int numSom;
}MatADJ;

typedef struct/// ????
{
  MatADJ *first;
}file;

typedef struct//Autre Matrice d'Adjacence ?
{
  int nb_sommet;
  int ** mat;
  valeur;
}matAdj;

typedef struct //Cours de ludo
{
  int nbSom;
  int ** mat;
  Telem **val; // dans le cas d’un graphe valué
}MatAdjacence;

typedef struct
{//Matrice d'incidence pour graph non orienté
  int nbSom;
  int nbArc;
  int ** mat;
} MatIncSomArc;

typedef struct
{//Matrice d'incidence pour graph orienté
  int nbSom;
  int nbArete;
  int ** mat;
  Telem *val; // dans le cas d’un graphe valué
} MatIncSomArete;

typedef struct
{
  int nbSom;
  int nbArcs; // arêtes
  int * FS;
  int * APS; //cas valué
  Telem *val; // cas valué
}FileSuccesseurs;

typedef struct
{//Liste d'Adjacence
  int nbSom;
  int *tab;
}ListeAdjacente;

typedef struct cellule
{//Liste pour les listes d'Adjacence
  int suAdj;
  Telem val;
  struct cellule *suiv;
}*Liste;

typedef struct celluleSucc
{//Liste de Successeurs
  int somSucc;
  struct celluleSucc *suiv;
}*ListeDeSuccesseur;

typedef struct
{//Liste de Successeurs et prédécesseur. +lourd mais se parcourp dans les 2 sens
int nbSom;
int *tab[2];
}*ListeDeSuccesseurPredecesseur;

typedef struct celluleListePrincipal
{//Cellule Liste Principal
  ListePrincipale SomAdj; // SomSucc;
  Telem val; //cas valué;
  struct cellule *suiv;
}*ListePrincipale;

typedef struct principal
{//Liste Principal
  int som;
  ListeP lsucc;
  struct principal *suiv;
}*ListeP;

typedef struct
{
  int Nbsom;
  ListeMatCreuse * tabSucc;
  ListeMatCreuse * tabPred;
}MatriceCreuse;

typedef struct celluleMatCreuse
{
  int somSucc;
  int somPred;
  Telem val; // dans le cas Valué
  struct celluleMatCreuse * succeSuiv;
  struct celluleMatCreuse * predSuiv;
}*ListeMatCreuse;

#endif
