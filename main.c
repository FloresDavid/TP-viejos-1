#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int numeroUno;
    int numeroDos;
    float resultado;
    unsigned long factorial;
    int flagNUno = 0;
    int flagNDos = 0;

    while(seguir=='s')
    {
        if (flagNUno == 1 && flagNDos == 1)
        {
            printf("\n1) Ingresar 1er operando (entero). (A = %d)\n", numeroUno);
            printf("2) Ingresar 2do operando (entero). (B = %d)\n", numeroDos);

        }
        else
        {
            if (flagNUno == 0 && flagNDos == 1)
            {
                printf("\n1) Ingresar 1er operando (entero). (A = x)\n");
                printf("2) Ingresar 2do operando (entero). (B = %d)\n", numeroDos);
            }
            else
            {
                if (flagNUno == 1 && flagNDos == 0)
                {
                    printf("\n1) Ingresar 1er operando (entero). (A = %d)\n", numeroUno);
                    printf("2) Ingresar 2do operando (entero). (B = y)\n");
                }
                else
                {
                    printf("\n1) Ingresar 1er operando (entero). (A = x)\n");
                    printf("2) Ingresar 2do operando (entero). (B = y)\n");
                }
            }
        }
        printf("3) Calcular la suma. (A+B)\n");
        printf("4) Calcular la resta. (A-B)\n");
        printf("5) Calcular la division. (A/B)\n");
        printf("6) Calcular la multiplicacion. (A*B)\n");
        printf("7) Calcular el factorial. (A!) \n");
        printf("8) Calcular todas las operaciones. \n");
        printf("9) Salir. \n\n");

        scanf("%d",&opcion);

        if (opcion < 1 || opcion > 9)
        {
            limpiar(opcion);
            printf("\nError, el numero ingresado no corresponde a ninguna opcion. Ingrese nuevamente \n");
        }
        switch(opcion)
        {
            case 1:
                limpiar(opcion);
                numeroUno = pedirNumero();
                flagNUno = 1;
                break;
            case 2:
                limpiar(opcion);
                numeroDos = pedirNumero();
                flagNDos = 1;
                break;
            case 3:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    limpiar(opcion);
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    limpiar(opcion);
                    resultado = sumar(numeroUno, numeroDos);
                    printf ("\nLa suma es: %.0f.\n", resultado);
                }
                break;
            case 4:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    limpiar(opcion);
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    limpiar(opcion);
                    resultado = restar(numeroUno, numeroDos);
                    printf ("\nLa resta es: %.0f.\n", resultado);
                }
                break;
            case 5:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    limpiar(opcion);
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    if (numeroDos != 0)
                    {
                        limpiar(opcion);
                        resultado = dividir(numeroUno, numeroDos);
                        printf ("\nLa division es: %.2f.\n", resultado);
                    }
                    else
                    {
                        limpiar(opcion);
                        printf ("\nError, no se puede dividir por 0.\n");
                    }
                }
                break;
            case 6:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    limpiar(opcion);
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    limpiar(opcion);
                    resultado = multiplicar(numeroUno, numeroDos);
                    printf ("\nLa multiplicacion es: %.0f.\n", resultado);
                }
                break;
            case 7:
                if(flagNUno == 0)
                {
                    limpiar(opcion);
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    if(numeroUno >= 0 && numeroUno <= 33)
                    {
                        limpiar(opcion);
                        factorial = factorizar(numeroUno);
                        printf("\nEl factorial del primer numero es: %lu.\n", factorial);
                    }
                    else
                    {
                        limpiar(opcion);
                        printf("\nError, No se puede calcular el factorial del numero, es negativo o mayor a 33.\n(el tipo de dato solo soporta hasta el numero 33 incluido).\n");
                    }
                }
                break;
            case 8:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    limpiar(opcion);
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    limpiar(opcion);
                    mostrarTodas(numeroUno, numeroDos);
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
