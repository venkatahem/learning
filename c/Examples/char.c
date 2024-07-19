#include <stdio.h>
#include <string.h>
struct data
{
   char a[10];
};

void change(struct data *d)
{
   int i;
   int j;
   i = 0;
   j = 1;
   //char temp[10] = d[j].a;
   //*d[i].a = d[j].a;
   strcpy(d[i].a, d[j].a);
   //fgets(d[i].a, 10, temp);
   printf("%s", d[i].a);
}

int main()
{
   struct data d[3];

   printf("1: ");
   fgets(d[0].a, 10, stdin);
   printf("1: ");
   fgets(d[1].a, 10, stdin);
   change(d);
   return 0;
}