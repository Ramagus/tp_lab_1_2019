/** \brief Formaliza el nombre o apellido recibido
 *
 * \param cadena char* Nombre o apellido a ser formalizado
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna -1 si hubo un error (puntero NULL o límite inválido) y 0 si no
 *
 */
int utn_formatearCadena(char* cadena, int limite);


/** \brief Solicita un número entero al usuario y devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es el número mínimo a ser aceptado
 * \param maximo int Es el número máximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el número y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita un número flotante al usuario y devuelve el resultado
 *
 * \param pResultado float* Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo float Es el número mínimo a ser aceptado
 * \param maximo float Es el número máximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el número y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/** \brief Solicita una cadena alfabética al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad mínima de caracteres a ser aceptada
 * \param maximo int Es la cantidad máxima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getAlfabetico(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita un caracter al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo char Es el caracter mínimo a ser aceptado
 * \param maximo char Es el caracter máximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el caracter y -1 si no
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


/** \brief Verifica si la respuesta es afirmativa
 *
 * \param mensaje char* Texto que pide el valor
 * \param mensajeError char* Texto en caso de error
 *
 * \return int Retorna 1 si la respuesta es 'S', 0 si la respuesta es 'N' o -1 si hubo un error
 *
 */
int utn_respuestaEsAfirmativa(char* mensaje, char* mensajeError);

