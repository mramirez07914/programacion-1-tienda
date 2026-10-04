#include <stdio.h>

int main()
{
    // Datos del producto
    int id;
    char nombre[50];
    int stock;
    float precio;

    // Datos de las operaciones
    int opcion;
    int cantidad;
    float ganancias = 0;
    float descuento;
    float totalVenta;

    printf("\n==== REGISTRO DEL PRODUCTO ====\n");

    do
    {
        printf("Ingrese el ID del producto: ");

        if (scanf("%d", &id) != 1)
        {
            printf("Error: Debe ingresar un numero.\n");

            while (getchar() != '\n')
            {
            }

            id = -1;
        }
        else if (id <= 0)
        {
            printf("Error: El ID debe ser mayor que 0.\n");
        }

    } while (id <= 0);

    printf("Ingrese el nombre del producto: ");
    scanf(" %49[^\n]", nombre);

    do
    {
        printf("Ingrese la cantidad en stock: ");

        if (scanf("%d", &stock) != 1)
        {
            printf("Error: Debe ingresar un numero.\n");

            while (getchar() != '\n')
            {
            }

            stock = -1;
        }
        else if (stock < 0)
        {
            printf("Error: El stock no puede ser negativo.\n");
        }

    } while (stock < 0);

    do
    {
        printf("Ingrese el precio unitario: $");

        if (scanf("%f", &precio) != 1)
        {
            printf("Error: Debe ingresar un numero.\n");

            while (getchar() != '\n')
            {
            }

            precio = -1;
        }
        else if (precio <= 0)
        {
            printf("Error: El precio debe ser mayor que 0.\n");
        }

    } while (precio <= 0);

    do
    {
        printf("\n==== MENU PRINCIPAL ====\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer Producto\n");
        printf("3. Consultar Producto\n");
        printf("4. Ver ganancias\n");
        printf("5. Salir\n");

        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1)
        {
            printf("\nError: Debe ingresar un numero.\n");

            while (getchar() != '\n')
            {
            }

            continue;
        }

        switch (opcion)
        {
        case 1:
            printf("\n--- VENDER PRODUCTO ---\n");
            printf("Ingrese la cantidad que desea vender: ");

            if (scanf("%d", &cantidad) != 1)
            {
                printf("Error: Debe ingresar un numero.\n");

                while (getchar() != '\n')
                {
                }
            }
            else if (cantidad <= 0)
            {
                printf("Error: La cantidad debe ser mayor que 0.\n");
            }
            else if (cantidad <= stock)
            {
                printf("Ingrese el porcentaje de descuento (0 a 100): ");
                if (scanf("%f", &descuento) != 1)
                {
                    printf("Error: Debe ingresar un numero.\n");

                    while (getchar() != '\n')
                    {
                    }

                    descuento = -1;
                }

                else if (descuento < 0 || descuento > 100)
                {
                    printf("Error: El descuento debe estar entre 0 y 100.\n");
                }
                else
                {
                    totalVenta = cantidad * precio;
                    totalVenta = totalVenta - (totalVenta * descuento / 100);

                    stock = stock - cantidad;
                    ganancias = ganancias + totalVenta;

                    printf("Venta realizada correctamente.\n");
                    printf("Total de la venta con descuento: $%.2f\n", totalVenta);
                    printf("Stock restante: %d\n", stock);
                }
            }
            else
            {
                printf("Error: Stock insuficiente.\n");
            }

            break;

        case 2:
            printf("\n--- REABASTECER PRODUCTO ---\n");
            printf("Ingrese la cantidad que desea agregar: ");

            if (scanf("%d", &cantidad) != 1)
            {
                printf("Error: Debe ingresar un numero.\n");

                while (getchar() != '\n')
                {
                }
            }
            else if (cantidad > 0)
            {
                stock = stock + cantidad;

                printf("Producto reabastecido correctamente.\n");
                printf("Nuevo stock: %d\n", stock);
            }
            else
            {
                printf("Error: La cantidad debe ser mayor que 0.\n");
            }

            break;
        case 3:
            printf("\n--- INFORMACION DEL PRODUCTO ---\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Stock actual: %d\n", stock);
            printf("Precio Unitario: $%.2f\n", precio);
            break;
        case 4:
            printf("\n--- GANANCIAS ---\n");
            printf("Ganancias obtenidas: $%.2f\n", ganancias);
            break;
        case 5:
            printf("\nGracias por utilizar el programa.\n");
            printf("Saliendo...\n");
            break;

        default:
            printf("\nError: Opcion no valida.\n");
            printf("Seleccione una opcion del 1 al 5.\n");
            break;
        }

    } while (opcion != 5);

    return 0;
}