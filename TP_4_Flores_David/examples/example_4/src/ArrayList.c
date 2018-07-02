#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}

/** \brief se fija si esta lleno, si es así, lo agranda, y agrega un elemento al array
 *
 * \param this puntero a ArrayList
 * \param pElement Puntero al elemento
 * \return return = -1 si hubo un error, y 0 si esta todo bien
 *
 */

int al_add(ArrayList* this, void* pElement)
{
    int retorno = -1;
    int flag = 0;

    if(this != NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
        {
            flag = resizeUp(this);
        }
        if(flag == 0)
        {
            *(this->pElements + this->size) = pElement;
            this->size++;
            retorno = 0;
        }
    }
    return retorno;
}


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if (this != NULL && index > -1 && index < this->size)
    {
        returnAux = *(this->pElements+index);
    }


    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int flag=0;

    if(this != NULL && pElement != NULL)
    {
        for(int i = 0; i < this->size; i++)
        {
            if(*(this->pElements+i)==pElement)
            {
                returnAux = 1;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this != NULL && pElement != NULL && index >= 0 && index <= this->size)
        {
            (*(this->pElements+index)) = pElement;
            returnAux = 0;
        }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;

    if (this != NULL && index >= 0 && index < this->size)
        {
            for (int i = index; i < this->size; i++)
            {
                (*(this->pElements+i)) = (*(this->pElements+i+1));
            }
            returnAux = 0;
            this->size--;
        }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        for (int i = 0; i < this->size; i++)
        {
            free(this->pElements+i);
        }
        this->size = 0;
        returnAux = 0;
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;

    if (this != NULL)
    {
        returnAux = al_newArrayList();
        returnAux->size = this->size;
        for (int i = 0; i < this->size; i++)
        {
            al_add(returnAux, (*(this->pElements+i)));
        }
    }
    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    int retorno=0;

    if (this != NULL && pElement != NULL && index >= 0 && index <= this->size)
    {
        if (this->size == this->reservedSize)
        {
            retorno = resizeUp(this);
        }
        if (retorno == 0)
        {
            index = expand(this, index);
            if (index != -1)
            {
                (*(this->pElements+index)) = pElement;
                this->size++;
                returnAux = 0;
            }
        }
    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL)
    {
        for(int i = 0; i < this->size; i++)
        {
            if((*(this->pElements+i)) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(this->size == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}





/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    int eliminado;

    if(this != NULL && index >= 0 && index <= this->size)//es mayor a 0 y menor al size
    {
        returnAux = (*(this->pElements+index));
        eliminado = al_remove(this, index);
        if(eliminado == -1)
        {
            returnAux = NULL;
        }
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    void* aux;

    if (this != NULL && from < this->size && from >= 0 && to <= this->size && to > 0 && from < to)
    {
        returnAux = al_newArrayList();

        for(int i = from; i < to; i++)
        {
            aux = this->get(this, i);
            this->add(returnAux, aux);
        }
    }
    return returnAux ;
}

/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this, ArrayList* this2)
{
    int returnAux = -1;
    int flag = 0;
    int contador = 0;

    if(this != NULL && this2 != NULL)
    {
        for(int i = 0; i < this2->size; i++)
        {
            flag = 0;
            for (int j = 0; j < this->size; j++)
            {
                if((*(this->pElements + i)) == (*(this2->pElements + j)))
                {
                    flag = 1;
                    contador++;
                    break;
                }
            }
            if(flag == 0)
            {
                returnAux=0;
                break;
            }
        }
        if(contador == this->size)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int retorno;
    void* aux;

    if (this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        returnAux=0;

        for(int i = 0; i < this->size-1; i++)
        {
            for(int j = i+1; j < this->size; j++)
            {
                if(order == 0)
                {
                    retorno = pFunc((*(this->pElements+i)), (*(this->pElements+j)));

                    if (retorno == 1)
                    {
                        aux = (*(this->pElements+i));
                        (*(this->pElements+i)) = (*(this->pElements+j));
                        (*(this->pElements+j)) = aux;
                    }
                }

                if(order == 1)
                {
                    retorno = pFunc((*(this->pElements+i)), (*(this->pElements+j)));
                    if(retorno == -1)
                    {
                        aux = (*(this->pElements+i));
                        (*(this->pElements+i)) = (*(this->pElements+j));
                        (*(this->pElements+j)) = aux;
                    }
                }
            }
        }
    }
    return returnAux;

}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int retorno = -1;
    void* aux;
    if (this != NULL)
    {
        aux = realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));
        if (aux != NULL)
        {
            this->pElements = aux;
            this->reservedSize += AL_INCREMENT;
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this, int index)
{
    int returnAux = -1;

    for(int i = this->size; i > index; i--)
    {
        (*(this->pElements+i)) = (*(this->pElements+i-1));
    }

    returnAux = index;

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;


    return returnAux;
}
