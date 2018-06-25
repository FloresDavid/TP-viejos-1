#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 50

int inicializarPeliculas(EMovie* pelicula, int tam)
{
    int retorno = -1;

    if (pelicula != NULL)
    {
        for (int i = 0; i < tam; i++)
        {
            (*(pelicula + i)).estado = 1;
        }
        retorno = 0;
    }
    return retorno;
}

void agregarPelicula(EMovie* pelicula, int tam, int indice)
{
    EMovie nuevaPelicula;
    int lugar;
    char sDuracion[20];
    char sPuntaje[20];
    int esNumero;

    if (indice == -1)
    {
        printf("No hay mas lugar para nuevas peliculas.\n");
    }
    else
    {
        printf("Ingrese el titulo: ");
        fflush(stdin);
        gets(nuevaPelicula.titulo);

        while (nuevaPelicula.titulo == NULL)
        {
            printf("Error, reingrese el titulo: ");
            fflush(stdin);
            gets(nuevaPelicula.titulo);
        }
        nuevaPelicula.estado = 0;

        printf("Ingrese el genero: ");
        fflush(stdin);
        gets(nuevaPelicula.genero);
        esNumero = validarString(nuevaPelicula.genero);

        while (esNumero == 1)
        {
            printf("Error. genero incorrecto, reingrese el genero: ");
            fflush(stdin);
            gets(nuevaPelicula.genero);
            esNumero = validarString(nuevaPelicula.genero);
        }

        printf("Ingrese la duracion en minutos: ");
        fflush(stdin);
        gets(sDuracion);
        esNumero = validarNumero(sDuracion);

        while (esNumero == 1)
        {
            printf("Error. Duracion incorrecta, reingrese la duracion en minutos: ");
            fflush(stdin);
            gets(sDuracion);
            esNumero = validarNumero(sDuracion);
        }

        nuevaPelicula.duracion = atoi(sDuracion);

        printf("Ingrese la descripcion: ");
        fflush(stdin);
        gets(nuevaPelicula.descripcion);

        while (nuevaPelicula.descripcion == NULL)
        {
            printf("Error, reingrese la descripcion: ");
            fflush(stdin);
            gets(nuevaPelicula.descripcion);
        }

        printf("Ingrese el puntaje: ");
        fflush(stdin);
        gets(sPuntaje);
        esNumero = validarNumero(sPuntaje);
        nuevaPelicula.puntaje = atoi(sPuntaje);

        while (esNumero == 1 || nuevaPelicula.puntaje <= 0)
        {
            printf("Error. Puntaje incorrecto, reingrese el puntaje: ");
            fflush(stdin);
            gets(sPuntaje);
            esNumero = validarNumero(sPuntaje);
            nuevaPelicula.puntaje = atoi(sPuntaje);
        }

        printf("Ingrese el link a la imagen: ");
        fflush(stdin);
        gets(nuevaPelicula.linkImagen);

        while (nuevaPelicula.linkImagen == NULL)
        {
            printf("Error. Reingrese el link a la imagen: ");
            fflush(stdin);
            gets(nuevaPelicula.linkImagen);
        }

        *(pelicula + indice) = nuevaPelicula;
        printf("Alta exitosa!!\n\n");
    }
}

int obtenerEspacioLibre(EMovie* pelicula, int tam)
{
   int indice = -1;

   for (int i = 0; i < tam; i++)
   {
        if ((*(pelicula + i)).estado == 1)
        {
            indice = i;
            break;
        }
   }
   return indice;
}

int eliminarPelicula (EMovie* peliculas, int tam)
{
    char sRespuesta[1];
    int respuesta = 2;
    char titulo[20];
    int esNumero;
    int hayPelicula = 0;

    printf("Ingrese el titulo de la pelicula a eliminar: \n");
    fflush(stdin);
    gets(titulo);

    for (int i = 0; i < tam; i++)
    {
        if (strcmp((*(peliculas + i)).titulo, titulo) == 0 && (*(peliculas + i)).estado == 0)
        {
            printf("Esta seguro que desea eliminar a : %s \n", (*(peliculas + i)).titulo);
            printf("1) Si. \n");
            printf("2) No. \n");
            gets(sRespuesta);
            esNumero = validarNumero(sRespuesta);
            respuesta = atoi(sRespuesta);

            while(esNumero == 1 || respuesta < 1 || respuesta > 2)
            {
                printf("Error. Opcion incorrecta, reingrese la opcion deseada: ");
                gets(sRespuesta);
                esNumero = validarNumero(sRespuesta);
                respuesta = atoi(sRespuesta);
            }

            switch (respuesta)
            {
                case 1:
                    (*(peliculas + i)).estado = 1;
                    printf("Eliminacion exitosa!!\n");
                    break;
                case 2:
                    printf("Eliminacion cancelada, la pelicula no se eliminara.\n");
                    break;
            }
            break;
        }
        else
        {
            hayPelicula += 1;
        }
    }
    if (hayPelicula == tam)
    {
        hayPelicula = -1;
    }
    return hayPelicula;
}

