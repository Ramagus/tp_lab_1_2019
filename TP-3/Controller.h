#include "LinkedList.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* ID de empleado a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int* id);


/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* ID de empleado a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int* id);


/** \brief Alta de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* ID de empleado a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_listEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario)
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);


/** \brief Comprueba si un archivo existe
 *
 * \param path char* Ruta donde se encuentra el archivo
 * \param mode char* Modo de acceso al archivo
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int controller_fileExists(char* path, char* mode);
