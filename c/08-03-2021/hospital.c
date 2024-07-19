#include <stdio.h>
#include <string.h>

int n = 5;
struct patient
{
    char name[20];
    char disease[20];
    int ward;
};
void write(struct patient *p)
{
    int i;
    char a[20] = "Patient Details";
    FILE *f;
    f = fopen("Patient Details.txt","w");
    fprintf(f,"%s\n\n",a);
    for(i=0;i<n;i++)
    {
        fprintf(f,"Name: %s\n",p[i].name);
        fprintf(f,"Ward no: %d\n",p[i].ward);
        fprintf(f,"Disease: %s\n\n",p[i].disease);
    }
    fclose(f);
}
void search(struct patient *p)
{
    char a[20] = "Malaria";
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(a,p[i].disease) == 0)
        {
            printf("\nPatient name: %s\n",p[i].name);
            printf("Ward no: %d\n",p[i].ward);
        }
    }
}
void main()
{
    struct patient p[5] = {{"Alex","Malaria",4},
                            {"Robert","Fever",12},
                            {"Root","Malaria",2},
                            {"Stokes","Stomach Ache",7},
                            {"Taylor","Malaria",15}};
    write(p);
    printf("\nPatients suffering from 'MALARIA'\n");
    search(p);
}
