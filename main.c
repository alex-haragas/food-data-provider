#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_NAME 100
#define MAX_SPECIFIC_FOOD_NAME 100
#define MAX_DRINK_NAME 100

void readmenuitem(char *menuitem);
int main() {
    FILE * datafile;
    datafile=fopen("D:\\CP\\food-data-provider\\data.txt", "w");//for some reason it didn't write until I put the entire path
    int nofood;
    printf("Please input number of food types: \n");
    scanf("%d", &nofood);
    char** food=(char**)malloc(nofood * sizeof(char*));
    printf("Please input food types (each on a new line, may contain spaces):\n");
    for(int i=0;i<nofood;i++)
    {
        food[i]=(char*)malloc(MAX_FOOD_NAME* sizeof(char));
        scanf("%s", food[i]);
    }
    int* nospecificfood=(int *)malloc(nofood* sizeof(int));
    char*** specificfood=(char***)malloc(nofood* sizeof(char**));
    double ** foodprice=(double **)malloc(nofood* sizeof(double *));
    for(int i=0;i<nofood;i++)
    {
        printf("Please input no of specific food for food %s: \n", food[i]);
        scanf("%d",&nospecificfood[i]);
        getchar();
        specificfood[i]=(char**)malloc(nospecificfood[i]* sizeof(char*));
        foodprice[i]=(double *)malloc(nospecificfood[i]* sizeof(double));
        printf("Please input %s specific foods & prices: each line in the format <specific food> (price): \n",food[i]);
        for(int j=0;j<nospecificfood[i];j++)
        {
            specificfood[i][j]=(char *)malloc(MAX_SPECIFIC_FOOD_NAME* sizeof(char));
            readmenuitem(specificfood[i][j]);
            scanf("%lf",&foodprice[i][j]);
            getchar();//reads the ')' after the number
            getchar();
        }
    }
    int nodrink;
    printf("Please input no of drinks:\n");
    scanf("%d",&nodrink);
    getchar();
    char** drink=(char**)malloc(nodrink* sizeof(char*));
    double * drinkprice=(double *)malloc(nodrink* sizeof(double));
    printf("Please input the drinks: each line in the format <drink> (price):\n");
    for(int i=0;i<nodrink;i++)
    {
        drink[i]=(char*)malloc(MAX_DRINK_NAME* sizeof(char));
        readmenuitem(drink[i]);
        scanf("%lf", &drinkprice[i]);
        getchar();//reads the ')' after the number
        getchar();
    }
    fprintf(datafile, "%d:\n", nofood);
    for(int i=0;i<nofood;i++)
    {
        fprintf(datafile, "%s %d: ", food[i],nospecificfood[i]);
        for(int j=0;j<nospecificfood[i];j++)
        {
            fprintf(datafile, " (%s - %.2f)", specificfood[i][j], foodprice[i][j]);
        }
        fprintf(datafile, "\n");
    }
    fprintf(datafile, "%d:\n", nodrink);
    for(int i=0;i<nodrink;i++)
    {
        fprintf(datafile, "(%s - %.2f)", drink[i], drinkprice[i]);
        if(i!=nodrink-1)
            fprintf(datafile, ", ");
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
    fclose(datafile);
    return 0;
}
void readmenuitem(char * menuitem) {
    char c=getchar();
    int i=0;
    while(c!='(')
    {
        menuitem[i]=c;
        c=getchar();
        i++;
    }
    menuitem[i - 1]='\0';
}