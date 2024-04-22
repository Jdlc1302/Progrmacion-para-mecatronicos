
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Este programa calcula el costo x km de un viaje en carro, junto con el valor actual del vehiculo*/

struct Vehiculo /*Definición de la estructura Vehiculo para almacenar datos relacionados con un vehículo*/
{
    float distancia;
    float km_por_litro;
    float valor_adquisicion;
    float precio_litro_combustible;
    float depreciacion;
    float mantenimiento;
};


void leerDatos(struct Vehiculo *vehiculo) /*Función para leer los datos del vehículo desde el usuario*/

{
    printf("\nBienvenidos, si desea consultar datos anteriores por favor pulsar 'S' o 'N', de lo contrario precedeer a introducior los datos solicitados. \n"); /*Mensaje de bienvenida y solicitud de datos al usuario*/

    printf("\nIngrese la distancia del viaje en kilometros : ");
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

void guardarDatos(struct Vehiculo vehiculo) /*Función para guardar los datos del vehículo en un archivo*/
{
    FILE *archivo;
    archivo = fopen("dato_vehiculo.txt", "a"); /*Guarda los datos del vehículo en un archivo llamado "dato_vehiculo.txt"*/
    if (archivo != NULL)
    {
        fprintf(archivo, "%.2f %.2f %.2f %.2f %.2f %.2f\n", /*Función para mostrar los datos del vehículo en la consola*/
                vehiculo.distancia, vehiculo.km_por_litro, vehiculo.valor_adquisicion,
                vehiculo.precio_litro_combustible, vehiculo.depreciacion, vehiculo.mantenimiento);
        fclose(archivo);
    }
    else
    {
        printf("Error al abrir el archivo.");
    }
}

void mostrarDatos(struct Vehiculo vehiculo) /*Muestra los datos del vehículo en formato tabular en la consola*/
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

void mostrarProyeccion(struct Vehiculo vehiculo) /*Función para mostrar la proyección de costos relacionados con el vehículo en la consola*/
{
    printf("------------------------------------------");
    printf("\nProyeccion:\n");
    printf("| %-20s | %-15s |\n", "Parametro", "Valor");
    printf("|----------------------|-----------------|\n");
    printf("| %-20s | %-15.2f |\n", "Consumo (litros)", vehiculo.distancia / vehiculo.km_por_litro);
    printf("| %-20s | %-15.2f |\n", "Costo por kilometro", vehiculo.precio_litro_combustible / vehiculo.km_por_litro);
    printf("| %-20s | %-15.2f |\n", "Kilometros por galon", vehiculo.km_por_litro * 0.264172);
    printf("| %-20s | %-15.2f |\n", "Costo total viaje", (vehiculo.distancia / vehiculo.km_por_litro) * vehiculo.precio_litro_combustible);  /*Calcula y muestra la proyección de costos relacionados con el vehículo en la consola*/
    printf("| %-20s | %-15.2f |\n", "Valor actual",(vehiculo.valor_adquisicion - vehiculo.depreciacion)+ vehiculo.mantenimiento);
    printf("------------------------------------------\n");

}

void leerDesdeArchivo(struct Vehiculo *vehiculo) /*Función para leer los datos del vehículo desde un archivo*/
{
    FILE *archivo;
    archivo = fopen("dato_vehiculo.txt", "r"); /*Lee los datos del vehículo desde un archivo llamado "dato_vehiculo.txt"*/
    if (archivo != NULL)
    {
        fscanf(archivo, "%f %f %f %f %f %f",
               &vehiculo->distancia, &vehiculo->km_por_litro, &vehiculo->valor_adquisicion,
               &vehiculo->precio_litro_combustible, &vehiculo->depreciacion, &vehiculo->mantenimiento); /*Lee los datos del vehículo desde un archivo llamado "dato_vehiculo.txt"*/
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
        leerDatos(&vehiculo); /* Llama a la función para que el usuario ingrese los datos del vehículo*/

        printf("¿Desea guardar los datos del vehiculo? (S/N): ");
        scanf(" %c", &opcion);
        if (opcion == 'S' || opcion == 's') /*Si el usuario elige guardar, llama a la función para guardar los datos en un archivo*/
        {
            guardarDatos(vehiculo);
        }
        else if (opcion == 'N' || opcion == 'n') /*Si el usuario elige no guardar, muestra un mensaje*/
        {
            printf("No se guardaron los datos del vehiculo.\n");
        }
        else
        {
            printf("Opcion no valida.\n"); /*Si el usuario ingresa una opción no válida, muestra un mensaje y termina el programa*/
            return 1;
        }

        mostrarDatos(vehiculo); /*Muestra los datos del vehículo en la consola*/
        mostrarProyeccion(vehiculo); /*Muestra la proyección de costos relacionados con el vehículo en la consola*/

        printf("¿Desea salir o continuar? (S para salir, c para continuar): ");
        scanf(" %c", &opcion);

        if (opcion == 'S' || opcion == 's') /*Si el usuario elige salir, muestra un mensaje y termina el programa*/
        {
            printf("Paseme con 100 profesor xfa.\n");
            return 0;
        }

        if (opcion == 'C' || opcion == 'c') /*Si el usuario elige utilizar datos del archivo, llama a la función para leer desde el archivo*/
        {
            printf("¿Desea utilizar los datos del archivo o ingresar nuevos? (A para archivo, cualquier otra tecla para continuar): ");
            scanf(" %c", &opcion);
            if (opcion == 'A' || opcion == 'a')
            {
                leerDesdeArchivo(&vehiculo);
            }
        }

    }
    while (opcion != 'S' && opcion != 's'); /*Continúa el ciclo mientras el usuario no elija salir*/

    return 0;
}
