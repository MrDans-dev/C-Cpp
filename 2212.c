#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pierw(int n, int m){
    if(n == 0) return 0;
    return pow(n, 1/m);
}

int suma(int n, int m){
    int x,i;
    for(i=0; i<=n; i++)
        x += pierw(i, m);
    return x;
}

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    printf("%i", suma(n, m));
    return 0;
}
