#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Serializer.h"

int serializer_EmployeeToText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int auxReturn = -1;
	int length;
	int i;

	Employee* this = NULL;

	char auxId[BUFFER_LEN];
	char auxNombre[NOMBRE_LEN];
	char auxHorasTrabajadas[BUFFER_LEN];
	char auxSueldo[BUFFER_LEN];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		length = ll_len(pArrayListEmployee);

		if(length > 0)
		{
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

			for(i = 0; i < length; i++)
			{
				this = (Employee*) ll_get(pArrayListEmployee, i);

				if(this != NULL && !employee_getIdTxt(this, auxId) && !employee_getNombre(this, auxNombre) &&
				   !employee_getHorasTrabajadasTxt(this, auxHorasTrabajadas) && !employee_getSueldoTxt(this, auxSueldo))
				{
					fprintf(pFile, "%s,%s,%s,%s\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
				}

				else
				{
					break;
				}
			}

			if(i == length)
			{
				auxReturn = 0;
			}
		}
	}

	return auxReturn;
}

int serializer_EmployeeToBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int auxReturn = -1;
	int length;
	int i;

	Employee* this = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		length = ll_len(pArrayListEmployee);

		if(length > 0)
		{
			for(i = 0; i < length; i++)
			{
				this = (Employee*) ll_get(pArrayListEmployee, i);

				if(this == NULL || fwrite(this, sizeof(Employee), 1, pFile) != 1)
				{
					break;
				}
			}

			if(i == length)
			{
				auxReturn = 0;
			}
		}
	}

	return auxReturn;
}
