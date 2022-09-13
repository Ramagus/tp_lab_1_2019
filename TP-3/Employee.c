#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "Employee.h"
#define BUFFER_LEN 20


/** \brief Verifica si la cadena ingresada es numérica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es numérica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isInt(char* cadena, int limite);


/** \brief Verifica si la cadena ingresada es flotante
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es flotante, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isFloat(char* cadena, int limite);


/** \brief Verifica si la cadena ingresada es alfabética
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es alfabética, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isAlphabetical(char* cadena, int limite);


/** \brief Verifica si el id es válido
 *
 * \param horasTrabajadas int Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidId(int id);


/** \brief Verifica si las horas trabajadas son válidas
 *
 * \param horasTrabajadas int Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidWorkedHours(int horasTrabajadas);


/** \brief Verifica si el sueldo es válido
 *
 * \param sueldo float Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidSalary(float sueldo);


/** \brief Imprime las opciones a elegir del menú de modificaciones
 *
 * \param this Employee* Puntero al empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
static int showModificationsMenu(Employee* this);


/** \brief Imprime los datos de un empleado
 *
 * \param this Employee* Puntero al empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
static int printAnEmployee(Employee* this);


/** \brief Compara los valores de dos int
 *
 * \param a int Primer int
 * \param b int Segundo int
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer int es menor al segundo int
 *             ( 0) si ambos int son iguales
 *             ( 1) si el primer int es mayor al segundo int
 *
 */
static int compareInt(int a, int b);


/** \brief Compara los valores de dos float
 *
 * \param a float Primer float
 * \param b float Segundo float
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer float es menor al segundo float
 *             ( 0) si ambos float son iguales
 *             ( 1) si el primer float es mayor al segundo float
 *
 */
static int compareFloat(float a, float b);


/** \brief Compara los valores de dos string
 *
 * \param a char* Primer string
 * \param b char* Segundo string
 * \param length int Longitud de String
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer string es menor al segundo string en su valor
 *             ( 0) si ambos string son iguales
 *             ( 1) si el primer string es mayor al segundo string en su valor
 *
 */
static int compareString(char* a, char* b, int length);


Employee* employee_new(void)
{
    Employee* this = NULL;

    this = (Employee*) malloc(sizeof(Employee));

    return this;
}

Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, float sueldo)
{
    Employee* this = NULL;

    if(nombre != NULL)
    {
        this = employee_new();

        if(this != NULL && (employee_setId(this, id) || employee_setNombre(this, nombre) ||
           employee_setHorasTrabajadas(this, horasTrabajadas) || employee_setSueldo(this, sueldo)))
        {
            employee_delete(this);
            this = NULL;
        }
    }

    return this;
}

Employee* employee_newParametrosTxt(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = NULL;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this = employee_new();

        if(this != NULL && (employee_setIdTxt(this, idStr) || employee_setNombre(this, nombreStr) ||
           employee_setHorasTrabajadasTxt(this, horasTrabajadasStr) || employee_setSueldoTxt(this, sueldoStr)))
        {
            employee_delete(this);
            this = NULL;
        }
    }

    return this;
}

