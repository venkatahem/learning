#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

struct teach
{
    char name[30];
    char sub[20];
    char branch[30];
    int exp;
};
void input(struct teach *t)
{
    static int i = 0;
    
        printf("\nTeacher %d\n",i+1);
        printf("Enter name:\n");
        fgets(t[i].name,30,stdin);
        printf("\nEnter the subject teaching:\n");
        fgets(t[i].sub,20,stdin);
        printf("\nEnter the teacher's branch:\n");
        fgets(t[i].branch,30,stdin);
        printf("\nEnter the teacher's experince: ");
        scanf("%d",&t[i].exp);
        getchar();
        i++;
}
void write(struct teach *t)
{
    FILE *f;
    int i,j;
    char a[20] = "Teachers Details";
    char b[30] = "NAME",c[20] = "SUBJECT",d[20] = "BRANCH",e[15] = "EXPERIENCE";
    f = fopen("Teacher_1.txt","w");
    fprintf(f,"%s\n\n",a);
    fprintf(f,"%-25s %-20s %-10s %s\n\n",b,c,d,e);
    for(i=0;i<SIZE;i++)
    {
        strcpy(b,t[i].name);
        j = strlen(b);
        b[j-1] = '\0';
        strcpy(c,t[i].sub);
        j = strlen(c);
        c[j-1] = '\0';
        strcpy(d,t[i].branch);
        j = strlen(d);
        d[j-1] = '\0';
        fprintf(f,"%-25s %-20s %-10s %d\n",b,c,d,t[i].exp);
    }
}
void main()
{
    int i;
    struct teach t[5];
    printf("\nInput the details of %d teachers\n",SIZE);
    for(i=0;i<SIZE;i++)
    input(t);

    write(t);

    printf("\nSuccesfully Completed\n\n");
}