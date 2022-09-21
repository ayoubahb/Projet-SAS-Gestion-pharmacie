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
void affiche_achat();
//Global variable

int length = 4 ;


//Structure

typedef struct produit
{
  char code[50];
  char nom[50];
  int quantite;
  float prix;
  float prix_ttc;
  float total;
}PRODUIT;

typedef struct achat
{
  char date[50];
  PRODUIT prd_ach;
  int qtty;
  float total;
}ACHAT;

int achat_len = 0;


/*====================================Fonctions====================================*/
int position_code(PRODUIT arr[],char prd_ach[50]){
  int cible;
  for (int i = 0; i < length; i++)
  {
    if(strcmp(arr[i].code,prd_ach)==0){
      cible = i;
      return cible;
    }
  }
  return -1;
}
// ajouter un ou plusieur produit 
void ajout(PRODUIT arr[]){
  int x ;
  x=length;
  int n,check;
  int j=1;
  printf("\nCombient de produit vous pouvez ajouter : ");
  scanf("%d",&n);
  fflush(stdin); 
  system("cls");
  for (int i = x; i < n+x; i++)
  {
    printf("======== Produit %d ========",j);
    printf("\ncode :");
    fgets(arr[i].code,50,stdin);
    check = position_code(arr,arr[i].code);
    if (check !=-1)
    {
      i--;
      printf("Produit avec le code %s est deja ecxiste dans la list des produit\n",arr[i].code);
      continue;
    }
    printf("\nnom :");
    fgets(arr[i].nom,50,stdin);
    printf("\nqty :");
    scanf("%d",&arr[i].quantite);
    printf("\nprix :");
    scanf("%f",&arr[i].prix);
    fflush(stdin);
    arr[i].prix_ttc = arr[i].prix+(arr[i].prix * 0.15);
    arr[i].total=0;
    j++;
    length++;
  }
  system("cls");
  printf("\nProduit(s) ajoute avec succsse\n");
}
//trier la list principal avec les prix des produit **order decroissant** ou nom **order alphabetique
void tri (PRODUIT arr[],int ord){
  int index;
  PRODUIT temp;
  if (ord==1)
  {
    for (int i = 0; i < length-1; i++)
    {
      index=i;
      for (int j = i; j < length; j++)
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
    system("cls");
    affichage (arr);
  }else if (ord==2)
  {
    for (int i = 0; i < length-1; i++)
    {
      index=i;
      for (int j = i; j < length; j++)
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
    system("cls");
    affichage (arr);
  }else if(ord==0){
    printf("\n");
  }else{
    printf("\nCe choix n'excist pas.");
  }
}
//Affichage les produits
void affichage (PRODUIT arr[]){
  printf("\n=======================================================================================================\n");
  for (int i = 0; i < length; i++)
  {
    printf("code : %s",arr[i].code);
    printf("\tnom : %s",arr[i].nom);
    printf("\tquantite : %d",arr[i].quantite);
    printf("\tprix : %.2f DH",arr[i].prix);
    printf("\tprix TTC : %.2f DH",arr[i].prix_ttc);
    printf("\n=======================================================================================================\n");
  }
}
//Achat de produit
void achat(PRODUIT arr[],ACHAT ach[]){
  system("cls");
  char nom_prd[50];
  int qty_ach;
  fflush(stdin);    
  printf("Veuillez entrer le code de produit a aheter : ");
  fgets(nom_prd,50,stdin);
  printf("\nLa quantite a aheter : ");
  scanf("%d",&qty_ach);
  int cible;
  cible = position_code(arr,nom_prd);
  if(cible==-1 || arr[cible].quantite < qty_ach){
    printf("\nImpossible d effectuer l achat\nVeuileez verifier l etat de stock de produit ou si le produit ecxiste\n");
  }else{
    arr[cible].quantite -= qty_ach;
    strcpy(ach[achat_len].date,__DATE__);
    ach[achat_len].prd_ach = arr[cible];
    ach[achat_len].qtty = qty_ach;
    ach[achat_len].total = ach[achat_len].prd_ach.prix_ttc * qty_ach;
    achat_len++;
    printf("\nACHAT EFFECTUEE\n");
  }
}
//chercher et afficher le produit
void recherche(PRODUIT arr[]){
  int n;
  int cible;

  system("cls");
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
      printf("\n=======================================================================================================\n");
      printf("code : %s",arr[cible].code);
      printf("\tnom : %s",arr[cible].nom);
      printf("\tquatite : %d",arr[cible].quantite);
      printf("\tprix : %.2f DH",arr[cible].prix);
      printf("\tprix TTC : %.2f DH",arr[cible].prix_ttc);
      printf("\n=======================================================================================================\n");
    }else{
      printf("\nAucun produit avec le code entree dans le stock\n");
    }
  }else if (n==2){
    int quant;
    printf("Entrer la quantite : ");
    scanf("%d",&quant);
    for (int i = 0; i < length; i++)
    {
      if(arr[i].quantite == quant){
        cible = i;
        break;
      }
    }
    if(cible!=-1){
      printf("\n=======================================================================================================\n");
      printf("code : %s",arr[cible].code);
      printf("\tnom : %s",arr[cible].nom);
      printf("\tquatite : %d",arr[cible].quantite);
      printf("\tprix : %.2f DH",arr[cible].prix);
      printf("\tprix TTC : %.2f DH",arr[cible].prix_ttc);
      printf("\n=======================================================================================================\n");
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
  for (int i = 0; i < length; i++)
  {
    if(arr[i].quantite <= 3){
      check++;
    }
  }
  system("cls");
  if (check==0)
  {
    printf("Pas de produit dont sa quantite inferieur a 3");
  }else{
    printf("\nLes produits ayant une quantite inferieur a 3 : \n");
    for (int i = 0; i < length; i++)
    {
      if(arr[i].quantite <= 3){
      printf("\n=======================================================================================================\n");
      printf("code : %s",arr[i].code);
      printf("\tnom : %s",arr[i].nom);
      printf("\tquatite : %d",arr[i].quantite);
      printf("\tprix : %.2f DH",arr[i].prix);
      printf("\tprix TTC : %.2f DH",arr[i].prix_ttc);
      printf("\n=======================================================================================================\n");
      }
    }
  }
}
//incrementer la quantite d'un produit
void alimentation(PRODUIT arr[]){
  system("cls");
  int qty_al; 
  char nom_prd[50];
  int cible;
  fflush(stdin);
  printf("Veuillez entrer le code de produit a alimenter : ");
  fgets(nom_prd,50,stdin);
  cible = position_code(arr,nom_prd);
  if(cible!=-1){
    printf("\n=======================================================================================================\n");
    printf("code : %s",arr[cible].code);
    printf("\tnom : %s",arr[cible].nom);
    printf("\tquatite : %d",arr[cible].quantite);
    printf("\tprix : %.2f DH",arr[cible].prix);
    printf("\tprix TTC : %.2f DH",arr[cible].prix_ttc);
    printf("\n=======================================================================================================\n");
    printf("\nLa quantite a aheter : ");
    scanf("%d",&qty_al);
    arr[cible].quantite += qty_al;
    printf("\nVotre alimentation a ete effectue\n");
  }else{
    printf("\nAucun produit avec le code entree dans le stock\n");
  }
}
//supprimer un produit
void supprime (PRODUIT arr[]){
  int cible;
  char nom_prd[50];
  fflush(stdin);
  printf("Veuillez entrer le code de produit a supprimer : ");
  fgets(nom_prd,50,stdin);
  cible = position_code(arr,nom_prd);
  if(cible!=-1){
    for (int i = cible; i < length; i++)
    {
      arr[i]=arr[i+1];
    }
    printf("\noperation effectuer avec succsse\n");
    length--;
  }else{
    printf("\nAucun produit avec le code entree dans le stock\n");
  }
}

float total (ACHAT arr[]){
  float total=0;
  for (int i = 0; i < achat_len; i++)
  {
    if (strcmp(arr[i].date,__DATE__)==0)
    {
      total+=arr[i].total; 
    }
    
  }
  return total;
}

float moyenne (ACHAT arr[]){
  int quantite_vendu = 0;
  for (int i = 0; i < achat_len; i++)
  {
    if (strcmp(arr[i].date,__DATE__)==0)
    {
      quantite_vendu += arr[i].qtty; 
    }
  }
  return total(arr)/quantite_vendu;
}

void minimum(ACHAT list[],PRODUIT arr[]){

  float min;
  int pos=0;
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < achat_len; j++)
    {
      if (strcmp(list[j].date,__DATE__)==0 && strcmp(arr[i].code,list[j].prd_ach.code)==0)
      {
        arr[i].total+=list[j].total;
      }
    } 
  }
  min=arr[0].total;
  for(int i=0;i<length;i++){
    if (min>arr[i].total)
    {
      pos=i;
      min=arr[i].total;
    }
  }

  printf("le Min des prix des produits vendus en journee courante est :\n");
  printf("code : %s",arr[pos].code);
  printf("nom : %s",arr[pos].nom);
  printf("\nTotal de prix vendu TTC: %.2f DH",arr[pos].total);
}
void maximum(ACHAT list[],PRODUIT arr[]){

  float max;
  int pos=0;
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < achat_len; j++)
    {
      if (strcmp(list[j].date,__DATE__)==0 && strcmp(arr[i].code,list[j].prd_ach.code)==0)
      {
        arr[i].total+=list[j].total;
      }
    } 
  }
  max=arr[0].total;
  for(int i=0;i<length;i++){
    if (max<arr[i].total)
    {
      pos=i;
      max=arr[i].total;
    }
  }

  printf("le Max des prix des produits vendus en journee courante est :\n");
  printf("code : %s",arr[pos].code);
  printf("nom : %s",arr[pos].nom);
  printf("\nTotal de prix vendu TTC: %.2f DH",arr[pos].total);
}
void stat_affichage(ACHAT list[],PRODUIT arr[]){
  system("cls");
  int ch;
  printf("\n\n1-Afficher le total des prix des produits vendus en journee courante");
  printf("\n2-Afficher la moyenne des prix des produits vendus en journee courante");
  printf("\n3-Afficher le MIN des prix des produits vendus en journee courante");
  printf("\n4-Afficher le MAX des prix des produits vendus en journee courante");
  printf("\n4-Afficher les achats de journee courante");
  printf("\n\nVotre choix : ");
  scanf("%d",&ch);

  switch (ch)
  {
  case 1:
    system("cls");
    printf("Le total des prix des produits vendus en journee courante est : %.2f",total(list));
    break;
  
  case 2:
    system("cls");
    printf("La moyenne des prix des produits vendus en journee courante est : %.2f",moyenne(list));
    break;
  
  case 3:
    system("cls");
    minimum(list,arr);
    break;
  
  case 4:
    system("cls");
    maximum(list,arr);
    break;
  
  case 5:
    system("cls");
    affiche_achat(list);
    break;
  
  default:
    system("cls");
    printf("Ce choix n existe pas");
    break;
  }
}

