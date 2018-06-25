
#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"
#define TAM 50

int main()
{
    char seguir='s';
    char sOpcion[1];
    int opcion=0;
    int indice;
    int esNumero;
    int hayPelicula = -1;

    EMovie peliculas[TAM];

    inicializarPeliculas(peliculas, TAM);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula.\n");
        printf("2- Borrar pelicula.\n");
        printf("3- Modificar pelicula.\n");
        printf("4- Generar pagina web.\n");
        printf("5- Salir\n");

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
                indice = obtenerEspacioLibre(peliculas, TAM);
                agregarPelicula(peliculas, TAM, indice);
                system("pause");
                system("cls");
                break;
            case 2:
                crearArchivo(peliculas);
                hayPelicula = eliminarPelicula(peliculas, TAM);

                while (hayPelicula == -1)
                {
                    printf("No existe ninguna pelicula con ese titulo.");
                    hayPelicula = eliminarPelicula(peliculas, TAM);
                }
                system("pause");
                system("cls");
                break;
            case 3:
                crearArchivo(peliculas);
                modificarPelicula(peliculas);
                system("pause");
                system("cls");
                break;
            case 4:
                generarPagina(peliculas);
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
