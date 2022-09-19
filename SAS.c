#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int position_code();
void affichage ();
void ajout();
void tri();
void achat();
void recherche();
void etat();
void alimentation();
void supprime();
//Global variable

int nbr_prd = 5 ;
float prix_total = 0;
//Structure

typedef struct produit
{
  char code[50];
  char nom[50];
  int quantite;
  float prix;
  float prix_ttc;
  int quantite_vendu;
}PRODUIT;

/*====================================Fonctions====================================*/
int position_code(PRODUIT arr[],char prd_ach[50]){
  int cible = -1;
  for (int i = 0; i < nbr_prd; i++)
  {
    if(strcmp(arr[i].code,prd_ach)==0){
      cible = i;
      break;
    }
  }
  return cible;
}
// ajouter un ou plusieur produit 
void ajout(PRODUIT arr[]){
  int n ;
  int j=1;
  printf("\nCombient de produit vous pouvez ajouter : ");
  scanf("%d",&n);
  fflush(stdin); 
  for (int i = nbr_prd; i < n+nbr_prd; i++)
  {
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
    arr[i].quantite_vendu=0;
    j++;
  }
  nbr_prd+=n;
  printf("Produit(s) ajoute avec succsse");
}
//trier la list principal avec les prix des produit **order decroissant** ou nom **order alphabetique
void tri (PRODUIT arr[]){
  int index,ord;
  PRODUIT temp;
  printf("\nDe quel ordre vous pouvez afficher la list des produit \n");
  printf("\n1.Par prix ou prix TTC(order decroissant)");
  printf("\n2.Par order alphabetique");
  printf("\n0.Retour a la menu");
  printf("\n\nVotre choix : ");
  scanf("%d",&ord);
  if (ord==1)
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
  }else if (ord==2)
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
  }else if(ord==0){
    printf("\n");
  }else{
    printf("\nCe choix n'excist pas.");
  }
}
//Affichage les produits
void affichage (PRODUIT arr[]){
  for (int i = 0; i < nbr_prd; i++)
  {
    printf("\n\ncode : %s",arr[i].code);
    printf("\nnom : %s",arr[i].nom);
    printf("\nquatite : %d\n",arr[i].quantite);
    printf("prix : %.2f DH\n",arr[i].prix);
    printf("prix TTC : %.2f DH\n\n",arr[i].prix_ttc);
    printf("=====================");
  }
}
//Achat de produit
void achat(PRODUIT arr[]){
  char nom_prd[50];
  int qty_ach;
  fflush(stdin);    
  printf("Veuillez entrer le code de produit a aheter : ");
  fgets(nom_prd,50,stdin);
  int cible;
  cible = position_code(arr,nom_prd);
  if(cible!=-1){
    if (arr[cible].quantite == 0)
    {
      printf("\nEn repture de stock\n");
    }else{
      printf("\nLa quantite a aheter : ");
      scanf("%d",&qty_ach);
      arr[cible].quantite -= qty_ach;
      arr[cible].quantite_vendu += qty_ach;
      prix_total += arr[cible].quantite_vendu * arr[cible].prix;
      printf("\nVotre achat a ete effectue\n");
    }
  }else{
    printf("\nAucun produit avec le code entree dans le stock\n");
  }
}
//chercher et afficher le produit
void recherche(PRODUIT arr[]){
  int n;
  int cible;

  printf("\nDe quel recherche vous pouvez chercher \n");
  printf("\n1.Par code");
  printf("\n2.Par quantite");
  printf("\n0.Retour a la menu");
  printf("\n\nVotre choix : ");
  scanf("%d",&n);
  
  if (n==1){
    fflush(stdin);
    char prd_ach[50];
    printf("Entrer le code de produit : ");
    fgets(prd_ach,50,stdin);
    cible = position_code(arr,prd_ach);
    if(cible!=-1){
      printf("\n\ncode : %s",arr[cible].code);
      printf("nom : %s",arr[cible].nom);
      printf("\nquatite : %d\n",arr[cible].quantite);
      printf("prix : %.2f DH\n",arr[cible].prix);
      printf("prix TTC : %.2f DH\n\n",arr[cible].prix_ttc);
    }else{
      printf("\nAucun produit avec le code entree dans le stock\n");
    }
  }else if (n==2){
    int quant;
    printf("Entrer la quantite : ");
    scanf("%d",&quant);
    for (int i = 0; i < nbr_prd; i++)
    {
      if(arr[i].quantite == quant){
        cible = i;
        break;
      }
    }
    if(cible!=-1){
      printf("\n\ncode : %s",arr[cible].code);
      printf("nom : %s",arr[cible].nom);
      printf("\nquatite : %d\n",arr[cible].quantite);
      printf("prix : %.2f DH\n",arr[cible].prix);
      printf("prix TTC : %.2f DH\n\n",arr[cible].prix_ttc);
    }else{
      printf("\nAucun produit avec la quantite entree dans le stock\n");
    }

  }else if(n==0){
    printf("\n");
  }else
  {
    printf("\nCe choix n'excist pas.");
  }
  
}
//afficher les produits dont leur etate de stock inferieur de 3
void etat(PRODUIT arr[]){
  int check = 0;
  for (int i = 0; i < nbr_prd; i++)
  {
    if(arr[i].quantite <= 3){
      printf("\n\ncode : %s",arr[i].code);
      printf("nom : %s",arr[i].nom);
      printf("quatite : %d\n",arr[i].quantite);
      printf("prix : %.2f DH\n",arr[i].prix);
      printf("prix TTC : %.2f DH\n\n",arr[i].prix_ttc);
      printf("=====================");
      check++;
    }
  }
  if (check==0)
  {
    printf("Pas de produit dont la quantite inferieur a 3");
  }
}
//incrementer la quantite d'un produit
void alimentation(PRODUIT arr[],char prd_ach[50],int qty){
  int cible;
  cible = position_code(arr,prd_ach);
  if(cible!=-1){
    arr[cible].quantite += qty;
    printf("\nVotre alimentation a ete effectue\n");
  }else{
    printf("\nAucun produit avec le code entree dans le stock\n");
  }
}
//supprimer un produit
void supprime (PRODUIT arr[],char prd_ach[50]){
  int cible;
  cible = position_code(arr,prd_ach);
  for (int i = cible; i < nbr_prd; i++)
  {
    arr[i]=arr[i+1];
  }
  nbr_prd--;
}

