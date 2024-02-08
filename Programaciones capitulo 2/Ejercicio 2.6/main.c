#include <stdio.h>
 /* Incremento de salario.
 El programa, al recibir como dato el nivel de un profesir, incrementa su salario en funcion de la tabla 2.3.

 NIV: variables de tipo entero.
 SAL: variable de tipo real. */
 int main (void)
 {
     float SAL;
     int NIV;
     printf("Ingrese el nivel academico del profesor: ");
     scanf ("%d", &NIV);
     printf("Ingrese el salario:  ");
     scanf("%f", &SAL);
     switch (NIV)
     printf("Infrese el salario:  ");
     scanf("%f", &SAL);
     switch(NIV)
     {
         case 1: SAL = SAL * 1.0035; break;
         case 2: SAL = SAL * 1.0041; break;
         case 3: SAL = SAL * 1.0048; break;
         case 4: SAL = SAL * 1.0053; break;

     }
     printf("\nNivel: %d \tNuevo salario: %8.2f", NIV, SAL);
 }
