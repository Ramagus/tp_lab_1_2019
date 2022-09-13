#include "LinkedList.h"

#define BUFFER_LEN 100


/** \brief Serializa los datos de los empleados al archivo data.csv (modo texto)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int serializer_EmployeeToText(FILE* pFile, LinkedList* pArrayListEmployee);


/** \brief Serializa los datos de los empleados al archivo data.bin (modo binario)
 *
 * \param pFile FILE* Puntero al Archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int serializer_EmployeeToBinary(FILE* pFile, LinkedList* pArrayListEmployee);
