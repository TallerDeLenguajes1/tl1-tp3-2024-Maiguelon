#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} typedef Cliente;

float montoTotal(Producto *producto);

int main() {
    
    srand(time(NULL));
    int cantidadClientes;

    // Lista de productos
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillo", "Caramelo", "Bebidas"};
    char *buffer = (char *)malloc(sizeof(char) * 100);

    do {
        printf("Introduzca la cantidad de clientes: ");
        scanf("%d", &cantidadClientes);
        fflush(stdin);
    } while (cantidadClientes < 1 || cantidadClientes > 5); // control de cantidad de clientes

    float *montos = (float *)malloc(cantidadClientes * sizeof(float)); // Almacenamiento montos
    float *total = (float *)malloc(cantidadClientes * sizeof(float)); //Almaceno los montos totales a pagar de cada cliente

    Cliente *listaClientes = (Cliente *)malloc(sizeof(Cliente) * cantidadClientes);

    for (int i = 0; i < cantidadClientes; i++)
    {
        listaClientes[i].ClienteID = i + 1; // Asigno directamente el número de id
          
        printf("Introduzca los datos del cliente\n");
        printf("Introduzca el nombre del cliente %d: ", listaClientes[i].ClienteID);
        gets(buffer);

        listaClientes[i].NombreCliente = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(listaClientes[i].NombreCliente, buffer); // paso el nombre a la lista

        // Defino los productos a pedir
        listaClientes[i].CantidadProductosAPedir = rand() %5 + 1;

        // Reservo memoria para los productos
        listaClientes[i].Productos = (Producto *)malloc(sizeof(Producto) * listaClientes[i].CantidadProductosAPedir);

        // Cargo los productos
        for (int j = 0; j < listaClientes[i].CantidadProductosAPedir; j++)
        {   
            // El id de los productos arranca en 1
            listaClientes[i].Productos[j].ProductoID = j + 1;

            // Se define aleatoreamente la cantidad de productos

            listaClientes[i].Productos[j].Cantidad = rand() %10 + 1;

            //Se define aleatoreamente el precio
            listaClientes[i].Productos[j].PrecioUnitario = rand() %91 + 10; // entre 10 y 100

            //Saco el índice del producto para usar en el arreglo de Tiposproducto
            int indice = rand() %5;

            // Reservo memoria para el producto
            listaClientes[i].Productos[j].TipoProducto = (char *)malloc(sizeof(char) * (strlen(TiposProductos[indice]) + 1));
            strcpy(listaClientes[i].Productos[j].TipoProducto, TiposProductos[indice]); // copio el producto en la lista

            // Determino el precio total
            montos[j] = montoTotal(&(listaClientes[i].Productos[j]));

            //Suma de los montos de cada cliente
            total[i] += montos[j];    //Suma de los montos de todos los productos
        }
    }
    free(buffer);
    free(montos);

    // Impresion de lo cargado
    printf("Info de los clientes ingresados:\n");

    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("Cliente ID: %d\n", listaClientes[i].ClienteID);

        puts(listaClientes[i].NombreCliente);
        free(listaClientes[i].NombreCliente); // Libero la memoria asignada al nombre

        printf("\n\t");   //Salto de linea estetico

        printf("Productos del Cliente:\n");

        for (int j = 0; j < listaClientes[i].CantidadProductosAPedir; j++)
        {
            printf("\t\t--> Producto  ID %d\n", listaClientes[i].Productos[j].ProductoID);  
            printf("Nombre del Producto: %s\n", listaClientes[i].Productos[j].TipoProducto);
            printf("Cantidad de Unidades Pedidas: %d\n", listaClientes[i].Productos[j].Cantidad);
            printf("Costo Pagado por Unidad: %f\n", listaClientes[i].Productos[j].PrecioUnitario);
        }

        printf("Total a Pagar por el Cliente ID %d:\n %.2f\n", listaClientes[i].ClienteID, total[i]);
    }
    free(total);
    free(listaClientes);
    return 0;
}

    float montoTotal(Producto *producto) {
        float monto = producto->PrecioUnitario * producto->Cantidad;
        return monto;
    }