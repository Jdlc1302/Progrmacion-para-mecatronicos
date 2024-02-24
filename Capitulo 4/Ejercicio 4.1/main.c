#include <stdio.h>

int cubo (void);            /*Prototipo de funcion. */
int I;                      /* Variable global. */

int main(void)
{
    int CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo();
        printf  ("\nEl cubo de %d es: %d", I, CUB);
    }
}

int cubo(void)       /* Declaracion de la funcion. */
/* La funcion calcula el cubo de la variable global I. */
{
    return (I*I*I);

}
