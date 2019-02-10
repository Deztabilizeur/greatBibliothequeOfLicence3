#include <stdio.h>
#include <stdlib.h>
#include "greatBibliothequeOfLicence3.h"


int main(){
  int **mat;
  printf("************MATRICE ADJACENTE******************\n");
  buildMatrice("matriceAdjacente.txt", &(*mat));
  printf("***********************************************\n");

}
