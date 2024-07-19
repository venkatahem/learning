#include <stdio.h>

void Encode()
{
  char str[100];
  int i;
  printf("\nEnter a string:\n");
  fgets(str,100,stdin);
	printf("\n");
	printf("Encoded Text:\n");
      	for(i=0;str[i]!='\0';i++)
      	{
          if(str[i]!=' ')
            {
      	    	str[i] = str[i] - 10;
    	      }
    	      printf("%c",str[i]);
    	}
    	printf("\n");
}
void Decode()
{
  char str[100];
  int i;
  printf("Enter a string:\n");
  fgets(str,100,stdin);
        printf("\n");
        printf("Decoded Text:\n");
  	for(i=0;str[i]!='\0';i++)
  	{
    	  if(str[i]!=' ')
    	  {
      	    str[i] = str[i] + 10;
    	  }
    	  printf("%c",str[i]);
  	}
  	printf("\n");
}
void main()
{
  int x;
  do
  {
    printf("1 ==> Encode\n2 ==> Decode\n3 ==> Quit\n\nEnter: ");
    scanf("%d",&x);
    getchar();
    if(x == 1)
    {
      Encode();
    }
    else if(x == 2)
    {
      Decode();
    }
  }while(x !=3);
}
