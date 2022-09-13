#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Indice del nodo a obtener
 *
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);


/** \brief  Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 *
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->pFirstNode = NULL;
        this->size = 0;
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        auxReturn = this->size;
    }

    return auxReturn;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;

        for(i = 0; i < nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }

    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int auxReturn = -1;

    Node* pNewNode = NULL;
    Node* pPrevNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNewNode = (Node*) malloc(sizeof(Node));

        if(pNewNode != NULL)
        {
            pNewNode->pElement = pElement;

            if(nodeIndex == 0)
            {
                pNewNode->pNextNode = this->pFirstNode;
                this->pFirstNode = pNewNode;
            }

            else
            {
                pPrevNode = getNode(this, nodeIndex - 1);

                if(pPrevNode != NULL)
                {
                    pNewNode->pNextNode = pPrevNode->pNextNode;
                    pPrevNode->pNextNode = pNewNode;
                }
            }

            if(nodeIndex == 0 || pPrevNode != NULL)
            {
                this->size++;
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int test_addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    return addNode(this, nodeIndex, pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int auxReturn = -1;

    if(this != NULL && !addNode(this, ll_len(this), pElement))
    {
        auxReturn = 0;
    }

    return auxReturn;
}

void* ll_get(LinkedList* this, int index)
{
    void* auxReturn = NULL;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pNode = getNode(this, index);

        if(pNode != NULL)
        {
            auxReturn = pNode->pElement;
        }
    }

    return auxReturn;
}

int ll_set(LinkedList* this, int index, void* pElement)
{
    int auxReturn = -1;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pNode = getNode(this, index);

        if(pNode != NULL)
        {
            pNode->pElement = pElement;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int ll_remove(LinkedList* this, int index)
{
    int auxReturn = -1;

    Node* pActualNode = NULL;
    Node* pPrevNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(index == 0)
        {
            pActualNode = this->pFirstNode;
            this->pFirstNode = pActualNode->pNextNode;
        }

        else
        {
            pPrevNode = getNode(this, index - 1);

            if(pPrevNode != NULL)
            {
                pActualNode = pPrevNode->pNextNode;
                pPrevNode->pNextNode = pActualNode->pNextNode;
            }
        }

        if(index == 0 || pPrevNode != NULL)
        {
            free(pActualNode);
            pActualNode = NULL;

            this->size--;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int ll_clear(LinkedList* this)
{
    int auxReturn = -1;
    int i;

    if(this != NULL)
    {
        for(i = ll_len(this) - 1; i >= 0; i--)
        {
            if(ll_remove(this, 0))
            {
                break;
            }
        }

        if(i == -1)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int auxReturn = -1;

    if(this != NULL && !ll_clear(this))
    {
        free(this);

        auxReturn = 0;
    }

    return auxReturn;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int auxReturn = -1;
    int length;
    int i;

    void* pAux = NULL;

    if(this != NULL)
    {
        length = ll_len(this);

        for(i = 0; i < length; i++)
        {
            pAux = ll_get(this, i);

            if(pAux == pElement)
            {
                auxReturn = i;
                break;
            }
        }
    }

    return auxReturn;
}

int ll_isEmpty(LinkedList* this)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        auxReturn = 1;

        if(this->pFirstNode != NULL)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int auxReturn = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this) && !addNode(this, index, pElement))
    {
        auxReturn = 0;
    }

    return auxReturn;
}

void* ll_pop(LinkedList* this, int index)
{
    void* auxReturn = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxReturn = ll_get(this, index);

        if(ll_remove(this, index))
        {
            auxReturn = NULL;
        }
    }

    return auxReturn;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        auxReturn = 0;

        if(ll_indexOf(this, pElement) >= 0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int auxReturn = -1;
    int length;
    int i;

    void* pElement = NULL;

    if(this != NULL && this2 != NULL)
    {
        auxReturn = 1;

        length = ll_len(this2);

        for(i = 0; i < length; i++)
        {
            pElement = ll_get(this2, i);

            if(!ll_contains(this, pElement))
            {
                auxReturn = 0;
                break;
            }
        }
    }

    return auxReturn;
}

LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;

    void* pElement = NULL;
    int length;
    int i;

    if(this != NULL && from >= 0 && to > 0 && from < to)
    {
        length = ll_len(this);

        if(length > 0 && from < length && to <= length)
        {
            cloneArray = ll_newLinkedList();

            if(cloneArray != NULL)
            {
                for(i = from; i < to; i++)
                {
                    pElement = ll_get(this, i);

                    if(ll_add(cloneArray, pElement))
                    {
                        ll_deleteLinkedList(cloneArray);
                        cloneArray = NULL;
                        break;
                    }
                }
            }
        }
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order)
{
    int auxReturn = -1;
    int length;
    int i;
    int flagSwap;

    void* pElement1 = NULL;
    void* pElement2 = NULL;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        length = ll_len(this);

        if(length > 0)
        {
            do
            {
                flagSwap = 0;

                for(i = 0; i < length - 1; i++)
                {
                    pElement1 = ll_get(this, i);
                    pElement2 = ll_get(this, i + 1);

                    if(pFunc(pElement1, pElement2) == order - !order)
                    {
                        ll_set(this, i, pElement2);
                        ll_set(this, i + 1, pElement1);

                        flagSwap = 1;
                    }
                }

                length--;

            } while(flagSwap);

            auxReturn = 0;
        }
    }

    return auxReturn;
}
