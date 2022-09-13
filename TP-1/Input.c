#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Input.h"

#define MAX_LEN 100


/** \brief Lee de stdin una cadena hasta que encuentra un '\n' o hasta que haya copiado
 *         un máximo de "longitud - 1" caracteres
 *
 * \param pResultado char* Puntero al espacio de memoria donde se copiará la cadena obtenida
 * \param longitud int Define el tamaño de cadena
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud);


/** \brief Verifica si la cadena ingresada es numérica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es numérica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite);


/** \brief Obtiene un número entero
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejará el resultado de la función
 *
 * \return int Retorna 0 (EXITO) si se obtiene un número entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado);


/** \brief Verifica si la cadena ingresada es flotante
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es flotante, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esFlotante(char* cadena, int limite);


/** \brief Obtiene un número double
 *
 * \param pResultado double* Puntero al espacio de memoria donde se dejará el resultado de la función
 *
 * \return int Retorna 0 (EXITO) si se obtiene un número flotante y -1 (ERROR) si no
 *
 */
static int getDouble(double* pResultado);


static int getString(char* cadena, int longitud)
{
    int retorno = -1;
    int len;

    if(cadena != NULL && longitud > 0)
    {
    	fflush(stdin);

        if(fgets(cadena, MAX_LEN, stdin) != NULL)
        {
            len = strnlen(cadena, MAX_LEN);

            if(len < longitud)
            {
                if(cadena[len - 1] == '\n')
                {
                    cadena[len - 1] = '\0';
                }

                retorno = 0;
            }
        }
    }

    return retorno;
}

static int esNumerica(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if((i == 0) && (cadena[i] == '-' || cadena[i] == '+'))
                {
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esNumerica(bufferString, MAX_LEN) == 1)
    {
        *pResultado = atoi(bufferString);
        retorno = 0;
    }

    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    int flagError = 0;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

        } while(getInt(pResultado));

        retorno = 0;
    }

    return retorno;
}

static int esFlotante(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tienePunto = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if((i == 0) && (cadena[i] == '-' || cadena[i] == '+'))
                {
                    continue;
                }

                if(cadena[i] == '.' && tienePunto == 0)
                {
                    tienePunto = 1;
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getDouble(double* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esFlotante(bufferString, MAX_LEN) == 1)
    {
        *pResultado = atof(bufferString);
        retorno = 0;
    }

    return retorno;
}

int utn_getNumeroDouble(double* pResultado, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    int flagError = 0;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

        } while(getDouble(pResultado));

        retorno = 0;
    }

    return retorno;
}

int utn_respuestaEsAfirmativa(char* mensaje, char* mensajeError)
{
    int retorno = -1;
    int flagError = 0;
    char dato = '\0';

    if(mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            dato = toupper(getche());
            printf("\n");

        } while(dato != 'S' && dato != 'N');

        switch(dato)
        {
            case 'S':

                retorno = 1;

                break;

            case 'N':

                retorno = 0;

                break;
        }
    }

    return retorno;
}
