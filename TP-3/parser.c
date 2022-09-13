#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* id)
{
    int auxReturn = -1;
    int flag = 0;
    int auxId;

    char idStr[BUFFER_LEN];
    char nombreStr[BUFFER_LEN];
    char horasTrabajadasStr[BUFFER_LEN];
    char sueldoStr[BUFFER_LEN];

    Employee* this = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL && id != NULL)
    {
        do
        {
            this = employee_new();

            if(!employee_delete(this))
            {
                this = NULL;

                if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr) == 4)
                {
                    this = employee_newParametrosTxt(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

                    if(this != NULL)
                    {
                        if(!ll_add(pArrayListEmployee, this))
                        {
                            auxId = atoi(idStr);

                            if(auxId > *id)
                            {
                                *id = auxId + 1;
                            }

                            flag = 1;
                        }

                        else
                        {
                            employee_delete(this);
                            this = NULL;

                            break;
                        }
                    }
                }
            }

            else
            {
                break;
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
    int flagParse = 0;
    int flagRead;
    int auxId;

    Employee* this = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL && id != NULL)
    {
        do
        {
            this = employee_new();

            if(this != NULL)
            {
                flagRead = 0;

                if(fread(this, sizeof(Employee), 1, pFile) == 1)
                {
                    flagRead = 1;
                }

                if(flagRead && !ll_add(pArrayListEmployee, this))
                {
                    if(!employee_getId(this, &auxId) && auxId > *id)
                    {
                        *id = auxId + 1;
                    }

                    flagParse = 1;
                }

                else
                {
                    employee_delete(this);
                    this = NULL;

                    if(flagRead)
                    {
                        break;
                    }
                }
            }

            else
            {
                break;
            }

        } while(!feof(pFile));

        if(flagParse)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}
