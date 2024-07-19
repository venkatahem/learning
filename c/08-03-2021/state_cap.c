#include <stdio.h>
#include <string.h>

int n = 5;

void write_file()
{
    FILE *f;
    int i;
    char a[20];
    f = fopen("State.txt","w");
    for(i=0;i<n;i++)
    {
        printf("\nEnter a state name %d:\n",i+1);
        fgets(a,20,stdin);
        fprintf(f,"%s",a);
    }
    fclose(f);
}
void capitals()
{
    FILE *f1,*f2,*f3;
    char a[20],b[20];
    int i,j;
    f1 = fopen("State.txt","r");
    f2 = fopen("City.txt","r");
    f3 = fopen("State_Capital.txt","w");
    for(i=0;i<n;i++)
    {
        fgets(a,20,f1);
        j = strlen(a);
        a[j-1] = '\0';
        fscanf(f2,"%s",b);
        fprintf(f3,"The capital of the state %s is %s\n",a,b);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
void main()
{
    write_file();
    capitals();
}