int validarString (char* cadena)
{
    int esNumero = 0;

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (isalpha(*(cadena + i)) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}

void modificarPelicula(EMovie* pelicula)
{
    int indice = -1;
    int esNumero;
    int opcion;
    char sDuracion [10];
    char sPuntaje [10];
    char sOpcion [10];
    char titulo [50];
    char genero [10];
    char link [200];
    char descripcion [200];


    printf("Ingrese el titulo de la pelicula a modificar. \n");
    fflush(stdin);
    gets(titulo);

    while (titulo == NULL)
    {
        printf("Error, reingrese el titulo de la pelicula a modificar. \n");
        gets(titulo);
    }

    for (int i = 0; i < TAM; i++)
    {
        if ((*(pelicula + i)).estado == 0 && stricmp((*(pelicula + i)).titulo, titulo) == 0)
        {
            indice = i;
            break;
        }
    }

    while (indice == -1)
    {
        printf("Error, el titulo ingresado no coincide con ninguna pelicula, vuelva a ingresar el titulo. \n");
        gets(titulo);

        while (titulo == NULL)
        {
            printf("Error, reingrese el titulo de la pelicula a modificar. \n");
            gets(titulo);
        }

        for (int i = 0; i < TAM; i++)
        {
            if ((*(pelicula + i)).estado == 0 && strcmp((*(pelicula + i)).titulo, titulo) == 0)
            {
                indice = i;
                break;
            }
        }

    }
    printf("\nIngrese la opcion que quiera utilizar.\n");
    printf("1) Modificar Titulo.\n");
    printf("2) Modificar Genero.\n");
    printf("3) Modificar Duracion.\n");
    printf("4) Modificar Descripcion.\n");
    printf("5) Modificar Puntaje.\n");
    printf("6) Modificar Link de la imagen.\n");
    printf("7) Salir.\n");

    gets(sOpcion);
    esNumero = validarNumero(sOpcion);
    opcion = atoi(sOpcion);

    while (opcion < 1 || opcion > 7 || esNumero == 1)
    {
        printf("Error, reingrese la opcion.\n\n");
        gets(sOpcion);
        esNumero = validarNumero(sOpcion);
        opcion = atoi(sOpcion);
    }
    switch(opcion)
    {
        case 1:

            printf ("Ingrese el nuevo titulo de la pelicula. \n\n");
            fflush(stdin);
            gets(titulo);

            while (titulo == NULL)
            {
                printf("Error, reingrese el titulo de la pelicula a modificar. \n");
                gets(titulo);
            }

            strcpy((pelicula + indice)->titulo, titulo);

            printf("Titulo modificado con exito!\n");

            break;
        case 2:

            printf ("Ingrese el nuevo genero de la pelicula. \n\n");
            fflush(stdin);
            gets(genero);

            strcpy((*(pelicula + indice)).genero, genero);

            printf("Genero modificado con exito!\n");

            break;
        case 3:

            printf ("Ingrese la nueva duracion de la pelicula. (Minutos)\n\n");
            gets(sDuracion);

            esNumero = validarString(sDuracion);
            (*(pelicula + indice)).duracion = atoi(sDuracion);

            while (esNumero == 1 || (*(pelicula + indice)).duracion <= 0)
            {
                printf("Error. Duracion incorrecta, reingrese la duracion en minutos: ");
                fflush(stdin);
                gets(sDuracion);

                esNumero = validarNumero(sDuracion);
                (*(pelicula + indice)).duracion = atoi(sDuracion);

            }

            printf("Duracion modificada con exito!\n");

            break;
        case 4:

            printf("Ingrese la nueva descripcion: ");
            fflush(stdin);
            gets(descripcion);

            while (descripcion == NULL)
            {
                printf("Error, reingrese la descripcion: ");
                fflush(stdin);
                gets(descripcion);
            }

            strcpy((*(pelicula + indice)).descripcion, descripcion);

            printf("Descripcion modificada con exito!\n");
            break;
        case 5:
            printf("Ingrese el nuevo puntaje: ");
            fflush(stdin);
            gets(sPuntaje);

            esNumero = validarNumero(sPuntaje);
            (*(pelicula + indice)).puntaje = atoi(sPuntaje);

            while (esNumero == 1 || (*(pelicula + indice)).puntaje <= 0)
            {
                printf("Error. Puntaje incorrecto, reingrese el puntaje: ");
                fflush(stdin);
                gets(sPuntaje);

                esNumero = validarNumero(sPuntaje);
                (*(pelicula + indice)).puntaje = atoi(sPuntaje);
            }

            printf("Puntaje modificado con exito!\n");
            break;
        case 6:

            printf("Ingrese el nuevo link a la imagen: ");
            fflush(stdin);
            gets(link);

            while (link == NULL)
            {
                printf("Error. Reingrese el link a la imagen: ");
                fflush(stdin);
                gets(link);
            }
            strcpy((*(pelicula + indice)).linkImagen, link);
            printf("Enlace de la imagen modificado con exito!\n");
            break;
        case 7:
            break;
    }
}
int validarNumero (char* numero)
{
    int esNumero = 0;
    int len;

    len = strlen(numero);

    for (int i = 0; i < len; i++)
    {
        if (isdigit(*(numero + i)) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}

void crearArchivo (EMovie* peliculas)
{
    FILE* listado;

    listado = fopen("peliculas.txt", "w");

    if (listado != NULL)
    {
        fprintf(listado, "Titulos de las peliculas:\n");
        for (int i = 0; i < TAM; i++)
        {
            if ((peliculas + i)->estado == 0)
            {
                fprintf(listado, "%s \n", (peliculas + i)->titulo);
            }
        }
        fclose(listado);
    }

}


void generarPagina(EMovie* pelicula)
{
    FILE *file;
    file=fopen("pelicula.html","w");

    if(file == NULL)
    {
        printf("El archivo no pudo ser creado.");
        exit(1);
    }

        fprintf(file,"<!DOCTYPE html>");
        fprintf(file,"<html lang='en'>");
        fprintf(file,"<head>");
            fprintf(file,"<title>Listado de peliculas</title>");
            fprintf(file,"<meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'>");
            fprintf(file,"<meta name='viewport' content='width=device-width, initial-scale=1'>");
            fprintf(file,"<link href='css/bootstrap.min.css' rel='stylesheet'>");
            fprintf(file,"<link href='css/custom.css' rel='stylesheet'>");
        fprintf(file,"</head>");
        fprintf(file,"<body>");
            fprintf(file,"<div class='container'>");
            fprintf(file,"<div class='row'>");

            for(int i = 0; i < TAM; i++)
            {
                if((*(pelicula + i)).estado == 0)
                {
                    fprintf(file,"<article class='col-md-4 article-intro'>");
                    fprintf(file,"<a href='#'>");
                    fprintf(file,"<img class='img-responsive img-rounded' src='%s' alt='%s'></a>\n", (*(pelicula + i)).linkImagen, (*(pelicula + i)).titulo);
                    fprintf(file,"<h3 style='color:#2196f3'>%s</h3>\n", (*(pelicula + i)).titulo);
                    fprintf(file,"<ul><li>Genero: %s</li>\n<li>Puntaje: %d</li>\n<li>Duracion: %d mins</li></ul>\n", (*(pelicula + i)).genero, (*(pelicula + i)).puntaje, (*(pelicula + i)).duracion);
                    fprintf(file,"<p>%s</p></article>", (*(pelicula+i)).descripcion);
                }
            }
        fprintf(file,"</div></div>");
            fprintf(file,"<script src='js/jquery-1.11.3.min.js'></script>");
            fprintf(file,"<script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'>");
            fprintf(file,"</script><script src='js/holder.min.js'></script>");
        fprintf(file,"</body>");
        fprintf(file,"</html>");
    fclose(file);
}