void affiche_achat(ACHAT list[]){
  system("cls");
  for (int i = 0; i < achat_len; i++)
  {
    printf("\nDate : %s",list[i].date);
    printf("\nCode de produit : %s",list[i].prd_ach.code);
    printf("Nom de produit : %s",list[i].prd_ach.nom);
    printf("\nMontant d achat en TTC : %.2f",list[i].total);
    printf("\n+++++++++++++++++++++++++\n");
  }
}

int main(){
  //Variables
  int ch,ord;
  ACHAT history [1000];
  PRODUIT prd[1000];

  strcpy(prd[0].code,"6118000170167\n");
  strcpy(prd[0].nom,"GLUCOR");
  prd[0].quantite=100;
  prd[0].prix=892,00;
  prd[0].prix_ttc=prd[0].prix + (prd[0].prix * 0.15);
  prd[0].total=0;
  

  strcpy(prd[1].code,"6118000080060\n");
  strcpy(prd[1].nom,"AIRTAL");
  prd[1].quantite=100;
  prd[1].prix=942,00;
  prd[1].prix_ttc=prd[1].prix + (prd[1].prix * 0.15);
  prd[1].total=0;

  strcpy(prd[2].code,"6118000170242\n");
  strcpy(prd[2].nom,"RANTUDIL");
  prd[2].quantite=100;
  prd[2].prix=872,00;
  prd[2].prix_ttc=prd[2].prix + (prd[2].prix * 0.15);
  prd[2].total=0;

  strcpy(prd[3].code,"6118000012337\n");
  strcpy(prd[3].nom,"DIAMOX");
  prd[3].quantite=100;
  prd[3].prix=192,00;
  prd[3].prix_ttc=prd[3].prix + (prd[3].prix * 0.15);
  prd[3].total=0;
  //dashboard
  system("cls");
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
    printf("\n7.Suporime un produit");
    printf("\n8.Statistique de vente");
    printf("\n0.Quitter");
    printf("\n\nVotre choix : ");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1:    
        ajout(prd);
        break;
      case 2:
        printf("\nDe quel ordre vous pouvez afficher la list des produit \n");
        printf("\n1.Par prix ou prix TTC(order decroissant)");
        printf("\n2.Par order alphabetique");
        printf("\n0.Retour a la menu");
        printf("\n\nVotre choix : ");
        scanf("%d",&ord);
        tri(prd,ord);
        break;
      
      case 3:
        achat(prd,history);
        break;
      
      case 4:
        recherche(prd);
        break;
      case 5:
        etat(prd);
        break;
      case 6:
        alimentation(prd);
        break;
      
      case 7:
        supprime(prd);
        break;

      case 8:
        stat_affichage(history,prd);
        break;
      
      case 0:
        break;
      
      default:
        printf("Ce choix n existe pas");
        break;
      }
  } while (ch!=0);
  return 0;
}
