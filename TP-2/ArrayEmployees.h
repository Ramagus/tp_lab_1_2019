#define NAME_LEN 51
#define LAST_NAME_LEN 51
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0

typedef struct
{
    int id;
    char name[NAME_LEN];
    char lastName[LAST_NAME_LEN];
    float salary;
    int sector;
    int isEmpty;

} Employee;


/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all position of the array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief Find the first free position
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if [Invalid length or NULL pointer received or free space not found] or free space index position
 *
 */
int getEmptyIndex(Employee* list, int len);


/** \brief Check if the array is empty
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (1) if True - (0) if False
 *
 */
int arrayIsEmpty(Employee* list, int len);


/** \brief Load some employee data to testing
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int* Employee ID to load
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardCodeEmployees(Employee* list, int len, int* id);


/** \brief Add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID to add
 * \param name[] char Employee name to add
 * \param lastName[] char Employee last name to add
 * \param salary float Employee salary to add
 * \param sector int Employee sector to add
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/** \brief Find an Employee by ID
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID to search
 *
 * \return int (-1) if [Invalid length or NULL pointer received or employee not found] or employee index position
 *
 */
int findEmployeeById(Employee* list, int len, int id);


/** \brief Compares the values of two string
 *
 * \param a char* First string
 * \param b char* Second string
 * \param length int String length
 *
 * \return int (-2) if Error
 *             (-1) if First string is less than Second string in value
 *             ( 0) if both string are equal
 *             ( 1) if First string is greater than Second string in value
 *
 */
int compareString(char* a, char* b, int length);


/** \brief Compares the values of two int
 *
 * \param a int First int
 * \param b int Second int
 *
 * \return int (-2) if Error
 *             (-1) if First int is less than Second int in value
 *             ( 0) if both int are equal
 *             ( 1) if First int is greater than Second int in value
 *
 */
int compareInt(int a, int b);


/** \brief Exchange the values of two employees
 *
 * \param a Employee* First Employee
 * \param b Employee* Second Employee
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int swapEmployees(Employee* a, Employee* b);


/** \brief Sort the elements in the array of employees. The order argument indicate UP or DOWN order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 *
 * \return int (-1) if Error [Invalid length or NULL pointer or wrong order] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief Set the chosen sort order
 *
 * \param option int* Memory space where the chosen order will be saved
 *
 * \return int (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int chooseSortOrder(int* order);


/** \brief Calculate the employee salaries sum
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param accumulator float* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int accumulateEmployeeSalaries(Employee* list, int len, float* accumulator);


/** \brief Calculate the employee salaries quantity
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param counter int* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int countEmployeeSalaries(Employee* list, int len, int* counter);


/** \brief Calculate the salaries average
 *
 * \param accumulator float Employee salaries sum
 * \param counter int Employee salaries quantity
 * \param average float* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int getAverageSalary(float accumulator, int counter, float* average);


/** \brief Calculate how many employees exceed the salary average
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param average float Employee salary average
 * \param counter int* Pointer where the result is saved
 *
 * \return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int countExceededSalariesFromAverage(Employee* list, int len, float average, int* counter);


/** \brief Print options menu to choose
 *
 * \param option int* Memory space where the data entered by the user will be saved
 *
 * \return int (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int showEmployeesMenu(int* option);

