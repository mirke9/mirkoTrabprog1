#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// INTEGRANTES: Santiago Brasca, Ezequiel Coria, Mirko Durich, Diego Contreras

void main()
{
    int opcion, stock[100], respuesta, i, cantidad, codigoEncontrado, cantidadNueva, sinStock;
    char codigo[100][15], descripcion[100][100], codigoBuscar[15]; // 100 electrodomésticos con una descripción de 100 letras cada uno y codigo de hasta 15 numeros
    struct electrodomestico
    {
        int stock;
        char codigo[15], descripcion[100];
    };
    struct electrodomestico electrodomesticos[100];

    do
    {

        printf("Ingrese una opci%cn del menu: \n", 162);
        printf("1. Cargar productos \n");
        printf("2. Modificar stock \n");
        printf("3. Mostrar productos sin stock \n");
        printf("4. Listar productos \n");
        printf("5. Salir \n");
        scanf("%i", &opcion);

        while (opcion < 1 || opcion > 5)
        {
            printf("Opci%cn incorrecta. Ingrese nuevamente: \n", 162);
            scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 1:
            printf("Ingrese cantidad de electrodom%csticos a cargar:\n", 130);
            scanf("%i", &cantidad);
            while (cantidad < 1 || cantidad > 100)
            {
                printf("Cantidad incorrecta. Ingrese nuevamente: \n");
                scanf("%i", &cantidad);
            }
            for (i = 0; i <= cantidad - 1; i++)
            {
                printf("Ingrese el c%cdigo de barras del electrodomestico %i: \n", 162, i + 1);
                scanf("%s", &electrodomesticos[i].codigo);

                while (strlen(electrodomesticos[i].codigo) < 5 || strlen(electrodomesticos[i].codigo) > 13)
                {
                    printf("C%cdigo incorrecto. Ingrese nuevamente: \n", 162);
                    scanf("%s", &electrodomesticos[i].codigo);
                }
                fflush(stdin);
                printf("Ingrese la descripci%cn:\n", 162);
                scanf("%[^\n]", &electrodomesticos[i].descripcion);
                printf("Ingrese la cantidad:\n");
                scanf("%i", &electrodomesticos[i].stock);
                while (stock[i] < 0)
                {
                    printf("Cantidad incorrecta. Ingrese nuevamente: \n");
                    scanf("%i", &electrodomesticos[i].stock);
                }
            }
            break;
        case 2:
            codigoEncontrado = 0;
            printf("Ingrese el c%cdigo de barras del electrodomestico a buscar:\n", 162);
            scanf("%s", &codigoBuscar);
            while (strlen(codigoBuscar) < 5 || strlen(codigoBuscar) > 13)
            {
                printf("C%cdigo incorrecto. Ingrese nuevamente: \n", 162);
                scanf("%s", &codigoBuscar);
            }
            printf("Ingrese la nueva cantidad:\n");
            scanf("%i", &cantidadNueva);
            while (cantidadNueva < 0)
            {
                printf("Cantidad incorrecta. Ingrese nuevamente: \n");
                scanf("%i", &cantidadNueva);
            }
            for (i = 0; i <= cantidad - 1; i++)
            {
                if (strcmp(codigoBuscar, electrodomesticos[i].codigo) == 0)
                {
                    electrodomesticos[i].stock = cantidadNueva;
                    codigoEncontrado = 1;
                }
            }
            if (codigoEncontrado == 0)
            {
                printf("Electrodom%cstico inexistente\n", 130);
            }
            break;
        case 3:
            sinStock = 0;
            printf("Electrodom%csticos sin stock:\n", 130);
            for (i = 0; i <= cantidad - 1; i++)
            {
                if (electrodomesticos[i].stock == 0)
                {
                    printf("C%cdigo de barras: %s \n", 162, electrodomesticos[i].codigo);
                    printf("Descripci%cn: %s \n\n", 162, electrodomesticos[i].descripcion);
                    sinStock++;
                }
            }
            if (sinStock == 0)
            {
                printf("No hay ning%cn electrodom%cstico sin stock\n", 163, 130);
            }
            system("pause");
            break;
        case 4:
            printf("Listado de electrodom%csticos: \n", 130);
            for (i = 0; i <= cantidad - 1; i++)
            {
                printf("C%cdigo de barras: %s \n", 162, electrodomesticos[i].codigo);
                printf("Descripci%cn: %s \n", 162, electrodomesticos[i].descripcion);
                printf("Cantidad: %i \n\n", electrodomesticos[i].stock);
            }
            system("pause");
            break;
        }

    } while (opcion != 5);
}