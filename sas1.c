#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct PRD{
    char nom [50];
    char code[30];
    int qtt;
    float prix;
}prd8;

int nbr_tot = 0;

// void ajout_prd8(int N,prd8 ARR[]){
//     for(int i=nbr_tot; i<N+nbr_tot;i++){
//     printf("Nom :\n");fflush(stdin);fgets(ARR[i].nom,50,stdin);
//     printf("Code :\n");fgets(ARR[i].code,30,stdin);
//     printf("Quantite :\n");scanf("%d",&ARR[i].qtt);
//     printf("Prix :\n");scanf("%f",&ARR[i].prix);
//     }
//     nbr_tot+=N;
// }
void tri_prix (prd8 ARR[]){
    int index;
    prd8 tmp;
    for (int i=0; i < (5-1); i++)
    {
    index = i;

    for (int j=i + 1; j < 5; j++)
    {
      //strcmp(arr[index].nom, arr[j].nom)>0
      if (ARR[index].prix < ARR[j].prix)
        index = j;
    }
    if (index != i)
    {
      tmp = ARR[i];
      ARR[i] = ARR[index];
      ARR[index] = tmp;
    }
  }
}
void tri_alph (prd8 ARR[]){
    int index;
    prd8 tmp;
    for (int i=0; i < (5-1); i++)
    {
    index = i;

    for (int j=i + 1; j < 5; j++)
    {
    
      if (strcmp(ARR[index].nom, ARR[j].nom)>0)
        index = j;
    }
    if (index != i)
    {
      tmp = ARR[i];
      ARR[i] = ARR[index];
      ARR[index] = tmp;
    }
  }
}


int main()
{
  int ch,N,ch2;
    prd8 PRODUIT[1000];
  strcpy(PRODUIT[0].code,"6118000170167");
  strcpy(PRODUIT[0].nom,"GLUCOR");
  PRODUIT[0].qtt=100;
  PRODUIT[0].prix=192,00;
  // PRODUIT[0].prix_ttc=PRODUIT[0].prix + (PRODUIT[0].prix * 0.15);
  
  strcpy(PRODUIT[1].code,"6118000060154");
  strcpy(PRODUIT[1].nom,"SECTRAL");
  PRODUIT[1].qtt=100;
  PRODUIT[1].prix=992,00;
  // PRODUIT[1].prix_ttc=PRODUIT[0].prix + (PRODUIT[0].prix * 0.15);
  
  strcpy(PRODUIT[2].code,"6118000080060");
  strcpy(PRODUIT[2].nom,"AIRTAL");
  PRODUIT[2].qtt=100;
  PRODUIT[2].prix=792,00;
  // PRODUIT[2].prix_ttc=PRODUIT[0].prix + (PRODUIT[0].prix * 0.15);
  
  strcpy(PRODUIT[3].code,"6118000170242");
  strcpy(PRODUIT[3].nom,"RANTUDIL");
  PRODUIT[3].qtt=100;
  PRODUIT[3].prix=292,00;
  // PRODUIT[3].prix_ttc=PRODUIT[0].prix + (PRODUIT[0].prix * 0.15);
  
  strcpy(PRODUIT[3].code,"6118000012337");
  strcpy(PRODUIT[3].nom,"DIAMOX");
  PRODUIT[4].qtt=100;
  PRODUIT[4].prix=842,00;
  // PRODUIT[4].prix_ttc=PRODUIT[0].prix + (PRODUIT[0].prix * 0.15);
  
  strcpy(PRODUIT[4].code,"6118000071310");
  strcpy(PRODUIT[4].nom,"CICLOVIRAL");
  PRODUIT[4].qtt=100;
  PRODUIT[4].prix=92,00;
  // PRODUIT[4].prix_ttc=PRO
    do{
      printf("\t *********\n");
      printf("\t\tMenu principal\n\n");
      printf("\t *********\n");
      printf("\t 1.Ajouter un produit\n");
      printf("\t 2.Lister les produits\n");
      printf("\t 3.Acheter un produit\n");
      printf("\t 4.Cherecher un produit\n");
      printf("\t 5.Afficher l'etat du stock\n");
      printf("\t 5.Supprimer un produit\n");
      printf("\t 0.Quitter\n");
      printf("\t**********\n");
      printf("\t Entrez l'option :");
      scanf("%d",&ch);
  
      switch (ch){
      case 1: 
        // ajout_prd8(3,PRODUIT);
        break;
      case 2:

          printf("Veuillez saisir le tri :");
          scanf("%d",&ch2);
          if(ch2==1){
          tri_prix(PRODUIT);
          }else if(ch2==2) {
          tri_alph(PRODUIT); }
          else {
          printf("le choix incorrect ");
          }
          for (int i = 0; i < 5; i++)
          {
            printf("le nom:%sle code:%sprix:%.2f\nquantit:%d",PRODUIT[i].nom,PRODUIT[i].code,PRODUIT[i].prix,PRODUIT[i].qtt);
          }
          
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      }
  }while (ch!=0);
  return 0;
}

