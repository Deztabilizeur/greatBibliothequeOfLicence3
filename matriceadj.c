#include <stdio.h>
#include <stdlib.h>
#include "greatBibliothequeOfLicence3.h"



void rerror(char *msg, char *fileName){
  if(fileName == NULL) printf("%s\n",msg);
  else printf("%s %s\n", msg, fileName);
  exit(0);
}
int empty(file f){
  return f == NULL;
}
void enfiler(int s, file f){

}
void defiler(file f){

}
file initFile(){
  return f == NULL;
}
int sommetfile(file f){

}
int nbSom(MatADJ g){
  return g.nbSom;
}
void allocTab(int n, int **tab){
  *tab = (int *)malloc(n*sizeof(int));
  if(*tab == NULL)
    rerror("ERROR in procedure allocTab", NULL);
}
int* allocTabl(int n){
  int *tab;
  tab = (int *)malloc(n*sizeof(int));
  if(tab == NULL) rerror("ERROR in fonction allocTabl", NULL);
  return tab;
}
int **allocMatr(int n, int m){
  int **mat;
  mat = (int **)malloc(m*sizeof(int *));
  if(mat == NULL) rerror("Error in fonction allocMatr", NULL);
  for(int i=0; i<m; i++) mat[i] = allocTabl(n);
  return mat;
}
void allocMat(int n, int m, int ***mat){
  *mat = (int **)malloc(m*sizeof(int *));
  if(*mat == NULL) rerror("Error in procedure allocMat", NULL);
  for(int i=0; i<m; i++)(*mat)[i] = allocTabl(n);
}
void parcoursLarg(MatADJ g, int s, int *niveau){
  int n = nbSom(g);
  file f = initFile();
  int nbSomVisite = 0;
  for(int ss=0; ss<n; ss++){
    g.value[ss] = 0;
  }
  enfiler(s, f);
  while(!empty(f)){
    int u = sommetfile(f);
    defiler(f);
    g.value[u] = 1;
    for(int t=0; t<n; t++){
      if(g.value[t] == 0){
        enfiler(t, f);
        niveau[t] = niveau[u] + 1;
      }

    }
  }
}
void partition(int n, int *niveau, int n1, int *s1, int n2, int *s2){
  n1, n2 = 0;
  for(int s=0; s<n; s++){
    if(pair(niveau[s])) {
      n1++;
      s1[n1] = s;
    }
    else{
      n2++;
      s2[n2] = s;
    }
  }
}
int estLibre(int n, int *s, MatADJ g){  // 1 si aucune liaison entre les elems de G dans G 0 sinon
  int u=0;
  int link = 0;
  int v=0;
  while(u<n && link==1){
    v = u+1;
    while(v<=n && nonArete(u, v, g)){
      v++;
    }
    if(v<=n) link = 1;
    else u++;
  }
  return !link;
}
void printMat(int **mat, int m, int n){
  for(int i =0; i<m; i++){
    for(int j=0; j<n; j++){
      printf("[%d]", mat[i][j]);
    }
    printf("\n");
  }
}

void buildMatrice(char *file, int **mat){
  int typegraphe, nbsom, som, nbsucc, succ, nbarc, origine, extrimite;
  FILE * fp;
  fp = fopen (file, "r+");
  if(fp == NULL) rerror("Enable to open file",file);
  fscanf(fp, "typGraphe=%d\n", &typegraphe);
  fscanf(fp, "nbSom=%d\n", &nbsom);
  fscanf(fp, "nbArcs=%d\n", &nbarc);
  if(typegraphe == 1){
    MatADJ adj;
    adj.numSom = nbsom;
    printf("type graphe = %d \t nbsom = %d \t nbarc = %d\n", typegraphe, nbsom, nbarc);
    adj.mat = allocMatr(nbsom, nbsom);
    for(int i=0; i<nbsom; i++){
      fscanf(fp, "som=%d nbsucc=%d succ=", &som, &nbsucc);
      for(int j=0; j<nbsucc;j++){
        fscanf(fp, "%d ", &succ);
        adj.mat[som-1][succ-1] = 1;
      }
    }
    printMat(adj.mat, nbsom, nbsom);
  }
}

int biPart(MatADJ g){
  int n = nbSom(g);
  int *niveau = allocTab(n);
  parcoursLarg(s, g, niveau);

  // determiner s1, s2, n1, n2

  partition(n, niveau, n1, s1, n2, s2);
  return estLibre(n1, s1, g) && estLibre(n2, s2, g);
}
