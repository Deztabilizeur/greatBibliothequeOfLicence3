#ifndef __GBOL3__
#define __GBOL3__


typedef enum {Faux , Vrai} Booleen;


typedef struct celluleDeListeChaine
{
  int Valeur;
  struct celluleDeListeChaine * Suivant;
}*ListeChaine;


typedef struct
{
  int nbSom;
  int **mat;
  int *value;
  int numSom;
}MatADJ;

typedef struct
{
  MatADJ *first;
}file;

typedef struct
{
  int nb_sommet;
  int ** mat;
  valeur;
}matAdj;
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


#endif
