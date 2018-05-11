#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"
#include "funciones.h"
#define TAM 20

int main()
{
    char seguir = 's';
    char sOpcion[1];
    int opcion = 0;
    int esNumero;
    int indice;
    int hayPersona = -1;

    ePersona personas[TAM];

    inicializarPersonas(personas, TAM);

    while(seguir == 's')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\n");

        fflush(stdin);
        gets(sOpcion);
        esNumero = validarNumero(sOpcion);
        opcion = atoi(sOpcion);

        while (esNumero == 1 || opcion < 1 || opcion > 5)
        {
            printf("Error. Opcion incorrecto, reingrese la opcion deseada: ");
            gets(sOpcion);
            esNumero = validarNumero(sOpcion);
            opcion = atoi(sOpcion);
        }

        switch(opcion)
        {
            case 1:
                indice = obtenerEspacioLibre(personas, TAM);
                agregarPersona(personas, TAM, indice);
                system("pause");
                system("cls");
                break;
            case 2:
                hayPersona = eliminarPersona(personas, TAM);
                while (hayPersona == -1)
                {
                    printf("No existe ninguna persona con ese DNI.");
                    hayPersona = eliminarPersona(personas, TAM);
                }
                system("pause");
                system("cls");
                break;
            case 3:
                mostrarPersonasPorNombre(personas, TAM);
                system("pause");
                system("cls");
                break;
            case 4:
                graficoEdades(personas, TAM);
                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
