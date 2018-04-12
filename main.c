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

        switch(opcion)
        {
            case 1:
                numeroUno = pedirNumero();
                flagNUno = 1;
                break;
            case 2:
                numeroDos = pedirNumero();
                flagNDos = 1;
                break;
            case 3:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    resultado = sumar(numeroUno, numeroDos);
                    printf ("\nLa suma es: %.0f.\n", resultado);
                }
                break;
            case 4:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    resultado = restar(numeroUno, numeroDos);
                    printf ("\nLa resta es: %.0f.\n", resultado);
                }
                break;
            case 5:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    if (numeroDos != 0)
                    {
                        resultado = dividir(numeroUno, numeroDos);
                        printf ("\nLa division es: %.2f.\n", resultado);
                    }
                    else
                    {
                        printf ("\nError, no se puede dividir por 0.\n");
                    }
                }
                break;
            case 6:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    resultado = multiplicar(numeroUno, numeroDos);
                    printf ("\nLa multiplicacion es: %.0f.\n", resultado);
                }
                break;
            case 7:
                if(flagNUno == 0)
                {
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
                    if(numeroUno >= 0 && numeroUno <= 33)
                    {
                        factorial = factorizar(numeroUno);
                        printf("\nEl factorial del primer numero es: %lu.\n", factorial);
                    }
                    else
                    {
                        printf("\nError, No se puede calcular el factorial del numero, es negativo o mayor a 33.\n(el tipo de dato solo soporta hasta el numero 33 incluido).\n");
                    }
                }
                break;
            case 8:
                if(flagNUno == 0 || flagNDos == 0)
                {
                    printf("\nError, ingrese ambos numeros antes de realizar la operacion.\n");
                }
                else
                {
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
