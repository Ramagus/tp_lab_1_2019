/** \brief Imprime las opciones a elegir del men�
 *
 * \param numero1 double Es el primer n�mero
 * \param numero2 double Es el segundo n�mero
 * \param flagNum1 int Bandera que verifica si el primer n�mero est� cargado
 * \param flagNum2 int Bandera que verifica si el segundo n�mero est� cargado
 * \param opcion int* Lugar donde se cargar� la opci�n ingresada por el usuario
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int mostrarMenuOpciones(double numero1, double numero2, int flagNum1, int flagNum2, int* opcion);


/** \brief Verifica si un n�mero recibido como double es un n�mero entero
 *
 * \param numero double Es el n�mero a analizar
 *
 * \return int 1 Si el n�mero es entero o 0 si no lo es
 *
 */
int esEntero(double numero);


/** \brief Verifica el n�mero recibido para calcular su factorial
 *
 * \param numero double Es el n�mero a verificar
 * \param fact unsigned long int* Lugar donde se guardar� el resultado del factorial del n�mero verificado
 * \param flagFact int* Bandera del factorial que verifica si el n�mero es entero positivo
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int procesarFactorial(double numero, unsigned long int* fact, int* flagFact);


/** \brief Calcula las operaciones aritm�ticas
 *
 * \param numero1 double Es el primer n�mero
 * \param numero2 double Es el segundo n�mero
 * \param suma double* Lugar donde se guardar� el resultado de la suma
 * \param resta double* Lugar donde se guardar� el resultado de la resta
 * \param division double* Lugar donde se guardar� el resultado de la divisi�n
 * \param multiplicacion double* Lugar donde se guardar� el resultado de multiplicaci�n
 * \param fact1 unsigned long int* Lugar donde se guardar� el resultado del factorial del primer n�mero
 * \param fact2 unsigned long int* Lugar donde se guardar� el resultado del factorial del segundo n�mero
 * \param flagDiv int* Bandera de la divisi�n que verifica si el segundo n�mero no es 0
 * \param flagFact1 int* Bandera del factorial del primer n�mero que verifica si ese n�mero es entero positivo
 * \param flagFact2 int* Bandera del factorial del segundo n�mero que verifica si ese n�mero es entero positivo
 *
 * \return int 0 si est� todo Ok o -1 si hubo un error
 *
 */
int realizarOperaciones(double numero1, double numero2, double* suma, double* resta, double* division,
                        double* multiplicacion, unsigned long int* fact1, unsigned long int* fact2,
						int* flagDiv, int* flagFact1, int* flagFact2);


/** \brief Imprime por pantalla el resultado de la divisi�n recibida
 *
 * \param division double Es el resultado de la divisi�n
 * \param flagDiv int Bandera de la divisi�n que verifica si el segundo n�mero no es 0
 *
 * \return void
 *
 */
void informarDivision(double division, int flagDiv);


/** \brief Imprime por pantalla el resultado del factorial recibido
 *
 * \param fact unsigned long int Es el resultado del factorial
 * \param letra char Indica si es el primer n�mero (A) o el segundo n�mero (B)
 * \param flagFact int Bandera del factorial que verifica si el n�mero es entero positivo
 *
 * \return void
 *
 */
void informarFactorial(unsigned long int fact, char letra, int flagFact);


/** \brief Imprime por pantalla los resultados de las operaciones aritm�ticas
 *
 * \param suma double Es el resultado de la suma
 * \param resta double Es el resultado de la resta
 * \param division double Es el resultado de la divisi�n
 * \param multiplicacion double Es el resultado de la multiplicaci�n
 * \param fact1 unsigned long int Es el resultado del factorial del primer n�mero
 * \param fact2 unsigned long int Es el resultado del factorial del segundo n�mero
 * \param flagDiv int Bandera de la divisi�n que verifica si el segundo n�mero no es 0
 * \param flagFact1 int Bandera del factorial del primer n�mero que verifica si ese n�mero es entero positivo
 * \param flagFact2 int Bandera del factorial del segundo n�mero que verifica si ese n�mero es entero positivo
 *
 * \return void
 *
 */
void informarResultados(double suma, double resta, double division, double multiplicacion,
		                unsigned long int fact1, unsigned long int fact2,
                        int flagDiv, int flagFact1, int flagFact2);
