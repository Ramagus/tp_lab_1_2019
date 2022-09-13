#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nexus.h"
#include "Input.h"

int loadEmployee(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec, int* idEmp)
{
    int auxReturn = -1;

    char auxName[NAME_LEN];
    char auxLastName[LAST_NAME_LEN];
    float auxSalary;
    int auxSector;

    if(listEmployees != NULL && lenEmp > 0 && listSectors != NULL && lenSec > 0 && idEmp != NULL &&
       !utn_getAlfabetico(auxName, "\nIngrese nombre: ", "Error. Ingrese solo letras: ", 3, NAME_LEN, 2) &&
       !utn_formatearCadena(auxName, NAME_LEN) &&
       !utn_getAlfabetico(auxLastName, "\nIngrese apellido: ", "Error. Ingrese solo letras: ", 3, LAST_NAME_LEN, 2) &&
       !utn_formatearCadena(auxLastName, LAST_NAME_LEN) &&
       !utn_getNumeroFlotante(&auxSalary, "\nIngrese salario entre 1 y 500000: ", "Error. Ingrese solo numeros flotantes dentro del rango: ", 1, 500000, 2) &&
       !printSectors(listSectors, lenSec) &&
       !utn_getNumero(&auxSector, "\nIngrese sector: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 6, 2) &&
       findSectorById(listSectors, lenSec, auxSector) > -1 &&
       !addEmployee(listEmployees, lenEmp, *idEmp, auxName, auxLastName, auxSalary, auxSector))
    {
        (*idEmp)++;

        auxReturn = 0;
    }

    return auxReturn;
}

int modifyEmployee(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec, int idEmp)
{
    int auxReturn = -1;
    int indexEmp;
    int indexSec;

    if(listEmployees != NULL && lenEmp > 0 && listSectors != NULL && lenSec > 0 && idEmp > 0)
    {
        indexEmp = findEmployeeById(listEmployees, lenEmp, idEmp);

        if(indexEmp > -1)
        {
            indexSec = findSectorById(listSectors, lenSec, listEmployees[indexEmp].sector);

            if(indexSec > -1)
            {
                printf("\n");
                system("pause");
                system("cls");

                printf("\tMODIFICACION DE EMPLEADO\n\n");

                printf("*----------*--------------------*--------------------*----------*------------------------------*\n");
				printf("|%-10s|%-20s|%-20s|%-10s|%-30s|\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
				printf("*----------*--------------------*--------------------*----------*------------------------------*\n");
                printAnEmployee(&listEmployees[indexEmp], &listSectors[indexSec]);
                printf("*----------*--------------------*--------------------*----------*------------------------------*\n");

                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                   !showModificationsMenu(listEmployees, lenEmp, listSectors, lenSec, indexEmp))
                {
                    auxReturn = 0;
                }
            }
        }
    }

    return auxReturn;
}

int showModificationsMenu(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec, int indexEmp)
{
    int auxReturn = -1;

    char auxName[NAME_LEN];
    char auxLastName[LAST_NAME_LEN];
    float auxSalary;
    int auxSector;

    char option;

    int flagMod = FALSE;
    int flagExit = FALSE;

    if(listEmployees != NULL && lenEmp > 0 && listSectors != NULL && lenSec > 0 && indexEmp >= 0 && indexEmp < lenEmp)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACION DE EMPLEADO\n\n");
            printf("A. Nombre\n");
            printf("B. Apellido\n");
            printf("C. Salario\n");
            printf("D. Sector\n");
            printf("E. Salir\n");

            if(!utn_getCaracter(&option, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'E', 2))
            {
                switch(option)
                {
                    case 'A':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el nombre del empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxName, "\nIngrese nuevo nombre: ", "Error. Ingrese solo letras: ", 3, NAME_LEN, 2) && !utn_formatearCadena(auxName, NAME_LEN))
                        {
                            strncpy(listEmployees[indexEmp].name, auxName, NAME_LEN);

                            flagMod = TRUE;
                        }

                        break;

                    case 'B':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el apellido del empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxLastName, "\nIngrese nuevo apellido: ", "Error. Ingrese solo letras: ", 3, LAST_NAME_LEN, 2) && !utn_formatearCadena(auxLastName, LAST_NAME_LEN))
                        {
                            strncpy(listEmployees[indexEmp].lastName, auxLastName, LAST_NAME_LEN);

                            flagMod = TRUE;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el salario del empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getNumeroFlotante(&auxSalary, "\nIngrese nuevo salario entre 1 y 500000: ", "Error. Ingrese solo numeros flotantes dentro del rango: ", 1, 500000, 2))
                        {
                            listEmployees[indexEmp].salary = auxSalary;

                            flagMod = TRUE;
                        }

                        break;

                    case 'D':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el sector del empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !printSectors(listSectors, lenSec) &&
                           !utn_getNumero(&auxSector, "\nIngrese nuevo sector: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 6, 2) &&
                           findSectorById(listSectors, lenSec, listEmployees[indexEmp].sector) > -1)
                        {
                            listEmployees[indexEmp].sector = auxSector;

                            flagMod = TRUE;
                        }

                        break;

                    case 'E':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu de modificacion\n");

                            flagExit = TRUE;
                        }

                        break;
                }
            }

        } while(option != 'E' || !flagExit);

        if(flagMod)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int removeEmployee(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec, int idEmp)
{
    int auxReturn = -1;
    int indexEmp;
    int indexSec;

    if(listEmployees != NULL && lenEmp > 0 && listSectors != NULL && lenSec > 0 && idEmp > 0)
    {
        indexEmp = findEmployeeById(listEmployees, lenEmp, idEmp);

        if(indexEmp > -1)
        {
            indexSec = findSectorById(listSectors, lenSec, listEmployees[indexEmp].sector);

            if(indexSec > -1)
            {
                printf("\n");
                system("pause");
                system("cls");

                printf("\tBAJA DE EMPLEADO\n\n");

                printf("*----------*--------------------*--------------------*----------*------------------------------*\n");
				printf("|%-10s|%-20s|%-20s|%-10s|%-30s|\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
				printf("*----------*--------------------*--------------------*----------*------------------------------*\n");
                printAnEmployee(&listEmployees[indexEmp], &listSectors[indexSec]);
                printf("*----------*--------------------*--------------------*----------*------------------------------*\n");

                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este empleado? (S/N): ", "Error. Solo S o N: ") == 1)
                {
                    listEmployees[indexEmp].isEmpty = TRUE;
                    auxReturn = 0;
                }
            }
        }
    }

    return auxReturn;
}

int printAnEmployee(Employee* anEmployee, Sector* aSector)
{
    int auxReturn = -1;

    if(anEmployee != NULL && aSector != NULL)
    {
        printf("|%-10d|%-20s|%-20s|%-10.2f|%-30s|\n", anEmployee->id, anEmployee->name, anEmployee->lastName, anEmployee->salary, aSector->description);

        auxReturn = 0;
    }

    return auxReturn;
}

int printEmployees(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec)
{
    int auxReturn = -1;
    int index;
    int i;

    if(listEmployees != NULL && lenEmp > 0 && listSectors != NULL && lenSec > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE EMPLEADOS\n\n");

        printf("*----------*--------------------*--------------------*----------*------------------------------*\n");
        printf("|%-10s|%-20s|%-20s|%-10s|%-30s|\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
        printf("*----------*--------------------*--------------------*----------*------------------------------*\n");

        for(i = 0; i < lenEmp; i++)
        {
            if(listEmployees[i].isEmpty == FALSE)
            {
                index = findSectorById(listSectors, lenSec, listEmployees[i].sector);

                if(index > -1 && printAnEmployee(&listEmployees[i], &listSectors[index]))
                {
                    break;
                }
            }
        }

        printf("*----------*--------------------*--------------------*----------*------------------------------*\n");

        if(i == lenEmp)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int showReportsMenu(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec)
{
    int auxReturn = -1;

    int order;
    float salaryAccumulator;
    int salaryCounter;
    float averageSalary;
    int employeeCounter;

    int option;

    int flagRep = FALSE;
    int flagExit = FALSE;

    if(listEmployees != NULL && lenEmp > 0 && listSectors != NULL && lenSec > 0)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE INFORMES\n\n");
            printf("1. Lista ordenada de empleados\n");
            printf("2. Promedio de salarios\n");
            printf("3. Salir\n");

            if(!utn_getNumero(&option, "\nElija una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 3, 2))
            {
                switch(option)
                {
                    case 1:

                        if(!chooseSortOrder(&order) && !sortEmployees(listEmployees, lenEmp, order))
                        {
                            printf("\nOrdenamiento realizado correctamente\n");

                            if(!printEmployees(listEmployees, lenEmp, listSectors, lenSec))
                            {
                                printf("\nLista mostrada correctamente\n");

                                flagRep = TRUE;
                            }

                            else
                            {
                                printf("\nNo se pudo mostrar la lista\n");
                            }
                        }

                        else
                        {
                            printf("\nError en el ordenamiento\n");
                        }

                        break;

                    case 2:

                        printf("\n");
                        system("pause");
                        system("cls");

                        if(!accumulateEmployeeSalaries(listEmployees, lenEmp, &salaryAccumulator) && !countEmployeeSalaries(listEmployees, lenEmp, &salaryCounter) &&
                           !getAverageSalary(salaryAccumulator, salaryCounter, &averageSalary) && !countExceededSalariesFromAverage(listEmployees, lenEmp, averageSalary, &employeeCounter))
                        {
                            printf("\tINFORME DE SALARIOS\n");

                            printf("\nSuma de salarios: %.2f - Cantidad de salarios: %d\n", salaryAccumulator, salaryCounter);
                            printf("\nEl promedio de salarios es: %.2f\n", averageSalary);

                            if(employeeCounter > 0)
                            {
                                printf("\nCantidad de empleados que superan el salario promedio: %d\n", employeeCounter);
                            }

                            else
                            {
                                printf("\nNo hay empleados que superen el salario promedio\n");
                            }

                            flagRep = TRUE;
                        }

                        else
                        {
                            printf("\nNo se pudo calcular el salario\n");
                        }

                        break;

                    case 3:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu de informes\n");

                            flagExit = TRUE;
                        }

                        break;
                }
            }

        } while(option != 3 || !flagExit);

        if(flagRep)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}
