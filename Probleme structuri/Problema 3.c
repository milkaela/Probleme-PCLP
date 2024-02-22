//enunt: https://imgur.com/a/e3O1beS
#include<stdio.h>
#include<string.h>

typedef struct
{
    char brand[25],tip[25];
    float tarie,pret;

} Lada;

void populare(Lada l[],int *nr_beri)
{   int i,n;

    printf("numar beri:\n");
    scanf("%d",&n);

    for (i=0; i<n; i++)
    {   printf("berea %d\n",i+1);
        getchar();

        printf("brand\n");
        gets(l[i].brand);

        printf("tip\n");
        gets(l[i].tip);

        printf("tarie\n");
        scanf("%f",&l[i].tarie);

        printf("pret\n");
        scanf("%f",&l[i].pret);

    }
    *nr_beri=n;
}

void disp(Lada l[],int nr_beri)
{   int i,bl=0,br=0,al=0,ipa=0,na=0;
    for(i=0; i<nr_beri; i++)
    {
        if(strcmp(l[i].tip,"blonda")==0)
        {
            bl++;
        }
        if(strcmp(l[i].tip,"bruna")==0)
        {
            br++;
        }
        if(strcmp(l[i].tip,"alba")==0)
        {
            al++;
        }
        if(strcmp(l[i].tip,"IPA")==0)
        {
            ipa++;
        }
        if(strcmp(l[i].tip,"N/A")==0)
        {
            na++;
        }
    }
    printf(" sunt: %d sticle bere blonda, %d sticle bere bruna, %d sticle bere alba, %d sticle bere IPA, %d sticle bere N/A.",bl,br,al,ipa,na);
}

float pret(Lada l[],int nr_beri,char *tip_bere)
{   int i,nr;
    float s=0;
    for(i=0; i<nr_beri; i++)
    {
        {
            if(strcmp(l[i].tip,tip_bere)==0)


                s=s+l[i].pret;
            nr++;
        }
    }
    float pret_mediu=(float)(s/nr);
    return pret_mediu;
}

int main()
{
    Lada l[9];
    char tip_bere[25];
    int nr_beri;
    float pretul;

    populare(l,&nr_beri);

    printf("\ncalculam nr de sortimente din fiecare bere,");
    disp(l,nr_beri);

    getchar();

    printf("\nintroduceti un tip de bere:\n");
    gets(tip_bere);

    pretul=pret(l,nr_beri,&tip_bere);
    printf("\npretul mediu pt acest tip de bere este: %0.2f \n",pretul);

    return 0;
}
