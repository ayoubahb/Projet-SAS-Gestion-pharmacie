#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produit
{
  char nom[50];
  char code[50];
  int quantite;
  float prix;
  float prix_ttc;
}PRODUIT;


int main(int argc, char const *argv[])
{
  PRODUIT prd[1000];
  char date[50];
  // strcpy(prd[0].code,"6118000170167");
  // strcpy(prd[0].nom,"GLUCOR");
  // prd[0].quantite=100;
  // prd[0].prix=892,00;
  // prd[0].prix_ttc=prd[0].prix + (prd[0].prix * 0.15);
  
  // strcpy(prd[1].code,"6118000060154");
  // strcpy(prd[1].nom,"SECTRAL");
  // prd[1].quantite=100;
  // prd[1].prix=92,00;
  // prd[1].prix_ttc=prd[1].prix + (prd[1].prix * 0.15);
  
  // strcpy(prd[2].code,"6118000080060");
  // strcpy(prd[2].nom,"AIRTAL");
  // prd[2].quantite=100;
  // prd[2].prix=942,00;
  // prd[2].prix_ttc=prd[2].prix + (prd[2].prix * 0.15);
  
  // strcpy(prd[3].code,"6118000170242");
  // strcpy(prd[3].nom,"RANTUDIL");
  // prd[3].quantite=100;
  // prd[3].prix=872,00;
  // prd[3].prix_ttc=prd[3].prix + (prd[3].prix * 0.15);
  
  // strcpy(prd[4].code,"6118000012337");
  // strcpy(prd[4].nom,"DIAMOX");
  // prd[4].quantite=100;
  // prd[4].prix=192,00;
  // prd[4].prix_ttc=prd[4].prix + (prd[4].prix * 0.15);
  
  // strcpy(prd[5].code,"6118000071310");
  // strcpy(prd[5].nom,"CICLOVIRAL");
  // prd[5].quantite=100;
  // prd[5].prix=62,00;
  // prd[5].prix_ttc=prd[5].prix + (prd[5].prix * 0.15);


  strcpy(date,__DATE__);
  
  if (strcmp(date,__DATE__)==0)
  {
    printf("hello");
  }
  printf("\n");
  return 0;
}
