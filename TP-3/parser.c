#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* id)
{
    int auxReturn = -1;
    int flag = 0;

    char idStr[BUFFER_LEN];
    char nombreStr[BUFFER_LEN];
    char horasTrabajadasStr[BUFFER_LEN];
    char sueldoStr[BUFFER_LEN];

    Employee* this = NULL;
    int auxId;

    if(pFile != NULL && pArrayListEmployee != NULL && id != NULL)
    {
        do
        {
            if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr) == 4)
            {
                this = employee_newParametrosTxt(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

                if(this != NULL)
                {
                    auxId = atoi(idStr);

                    if(auxId > *id)
                    {
                        *id = auxId + 1;
                    }

                    ll_add(pArrayListEmployee, this);

                    flag = 1;
                }
            }

        } while(!feof(pFile));

        if(flag)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee, int* id)
{
    int auxReturn = -1;
    int flag = 0;

    Employee* this = NULL;
    int auxId;

    if(pFile != NULL && pArrayListEmployee != NULL && id != NULL)
    {
        do
        {
            this = employee_new();

            if(this != NULL)
            {
                if(fread(this, sizeof(Employee), 1, pFile) == 1)
                {
                    if(!employee_getId(this, &auxId) && auxId > *id)
                    {
                        *id = auxId + 1;
                    }

                    ll_add(pArrayListEmployee, this);

                    flag = 1;
                }

                else
                {
                    employee_delete(this);
                }
            }

        } while(!feof(pFile));

        if(flag)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}
