#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Input.h"
#include "Calculadora.h"

int main()
{
	double numero_A;
    double numero_B;
    double suma;
    double resta;
    double division;
    double multiplicacion;
    unsigned long int fact_A;
    unsigned long int fact_B;
    int opcion;
    int flag_A = 0;
    int flag_B = 0;
    int flagCalculos = 0;
    int flagDiv = 0;
    int flagFact_A = 0;
    int flagFact_B = 0;
    int flagExit = 0;

    do
    {
        if(mostrarMenuOpciones(numero_A, numero_B, flag_A, flag_B, &opcion) == 0)
        {
            switch(opcion)
            {
                case 1:
                case 2:

                    if(flagCalculos == 0)
                    {
                        if(opcion == 1)
                        {
                            if(utn_getNumeroDouble(&numero_A, "\nIngrese el primer numero: ", "Error. Ingrese un numero flotante valido: ") == 0)
                            {
                                printf("\nPrimer numero cargado\n");

                                flag_A = 1;
                            }

                            else
                            {
                                printf("\nNo se pudo cargar el primer numero\n");
                            }
                        }

                        else
                        {
                            if(flag_A == 0)
                            {
                                printf("\nError. Debe ingresar el primer numero\n");
                            }

                            else
                            {
                                if(utn_getNumeroDouble(&numero_B, "\nIngrese el segundo numero: ", "Error. Ingrese un numero flotante valido: ") == 0)
                                {
                                    printf("\nSegundo numero cargado\n");

                                    flag_B = 1;
                                }

                                else
                                {
                                    printf("\nNo se pudo cargar el segundo numero\n");
                                }
                            }
                        }
                    }

                    else
                    {
                        printf("\nYa se han realizado los calculos. Debe ingresar al informe de resultados\n");
                    }

                    break;

                case 3:
                case 4:

                    if(flag_A == 0 && flag_B == 0)
                    {
                        printf("\nError. No hay ningun numero cargado\n");
                    }

                    else if(flag_A == 1 && flag_B == 0)
                    {
                        printf("\nError. El segundo numero no esta cargado\n");
                    }

                    else
                    {
                        if(opcion == 3)
                        {
                            if(flagCalculos == 0)
                            {
                                if(realizarOperaciones(numero_A, numero_B, &suma, &resta, &division, &multiplicacion, &fact_A,
                                                       &fact_B, &flagDiv, &flagFact_A, &flagFact_B) == 0)
                                {
                                    printf("\nCalculos realizados correctamente\n");

                                    flagCalculos = 1;
                                }

                                else
                                {
                                    printf("\nNo se pudieron calcular las operaciones\n");
                                }
                            }

                            else
                            {
                                printf("\nLas operaciones ya se han calculado\n");
                            }
                        }

                        else
                        {
                            if(flagCalculos == 0)
                            {
                                printf("\nError. No se han realizado los calculos aun\n");
                            }

                            else
                            {
                                informarResultados(suma, resta, division, multiplicacion, fact_A, fact_B, flagDiv, flagFact_A, flagFact_B);

                                flag_A = 0;
                                flag_B = 0;
                                flagCalculos = 0;
                                flagDiv = 0;
                                flagFact_A = 0;
                                flagFact_B = 0;
                            }
                        }
                    }

                    break;

                case 5:

                    if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                    {
                        printf("\nUsted ha salido de la calculadora\n");

                        flagExit = 1;
                    }

                    break;

                default:

                    printf("\nError. Elija una opcion correcta\n");
            }

            printf("\n");
            system("pause");
            system("cls");
        }

        else
        {
            printf("No se pudo mostrar el menu\n");
            break;
        }

    } while(opcion != 5 || !flagExit);

    return 0;
}
