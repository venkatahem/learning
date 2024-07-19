#include <stdio.h>
int main()
{
 int a[10][10],b[10][10],sub[10][10],r,c,i,j;    
 printf("enter the number of row=");    
 scanf("%d",&r);    
 printf("enter the number of column=");    
 scanf("%d",&c);    
 printf("enter the first matrix element=\n");    
 for(i=0;i<r;i++)    
  {    
   for(j=0;j<c;j++)   
   {  
    printf("Enter element A[%d][%d]: ",i+1,j+1);     
    scanf("%d",&a[i][j]);    
   }    
  }  
  printf("First matrix\n");
  for(i=0;i<r;i++)    
  {    
   for(j=0;j<c;j++)    
   {    
    printf("%d\t",a[i][j]);    
   }    
   printf("\n");    
  } 
 printf("enter the second matrix element=\n");    
 for(i=0;i<r;i++)    
 {    
  for(j=0;j<c;j++)    
  {    
   printf("Enter element A[%d][%d]: ",i+1,j+1);   
   scanf("%d",&b[i][j]);    
  } 
 }
 printf("Second matrix\n");  
 for(i=0;i<r;i++)    
  {    
   for(j=0;j<c;j++)    
  {    
   printf("%d\t",b[i][j]);    
  }    
  printf("\n");  
  }   
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
  {
    sub[i][j]=a[i][j]-b[i][j];
  }
  printf("After Subtracion\n");
 for(i=0;i<r;i++)    
  {    
   for(j=0;j<c;j++)    
  {    
   printf("%d\t",sub[i][j]);    
  }    
  printf("\n");    
  }    
 return 0;
}