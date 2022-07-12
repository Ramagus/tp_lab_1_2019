#include "ArrayEmployees.h"
#include "Sector.h"


/** \brief Load an employee data
 *
 * \param listEmployees Employee* Pointer to array of employees
 * \param lenEmp int Array of employees length
 * \param listSectors Sector* Pointer to array of sectors
 * \param lenSec int Array of sectors length
 * \param idEmp int* Employee ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int loadEmployee(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec, int* idEmp);


/** \brief Modify an Employee by ID
 *
 * \param listEmployees Employee* Pointer to array of employees
 * \param lenEmp int Array of employees length
 * \param listSectors Sector* Pointer to array of sectors
 * \param lenSec int Array of sectors length
 * \param idEmp int Employee ID to modify
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int modifyEmployee(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec, int idEmp);


/** \brief Modify the Employee chosen data
 *
 * \param listEmployees Employee* Pointer to array of employees
 * \param lenEmp int Array of employees length
 * \param listSectors Sector* Pointer to array of sectors
 * \param lenSec int Array of sectors length
 * \param indexEmp int Employee index position to modify
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or invalid index or if can't modify the Employee] - (0) if Ok
 *
 */
int showModificationsMenu(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec, int indexEmp);


/** \brief Remove an Employee by ID (put isEmpty Flag in TRUE)
 *
 * \param listEmployees Employee* Pointer to array of employees
 * \param lenEmp int Array of employees length
 * \param listSectors Sector* Pointer to array of sectors
 * \param lenSec int Array of sectors length
 * \param idEmp int Employee ID to remove
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec, int idEmp);


/** \brief Print the content of employee
 *
 * \param anEmployee Employee* Pointer to one employee
 * \param aSector Sector* Pointer to employee related sector
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printAnEmployee(Employee* anEmployee, Sector* aSector);


/** \brief Print the content of employees array
 *
 * \param listEmployees Employee* Pointer to array of employees
 * \param lenEmp int Array of employees length
 * \param listSectors Sector* Pointer to array of sectors
 * \param lenSec int Array of sectors length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec);


/** \brief Print the info chosen
 *
 * \param listEmployees Employee* Pointer to array of employees
 * \param lenEmp int Array of employees length
 * \param listSectors Sector* Pointer to array of sectors
 * \param lenSec int Array of sectors length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int showReportsMenu(Employee* listEmployees, int lenEmp, Sector* listSectors, int lenSec);

