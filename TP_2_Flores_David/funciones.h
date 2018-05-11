#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tam pasa el tamaño de array para recorrerlo.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tam pasa el tamaño del array para recorrerlo.
 * @return El indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni, int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tam pasa el tamaño de array para recorrerlo.
 */
void inicializarPersonas(ePersona lista[], int tam);

/**
 * Pide los datos y agrega a la persona al array.
 * @param lista el array se pasa como parametro.
 * @param indice pasa el lugar donde se aade la pesona.
 * @param tam pasa el tamaño de array para recorrerlo.
 */
void agregarPersona(ePersona lista[], int tam, int indice);

/**
 * Muestra los datos de una persona.
 * @param lista el array se pasa como parametro.
 */
void mostrarPersona(ePersona lista);

/**
 * Elimina a una persona del array
 * @param lista el array se pasa como parametro.
 * @param tam pasa el tamaño de array para recorrerlo.
 * @return la cantidad de veces que no coincide el dni ingresado con un dni de una persona.
 */
 int eliminarPersona(ePersona lista[], int tam);

/**
 * Valida que  se hayan ingresado solo caracteres.
 * @param cadena el string se pasa como parametro.
 * @return 0 si se ingresaron solo caracteres, 1 si se ingreso algun numero o simbolo.
 */
int validarString(char cadena[]);

/**
 * Valida que se hayan ingresado solo numeros
 * @param numero el string se pasa como parametro.
 * @return 0 si se ingresaron solo numeros, 1 si se ingreso algun caracter o simbolo.
 */
int validarNumero(char numero[]);

/**
 * Muestra las personas ordenadas alfabeticamente por nombre.
 * @param lista el array se pasa como parametro.
 * @param tam pasa el tamaño de array para recorrerlo.
 */
void mostrarPersonasPorNombre(ePersona lista[], int tam);

/**
 * Ordena a las personas por nombre alfabeticamente.
 * @param lista el array se pasa como parametro.
 * @param tam pasa el tamaño de array para recorrerlo.
 */

void ordenarPorNombre(ePersona lista[], int tam);


#endif // FUNCIONES_H_INCLUDED
