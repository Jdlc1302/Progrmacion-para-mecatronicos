#include <stdio.h>
#include <string.h>
#include <ctype.h>

void minymar(char *cadena);

int main(void)
{
    int i, n;
    char FRA[20][50];
    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);
    for (i=0;i<n;i++)
    {
        printf("\Ingrese la ,inea %d de texto: ", i+1);
        fflush(stdin);
        gets(FRA[i]);
    }
    printf("\n\n");
    for (i=0; i<n; i++)
        minymar(FRA[i]);
}

void minymar(char *cadena)
{
    int i=0, mi=0, ma=0;
    while(cadena[i] != '\0')
    {
        if (islower(cadena[i]))
            mi++;
        else
            if (isupper(cadena[i]))
            ma++;
        i++;
    }
    printf("\n\Numero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);
}
