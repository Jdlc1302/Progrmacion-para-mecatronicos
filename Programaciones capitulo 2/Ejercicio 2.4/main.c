#include <stdio.h>

/* Incremento de precio.
el programa, al recibir como dato el precio de un producto, incrementa al mismo un 11% si es menor de 1500$ y 8% en caso contrario (mayor o igual).

PRE y NPR: variables de tipo real. */

int main (void)
{
    float PRE, NPR;
    printf ("ingrese el precio del producto: ");
    scanf ("%f", &PRE);
    if (PRE < 1500)
        NPR = PRE*1.11;
    else
        NPR=PRE*1.08;
    printf("\nNuesvo precio del producto: %8.2f", NPR);


}
