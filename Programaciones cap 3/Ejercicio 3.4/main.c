#include <stdio.h>
#include <math.h>

int main (void)
{
    int NUM;
    long CUA, SUC = 0;
    printf("\nIngrese un numero entero -0 para terminar-:\t");
    scanf("%d, &NUM");
    while (NUM)
        /* Observa que la condicion es verdadera mientras el entero es diferente de 0. */
    {
        CUA = pow (NUM, 2);
        printf("%d al cubo es %1d", NUM, CUA);
        SUC = SUC + CUA;
        printf("\nIngrese un numero entero -0 para terminar-:\t ");
        scanf("%d", &NUM);

    }
    printf("\nLa suma de los cuadrados es: %1d, SUC");
}
