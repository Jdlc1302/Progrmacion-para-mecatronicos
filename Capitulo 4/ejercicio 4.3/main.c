#include <stdio.h>
 /* Conflicto de variables con el mismo nombre. */

 int f1(void);     /* Prototipo de funcion. */
 int K = 5;         /* Variable global. */

 int main(void)
 {
     int I;
     for(I = 1; I <= 3; I++)
        f1();
 }
 int f1(void)

 {
     int K = 2;
     K += K;
     printf("\n\El valor de la variable local es: %d", K);
     ::K = ::K+K;
     printf("\nEl valor de la variable global es: %d", K);
 }

