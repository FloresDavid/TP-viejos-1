#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void inicializarPersonas(ePersona lista[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        lista[i].estado = 1;
    }
}

void agregarPersona(ePersona lista[], int tam, int indice)
{
    ePersona nuevaPersona;
    int lugar;
    char sDni[10];
    char sEdad[5];
    int esNumero;

    if (indice == -1)
    {
        printf("No hay mas lugar para nuevas personas.\n");
    }
    else
    {
        printf("Ingrese el dni: ");
        scanf("%s", &sDni);
        esNumero = validarNumero(sDni);

        while (esNumero == 1)
        {
            printf("Error. DNI incorrecto, reingrese el dni: ");
            scanf("%s", &sDni);
            esNumero = validarNumero(sDni);
        }

        nuevaPersona.dni = atoi(sDni);

        lugar = buscarPorDni(lista, nuevaPersona.dni, tam);

        while (lugar != -1)
        {
            printf("Ya existe una persona con ese dni \n\n");
            printf("        Nombre      Edad        DNI\n");
            mostrarPersona(lista[lugar]);

            printf("Reingrese el dni: ");
            scanf("%s", &sDni);
            esNumero = validarNumero(sDni);

            while (esNumero == 1)
            {
                printf("Error. DNI incorrecto, reingrese el dni: ");
                scanf("%s", &sDni);
                esNumero = validarNumero(sDni);
            }

            nuevaPersona.dni = atoi(sDni);

            lugar = buscarPorDni(lista, nuevaPersona.dni, tam);
        }
        nuevaPersona.estado = 0;

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nuevaPersona.nombre);
        esNumero = validarString(nuevaPersona.nombre);

        while (esNumero == 1)
        {
            printf("Error. Nombre incorrecto, reingrese el nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);
            esNumero = validarString(nuevaPersona.nombre);
        }

        printf("Ingrese la edad: ");
        fflush(stdin);
        gets(sEdad);
        esNumero = validarNumero(sEdad);

        while (esNumero == 1)
        {
            printf("Error. Edad incorrecta, reingrese la edad: ");
            fflush(stdin);
            gets(sEdad);
            esNumero = validarNumero(sEdad);
        }

        nuevaPersona.edad = atoi(sEdad);
        lista[indice] = nuevaPersona;
        printf("Alta exitosa!!\n\n");
    }
}

int obtenerEspacioLibre(ePersona lista[], int tam)
{
   int indice = -1;

   for (int i = 0; i < tam; i++)
   {
        if (lista[i].estado == 1)
        {
            indice = i;
            break;
        }
   }
   return indice;
}

int buscarPorDni(ePersona lista[], int dni, int tam)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (lista[i].estado == 0 && lista[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarPersona (ePersona lista)
{
    if (lista.estado == 0)
    {
        printf("%15s        %2d     %8d\n", lista.nombre, lista.edad, lista.dni);
    }
}

int eliminarPersona (ePersona lista[], int tam)
{
    char sRespuesta[1];
    int respuesta = 2;
    int sDni[10];
    int dni;
    int esNumero;
    int hayPersona = 0;

    printf("Ingrese el dni de la persona a eliminar: \n");
    fflush(stdin);
    gets(sDni);
    esNumero = validarNumero(sDni);

    while (esNumero == 1)
    {
        printf("Error. DNI incorrecto, reingrese el dni: ");
        scanf("%s", &sDni);
        esNumero = validarNumero(sDni);
    }

    dni = atoi(sDni);

    for (int i = 0; i < tam; i++)
    {
        if (lista[i].dni == dni && lista[i].estado == 0)
        {
            printf("Esta seguro que desea eliminar a : %s \n", lista[i].nombre);
            printf("1) Si. \n");
            printf("2) No. \n");
            scanf("%s", &sRespuesta);
            esNumero = validarNumero(sRespuesta);
            respuesta = atoi(sRespuesta);

            while(esNumero == 1 || respuesta < 1 || respuesta > 2)
            {
                printf("Error. Opcion incorrecta, reingrese la opcion deseada: ");
                scanf("%s", &sRespuesta);
                esNumero = validarNumero(sRespuesta);
                respuesta = atoi(sRespuesta);
            }


            switch (respuesta)
            {
                case 1:
                    lista[i].estado = 1;
                    printf("Eliminacion exitosa!!");
                    break;
                case 2:
                    printf("Eliminacion cancelada, la persona no se eliminara.\n");
                    break;
            }
            break;
        }
        else
        {
            hayPersona+= 1;
        }
    }
    if (hayPersona == tam)
    {
        hayPersona = -1;
    }
    return hayPersona;
}

int validarString (char cadena[])
{
    int esNumero = 0;

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (isalpha(cadena[i]) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}

int validarNumero (char numero[])
{
    int esNumero = 0;
    int len;

    len = strlen(numero);

    for (int i = 0; i < len; i++)
    {
        if (isdigit(numero[i]) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}

void mostrarPersonasPorNombre (ePersona lista[], int tam)
{
    ordenarPorNombre(lista, tam);

    printf("\n              Lista ordenada alfabeticamente.\n");
    printf("        Nombre      Edad        DNI\n");

    for (int i = 0; i < tam; i++)
    {
        mostrarPersona(lista[i]);
    }
}

void ordenarPorNombre (ePersona lista[], int tam)
{
    ePersona perAux;

    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                perAux = lista[i];
                lista[i] = lista[j];
                lista[j] = perAux;
            }
        }
    }
}

void graficoEdades(ePersona lista[], int tam)
{
    printf("                Grafico de edades\n\n");
    printf("Menores de 18.   Entre 19 y 35.     Mayores de 35. " );

    int menoresDe18 = 0;
    int entre19Y35Anios = 0;
    int mayoresDe35 = 0;

    for (int i = 0; i < tam; i++)
    {
        if (lista[i].edad < 19 && lista[i].estado == 0)
        {
            menoresDe18 += 1;
        }
        else
        {
            if (lista[i].edad > 18 && lista[i].edad < 36 && lista[i].estado == 0)
            {
                entre19Y35Anios += 1;
            }
            else
            {
                if (lista[i].edad > 35 && lista[i].estado == 0)
                {
                    mayoresDe35 += 1;
                }
            }
        }
    }

    for (int i = 0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {

            if (menoresDe18 > 0)
            {
                printf("*");
                menoresDe18 -= 1;
            }
            else
            {
                printf(" ");
            }
            if ( entre19Y35Anios > 0)
            {

                printf("                *");
                entre19Y35Anios -= 1;
            }
            else
            {
                printf("                 ");
            }
            if (mayoresDe35 > 0)
            {
                printf("                  *");
                mayoresDe35 -=1;
            }
        }
        printf("\n");
    }
}
