#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int nbr_appr = 0;

typedef struct {
    char nom[20];
    char prenom[20];
    struct date {
        int jour;
        int mois;
        int annee;
    }date;
}apprenants;
void info (apprenants etudiant[],int n){
        for (size_t i = nbr_appr; i < nbr_appr+n; i++)
        {
        printf("\nVeillez entrer votre prenom : ");
        fflush(stdin);
        fgets(etudiant[i].prenom,20,stdin);
        printf("\nVeillez entrer votre nom : ");
        fflush(stdin);
        fgets(etudiant[i].nom,20,stdin);
        printf("\nVeillez entrer votre date de naissance : \n");
        printf("\nJOUR : ");
        scanf("%d",&etudiant[i].date.jour);
        printf("\nMOIS : ");
        scanf("%d",&etudiant[i].date.mois);
        printf("\nANNEE : ");
        scanf("%d",&etudiant[i].date.annee);
        }
        nbr_appr +=n; 
        printf("\n=====================\n");
}
void affichage_info(apprenants etudiant[]){
    for (int i = 0; i < nbr_appr; i++)
    {
        printf("\nPrenom: %s\nNom: %s\nDate de naissance: %d/%d/%d\n\nAge: %d\n",etudiant[i].prenom,etudiant[i].nom,etudiant[i].date.jour,etudiant[i].date.mois,etudiant[i].date.annee,2022-etudiant[i].date.annee);
        printf("\n=====================\n");
    }
}
void tri(apprenants etudiant[]){
    int index,index1,index2;
    apprenants temp;
    for (int i = 0; i < nbr_appr-1; i++)
    {
        index=i;
        for (int j = i; j < nbr_appr; j++)
        {
            if(etudiant[index].date.annee < etudiant[j].date.annee){ 
                index = j;
            }
        }
        if (index != i)
        {
            temp = etudiant[i];
            etudiant[i] = etudiant[index];
            etudiant[index] = temp;
        }
    }
    for (int k = 0; k < nbr_appr-1; k++)
    {
        index1 =k;
        for (int l = k; l < nbr_appr; l++)
        {
            // if (etudiant[index1].date.annee == etudiant[l].date.annee && etudiant[index1].date.mois < etudiant[l].date.mois)
            if (etudiant[index1].date.annee == etudiant[l].date.annee)
            {
                if (etudiant[index1].date.mois < etudiant[l].date.mois)
                {
                    index1 = l ;
                }
            }
            if (index1 != k)
            {
                temp = etudiant[k];
                etudiant[k] = etudiant[index1];
                etudiant[index1] = temp;
            }
        }
    }
    for (int m = 0; m < nbr_appr-1; m++)
    {
        index2 =m;
        for (int n = m; n < nbr_appr; n++)
        {
            // if (etudiant[index2].date.annee == etudiant[n].date.annee && etudiant[index2].date.mois == etudiant[n].date.mois && etudiant[index2].date.jour < etudiant[n].date.jour)
            if (etudiant[index2].date.annee == etudiant[n].date.annee && etudiant[index2].date.mois == etudiant[n].date.mois )
            {
                if (etudiant[index2].date.jour < etudiant[n].date.jour)
                {
                    index2 = n ;
                }
                
            }
            if (index2 != m)
            {
                temp = etudiant[m];
                etudiant[m] = etudiant[index2];
                etudiant[index2] = temp;
            }
        }
    }
    
}
void age(apprenants etudiant[]){
    float somme,moyenne;
    printf("\nL'apprenant ayant l'age le plus grand :\n");
    printf("\nPrenom: %s\nNom: %s\nDate de naissance: %d/%d/%d\n\nAge: %d\n",etudiant[nbr_appr-1].prenom,etudiant[nbr_appr-1].nom,etudiant[nbr_appr-1].date.jour,etudiant[nbr_appr-1].date.mois,etudiant[nbr_appr-1].date.annee,2022-etudiant[nbr_appr-1].date.annee);
    printf("\n=====================\n");
    printf("L'apprenant ayant l'age le plus petit :\n");
    printf("\nPrenom: %s\nNom: %s\nDate de naissance: %d/%d/%d\n\nAge: %d\n",etudiant[0].prenom,etudiant[0].nom,etudiant[0].date.jour,etudiant[0].date.mois,etudiant[0].date.annee,2022-etudiant[0].date.annee);
    printf("\n=====================\n");
    somme=0;
    for (int i = 0; i < nbr_appr; i++)
    {
        somme+=2022-etudiant[i].date.annee;
    }
    moyenne=somme/nbr_appr;
    printf("\nLe moyenne d'age est: %.2f",moyenne);
}
int main() {
    int nbr,choix;
    apprenants appr[100];
    
    do{
        
        printf("\n\n---------Bienvenue--------- \n\n");
        printf("1.Introduir des informations");
        printf("\n2.Afficher les apprenants trie selon age");
        printf("\n3.Afficher l'apprenant ayant l'age le plus petit et le plus grand et le moyenne d'age");
        printf("\n0.Quitter");
        printf("\n\nVotre choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            system("cls");
            printf("\nEntrer nombre d'apprenants : ");
            scanf("%d",&nbr);
            info(appr,nbr);
            tri(appr);
            printf("\n=====Ajout avec succee=====\n");
            break;
        case 2:
            // system("cls");
            affichage_info(appr);
            break;
        case 3:
            // system("cls");
            age(appr);
            break;
        case 0:
            break;
        default:
            printf("Votre choix n'existe pas");
            break;
        }
    }while(choix!=0);

    return 0;
}