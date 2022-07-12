#include <stdio.h>
#include <stdlib.h>
#include "Sector.h"

int hardCodeSectors(Sector* list, int len, int* id)
{
    int auxReturn = -1;
    int i;
    int quantity;

    Sector auxSectors[] =
    {
        {0, "Comunicacion"},
        {0, "Finanzas"},
        {0, "Salud"},
        {0, "Educacion"},
        {0, "Construccion"},
        {0, "Transporte y Logistica"}
    };

    if(list != NULL && len > 0 && id != NULL)
    {
        quantity = sizeof(auxSectors) / sizeof(Sector);

        if(quantity <= len)
        {
            for(i = 0; i < quantity; i++)
            {
                list[i] = auxSectors[i];
                list[i].id = *id;

                (*id)++;
            }

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int findSectorById(Sector* list, int len, int id)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0 && id > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                auxReturn = i;
                break;
            }
        }
    }

    return auxReturn;
}

int printASector(Sector* aSector)
{
    int auxReturn = -1;

    if(aSector != NULL)
    {
        printf("|%-10d|%-30s|\n", aSector->id, aSector->description);

        auxReturn = 0;
    }

    return auxReturn;
}

int printSectors(Sector* list, int len)
{
    int auxReturn = -1;
    int i;

    if(list != NULL && len > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE SECTORES\n\n");

        printf("*----------*------------------------------*\n");
        printf("|%-10s|%-30s|\n", "ID", "DESCRIPCION");
        printf("*----------*------------------------------*\n");

        for(i = 0; i < len; i++)
        {
            if(printASector(&list[i]))
            {
                break;
            }
        }

        printf("*----------*------------------------------*\n");

        if(i == len)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}
