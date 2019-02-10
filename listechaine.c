#include <string.h>
#include <stdio.h>
#include "greatBibliothequeOfLicence3.h"


ListeChaine Creer_ListeChaine(void)
{
  return(NULL);
}

ListeChaine Creer_Cellule (void)
{
  ListeChaine L1=(ListeChaine)malloc(sizeof(*L1));
  return(L1);
}

ListeChaine Obtenir_i (ListeChaine L, int i)
{
  if(L == NULL)
  {
    printf("La ListeChaine est vide\n");
  }

  if (i>0)
  {
  L = Obtenir_i(L->Suivant,i-1);
  }
  return L;
}

Booleen ListeChaine_Vide(ListeChaine L)
{
  if (L==NULL) return(Vrai); else return (Faux);
}

ListeChaine Inserer_En_Tete(ListeChaine L,  int x)
{
  ListeChaine L1;
  L1=(ListeChaine)malloc(sizeof(*L1));
  L1->Valeur=x;
  L1->Suivant=L;
  return(L1);
}


ListeChaine Inserer_En_Queue(ListeChaine L,  int x)
{
  if (L==NULL)
    {
      L=Creer_Cellule();
      L->Valeur=x;
      L->Suivant=NULL;
    }
  else
    {
      L->Suivant=Inserer_En_Queue(L->Suivant,x);
    }
  return(L);
}
/*
ListeChaine Inserer_ListeChaine_Triee(ListeChaine L,  int x)
{
  if (L==NULL)
  {
    L=Inserer_En_Queue(L,x);
  }
  else if (L->Valeur < x)
  {
  L->Suivant=Inserer_ListeChaine_Triee(L->Suivant,x);
  }
  else
  {
    L=Ajouter_Tete(L,x);
  }
  return(L);
}*/

Booleen Appartient(ListeChaine L,  int x)
{
  if (ListeChaine_Vide(L)) return(Faux);
  else if (L->Valeur ==x) return (Vrai);
  else return(Appartient(L->Suivant , x));
}

ListeChaine Supprimer(ListeChaine L,  int x)
{
  if (L!=NULL)
  {
    if (L->Valeur==x)
    {
      ListeChaine L1=L;
      L=L->Suivant ;
      free(L1) ;
    }
    else L->Suivant=Supprimer(L->Suivant,x);
  }
  return L;
}
int Long(ListeChaine L)
{
  if (ListeChaine_Vide(L)) return(0);
  else return(Long(L->Suivant)+1);
}

ListeChaine Inverser_ListeChaine(ListeChaine L)
{
  ListeChaine L1;
  if (L->Suivant == NULL) L1 = L;
  else
  {
    L1 = Inverser_ListeChaine(L->Suivant);
    L->Suivant->Suivant = L;
    L->Suivant = NULL;
  }
return L1;
}
ListeChaine Inverser1_ListeChaine(ListeChaine L, ListeChaine Dernier)
{
  ListeChaine L1;
  if (L!= NULL)
  {
    L1 = L->Suivant;
    L->Suivant=Dernier;
    Dernier=L;L=L1;
    return(Inverser1_ListeChaine(L, Dernier));
  }
}
ListeChaine Inverser(ListeChaine L)
{
  ListeChaine Aux, Dernier;
  Dernier=NULL;
  while (!ListeChaine_Vide(L))
  {
    Aux = L->Suivant;
    L->Suivant=Dernier;
    Dernier=L;
    L=Aux;
  }
  return(Dernier);
}
void Afficher(ListeChaine L)
  {
  printf("Affichage de la ListeChaine \n");
    while (!ListeChaine_Vide(L))
    {
      printf("Valeur de la ListeChaine :%d \n",L->Valeur);
      L=L->Suivant;
    }
  }
