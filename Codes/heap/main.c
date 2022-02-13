#include <stdio.h>
#include <assert.h>
#include "heapappconst.h"
#include "heap.h"

void test_sorting(int32_t list[], uint32_t len){
    for(uint32_t idx = 1; idx < len; ++idx) {
        assert(list[idx] <= list[idx+1]);
    }
}

void test_heap() {
    int32_t input_data[] = {0, 34, 25, 87, 90, 30, 60, 76,15, 41,54};
    Heap h = heap_new(input_data, 10);
    Heap *heap = &h;
    assert(heap_get_max(heap) == 90);
    heap_add(heap, 99);
    assert(heap_get_max(heap) == 99);
    assert(heap_extract_max(heap) == 99);
    assert(heap->size == 10);
    heap_sort(heap);
    test_sorting(heap->data, heap->size);

}

int main()
{
    test_heap();
    //printf("Hello world!\n");
    return 0;
}
