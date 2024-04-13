#include <string.h>

struct alumno
{
  int matricula;
  char nombre[20];
  char carrera[20];
  float promedio;
  char direccion[20];

};

void lectura(struct alumno *);

int main(void)
{
    struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queratano"};
    struct alumno *a3, *a4, *a5, a6;
    /* Observa que las variables *a3, *a4y *a5 se declaran como apuntadores de
 ➥tipo estructura alumno. a6 es una variable de tipo estructura alumno. */

 a3 = &a0;         /* En este caso al apuntador de tipo estructura alumno a3
 ➥se le asigna la dirección de la variable de tipo estructura alumno, a0. */

 a4 = new (struct alumno);

 /* Nota que al apuntador a4 es necesario asignarle una dirección de memoria.
 ➥Para tener acceso a los campos de un apuntador de tipo estructura, utiliza uno
 ➥de los dos formatos siguientes:

 apuntador->campo
 o bien
 (*apuntador).campo


 En la lectura de los campos de la variable a4se utilizan como ejemplo ambos
 ➥formatos. */

 printf("\Ingrese la matricula del alumno 4: ");
 scanf("%d", &(*a4).matricula);
 fflush(stdin);
 printf("Ingrese el nombre del alumno 4: ");
 gets(a4->nombre);
 printf("Ingrese la carrera del alumno 4: ");
 gets((*a4).carrera);
 printf("Ingrese promedio del alumno 4: ");
 scanf("%f", &a4->promedio);
 fflush(stdin);
 printf("Ingrese la direccion del alumno 4: ";
 gets(a4->direccion);

 a5 = new (struct alumno);
 lectura(a5);

 /* Eneste caso se pasa el apuntador de tipo estructura alumno
 a5a la función Lectura. */

 lectura(&a6);      /* En este caso se pasa la variable de tipo estructura alumno a6,
 ➥a la función Lectura. Observa que en este caso debemos utilizar el operador de
 ➥dirección para preceder a la variable. */

 printf("\nDatos del alumno 3\n");

  /* Observa la forma de escribir los campos de los apuntadores de tipo
 ➥estructura. */

 printf("%d\t%s\t%s\t%.2f\t%s", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);

 printf("\nDatos del alumno 4\n");
 printf("%d\t%s\t%s\t%.2f\t%s", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);

 printf("\nDatos del alumno 5\n");
 printf("%d\t%s\t%s\t%.2f\t%s", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);

 printf("\nDatos del alumno 6\n");
 printf("%d\t%s\t%s\t%.2f\t%s", a6->matricula, a6->nombre, a6->carrera, a6->promedio, a6->direccion);
}

void lectura(struct alumno *a)
 /* Esta función permite leer los campos de un apuntador de tipo estructura
 ➥alumno. */

 {
    printf("\Ingrese la matricula del alumno: ");
 scanf("%d", &(*a).matricula);
 fflush(stdin);
 printf("Ingrese el nombre del alumno: ");
 gets(a->nombre);
 printf("Ingrese la carrera del alumno : ");
 gets((*a).carrera);
 printf("Ingrese promedio del alumno: ");
 scanf("%f", &a->promedio);
 fflush(stdin);
 printf("Ingrese la direccion del alumno: ";
 gets(a->direccion);

 }