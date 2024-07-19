#include <stdio.h> 
int main() 
{ 
    FILE *fp; 
    int count = 0;  
    char filename[100]; 
    char c;
    printf("Enter the filename of the file you want to open:");
    scanf("%s", filename); 
    fp = fopen(filename, "r"); 
    if (fp == NULL) 
    { 
        printf("Could not open file %s\n", filename); 
        return 0; 
    } 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n') 
            count = count + 1; 
            
    fclose(fp); 
    printf("The file %s has %d lines\n ", filename, count); 
    return 0; 
}
