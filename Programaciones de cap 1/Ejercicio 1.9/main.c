#include <stdio.h>

/* Estancia
El programa, al recibir como dato la superficie de una estancia expresada en acres, la convierte a hectareas.

ECA: variable de tipo real. */

int main (void)
{
    float ECA;
    printf("Ingrese la extension de la estancia");
    scanf("%f" , &ECA);
    ECA = ECA * 4047 / 1000;
    printf("\nExtension de la estancia en hectareas: %5.2f" , ECA);
}
