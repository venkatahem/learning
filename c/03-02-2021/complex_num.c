#include <stdio.h>
struct complex
{
   int real, img;
};
int main()
{
   struct complex a,b,c;
   int x;

   printf("\nEnter the real and imaginary part of first complex number:\n");
   scanf("%d%d", &a.real, &a.img);
   printf("\nEnter the real and imaginary part of second complex number:\n");
   scanf("%d%d", &b.real, &b.img);
   printf("\n1st complex number: (%d) + (%di)\n",a.real,a.img);
   printf("\n2nd complex number: (%d) + (%di)\n",b.real,b.img);
   printf("\nEnter '1' for the additon of two complex numbers or '0' for substraction\n");
   scanf("%d",&x);
   if(x==1)
   {
        c.real = a.real + b.real;
        c.img = a.img + b.img;
        printf("Sum of the complex numbers: (%d) + (%di)\n", c.real, c.img);
   }
   else
   {
       c.real = a.real - b.real;
       c.img = a.img - b.img;
       printf("Substraction of the complex numbers: (%d) + (%di)\n", c.real, c.img);
   }    
   return 0;
}