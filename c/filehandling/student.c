#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n,i,id[20],m1[20],m2[20],m3[20],m4[20],m5[20];
    char name[20], *nam[20];
    int total[20]={0},k,j;
    FILE *f;
    f = fopen("file2.txt","r");
    if(f == NULL)
    {
        printf("Can't open file");
        exit(1);
    }
    printf("\nEnter the no.of students: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(f,"%d",&id[i]);
        fscanf(f,"%s",name);
        nam[i]=(char*)malloc((sizeof(name)+1)*sizeof(char));
        strcpy(nam[i],name);
        fscanf(f,"%d",&m1[i]);
        fscanf(f,"%d",&m2[i]);
        fscanf(f,"%d",&m3[i]);
        fscanf(f,"%d",&m4[i]);
        fscanf(f,"%d",&m5[i]);
        total[i] = total[i] + m1[i] + m2[i] + m3[i] + m4[i] + m5[i];
    }
    rewind(f);
    j = total[0];
    for(k=1;k<n;k++)
    {
        if(total[k]>j)
        {
            j=total[k];
            i=k;
        }
    }
    printf("\nHighest mark is secured by %s\nID: %d\nTotal: %d\n",nam[i],id[i],total[i]);

    return 0;
}