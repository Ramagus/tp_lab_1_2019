/** \brief Se calcula la suma entre 2 n�meros
 *
 * \param x double Es el primer n�mero
 * \param y double Es el segundo n�mero
 * \param pResultado double* Lugar donde se guardar� el resultado de la suma
 *
 * \return int Devuelve 0 si est� todo Ok, o -1 si hubo un error
 *
 */
int sumar(double x, double y, double* pResultado);


/** \brief Se calcula la resta entre 2 n�meros
 *
 * \param x double Es el primer n�mero
 * \param y double Es el segundo n�mero
 * \param pResultado double* Lugar donde se guardar� el resultado de la resta
 *
 * \return int Devuelve 0 si est� todo Ok, o -1 si hubo un error
 *
 */
int restar(double x, double y, double* pResultado);


/** \brief Se calcula la divisi�n entre 2 n�meros
 *
 * \param x double Es el primer n�mero
 * \param y double Es el segundo n�mero
 * \param pResultado double* Lugar donde se guardar� el resultado de la divisi�n
                             en caso de que el divisor no sea cero
 *
 * \return int Devuelve 0 si el segundo n�mero (divisor) es distinto de cero,
               o -1 si el segundo n�mero es igual a cero
 *
 */
int dividir(double x, double y, double* pResultado);


/** \brief Se calcula la multiplicaci�n entre 2 n�meros
 *
 * \param x double Es el primer n�mero
 * \param y double Es el segundo n�mero
 * \param pResultado double* Lugar donde se guardar� el resultado de la multiplicaci�n
 *
 * \return int Devuelve 0 si est� todo Ok, o -1 si hubo un error
 *
 */
int multiplicar(double x, double y, double* pResultado);


/** \brief Se calcula el factorial de un n�mero
 *
 * \param n int Es el n�mero a calcular
 * \param pResultado unsigned long int* Lugar donde se guardar� el resultado del factorial
                                        en caso de que el n�mero sea mayor o igual a cero
 *
 * \return int Devuelve 0 si el n�mero es mayor o igual a cero, o -1 si hubo un error
 *
 */
int factorial(int n, unsigned long int* pResultado);
