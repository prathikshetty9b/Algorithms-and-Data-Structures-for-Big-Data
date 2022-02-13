#include <assert.h>
#include <string.h>
#include "heapappconst.h"
#include "heap.h"
#include <stdint.h>

static void _swap_(int32_t *num1, int32_t *num2){
    int32_t temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

static void _heapify_(int32_t data[], uint32_t len, uint32_t parent){
    assert(parent > 0);
    uint32_t child = 2*parent;
    while(child <= len){
        if(child+1 <= len){ // there is right child also
            if(data[child+1] > data[child]){ // value of right child is greater than left child
                ++child;    // index of right child which has to be moved to parent if required
            }
        }
        if(data[parent] >= data[child]) {
            break;
        }
        _swap_(&data[parent], &data[child]);
        parent = child;
        child = 2*parent;
    }
}

static void _test_heap_(int32_t data[], uint32_t len) {
    for(uint32_t idx = len; idx > 1; --idx){
        assert(data[idx]<= data[idx/2]);
    }
}


Heap    heap_new(int32_t data[], uint32_t len) {
    assert(len > 0 && len < HEAP_MAX_SIZE);

    Heap heap;
    for(uint32_t idx = len/2; idx > 0; --idx){
        _heapify_(data, len, idx);
    }
    heap.size = len;
    memcpy(heap.data, data, (len+1)*sizeof(int32_t));
    _test_heap_(heap.data, heap.size);

    return heap;
}

int32_t heap_get_max(Heap *heap){
    assert(heap->size > 0);
    return heap->data[1];
}

Heap*   heap_add(Heap *heap, int32_t ele){
    assert(heap->size > 0 && (heap->size+1) < HEAP_MAX_SIZE);
    heap->size = ++heap->size;
    uint32_t loc = heap->size;

    while(loc > 1 && heap->data[loc/2] < ele){
        heap->data[loc] = heap->data[loc/2];
        loc = loc/2;
    }
    heap->data[loc] = ele;

    return heap;
}

int32_t heap_extract_max(Heap *heap){
    assert(heap->size > 0);
    int32_t del_ele = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size = --heap->size;
    _heapify_(heap->data, heap->size, 1);

    return del_ele;
}

Heap*   heap_sort(Heap *heap){
    assert(heap->size > 0);

    for(uint32_t idx = heap->size; idx > 1; --idx){
        _swap_(&heap->data[1], &heap->data[idx]);
        _heapify_(heap->data, idx-1, 1);
    }

    return heap;
}
