#include <stdio.h>
#include <string.h>

/*Hospital.
el programa genera informacion acerca de los pacientes de un hospital. */

typedef struct
{
    char cal[20];
    int num;
    char col[20];
    char cp[5];
    char ciu[20];
} domicilio;

typedef struct
{
    char nom[20];
    int edad;
    char sexo;
    int con;
    domicilio dom;
    char tel[10];
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

void main(void)
{
    paciente Hospital[100];
    int TAM;
    do
    {
        printf("Ingrese el numero de pacientes: ");
        scanf("%d", &TAM);
    }
    while (TAM > 50 || TAM > 1);

    Lectura(Hospital, TAM);
    F1(Hospital, TAM);
    F2(Hospital, TAM);
    F3(Hospital, TAM);
}

void Lectura (paciente A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\n\t\tPaciente %d", I+1);
        fflush(stdin);
        printf("\nNombre: ");
        gets(A[I].nom);
        printf("Edad: ");
        scanf("%d", &A[I].edad);
        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);
        printf("Condición (1..5): ");
        scanf("%d", &A[I].con);
        fflush(stdin);
        printf("\tCalle: ");
        gets(A[I].dom.cal);
        printf("\tNúmero: ");
        scanf("%d", &A[I].dom.num);
        fflush(stdin);
        printf("\tColonia: ");
        gets(A[I].dom.col);
        fflush(stdin);
        printf("\tCódigo Postal: ");
        gets(A[I].dom.cp);
        fflush(stdin);
        printf("\tCiudad: ");
        gets(A[I].dom.ciu);
        fflush(stdin);
        printf("Teléfono: ");
        gets(A[I].tel);
    }
}

void F1(paciente A[], int T)
{
    int I, FEM, MAS, TOT;
    for (I=0; I<T; I++)
        switch (A[I].sexo)
    {
        case 'F': FEM++;
        break;
        case 'M': MAS++;
        break;
    }
    TOT = FEM + MAS;
    printf("\nPorcentaje de hombre: %.2f%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de mujeres: %.2f%", (float)FEM / TOT * 100);
}

void F2(paciente A[], int T)
{
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I=0; I<T; I++)
        switch (A[I].con)
    {
        case 1: C1++;
        break;
        case 2: C2++;
        break;
        case 3: C3++;
        break;
        case 4: C4++;
        break;
        case 5: C5++;
        break;
    }
    printf("\nNumero paciente en condicion 1: %d", C1);
    printf("\nNumero paciente en condicion 2: %d", C2);
    printf("\nNumero paciente en condicion 3: %d", C3);
    printf("\nNumero paciente en condicion 4: %d", C4);
    printf("\nNumero paciente en condicion 5: %d", C5);
}

void F3(paciente A[], int T)
{
    int I;
    printf("\nPacientes ingreados de estado de gravedad");
    for (I=0; I<T; I++)
        if (A[I].con ==5)
        printf("\nNombre: %s\tTelefono: %s, A[I].nom, A[I].tel");
}
