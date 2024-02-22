//enunt: https://imgur.com/a/iw0JfkE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//punctul a
typedef struct
{
    char num[25];
    char prenum[25];
    int vrst;
    int nr_t;
    char post[25];
    int nr_joc;
} Echipa;

//punctul b
void citire (Echipa e[],int *n)
{
    int i,nr_juc;
    printf("nr juc\n");
    scanf("%d",&nr_juc);
    for(i=0; i<nr_juc; i++)
    {
        printf("juc: %d\n",i+1);
        getchar();
        printf("nume\n");
        gets(e[i].num);
        printf("prenume\n");
        gets(e[i].prenum);
        printf("varsta:\n");
        scanf("%d",&e[i].vrst);
        printf("nr tricou:\n");
        scanf("%d",&e[i].nr_t);
        getchar();
        printf("pozitie\n");
        gets(e[i].post);
        printf("nr joc:\n");
        scanf("%d",&e[i].nr_joc);
    }
    *n=nr_juc;
}

//punctul c
void lotul(Echipa e[],Echipa lot[],int nr_juc)
{   int i,k=0;
    for (i=0; i<nr_juc; i++)
    {
        if(strcmp(e[i].post,"Extrema stanga")==0 && e[i].vrst<=27 && e[i].vrst>=25)
        {
            lot[k]=e[i];
            k++;
        }
    }
    printf("jucatorii ce indeplinesc cerintele sunt:\n");
    for(i=0; i<k; i++)
    {
        puts(lot[i].num);

        puts(lot[i].prenum);

        printf("%d\n",lot[i].vrst);
        printf("%d\n",lot[i].nr_t);

        puts(lot[i].post);

        printf("%d\n",lot[i].nr_joc);
    }
}

//punctul d
void max(Echipa e[],int nr_juc)
{
    int i;
    int max=0;
    for(i=0; i<nr_juc; i++)
    {
        if(max<e[i].nr_joc)
        {
            max=e[i].nr_joc;
        }
    }
    for(i=0; i<nr_juc; i++)
    {
        if(e[i].nr_joc==max)
        {
            puts(e[i].num);
            puts(e[i].prenum);
            printf("%d\n",e[i].vrst);
            printf("%d\n",e[i].nr_t);
            puts(e[i].post);
            printf("%d\n",e[i].nr_joc);
        }
    }
}
int main()
{
    Echipa e[15],lot[6],jucator_com;
    int nr_juc;
    citire(e,&nr_juc);//punctul b
    lotul(e,lot,nr_juc);//punctul c
    printf("jucatorul/jucatorii cu nr max de jocuri complete este/sunt:\n");
    max(e,nr_juc);//punctul d
    return 0;
}

