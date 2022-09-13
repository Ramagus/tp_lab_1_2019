#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"
#define PATH_TXT "data.csv"
#define PATH_BIN "data.bin"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto)
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario)
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listEmployees = NULL;

    int option;
    int flagAnswer;
    int flagClear;
    int flagExit = 0;
    int id = 1;

    listEmployees = ll_newLinkedList();

    if(listEmployees != NULL)
    {
        do
        {
            if(!employee_optionsMenu(&option))
            {
                switch(option)
                {
                    case 1:
                    case 2:

                        flagAnswer = 0;
                        flagClear = 0;

                        if(!ll_isEmpty(listEmployees))
                        {
                            flagAnswer = 1;

                            if(utn_respuestaEsAfirmativa("\nCiudado, se van a sobrescribir los datos. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
                            {
                                if(!employee_clear(listEmployees))
                                {
                                    flagClear = 1;
                                }
                            }

                            else
                            {
                                printf("\nAccion cancelada\n");
                            }
                        }

                        if(!flagAnswer || flagClear)
                        {
                            if(option == 1)
                            {
                                if(!controller_loadFromText(PATH_TXT, listEmployees, &id))
                                {
                                    printf("\nEl archivo de texto se ha leido correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo leer el archivo de texto\n");
                                }
                            }

                            else
                            {
                                if(!controller_loadFromBinary(PATH_BIN, listEmployees, &id))
                                {
                                    printf("\nEl archivo binario se ha leido correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo leer el archivo binario\n");
                                }
                            }
                        }

                        else
                        {
                            printf("\nError en la carga\n");
                        }

                        break;

                    case 3:

                        printf("\n");
                        system("pause");
                        system("cls");

                        printf("\tALTA DE EMPLEADO\n");

                        if(!controller_addEmployee(listEmployees, &id))
                        {
                            printf("\nEmpleado cargado correctamente\n");
                        }

                        else
                        {
                            printf("\nNo se pudo cargar al empleado\n");
                        }

                        break;

                    case 4:

                        if(!ll_isEmpty(listEmployees))
                        {
                            if(!controller_editEmployee(listEmployees))
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
                            printf("\nNo hay empleados cargados para poder modificar\n");
                        }

                        break;

                    case 5:

                        if(!ll_isEmpty(listEmployees))
                        {
                            if(!controller_removeEmployee(listEmployees))
                            {
                                printf("\nEl empleado ha sido eliminado\n");
                            }

                            else
                            {
                                printf("\nError en la eliminacion\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para poder eliminar\n");
                        }

                        break;

                    case 6:

                        if(!ll_isEmpty(listEmployees))
                        {
                            if(!controller_listEmployee(listEmployees))
                            {
                                printf("\nLista mostrada correctamente\n");
                            }

                            else
                            {
                                printf("\nNo se pudo mostrar la lista\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para mostrar\n");
                        }

                        break;

                    case 7:

                        if(!ll_isEmpty(listEmployees))
                        {
                            if(!controller_sortEmployee(listEmployees))
                            {
                                printf("\n\nOrdenamiento realizado correctamente\n");
                            }

                            else
                            {
                                printf("\nNo se pudo realizar el ordenamiento\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para ordenar\n");
                        }

                        break;

                    case 8:

                        if(!ll_isEmpty(listEmployees))
                        {
                            if(!controller_fileExists(PATH_TXT, "r") ||
                               utn_respuestaEsAfirmativa("\nCiudado, se va a sobrescribir el archivo de texto. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
                            {
                                if(!controller_saveAsText(PATH_TXT, listEmployees))
                                {
                                    printf("\nEl archivo de texto se ha escrito correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo escribir el archivo de texto\n");
                                }
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para guardar en el archivo de texto\n");
                        }

                        break;

                    case 9:

                        if(!ll_isEmpty(listEmployees))
                        {
                            if(!controller_fileExists(PATH_BIN, "rb") ||
                               utn_respuestaEsAfirmativa("\nCiudado, se va a sobrescribir el archivo binario. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
                            {
                                if(!controller_saveAsBinary(PATH_BIN, listEmployees))
                                {
                                    printf("\nEl archivo binario se ha escrito correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo escribir el archivo binario\n");
                                }
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para guardar en el archivo binario\n");
                        }

                        break;

                    case 10:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(option != 10 || !flagExit);

        employee_clear(listEmployees);
        ll_deleteLinkedList(listEmployees);
    }

    else
    {
        printf("No se pudo generar el LinkedList\n");
    }

    return 0;
}
