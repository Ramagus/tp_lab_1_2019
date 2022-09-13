#include "LinkedList.h"

#define BUFFER_LEN 100


/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* ID de empleado a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* id);


/** \brief Parsea los datos de los empleados desde el archivo data.bin (modo binario)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* ID de empleado a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee, int* id);
