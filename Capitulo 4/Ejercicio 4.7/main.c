#include <stdio.h>
/* Prueba de parametros por valor. */
int f1 (int);
       /*Prototipo de funcion. el parametro s por valor y de tipo entero. */

void main(void)
{

    int I, K = 4;
    for (I = 1; I <=3; I++)
    {
        printf("\n\nValor de K antes de llamar la funcion: %d", ++K);
        printf("\nValor de K despues de llamar la funcion: %d", f1(K));
    }
}
int f1(int R)
{
    R += R;
    return (R);
}
