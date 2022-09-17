#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int nbr_prd = 0 ;
typedef struct produit
{
  char code[20];
  char nom[20];
  int quantite;
  float prix;
  float prix_ttc;
}PRODUIT;
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
  }else if (n==2)
  {
    for (int i = 0; i < nbr_prd-1; i++)
    {
      index=i;
      for (int j = i; j < nbr_prd; j++)
      {
          if(arr[index].prix_ttc < arr[j].prix_ttc){ 
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
  }else if (n==3)
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
  }else{
    printf("\n");
  }
}

void ajout(PRODUIT arr[],int n){
  int j=1;
  for (int i = nbr_prd; i < n+nbr_prd; i++)
  {
    fflush(stdin);
    printf("======== Produit %d ========",j);
    printf("\ncode :");
    fgets(arr[i].code,30,stdin);
    printf("\nnom :");
    fgets(arr[i].nom,30,stdin);
    printf("\nqty :");
    scanf("%d",&arr[i].quantite);
    printf("\nprix :");
    scanf("%f",&arr[i].prix);
    arr[i].prix_ttc = arr[i].prix+(arr[i].prix * 0.15);
    j++;
  }
  nbr_prd+=n;
}

// void tri_prix (PRODUIT arr[]){
//   int index;
//   PRODUIT temp;
//   for (int i = 0; i < nbr_prd-1; i++)
//   {
//       index=i;
//       for (int j = i; j < nbr_prd; j++)
//       {
//           if(arr[index].prix < arr[j].prix){ 
//               index = j;
//           }
//       }
//       if (index != i)
//       {
//           temp = arr[i];
//           arr[i] = arr[index];
//           arr[index] = temp;
//       }
//   }
// }
// void tri_nom (PRODUIT arr[]){
//   int index;
//   PRODUIT temp;
//   for (int i = 0; i < nbr_prd-1; i++)
//   {
//       index=i;
//       for (int j = i; j < nbr_prd; j++)
//       {
//           if(strcmp(arr[index].nom, arr[j].nom)>0){ 
//             index = j;
//           }
//       }
//       if (index != i)
//       {
//           temp = arr[i];
//           arr[i] = arr[index];
//           arr[index] = temp;
//       }
//   }
// }
int main()
{
  PRODUIT list[1000];

  ajout(list,4);
  tri(list,0);
  // for (int i = 0; i < nbr_prd; i++)
  // {
  //   printf("\n\ncode : %s",list[i].code);
  //   printf("nom : %s",list[i].nom);
  //   printf("quatite : %d\n",list[i].quantite);
  //   printf("prix : %.2f\n",list[i].prix);
  //   printf("prix TTC : %.2f\n",list[i].prix_ttc);
  //   printf("=====================");
  // }
  printf("\nHI");
  printf("\n");
  return 0;
}
  // prd arr_prd[1000];
  // for (int i = 0; i < 2; i++)
  // {
  //   fflush(stdin);
  //   printf("======== Produit %d ========",i+1);
  //   printf("\ncode :");
  //   fgets(arr_prd[i].code,30,stdin);
  //   printf("\nnom :");
  //   fgets(arr_prd[i].nom,30,stdin);
  //   printf("\nqty :");
  //   scanf("%d",&arr_prd[i].quantite);
  //   printf("\nprix :");
  //   scanf("%f",&arr_prd[i].prix);
  //   arr_prd[i].prix_ttc = arr_prd[i].prix+(arr_prd[i].prix * 0.15);
  // }
  // for (int i = 0; i < 2; i++)
  // {
  //   printf("\n\ncode : %s",arr_prd[i].code);
  //   printf("nom : %s",arr_prd[i].nom);
  //   printf("quatite : %d\n",arr_prd[i].quantite);
  //   printf("prix : %.2f\n",arr_prd[i].prix);
  //   printf("prix TTC : %.2f\n",arr_prd[i].prix_ttc);
  //   printf("=====================");
  // }
  // printf("\n");
  // fflush(stdin);
  // char txt[30];
  // fgets(txt,30,stdin);
  // if(strcmp(txt,arr_prd[1].code)==0){
  //   printf("\n\nMatch");
  // }else{
    
  //   printf("\n\nNo Match");
  // }
  


// int main()
// {
//   int T[5]={2,5,7,9,2};
//   int R[5];

//   for (int i = 0; i < 5; i++)
//   {
//     R[i]=T[i];
//   }
//   for (int i = 0; i < 5; i++)
//   {
//     printf("\n%d",R[i]);
//   }
//   printf("\n");
  

//   return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main(){
//   int i,j,n;
//   char str[100][100],s[100];
//   printf("Enter number of names :\n");
//   scanf("%d",&n);
//   printf("Enter names in any order:\n");
//   for(i=0;i<n;i++){
//     scanf("%s",str[i]);
//   }
//   for(i=0;i<n;i++){
//     for(j=i+1;j<n;j++){
//         if(strcmp(str[i],str[j])>0){
//           strcpy(s,str[i]);
//           strcpy(str[i],str[j]);
//           strcpy(str[j],s);
//         }
//     }
//   }
//   printf("\nThe sorted order of names are:\n");
//   for(i=0;i<n;i++){
//     printf("%s\n",str[i]);
//   }
//   printf("\n");
//   return 0 ;
// }
