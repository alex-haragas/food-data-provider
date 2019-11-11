#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_NAME 100
#define MAX_SPECIFIC_FOOD_NAME 100
#define MAX_DRINK_NAME 100
void readmenuitem(char *thing);
int main() {
    int nofood;
    printf("Please input number of food types: \n>");
    scanf("%d", &nofood);
    char** food=(char**)malloc(nofood * sizeof(char*));
    printf("Please input food types (each on a new line, may contain spaces):\n");
    for(int i=0;i<nofood;i++)
    {
        printf(">");
        food[i]=(char*)malloc(MAX_FOOD_NAME* sizeof(char));
        scanf("%s", food[i]);
    }
    int* nospecificfood=(int *)malloc(nofood* sizeof(int));
    char*** specificfood=(char***)malloc(nofood* sizeof(char**));
    double ** foodprice=(double **)malloc(nofood* sizeof(double *));
    for(int i=0;i<nofood;i++)
    {
        printf("Please input no of specific food for food %c%s%c: \n>",'"', food[i],'"');
        scanf("%d",&nospecificfood[i]);
        getchar();
        specificfood[i]=(char**)malloc(nospecificfood[i]* sizeof(char*));
        foodprice[i]=(double *)malloc(nospecificfood[i]* sizeof(double));
        printf("Please input %c%s%c specific foods & prices: each line in the format <specific food> (price): \n",'"', food[i],'"');
        for(int j=0;j<nospecificfood[i];j++)
        {
            printf(">");
            specificfood[i][j]=(char *)malloc(MAX_SPECIFIC_FOOD_NAME* sizeof(char));
            readmenuitem(specificfood[i][j]);
            scanf("%lf",&foodprice[i][j]);
            getchar();
            getchar();
        }
    }
    int nodrink;
    printf("Please input no of drinks:\n>");
    scanf("%d",&nodrink);
    getchar();
    char** drink=(char**)malloc(nodrink* sizeof(char*));
    double * drinkprice=(double *)malloc(nodrink* sizeof(double));
    printf("Please input the drinks: eac line in the format <drink> (price):\n");
    for(int i=0;i<nodrink;i++)
    {
        printf(">");
        drink[i]=(char*)malloc(MAX_DRINK_NAME* sizeof(char));
        readmenuitem(drink[i]);
        scanf("%lf", &drinkprice[i]);
        getchar();
        getchar();
    }
    printf("The food data is:");
    for(int i=0;i<nofood;i++)
    {
        printf("%s:",food[i]);
        for(int j=0;j<nospecificfood[i];j++)
        {
            printf(" (%s - %.2f)",specificfood[i][j],foodprice[i][j]);
        }
        printf("\n");
    }
    printf("The drinks data is:\ndrinks: ");
    for(int i=0;i<nodrink;i++)
    {
        printf("%s",drink[i]);
        if(i!=nodrink-1)
            printf(", ");
    }
    printf("\nprice: ");
    for(int i=0;i<nodrink;i++)
    {
        printf("%.2f",drinkprice[i]);
        if(i!=nodrink-1)
            printf(", ");
    }
    for(int i=0;i<nodrink;i++)
        free(drink[i]);
    free(drinkprice);
    free(drink);
    for(int i=0;i<nofood;i++)
    {
        for(int j=0;j<nospecificfood[i];j++)
            free(specificfood[i][j]);
        free(foodprice[i]);
        free(specificfood[i]);
        free(food[i]);
    }
    free(food);
    return 0;
}
void readmenuitem(char * thing) {
    char c=getchar();
    int i=0;
    while(c!='(')
    {
        thing[i]=c;
        c=getchar();
        i++;
    }
    thing[i-1]='\0';
}