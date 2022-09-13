#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"
#include "Serializer.h"
#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int* id)
{
    int auxReturn = -1;

    FILE* pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL && id != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee, id))
            {
                auxReturn = 0;
            }

            fclose(pFile);
            pFile = NULL;
        }
    }

    return auxReturn;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int* id)
{
    int auxReturn = -1;

    FILE* pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL && id != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee, id))
            {
                auxReturn = 0;
            }

            fclose(pFile);
            pFile = NULL;
        }
    }

    return auxReturn;
}

int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int auxReturn = -1;

    if(pArrayListEmployee != NULL && id != NULL && !employee_add(pArrayListEmployee, id))
    {
        auxReturn = 0;
    }

    return auxReturn;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    if(pArrayListEmployee != NULL && !employee_edit(pArrayListEmployee))
    {
        auxReturn = 0;
    }

    return auxReturn;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    if(pArrayListEmployee != NULL && !employee_remove(pArrayListEmployee))
    {
        auxReturn = 0;
    }

    return auxReturn;
}

int controller_listEmployee(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    if(pArrayListEmployee != NULL && !employee_listEmployee(pArrayListEmployee))
    {
        auxReturn = 0;
    }

    return auxReturn;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    if(pArrayListEmployee != NULL && !employee_sort(pArrayListEmployee))
    {
        auxReturn = 0;
    }

    return auxReturn;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    FILE* pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");

        if(pFile != NULL)
        {
            if(!serializer_EmployeeToText(pFile, pArrayListEmployee))
            {
                auxReturn = 0;
            }

            fclose(pFile);
            pFile = NULL;
        }
    }

    return auxReturn;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    FILE* pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");

        if(pFile != NULL)
        {
            if(!serializer_EmployeeToBinary(pFile, pArrayListEmployee))
            {
                auxReturn = 0;
            }

            fclose(pFile);
            pFile = NULL;
        }
    }

    return auxReturn;
}

int controller_fileExists(char* path, char* mode)
{
    int auxReturn = -1;

    FILE* pFile = NULL;

    if(path != NULL && mode != NULL)
    {
        auxReturn = 0;

        pFile = fopen(path, mode);

        if(pFile != NULL)
        {
            auxReturn = 1;

            fclose(pFile);
            pFile = NULL;
        }
    }

    return auxReturn;
}
