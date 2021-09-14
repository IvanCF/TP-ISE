
#include "LinkedList2.h"

template<class retT>
LinkedList2<retT>::LinkedList2()
{
    _head = 0;
    return;
}

template<class retT>
LinkedList2<retT>::~LinkedList2()
{
    while(remove(1) != NULL);
    return;
}

template<class retT>
retT *LinkedList2<retT>::push(void *data)
{
    retT *new_node = new retT [1];
    if (0 == new_node)
    {
        error("Memory allocation failed\n");
    }
    new_node->next = _head;
    new_node->data = data;
    _head = new_node;
    return _head;
}

template<class retT>
retT *LinkedList2<retT>::append(void *data)
{
    retT *current = _head;
    retT *new_node = new retT [1];
    if (0 == new_node)
    {
        error("Memory allocation failed\n");
    }
    new_node->data = data;
    new_node->next = 0;
    if (0 == current)
    {
        _head = new_node;
        return _head;
    }
    else
    {
        while (current->next != 0)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    return current->next;
}

template<class retT>
retT *LinkedList2<retT>::remove(uint32_t loc)
{
    retT *current = _head;
    retT *prev = 0;
    if ((loc <= length()) && (loc > 0))
    {
        if (1 == loc)
        {
            _head = current->next;
            delete [] current;
        }
        else
        {
            for (uint32_t i=2; i<=loc; ++i)
            {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            delete [] current;
        }
    }

    return _head;
}

template<class retT>
retT *LinkedList2<retT>::pop(uint32_t loc)
{
    retT *current = _head;
    if ((loc > length()) || (loc == 0))
    {
        return 0;
    }
    for (uint32_t i=2; i<=loc; ++i)
    {
        current = current->next;
    }
    return current;
}

template<class retT>
uint32_t LinkedList2<retT>::length(void)
{
    int32_t count = 0;
    retT *current = _head;
    while (current != 0)
    {
        ++count;
        current = current->next;
    }
    return count;
}
template class LinkedList2<node>;
