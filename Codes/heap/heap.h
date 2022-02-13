#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include "heapappconst.h"
#include <stdint.h>

typedef struct _heap_   Heap;

struct _heap_ {
    uint32_t    size;
    int32_t     data[HEAP_MAX_SIZE];
};

Heap    heap_new(int32_t data[], uint32_t len);
Heap*   heap_test(Heap *heap);
Heap*   heap_sort(Heap *heap);
Heap*   heap_add(Heap *heap, int32_t ele);
int32_t heap_extract_max(Heap *heap);
int32_t heap_get_max(Heap *heap);



#endif // HEAP_H_INCLUDED
