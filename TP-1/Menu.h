/** \brief Imprime las opciones a elegir del menú
 *
 * \param numero1 double Es el primer número
 * \param numero2 double Es el segundo número
 * \param flagNum1 int Bandera que verifica si el primer número está cargado
 * \param flagNum2 int Bandera que verifica si el segundo número está cargado
 * \param opcion int* Lugar donde se cargará la opción ingresada por el usuario
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int mostrarMenuOpciones(double numero1, double numero2, int flagNum1, int flagNum2, int* opcion);


/** \brief Verifica si un número recibido como double es un número entero
 *
 * \param numero double Es el número a analizar
 *
 * \return int 1 Si el número es entero o 0 si no lo es
 *
 */
int esEntero(double numero);


/** \brief Verifica el número recibido para calcular su factorial
 *
 * \param numero double Es el número a verificar
 * \param fact unsigned long int* Lugar donde se guardará el resultado del factorial del número verificado
 * \param flagFact int* Bandera del factorial que verifica si el número es entero positivo
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int procesarFactorial(double numero, unsigned long int* fact, int* flagFact);


/** \brief Calcula las operaciones aritméticas
 *
 * \param numero1 double Es el primer número
 * \param numero2 double Es el segundo número
 * \param suma double* Lugar donde se guardará el resultado de la suma
 * \param resta double* Lugar donde se guardará el resultado de la resta
 * \param division double* Lugar donde se guardará el resultado de la división
 * \param multiplicacion double* Lugar donde se guardará el resultado de multiplicación
 * \param fact1 unsigned long int* Lugar donde se guardará el resultado del factorial del primer número
 * \param fact2 unsigned long int* Lugar donde se guardará el resultado del factorial del segundo número
 * \param flagDiv int* Bandera de la división que verifica si el segundo número no es 0
 * \param flagFact1 int* Bandera del factorial del primer número que verifica si ese número es entero positivo
 * \param flagFact2 int* Bandera del factorial del segundo número que verifica si ese número es entero positivo
 *
 * \return int 0 si está todo Ok o -1 si hubo un error
 *
 */
int realizarOperaciones(double numero1, double numero2, double* suma, double* resta, double* division,
                        double* multiplicacion, unsigned long int* fact1, unsigned long int* fact2,
						int* flagDiv, int* flagFact1, int* flagFact2);


/** \brief Imprime por pantalla el resultado de la división recibida
 *
 * \param division double Es el resultado de la división
 * \param flagDiv int Bandera de la división que verifica si el segundo número no es 0
 *
 * \return void
 *
 */
void informarDivision(double division, int flagDiv);


/** \brief Imprime por pantalla el resultado del factorial recibido
 *
 * \param fact unsigned long int Es el resultado del factorial
 * \param letra char Indica si es el primer número (A) o el segundo número (B)
 * \param flagFact int Bandera del factorial que verifica si el número es entero positivo
 *
 * \return void
 *
 */
void informarFactorial(unsigned long int fact, char letra, int flagFact);


/** \brief Imprime por pantalla los resultados de las operaciones aritméticas
 *
 * \param suma double Es el resultado de la suma
 * \param resta double Es el resultado de la resta
 * \param division double Es el resultado de la división
 * \param multiplicacion double Es el resultado de la multiplicación
 * \param fact1 unsigned long int Es el resultado del factorial del primer número
 * \param fact2 unsigned long int Es el resultado del factorial del segundo número
 * \param flagDiv int Bandera de la división que verifica si el segundo número no es 0
 * \param flagFact1 int Bandera del factorial del primer número que verifica si ese número es entero positivo
 * \param flagFact2 int Bandera del factorial del segundo número que verifica si ese número es entero positivo
 *
 * \return void
 *
 */
void informarResultados(double suma, double resta, double division, double multiplicacion,
		                unsigned long int fact1, unsigned long int fact2,
                        int flagDiv, int flagFact1, int flagFact2);
