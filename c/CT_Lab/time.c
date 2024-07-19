#include <stdio.h>
#include<time.h>
#define LOOP 10000

int main()
{

time_t start, end;
int elapsed;
long int prod;
int a, b;

    a = 100000;
    b = 500000;
start = time(NULL);
for(int i = 0; i<LOOP; i++)
{
prod = a + b;
printf("%d",prod);
}
end = time(NULL);

elapsed = end - start;

printf("\n%ld, %ld, %d\n",start, end, elapsed);
return 0; 
}