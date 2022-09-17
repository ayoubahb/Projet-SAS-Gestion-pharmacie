#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void affichage ();
//Global variable

int nbr_prd = 0 ;

//Structure

typedef struct produit
{
  char code[50];
  char nom[50];
  int quantite;
  float prix;
  float prix_ttc;
}PRODUIT;

/*====================================Fonctions====================================*/

void ajout(PRODUIT arr[],int n){
  int j=1;
  for (int i = nbr_prd; i < n+nbr_prd; i++)
  {
    // fflush(stdin);
    printf("======== Produit %d ========",j);
    printf("\ncode :");
    fgets(arr[i].code,50,stdin);
    printf("\nnom :");
    fgets(arr[i].nom,50,stdin);
    printf("\nqty :");
    scanf("%d",&arr[i].quantite);
    printf("\nprix :");
    scanf("%f",&arr[i].prix);
    fflush(stdin);
    arr[i].prix_ttc = arr[i].prix+(arr[i].prix * 0.15);
    j++;
  }
  nbr_prd+=n;
  printf("Produit(s) ajoute avec succsse");
}
//trier la list principal avec les prix des produit **order decroissant** ou nom **order alphabetique
void tri (PRODUIT arr[],int n){
  int index;
  PRODUIT temp;
  if (n==1)
  {
    for (int i = 0; i < nbr_prd-1; i++)
    {
      index=i;
      for (int j = i; j < nbr_prd; j++)
      {
        if(arr[index].prix < arr[j].prix){ 
          index = j;
        }
      }
      if (index != i)
      {
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
      }
    }
    affichage (arr);
  }else if (n==2)
  {
    for (int i = 0; i < nbr_prd-1; i++)
    {
      index=i;
      for (int j = i; j < nbr_prd; j++)
      {
        if(strcmp(arr[index].nom, arr[j].nom)>0){ 
          index = j;
        }
      }
      if (index != i)
      {
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
      }
    }
    affichage (arr);
  }else{
    printf("\n");
  }
}
//Affichage des produits
void affichage (PRODUIT arr[]){
  for (int i = 0; i < nbr_prd; i++)
  {
    printf("\n\ncode : %s",arr[i].code);
    printf("nom : %s",arr[i].nom);
    printf("quatite : %d\n",arr[i].quantite);
    printf("prix : %.2f DH\n",arr[i].prix);
    printf("prix TTC : %.2f DH\n\n",arr[i].prix_ttc);
    printf("=====================");
  }
}
//Achat de produit
void achat(PRODUIT arr[],char prd_ach[50],int qty){
  int cible = 0;
  for (int i = 0; i < nbr_prd; i++)
  {
    if(strcmp(arr[i].code,prd_ach)==0){
      cible = i;
      break;
    }
  }
  if(cible!=0){
    arr[cible].quantite -= qty;
    printf("Votre achat a ete effectue");
  }else{
    printf("no produit in stock");
  }
  
}

int main(){
  //Variables
  int ch,ord,qty;
  int nbr_ajout;
  char nom_prd[50];
  PRODUIT prd[1000];
  //dashboard
  do
  {
    fflush(stdin);
    printf("\n\n---------Bienvenue--------- \n\n");
    printf("1.Ajouter des produits");
    printf("\n2.Afficher les produits");
    printf("\n3.Acheter un produit");
    printf("\n0.Quitter");
    printf("\n\nVotre choix : ");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1:
        // system("cls");
        printf("\nCombient de produit vous pouvez ajouter : ");
        scanf("%d",&nbr_ajout);
        fflush(stdin);    
        ajout(prd,nbr_ajout);
        break;
      
      case 2:
        printf("\nDe quel ordre vous pouvez afficher la list des produit \n");
        printf("\n1.Par prix ou prix TTC(order decroissant)");
        printf("\n2.Par order alphabetique");
        printf("\n0.Retour a la menu");
        do
        {
          printf("\n\nVotre choix : ");
          scanf("%d",&ord);
        } while (ord<0 && ord>3);
        tri(prd,ord);
        break;
      
      case 3:
        fflush(stdin);    
        printf("Veuillez entrer le code de produit a aheter : ");
        fgets(nom_prd,50,stdin);
        printf("\nLa quantite a aheter : ");
        scanf("%d",&qty);
        achat(prd , nom_prd , qty);
        break;
      
      case 4:
        /* code */
        break;
      
      default:
        exit(0);
        break;
      }
  } while (ch!=0);
  
  return 0;
}