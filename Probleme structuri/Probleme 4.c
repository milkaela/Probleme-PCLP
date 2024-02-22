//enunt: https://imgur.com/a/PW6qJX4
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//punctul a
typedef struct
{   char nume[25];
    char prenume[25];
    int vrst;
} Lucrator;

typedef struct
{   int cod_op;
    int nr_op;
    int val_op;
    Lucrator l;
} Operatie;

//punctul b
void citire (Operatie o[],int *n_op)
{   int i,n;
    printf("nr op:\n");
    scanf("%d",&n);

    for (i=0; i<n; i++)
    {
        printf("operatia nr %d\n",i+1);
        printf("cod op\n");
        scanf("%d",&o[i].cod_op);

        printf("nr op\n");
        scanf("%d",&o[i].nr_op);

        printf("val op\n");
        scanf("%d",&o[i].val_op);
        getchar();

        printf("nume lucrator:\n");
        gets(o[i].l.nume);

        printf("prenume lucrator:\n");
        gets(o[i].l.prenume);

        printf("varsta:\n");
        scanf("%d",&o[i].l.vrst);
    }
    *n_op=n;
}

//punctul c
int suma(Operatie o[],int nrop)
{   int i,s=0,sumal=0;
    char nume1[25];
    char prenume1[25];
    printf("\nintroduceti un nume si un prenume:\n");
    scanf("%s %s",nume1,prenume1);
    for(i=0; i<nrop; i++)
    {
        if (strcmp(o[i].l.nume,nume1)==0 && strcmp(o[i].l.prenume,prenume1)==0)
        {
            s=s+o[i].nr_op*o[i].val_op;

        }
    }
    sumal=s*0.1;
    return sumal;
}

//punctul d
void op_descresc(Operatie o[],int nrop)
{   int i,j;
    Operatie aux;

    for(i=0; i<nrop-1; i++)
    {
        for (j=i+1; j<nrop; j++)
        {
            if(o[i].l.vrst<o[j].l.vrst)
            {
                aux=o[i];
                o[i]=o[j];
                o[j]=aux;

            }
        }
    }
}

int main()
{
    Operatie o[10];
    int i,nrop,sum;

    citire(o,&nrop);

    sum=suma(o,nrop);
    printf("\n\n(c)lucratorul va fi platit cu: %d\n",sum);

    printf("\n\n(d)ordonarea descresc dupa varsta este:\n");
    op_descresc(o,nrop);
    for(i=0; i<nrop; i++)
    {

        printf("cod op\n");
        printf("%d\n",o[i].cod_op);

        printf("nr op\n");
        printf("%d\n",o[i].nr_op);

        printf("val op\n");
        printf("%d\n",o[i].cod_op);

        printf("nume lucrator:\n");
        puts(o[i].l.nume);

        printf("prenume lucrator:\n");
        puts(o[i].l.prenume);

        printf("varsta:\n");
        printf("%d\n",o[i].l.vrst);
        printf("\n");

    }
    return 0;
}
