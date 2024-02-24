#include <stdio.h>

int F1(int, int *);

int a = 3;
int b = 7;
int c = 4;
int d = 2;

void main(void)
{
    a = F1 (c, &d);
    printf("\n%d %d %d %d", a, b, c, d);
    c = 3;
    c = F1 (a, &c);
    printf("\n%d %d %d %d", a, b, c, d);
}

int F1 (int X, int *Y)
{
    int a;
    a = X * *Y;
    c++;
    b += *Y;
    printf("\n%d %d %d %d", a, b, c, d);
    *Y--;
    return(c);
}
