#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED


#include "LinkedList.h"
#define NOMBRE_LEN 128


typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    float sueldo;

} Employee;


/** \brief Reserva espacio en memoria para un nuevo empleado
 *
 * \param void
 *
 * \return Employee* Retorna un puntero al empleado o NULL en caso de error
 *
 */
Employee* employee_new(void);


/** \brief Reserva espacio en memoria para un nuevo empleado y setea sus campos
 *         con los valores recibidos como parámetros
 *
 * \param id int ID del empleado
 * \param nombre char* Nombre del empleado
 * \param horasTrabajadas int Cantidad de horas que trabaja el empleado
 * \param sueldo float Sueldo del empleado
 *
 * \return Employee* Retorna un puntero al empleado o NULL en caso de error
 *
 */
Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, float sueldo);


/** \brief Reserva espacio en memoria para un nuevo empleado y setea sus campos como cadena
 *         con los valores recibidos como parámetros
 *
 * \param idStr char* ID del empleado
 * \param nombreStr char* Nombre del empleado
 * \param horasTrabajadasStr char* Cantidad de horas que trabaja el empleado
 * \param sueldoStr char* Sueldo del empleado
 *
 * \return Employee* Retorna un puntero al empleado o NULL en caso de error
 *
 */
Employee* employee_newParametrosTxt(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);


/** \brief Libera el espacio ocupado por un empleado recibido como parámetro
 *
 * \param this Employee* Puntero al empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_delete(Employee* this);


/** \brief Setea el ID de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param id int ID del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_setId(Employee* this, int id);


/** \brief Setea el ID de un empleado recibiendolo como cadena
 *
 * \param this Employee* Puntero al empleado
 * \param id char* ID del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_setIdTxt(Employee* this, char* id);


/** \brief Setea el nombre de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param nombre char* Nombre del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_setNombre(Employee* this, char* nombre);


/** \brief Setea las horas trabajadas de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int Cantidad de horas que trabaja el empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);


/** \brief Setea las horas trabajadas de un empleado recibiendolo como cadena
 *
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas char* Cantidad de horas que trabaja el empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);


/** \brief Setea el sueldo de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param sueldo float Sueldo del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_setSueldo(Employee* this, float sueldo);


/** \brief Setea el sueldo de un empleado recibiendolo como cadena
 *
 * \param this Employee* Puntero al empleado
 * \param sueldo char* Sueldo del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_setSueldoTxt(Employee* this, char* sueldo);


/** \brief Obtiene el ID de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param id int* Puntero donde se guardará el ID del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_getId(Employee* this, int* id);


/** \brief Obtiene el ID de un empleado como cadena
 *
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero donde se guardará el ID del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_getIdTxt(Employee* this, char* id);


/** \brief Obtiene el nombre de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero donde se guardará el nombre del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_getNombre(Employee* this, char* nombre);


/** \brief Obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int* Puntero donde se guardará la cantidad de horas que trabaja el empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);


/** \brief Obtiene las horas trabajadas de un empleado como cadena
 *
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas char* Puntero donde se guardará la cantidad de horas que trabaja el empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);


/** \brief Obtiene el sueldo de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param sueldo float* Puntero donde se guardará el sueldo del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_getSueldo(Employee* this, float* sueldo);


/** \brief Obtiene el sueldo de un empleado como cadena
 *
 * \param this Employee* Puntero al empleado
 * \param sueldo char* Puntero donde se guardará el sueldo del empleado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_getSueldoTxt(Employee* this, char* sueldo);


/** \brief Encuentra un empleado por ID
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int ID del empleado a buscar
 * \param index int* Índice del empleado encontrado
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_findEmployeeById(LinkedList* pArrayListEmployee, int id, int* index);


/** \brief Agrega un empleado a la lista
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 * \param id int* ID de empleado a asignar
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_add(LinkedList* pArrayListEmployee, int* id);


/** \brief Modifica los datos de un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_edit(LinkedList* pArrayListEmployee);


/** \brief Elimina un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_remove(LinkedList* pArrayListEmployee);


/** \brief Muestra la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_listEmployee(LinkedList* pArrayListEmployee);


/** \brief Elimina la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_clear(LinkedList* pArrayListEmployee);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param pFunc (**pFunc) Puntero a la función criterio
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_chooseCriterionOrder(int (**pFunc)(void*, void*));


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_chooseSortOrder(int* order);


/** \brief Ordena a los empleados según el criterio y el sentido elegidos
 *
 * \param pArrayListEmployee LinkedList* Puntero al LinkedList
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_sort(LinkedList* pArrayListEmployee);


/** \brief Función criterio que compara dos empleados por ID
 *
 * \param pElement1 void* Primer empleado a comparar
 * \param pElement2 void* Segundo empleado a comparar
 *
 * \return int Retorna (-3) si hubo un error en los parámetros
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el ID del primer empleado es menor al ID del segundo empleado
 *                     ( 0) si ambos ID son iguales
 *                     ( 1) si el ID del primer empleado es mayor al ID del segundo empleado
 *
 */
int employee_compareById(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos empleados por nombre
 *
 * \param pElement1 void* Primer empleado a comparar
 * \param pElement2 void* Segundo empleado a comparar
 *
 * \return int Retorna (-3) si hubo un error en los parámetros
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el nombre del primer empleado es menor alfabéticamente al nombre del segundo empleado
 *                     ( 0) si ambos nombres son iguales
 *                     ( 1) si el nombre del primer empleado es mayor alfabéticamente al nombre del segundo empleado
 *
 */
int employee_compareByName(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos empleados por cantidad de horas trabajadas
 *
 * \param pElement1 void* Primer empleado a comparar
 * \param pElement2 void* Segundo empleado a comparar
 *
 * \return int Retorna (-3) si hubo un error en los parámetros
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si la cantidad de horas trabajadas del primer empleado es menor a la cantidad de horas trabajadas del segundo empleado
 *                     ( 0) si ambas cantidades son iguales
 *                     ( 1) si la cantidad de horas trabajadas del primer empleado es mayor a la cantidad de horas trabajadas del segundo empleado
 *
 */
int employee_compareByWorkedHours(void* pElement1, void* pElement2);


/** \brief Función criterio que compara dos empleados por sueldo
 *
 * \param pElement1 void* Primer empleado a comparar
 * \param pElement2 void* Segundo empleado a comparar
 *
 * \return int Retorna (-3) si hubo un error en los parámetros
 *                     (-2) si hubo un error en la comparación
 *                     (-1) si el sueldo del primer empleado es menor al sueldo del segundo empleado
 *                     ( 0) si ambos sueldos son iguales
 *                     ( 1) si el sueldo del primer empleado es mayor al sueldo del segundo empleado
 *
 */
int employee_compareBySalary(void* pElement1, void* pElement2);



/** \brief Imprime las opciones a elegir del menú de empleados
 *
 * \param option int* Espacio de memoria donde se guardará el dato ingresado por el usuario
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int employee_optionsMenu(int* option);


#endif // employee_H_INCLUDED
