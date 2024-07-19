#include <stdio.h>
int add(int ,int);
int sub(int ,int);
int mul(int ,int);
int div(int ,int);
int mod(int ,int);

int main()
{
    int a,b;
    char c;
    int (*ptr[5])(int ,int)={add,sub,mul,div,mod};
    printf("Enter choice:\nA for addition\nS for sub\nM for mul\nD for div\nU for modulu divison\n");
    scanf("%c",&c);
    printf("Enter two numbers:\n");
    scanf("%d%d",&a,&b);
    switch (c)
    {
        case 'A' :    printf("Value = %d",ptr[0](a,b));
                      break;
        case 'S' :    printf("Value = %d",ptr[1](a,b));
                      break;
        case 'M' :    printf("Value = %d",ptr[2](a,b));
                      break;
        case 'D' :    printf("Value = %d",ptr[3](a,b));
                      break;
        case 'U' :    printf("Value = %d",ptr[4](a,b));
                      break;              
    }

    return 0;
}
int add(int a,int b){ return (a+b); }

int sub(int a,int b){ return (a-b); }

int mul(int a,int b){ return (a*b); }

int div(int a,int b){ return (a/b); }

int mod(int a,int b){ return (a%b); }