int main(){
  //Variables
  int ch;
  int qty_al;

  char nom_prd[50];
  PRODUIT prd[1000];

  strcpy(prd[0].code,"6118000170167\n");
  strcpy(prd[0].nom,"GLUCOR");
  prd[0].quantite=100;
  prd[0].prix=892,00;
  prd[0].prix_ttc=prd[0].prix + (prd[0].prix * 0.15);
  
  strcpy(prd[1].code,"6118000060154\n");
  strcpy(prd[1].nom,"SECTRAL");
  prd[1].quantite=100;
  prd[1].prix=92,00;
  prd[1].prix_ttc=prd[1].prix + (prd[1].prix * 0.15);
  
  strcpy(prd[2].code,"6118000080060\n");
  strcpy(prd[2].nom,"AIRTAL");
  prd[2].quantite=100;
  prd[2].prix=942,00;
  prd[2].prix_ttc=prd[2].prix + (prd[2].prix * 0.15);
  
  strcpy(prd[3].code,"6118000170242\n");
  strcpy(prd[3].nom,"RANTUDIL");
  prd[3].quantite=100;
  prd[3].prix=872,00;
  prd[3].prix_ttc=prd[3].prix + (prd[3].prix * 0.15);
  
  strcpy(prd[4].code,"6118000012337\n");
  strcpy(prd[4].nom,"DIAMOX");
  prd[4].quantite=100;
  prd[4].prix=192,00;
  prd[4].prix_ttc=prd[4].prix + (prd[4].prix * 0.15);
  
  strcpy(prd[5].code,"6118000071310\n");
  strcpy(prd[5].nom,"CICLOVIRAL");
  prd[5].quantite=100;
  prd[5].prix=62,00;
  prd[5].prix_ttc=prd[5].prix + (prd[5].prix * 0.15);

  //dashboard
  do
  {
    fflush(stdin);
    printf("\n\n--------- Bienvenue --------- \n\n");
    printf("1.Ajouter des produits");
    printf("\n2.Afficher les produits");
    printf("\n3.Acheter un produit");
    printf("\n4.Chercher un produit avec code");
    printf("\n5.Etat de stock");
    printf("\n6.Alimenter le stock");
    printf("\n0.Quitter");
    printf("\n\nVotre choix : ");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1:    
        ajout(prd);
        break;
      
      case 2:
        tri(prd);
        break;
      
      case 3:
        achat(prd);
        break;
      
      case 4:
        recherche(prd);
        break;
      case 5:
        printf("\nLes produits ayant une quantite inferieur a 3 : \n");
        etat(prd);
        break;
      case 6:
        fflush(stdin);    
        printf("Veuillez entrer le code de produit a alimenter : ");
        fgets(nom_prd,50,stdin);
        printf("\nLa quantite a aheter : ");
        scanf("%d",&qty_al);
        alimentation(prd,nom_prd,qty_al);
        break;
      
      default:
        exit(0);
        break;
      }
  } while (ch!=0);
  
  return 0;
}
