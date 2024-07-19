#include <stdio.h>

int main()
{
    char str[20];
    char *a;
    int vowels=0,con=0;
    a=str;
    printf("\nEnter a string: ");
    gets(str);
    for(a;*a!='\0';a++)
    {
        if(*a=='a'||*a=='e'||*a=='i'||*a=='o'||*a=='u'||*a=='A'||*a=='E'||*a=='I'||*a=='O'||*a=='U')
        {
            vowels++;
        }
        else
        {
            con++;
        }
    }
    printf("\nNo.of vowels are %d and no.of consonants are %d\n",vowels,con);

    return 0;
}