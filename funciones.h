#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/** \brief pide un numero y lo devuelve.
*
*   \param no posee parametros.
*
*   \return devuelve un numero entero.

*/
int pedirNumero (void);

/** \brief recibe dos numeros y develve la suma de ambos.
*
*   \param posee como parametros dos numeros de tipo entero.
*
*   \return devuelve la suma de los numeros como entero.

*/
int sumar (int, int);

/** \brief recibe dos numeros y develve la resta de ambos.
*
*   \param posee como parametros dos numeros de tipo entero.
*
*   \return devuelve la resta de los numeros como entero.

*/
int restar (int, int);

/** \brief recibe dos numeros y develve la multiplicacion de ambos.
*
*   \param posee como parametros dos numeros de tipo entero.
*
*   \return devuelve la multiplicacion de los numeros como entero.

*/
int multiplicar (int, int);

/** \brief recibe dos numeros y develve la division de ambos.
*
*   \param posee como parametros dos numeros de tipo entero.
*
*   \return devuelve la division de los numeros como float.

*/
float dividir (int, int);

/** \brief recibe un numeros y develve su factorizacion.
*
*   \param posee como parametro un numero de tipo entero.
*
*   \return devuelve la factorizacion de un numero como unsigned long.

*/
unsigned long factorizar (int);

/** \brief recibe dos numeros y muestra la suma, la resta, la multiplicacion y la division de ambos, y la factorizacion del primer numero.
*
*   \param posee como parametros dos numeros de tipo entero.
*
*   \return no devuelve ningun dato, los muestra directamente por pantalla.

*/
void mostrarTodas(int,int);

int pedirNumero (void)//Pide un numero y lo devuelve.
{
    int numero;

    printf("\nIngrese un numero: ");
    scanf("%d", &numero);

    return numero;
}

int sumar (int numeroUno, int numeroDos) //Devuelve la suma de los dos numeros ingresados.
{
    int suma;

    suma = numeroUno + numeroDos;

    return suma;
}

int restar (int numeroUno, int numeroDos) //Devuelve la resta del primer numero menos el segundo..
{
    int resta;

    resta = numeroUno - numeroDos;

    return resta;
}

int multiplicar (int numeroUno, int numeroDos)//Devuelve la multiplicacion de los dos numeros ingresados.
{
    int multiplicacion;

    multiplicacion = numeroUno * numeroDos;

    return multiplicacion;
}

float dividir (int numeroUno, int numeroDos)//Devuelve la divicion del primero numero por el segundo, solo si el segundo numero es distinto a 0.
{
        float division;
        division = (float) numeroUno / numeroDos;
        return division;
}

unsigned long factorizar (int numeroUno)//Devuelve la factorizacion del primero numero.
{
    int factorial = 1;

    for (int i = numeroUno; i > 0; i--)
    {
        factorial = factorial * i;
    }

    return factorial;
}

void mostrarTodas(int numeroUno, int numeroDos) //Ejecuta todas las operaciones y las muestra.
{
    int suma;
    int resta;
    int multiplicacion;
    float division;
    unsigned long factorial = 1;

    suma = numeroUno + numeroDos;
    printf ("\nLa suma es: %d.\n", suma);

    resta = numeroUno - numeroDos;
    printf ("\nLa resta es: %d.\n", resta);

    if (numeroDos != 0)
    {
        division = (float) numeroUno / numeroDos;
        printf ("\nLa division es: %.2f.\n", division);
    }
    else
    {
        printf ("\nError, no se puede dividir por 0.\n");
    }

    multiplicacion = numeroUno * numeroDos;
    printf ("\nLa multiplicacion es: %d.\n", multiplicacion);

    if((numeroUno <= 33 && numeroUno >= 0))
    {
        for (int i = numeroUno; i > 0; i--)
        {
            factorial = factorial * i;
        }
        printf("\nEl factorial del primer numero es: %lu.\n", factorial);
    }
    else
    {
        printf("\nError, No se puede calcular el factorial del numero, es negativo o mayor a 33\n(el tipo de dato solo soporta hasta el numero 33 incluido).\n");
    }
}

#endif // FUNCIONES_H_INCLUDED
