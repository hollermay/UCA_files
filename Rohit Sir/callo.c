#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_calloc(size_t num, size_t size) {
    void* ptr = malloc(num * size);
    if (ptr != NULL) {
        memset(ptr, 0, num * size);
    }
    return ptr;
}

int main() {
    int num_elements;
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    int* arr = (int*)my_calloc(num_elements, sizeof(int));
    if (arr != NULL) {
        for (int i = 0; i < num_elements; i++) {
            printf("Enter element %d: ", i+1);
            scanf("%d", &arr[i]);
        }

        printf("Bytes in reverse order: ");
        for (int i = sizeof(int) * num_elements - 1; i >= 0; i--) {
            unsigned char byte = *((unsigned char*)arr + i);
            printf("%02X ", byte);
        }

        free(arr);
    }
    return 0;
}