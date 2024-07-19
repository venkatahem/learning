#include <stdio.h>
#include <time.h>
#define LOOP 10000

int main()
{

clock_t start, end;
float elapsed;
long int prod;
int a, b;

    a = 100000;
    b = 500000;
start = clock();
for(int i = 0; i<LOOP; i++)
{
prod = a + b;
printf("%d",prod);
}
	end = clock();

	elapsed = end - start;

	printf("\n%ld, %ld, %f sec\n",start, end, elapsed/CLOCKS_PER_SEC);
return 0; 
}
