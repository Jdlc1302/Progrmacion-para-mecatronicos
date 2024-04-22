
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vehiculo
{
    float distancia;
    float km_por_litro;
    float valor_adquisicion;
    float precio_litro_combustible;
    float depreciacion;
    float mantenimiento;
};


void leerDatos(struct Vehiculo *vehiculo)

{
    printf("\nBienvenidos, si desea consultar datos anteriores por favor pulsar 'S' o 'N', de lo contrario precedeer a introducior los datos solicitados. \n");

    printf("\nIngrese la distancia del viaje en kilometros: ");
    scanf("%f", &vehiculo->distancia);
    printf("Ingrese los kilometros por litro del vehiculo: ");
    scanf("%f", &vehiculo->km_por_litro);
    printf("Ingrese el valor de adquisicion del vehiculo: ");
    scanf("%f", &vehiculo->valor_adquisicion);
    printf("Ingrese el precio por litro de combustible: ");
    scanf("%f", &vehiculo->precio_litro_combustible);
    printf("Ingrese la depreciacion del vehiculo: ");
    scanf("%f", &vehiculo->depreciacion);
    printf("Ingrese el costo de mantenimiento: ");
    scanf("%f", &vehiculo->mantenimiento);
}

void guardarDatos(struct Vehiculo vehiculo)
{
    FILE *archivo;
    archivo = fopen("dato_vehiculo.txt", "a");
    if (archivo != NULL)
    {
        fprintf(archivo, "%.2f %.2f %.2f %.2f %.2f %.2f\n",
                vehiculo.distancia, vehiculo.km_por_litro, vehiculo.valor_adquisicion,
                vehiculo.precio_litro_combustible, vehiculo.depreciacion, vehiculo.mantenimiento);
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo.");
    }
}

void mostrarDatos(struct Vehiculo vehiculo)
{
    printf("------------------------------------------");
    printf("\nDatos del vehiculo:\n");
    printf("| %-25s | %-10s |\n", "Parametro", "Valor");
    printf("|---------------------------|------------|\n");
    printf("| %-25s | %-10.2f |\n", "Distancia (km)", vehiculo.distancia);
    printf("| %-25s | %-10.2f |\n", "Km por litro", vehiculo.km_por_litro);
    printf("| %-25s | %-10.2f |\n", "Valor adquisicion", vehiculo.valor_adquisicion);
    printf("| %-25s | %-10.2f |\n", "Precio por litro", vehiculo.precio_litro_combustible);
    printf("| %-25s | %-10.2f |\n", "Depreciacion", vehiculo.depreciacion);
    printf("| %-25s | %-10.2f |\n", "Mantenimiento", vehiculo.mantenimiento);
    printf("------------------------------------------\n");
}

void mostrarProyeccion(struct Vehiculo vehiculo)
{
    printf("------------------------------------------");
    printf("\nProyeccion:\n");
    printf("| %-20s | %-15s |\n", "Parametro", "Valor");
    printf("|----------------------|-----------------|\n");
    printf("| %-20s | %-15.2f |\n", "Consumo (litros)", vehiculo.distancia / vehiculo.km_por_litro);
    printf("| %-20s | %-15.2f |\n", "Costo por kilometro", vehiculo.precio_litro_combustible / vehiculo.km_por_litro);
    printf("| %-20s | %-15.2f |\n", "Kilometros por galon", vehiculo.km_por_litro * 0.264172);
    printf("| %-20s | %-15.2f |\n", "Costo total viaje", (vehiculo.distancia / vehiculo.km_por_litro) * vehiculo.precio_litro_combustible);
    printf("| %-20s | %-15.2f |\n", "Valor actual",(vehiculo.valor_adquisicion - vehiculo.depreciacion)+ vehiculo.mantenimiento);
    printf("------------------------------------------\n");

}

void leerDesdeArchivo(struct Vehiculo *vehiculo)
{
    FILE *archivo;
    archivo = fopen("dato_vehiculo.txt", "r");
    if (archivo != NULL)
    {
        fscanf(archivo, "%f %f %f %f %f %f",
               &vehiculo->distancia, &vehiculo->km_por_litro, &vehiculo->valor_adquisicion,
               &vehiculo->precio_litro_combustible, &vehiculo->depreciacion, &vehiculo->mantenimiento);
        fclose(archivo);
    }
    else
    {
        printf("El archivo no existe o no se puede abrir.\n");
    }
}

int main()
{
    char opcion;
    struct Vehiculo vehiculo;

    do
    {
        leerDatos(&vehiculo);

        printf("¿Desea guardar los datos del vehiculo? (S/N): ");
        scanf(" %c", &opcion);
        if (opcion == 'S' || opcion == 's')
        {
            guardarDatos(vehiculo);
        }
        else if (opcion == 'N' || opcion == 'n')
        {
            printf("No se guardaron los datos del vehiculo.\n");
        }
        else
        {
            printf("Opcion no valida.\n");
            return 1;
        }

        mostrarDatos(vehiculo);
        mostrarProyeccion(vehiculo);

        printf("¿Desea salir o continuar? (S para salir, c para continuar): ");
        scanf(" %c", &opcion);

        if (opcion == 'S' || opcion == 's')
        {
            printf("Paseme con 100 profesor xfa.\n");
            return 0;
        }

        if (opcion == 'C' || opcion == 'c')
        {
            printf("¿Desea utilizar los datos del archivo o ingresar nuevos? (A para archivo, cualquier otra tecla para continuar): ");
            scanf(" %c", &opcion);
            if (opcion == 'A' || opcion == 'a')
            {
                leerDesdeArchivo(&vehiculo);
            }
        }

    }
    while (opcion != 'S' && opcion != 's');

    return 0;
}
