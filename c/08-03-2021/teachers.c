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
    int i;
    char a[20] = "Teachers Details";
    f = fopen("Teacher.txt","w");
    fprintf(f,"%s\n\n",a);
    for(i=0;i<SIZE;i++)
    {
        fprintf(f,"Name: %s",t[i].name);
        fprintf(f,"Subject teching: %s",t[i].sub);
        fprintf(f,"Teacher's branch: %s",t[i].branch);
        fprintf(f,"Experience in years: %d\n\n",t[i].exp);
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