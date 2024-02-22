//enunt: https://imgur.com/a/iWR63h8

#include<stdio.h>
#include<string.h>

typedef struct
{   int nr_cam;
    float S;
    char sursa_incalz[100];
    int nr_ident;
    int nr_pers;
} Apart;

//punctul b
void citire(Apart adm[],int *nr_ap)
{   int i,n;
    printf("nr de ap:\n");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {   printf("ap:%d\n",i+1);
        printf("nr cam:\n");
        scanf("%d",&adm[i].nr_cam);
        printf("nr suprafata:\n");
        scanf("%f",&adm[i].S);
        getchar();

        printf("sursa incalzire:\n");
        gets(adm[i].sursa_incalz);

        printf("nr identitate:\n");
        scanf("%d",&adm[i].nr_ident);

        printf("nr persoane:\n");
        scanf("%d",&adm[i].nr_pers);
    }
    *nr_ap=n;
}

//punctul d
void selectie(Apart adm[],Apart ap_d[],int nr_ap,int *nr)
{   int i,k=0;
    for(i=0; i<nr_ap; i++)
    {
        if(strcmp(adm[i].sursa_incalz,"Centrala proprie")==0 && adm[i].nr_cam<4)
        {
            ap_d[k]=adm[i];
            k++;
        }
    }
    *nr=k;
}

//punctul c
float factura(int n,Apart adm[],int nr_ap)
{
    int s_fact,i,n_cam=0;
    float suma=0;
    printf("introduceti suma de facturare:\n");
    scanf("%d",&s_fact);

    for(i=0; i<nr_ap; i++)
    {
        if(strcmp(adm[i].sursa_incalz,"Incalzire centralizata")==0)
            n_cam=adm[i].nr_cam+n_cam;
    }
    float cost_cam=(float)s_fact/n_cam;
    if(strcmp(adm[n-1].sursa_incalz,"Incalzire centralizata")==0)
    {
        suma=(adm[n-1].nr_cam)*cost_cam;
        return suma;
    }
    else
        return 0;
}

int main ()
{
    Apart adm[5],ap_d[3];
    int i,nr_ap,nr,n;
    float suma;
    citire(adm,&nr_ap);//pct b)
    selectie(adm,ap_d,nr_ap,&nr);//pct d)
    if(nr>0)
    {
        printf("\nApartamentele sunt:\n");
        for(i=0; i<nr; i++)
        {
            printf("%d. ",i+1);
            printf("%d\n",adm[i].nr_cam);
            printf("%.2f\n",adm[i].S);
            puts(adm[i].sursa_incalz);
            printf("%d\n",adm[i].nr_ident);
            printf("%d\n",adm[i].nr_pers);
        }
    }
    else
        printf("nu exista astfel de apartamente.\n");

    printf("introduceti numarul apartamentului:\n");//pct c)
    scanf("%d",&n);
    suma=factura(n,adm,nr_ap);
    printf("suma este: %.2f", suma);
    return 0;
}
