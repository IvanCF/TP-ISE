
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdint.h>
#include "mbed.h"

struct node
{
    void *data;
    struct node *next;
};

template<class retT>
class LinkedList2
{
protected:
    retT *_head;
public:    
    LinkedList2();    
    ~LinkedList2();
    retT *push(void *data);
    retT *append(void *data);
    retT *remove(uint32_t loc);
    retT *pop(uint32_t loc);
    uint32_t length(void);
};

#endif 
