#include <stdio.h>
struct search
{
    int a;
    struct search *next;
} *s;
void find(int x)
{
    int y=0;
    while(s!=NULL&&y==0)
    {
        if(x == s->a)
        {
            y=1;
        }
        else
        {
            s = s->next;
        }
    }
    if(y)
    printf("\nPresent!");
    else
    printf("\nNot present in the structure");
}
int main()
{
    int x;
    struct search s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,*s;
    s1.a=100;s2.a=200;s3.a=300;s4.a=400;
    s5.a=500;s6.a=600;s7.a=700;s8.a=800;
    s9.a=900;s10.a=1000;
    s1.next=&s2;s2.next=&s3;s3.next=&s4;s4.next=&s5;s5.next=&s6;s6.next=&s7;s7.next=&s8;
    s8.next=&s9;s9.next=&s10;s10.next=NULL;
    printf("Enter a integer to check if it is present in the structure: ");
    scanf("%d",&x);
    find(x);

    return 0;
}