int employee_delete(Employee* this)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        free(this);

        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setId(Employee* this, int id)
{
    int auxReturn = -1;

    if(this != NULL && isValidId(id))
    {
        this->id = id;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setIdTxt(Employee* this, char* id)
{
    int auxReturn = -1;
    int auxId;

    if(this != NULL && id != NULL && isInt(id, BUFFER_LEN) == 1)
    {
        auxId = atoi(id);

        if(isValidId(auxId))
        {
            this->id = auxId;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int auxReturn = -1;

    if(this != NULL && nombre != NULL && isAlphabetical(nombre, NOMBRE_LEN) == 1)
    {
        strncpy(this->nombre, nombre, NOMBRE_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int auxReturn = -1;

    if(this != NULL && isValidWorkedHours(horasTrabajadas))
    {
        this->horasTrabajadas = horasTrabajadas;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
    int auxReturn = -1;
    int auxHorasTrabajadas;

    if(this != NULL && horasTrabajadas != NULL && isInt(horasTrabajadas, BUFFER_LEN) == 1)
    {
        auxHorasTrabajadas = atoi(horasTrabajadas);

        if(isValidWorkedHours(auxHorasTrabajadas))
        {
            this->horasTrabajadas = auxHorasTrabajadas;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_setSueldo(Employee* this, float sueldo)
{
    int auxReturn = -1;

    if(this != NULL && isValidSalary(sueldo))
    {
        this->sueldo = sueldo;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_setSueldoTxt(Employee* this, char* sueldo)
{
    int auxReturn = -1;
    float auxSueldo;

    if(this != NULL && sueldo != NULL && isFloat(sueldo, BUFFER_LEN) == 1)
    {
        auxSueldo = atof(sueldo);

        if(isValidSalary(auxSueldo))
        {
            this->sueldo = auxSueldo;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_getId(Employee* this, int* id)
{
    int auxReturn = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getIdTxt(Employee* this, char* id)
{
    int auxReturn = -1;

    if(this != NULL && id != NULL)
    {
        snprintf(id, BUFFER_LEN, "%d", this->id);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int auxReturn = -1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, NOMBRE_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int auxReturn = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
    int auxReturn = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        snprintf(horasTrabajadas, BUFFER_LEN, "%d", this->horasTrabajadas);
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getSueldo(Employee* this, float* sueldo)
{
    int auxReturn = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        auxReturn = 0;
    }

    return auxReturn;
}

int employee_getSueldoTxt(Employee* this, char* sueldo)
{
    int auxReturn = -1;

    if(this != NULL && sueldo != NULL)
    {
        snprintf(sueldo, BUFFER_LEN, "%.2f", this->sueldo);
        auxReturn = 0;
    }

    return auxReturn;
}

static int isInt(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isFloat(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tienePunto = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if(cadena[i] == '.' && tienePunto == 0)
                {
                    tienePunto = 1;
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isAlphabetical(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalpha(cadena[i]) && !isspace(cadena[i]) && cadena[i] != '-')
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isValidId(int id)
{
    int retorno = 0;

    if(id >= 1 && id <= 10000)
    {
        retorno = 1;
    }

    return retorno;
}

static int isValidWorkedHours(int horasTrabajadas)
{
    int retorno = 0;

    if(horasTrabajadas >= 50 && horasTrabajadas <= 500)
    {
        retorno = 1;
    }

    return retorno;
}

static int isValidSalary(float sueldo)
{
    int retorno = 0;

    if(sueldo >= 10000 && sueldo <= 500000)
    {
        retorno = 1;
    }

    return retorno;
}

static int showModificationsMenu(Employee* this)
{
    int auxReturn = -1;

    char auxNombre[NOMBRE_LEN];
    int auxHorasTrabajadas;
    float auxSueldo;

    char option;

    int flagMod = 0;
    int flagExit = 0;

    if(this != NULL)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACION DE EMPLEADO\n\n");
            printf("A. Nombre\n");
            printf("B. Horas Trabajadas\n");
            printf("C. Sueldo\n");
            printf("D. Salir\n");

            if(!utn_getCaracter(&option, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'D', 2))
            {
                switch(option)
                {
                    case 'A':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el nombre del empleado? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxNombre, "\nIngrese nuevo nombre: ", "Error. Solo letras: ", 4, NOMBRE_LEN, 2) &&
                           !utn_formatearCadena(auxNombre, NOMBRE_LEN) && !employee_setNombre(this, auxNombre))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'B':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar las horas trabajadas del empleado? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getNumero(&auxHorasTrabajadas, "\nIngrese nuevas horas trabajadas entre 50 y 500: ",
                                          "Error. Solo numeros enteros dentro del rango: ", 50, 500, 2) &&
                           !employee_setHorasTrabajadas(this, auxHorasTrabajadas))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el sueldo del empleado? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                           !utn_getNumeroFlotante(&auxSueldo, "\nIngrese nuevo sueldo entre 10000 y 500000: ",
                                                  "Error. Solo numeros flotantes dentro del rango: ", 10000, 500000, 2) &&
                           !employee_setSueldo(this, auxSueldo))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'D':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu de modificacion\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

        } while(option != 'D' || !flagExit);

        if(flagMod)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

static int printAnEmployee(Employee* this)
{
    int auxReturn = -1;

    int auxId;
    char auxNombre[NOMBRE_LEN];
    int auxHorasTrabajadas;
    float auxSueldo;

    if(this != NULL && !employee_getId(this, &auxId) && !employee_getNombre(this, auxNombre) &&
       !employee_getHorasTrabajadas(this, &auxHorasTrabajadas) && !employee_getSueldo(this, &auxSueldo))
    {
        printf("|%-10d|%-20s|%-20d|%-10.2f|\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        auxReturn = 0;
    }

    return auxReturn;
}

static int compareInt(int a, int b)
{
	int auxReturn = -2;

	if(a > 0 && b > 0)
	{
		if(a < b)
		{
			auxReturn = -1;
		}

		else if(a == b)
		{
			auxReturn = 0;
		}

		else
		{
			auxReturn = 1;
		}
	}

	return auxReturn;
}

static int compareFloat(float a, float b)
{
	int auxReturn = -2;

	if(a > 0 && b > 0)
	{
		if(a < b)
		{
			auxReturn = -1;
		}

		else if(a == b)
		{
			auxReturn = 0;
		}

		else
		{
			auxReturn = 1;
		}
	}

	return auxReturn;
}

static int compareString(char* a, char* b, int length)
{
	int auxReturn = -2;
	int auxCmp;

	if(a != NULL && b != NULL && length > 0)
	{
		auxCmp = strncmp(a, b, length);

		if(auxCmp < 0)
		{
			auxReturn = -1;
		}

		else if(auxCmp == 0)
		{
			auxReturn = 0;
		}

		else
		{
			auxReturn = 1;
		}
	}

	return auxReturn;
}

int employee_findEmployeeById(LinkedList* pArrayListEmployee, int id, int* index)
{
    int auxReturn = -1;

    int length;
    int auxId;
    int i;

    Employee* this = NULL;

    if(pArrayListEmployee != NULL && index != NULL)
    {
        length = ll_len(pArrayListEmployee);

        for(i = 0; i < length; i++)
        {
            this = (Employee*) ll_get(pArrayListEmployee, i);

            if(this != NULL && !employee_getId(this, &auxId) && auxId == id)
            {
                *index = i;
                auxReturn = 0;
                break;
            }
        }
    }

    return auxReturn;
}

int employee_add(LinkedList* pArrayListEmployee, int* id)
{
    int auxReturn = -1;

    char auxNombre[NOMBRE_LEN];
    int auxHorasTrabajadas;
    float auxSueldo;

    Employee* this = NULL;

    if(pArrayListEmployee != NULL && id != NULL &&
       !utn_getAlfabetico(auxNombre, "\nIngrese nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2) &&
       !utn_formatearCadena(auxNombre, NOMBRE_LEN) &&
       !utn_getNumero(&auxHorasTrabajadas, "\nIngrese horas trabajadas entre 50 y 500: ",
                                           "Error. Solo numeros enteros dentro del rango: ", 50, 500, 2) &&
       !utn_getNumeroFlotante(&auxSueldo, "\nIngrese sueldo entre 10000 y 500000: ",
                                          "Error. Solo numeros flotantes dentro del rango: ", 10000, 500000, 2))
    {
        this = employee_newParametros(*id, auxNombre, auxHorasTrabajadas, auxSueldo);

        if(this != NULL && !ll_add(pArrayListEmployee, this))
        {
            (*id)++;

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_edit(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int auxId;
    int index;

    Employee* this = NULL;

    if(pArrayListEmployee != NULL && !employee_listEmployee(pArrayListEmployee) &&
       !utn_getNumero(&auxId, "\nIngrese el ID del empleado a modificar entre 1 y 10000: ",
                              "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
       !employee_findEmployeeById(pArrayListEmployee, auxId, &index))
    {
        this = (Employee*) ll_get(pArrayListEmployee, index);

        if(this != NULL)
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMODIFICACION DE EMPLEADO\n\n");

            printf("*----------*--------------------*--------------------*----------*\n");
            printf("|%-10s|%-20s|%-20s|%-10s|\n", "ID", "NOMBRE", "HORAS TRABAJADAS", "SUELDO");
            printf("*----------*--------------------*--------------------*----------*\n");
            printAnEmployee(this);
            printf("*----------*--------------------*--------------------*----------*\n");

            if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este empleado? (S/N): ", "Error. Solo S/N: ") == 1 && !showModificationsMenu(this))
            {
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int employee_remove(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int auxId;
    int index;

    Employee* this = NULL;

    if(pArrayListEmployee != NULL && !employee_listEmployee(pArrayListEmployee) &&
       !utn_getNumero(&auxId, "\nIngrese el ID del empleado a eliminar entre 1 y 10000: ",
                              "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
       !employee_findEmployeeById(pArrayListEmployee, auxId, &index))
    {
        this = (Employee*) ll_get(pArrayListEmployee, index);

        if(this != NULL)
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tBAJA DE EMPLEADO\n\n");

            printf("*----------*--------------------*--------------------*----------*\n");
            printf("|%-10s|%-20s|%-20s|%-10s|\n", "ID", "NOMBRE", "HORAS TRABAJADAS", "SUELDO");
            printf("*----------*--------------------*--------------------*----------*\n");
            printAnEmployee(this);
            printf("*----------*--------------------*--------------------*----------*\n");

            if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este empleado? (S/N): ", "Error. Solo S/N: ") == 1)
            {
                employee_delete(this);
                this = NULL;

                ll_remove(pArrayListEmployee, index);

                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int employee_listEmployee(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int length;
    int i;

    Employee* this = NULL;

    if(pArrayListEmployee != NULL)
    {
        length = ll_len(pArrayListEmployee);

        if(length > 0)
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tLISTA DE EMPLEADOS\n\n");

            printf("*----------*--------------------*--------------------*----------*\n");
            printf("|%-10s|%-20s|%-20s|%-10s|\n", "ID", "NOMBRE", "HORAS TRABAJADAS", "SUELDO");
            printf("*----------*--------------------*--------------------*----------*\n");

            for(i = 0; i < length; i++)
            {
                this = (Employee*) ll_get(pArrayListEmployee, i);

                if(printAnEmployee(this))
                {
                    break;
                }
            }

            printf("*----------*--------------------*--------------------*----------*\n");

            if(i == length)
            {
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int employee_clear(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;
    int length;
    int i;

    Employee* this = NULL;

    if(pArrayListEmployee != NULL)
    {
        length = ll_len(pArrayListEmployee);

        for(i = 0; i < length; i++)
        {
            this = (Employee*) ll_get(pArrayListEmployee, i);

            if(employee_delete(this))
            {
                break;
            }
        }

        if(i == length)
        {
            ll_clear(pArrayListEmployee);
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_chooseCriterionOrder(int (**pFunc)(void*, void*))
{
    int auxReturn = -1;
    char option;

    if(pFunc != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tCRITERIO DE ORDENAMIENTO\n\n");
        printf("A. ID\n");
        printf("B. Nombre\n");
        printf("C. Horas trabajadas\n");
        printf("D. Sueldo\n");

        if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'D', 2))
        {
            switch(option)
            {
                case 'A':

                    *pFunc = employee_compareById;

                    break;

                case 'B':

                    *pFunc = employee_compareByName;

                    break;

                case 'C':

                    *pFunc = employee_compareByWorkedHours;

                    break;

                case 'D':

                    *pFunc = employee_compareBySalary;

                    break;
            }

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_chooseSortOrder(int* order)
{
    int auxReturn = -1;
    char option;

    if(order != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tSENTIDO DE ORDENAMIENTO\n\n");
        printf("A. Orden Ascendente\n");
        printf("B. Orden Descendente\n");

        if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
        {
            switch(option)
            {
                case 'A':

                    *order = 1;

                    break;

                case 'B':

                    *order = 0;

                    break;
            }

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int employee_sort(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    int (*pFunc)(void*, void*) = NULL;
    int order;

    if(pArrayListEmployee != NULL && !employee_chooseCriterionOrder(&pFunc) && !employee_chooseSortOrder(&order))
    {
        printf("\nOrdenando... ");

        ll_sort(pArrayListEmployee, pFunc, order);

        auxReturn = 0;
    }

    return auxReturn;
}

int employee_compareById(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Employee* pEmp1 = NULL;
    Employee* pEmp2 = NULL;

    int id1;
    int id2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pEmp1 = (Employee*) pElement1;
        pEmp2 = (Employee*) pElement2;

        if(!employee_getId(pEmp1, &id1) && !employee_getId(pEmp2, &id2))
        {
            auxReturn = compareInt(id1, id2);
        }
    }

    return auxReturn;
}

int employee_compareByName(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Employee* pEmp1 = NULL;
    Employee* pEmp2 = NULL;

    char name1[NOMBRE_LEN];
    char name2[NOMBRE_LEN];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pEmp1 = (Employee*) pElement1;
        pEmp2 = (Employee*) pElement2;

        if(!employee_getNombre(pEmp1, name1) && !employee_getNombre(pEmp2, name2))
        {
            auxReturn = compareString(name1, name2, NOMBRE_LEN);
        }
    }

    return auxReturn;
}

int employee_compareByWorkedHours(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Employee* pEmp1 = NULL;
    Employee* pEmp2 = NULL;

    int hours1;
    int hours2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pEmp1 = (Employee*) pElement1;
        pEmp2 = (Employee*) pElement2;

        if(!employee_getHorasTrabajadas(pEmp1, &hours1) && !employee_getHorasTrabajadas(pEmp2, &hours2))
        {
            auxReturn = compareInt(hours1, hours2);
        }
    }

    return auxReturn;
}

int employee_compareBySalary(void* pElement1, void* pElement2)
{
    int auxReturn = -3;

    Employee* pEmp1 = NULL;
    Employee* pEmp2 = NULL;

    float salary1;
    float salary2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        pEmp1 = (Employee*) pElement1;
        pEmp2 = (Employee*) pElement2;

        if(!employee_getSueldo(pEmp1, &salary1) && !employee_getSueldo(pEmp2, &salary2))
        {
            auxReturn = compareFloat(salary1, salary2);
        }
    }

    return auxReturn;
}

int employee_optionsMenu(int* option)
{
    int auxReturn = -1;

    if(option != NULL)
    {
        printf("\t\tMENU\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
        printf("10. Salir\n");

        if(!utn_getNumero(option, "\nElija una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2))
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}
