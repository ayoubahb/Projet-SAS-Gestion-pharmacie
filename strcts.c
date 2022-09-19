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

void recherche(PRODUIT arr[]){
  int n;
  printf("1-par qty");
  printf("\n2-par code");
  printf("\n\nVotre choix :");
  scanf("%d",&n);
  if (n == 1){
    int qty;
    printf("entrer la quantite de produit ");
    scanf("%d",&qty);
    for (int i = 0; i < 6; i++)
    {
      if(arr[i].quantite == qty){
        printf("nom : %s code : %s",arr[i].nom,arr[i].code);
      }
    }
    
  }else if (n==2)
  {
    fflush(stdin);
    char code[50];
    printf("entrer le code de produit ");
    fgets(code,50,stdin);
    for (int i = 0; i < 6; i++)
    {
      if(strcmp(arr[i].code,code)==0){
        printf("nom : %s code : %s",arr[i].nom,arr[i].code);
      }
    }
  }
  
}
int main()
{
  PRODUIT prd[1000];

  strcpy(prd[0].code,"6118000170167");
  strcpy(prd[0].nom,"GLUCOR");
  prd[0].quantite=100;
  prd[0].prix=892,00;
  prd[0].prix_ttc=prd[0].prix + (prd[0].prix * 0.15);
  
  strcpy(prd[1].code,"6118000060154");
  strcpy(prd[1].nom,"SECTRAL");
  prd[1].quantite=1300;
  prd[1].prix=92,00;
  prd[1].prix_ttc=prd[1].prix + (prd[1].prix * 0.15);
  
  strcpy(prd[2].code,"6118000080060\n");
  strcpy(prd[2].nom,"AIRTAL");
  prd[2].quantite=1050;
  prd[2].prix=942,00;
  prd[2].prix_ttc=prd[2].prix + (prd[2].prix * 0.15);
  
  strcpy(prd[3].code,"6118000170242\n");
  strcpy(prd[3].nom,"RANTUDIL");
  prd[3].quantite=1007;
  prd[3].prix=872,00;
  prd[3].prix_ttc=prd[3].prix + (prd[3].prix * 0.15);
  
  strcpy(prd[4].code,"6118000012337");
  strcpy(prd[4].nom,"DIAMOX");
  prd[4].quantite=1008;
  prd[4].prix=192,00;
  prd[4].prix_ttc=prd[4].prix + (prd[4].prix * 0.15);
  
  strcpy(prd[5].code,"6118000071310");
  strcpy(prd[5].nom,"CICLOVIRAL");
  prd[5].quantite=1040;
  prd[5].prix=62,00;
  prd[5].prix_ttc=prd[5].prix + (prd[5].prix * 0.15);
  
  recherche(prd);
  
  return 0;
}
