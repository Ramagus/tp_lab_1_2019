#include <stdio.h>
#include <stdlib.h>
#include "Nexus.h"
#include "Input.h"

#define EMP_ELEMENTS 1000
#define SEC_ELEMENTS 6

int main()
{
    Employee arrayEmployees[EMP_ELEMENTS];
    Sector arraySectors[SEC_ELEMENTS];

    int option;
    int auxId;
    int flag = 0;

    int idEmployee = 1;
    int idSector = 1;

    if(!initEmployees(arrayEmployees, EMP_ELEMENTS) && !hardCodeSectors(arraySectors, SEC_ELEMENTS, &idSector))
    {
        do
        {
            if(!showEmployeesMenu(&option))
            {
                switch(option)
                {
                    case 1:

                        printf("\n");
                        system("pause");
                        system("cls");

                        printf("\tALTA DE EMPLEADO\n");

                        if(!loadEmployee(arrayEmployees, EMP_ELEMENTS, arraySectors, SEC_ELEMENTS, &idEmployee))
                        {
                            printf("\nEmpleado cargado\n");
                        }

                        else
                        {
                            printf("\nError en alta de empleado\n");
                        }

                        break;

                    case 2:

                        if(!arrayIsEmpty(arrayEmployees, EMP_ELEMENTS))
                        {
                            if(!printEmployees(arrayEmployees, EMP_ELEMENTS, arraySectors, SEC_ELEMENTS) &&
                               !utn_getNumero(&auxId, "\nIngrese el ID del empleado a modificar entre 1 y 10000: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
                               !modifyEmployee(arrayEmployees, EMP_ELEMENTS, arraySectors, SEC_ELEMENTS, auxId))
                            {
                                printf("\nEl empleado ha sido modificado\n");
                            }

                            else
                            {
                                printf("\nError en la modificacion\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados para modificar\n");
                        }

                        break;

                    case 3:

                        if(!arrayIsEmpty(arrayEmployees, EMP_ELEMENTS))
                        {
                            if(!printEmployees(arrayEmployees, EMP_ELEMENTS, arraySectors, SEC_ELEMENTS) &&
                               !utn_getNumero(&auxId, "\nIngrese el ID del empleado a eliminar entre 1 y 10000: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
                               !removeEmployee(arrayEmployees, EMP_ELEMENTS, arraySectors, SEC_ELEMENTS, auxId))
                            {
                                printf("\nEl empleado ha sido eliminado\n");
                            }

                            else
                            {
                                printf("\nError en la baja\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados para eliminar\n");
                        }

                        break;

                    case 4:

                        if(!arrayIsEmpty(arrayEmployees, EMP_ELEMENTS))
                        {
                            if(!showReportsMenu(arrayEmployees, EMP_ELEMENTS, arraySectors, SEC_ELEMENTS))
                            {
                                printf("\nMuestra correcta\n");
                            }

                            else
                            {
                                printf("\nError en la muestra de informes\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados para informar\n");
                        }

                        break;

                    case 5:

                        if(!hardCodeEmployees(arrayEmployees, EMP_ELEMENTS, &idEmployee))
                        {
                            printf("\nAlta forzada realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en el alta forzada\n");
                        }

                        break;

                    case 6:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu de empleados\n");

                            flag = 1;
                        }

                        break;
                }
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(option != 6 || !flag);
    }

    else
    {
        printf("Error en la inicializacion\n");
    }

    return 0;
}
