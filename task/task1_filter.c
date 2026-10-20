#include <stdio.h>
#include <stdlib.h>


 // Task 1:
 
int* filterEvenNumbers(const int *source, size_t src_size, size_t *out_size) {
    if (source == NULL || out_size == NULL) return NULL;

    // 1. Traverse source using pointer arithmetic to count even numbers
    size_t even_count = 0;
    for (size_t i = 0; i < src_size; i++) {
        if (*(source + i) % 2 == 0) {
            even_count++;
        }
    }

    *out_size = even_count;

    if (even_count == 0) {
        return NULL;
    }

    // 2.
    int *even_arr = (int*)malloc(even_count * sizeof(int));
    if (even_arr == NULL) {
        perror("Memory allocation failed for filtered array!");
        exit(EXIT_FAILURE);
    }

    // 3. 
    int *dest_ptr = even_arr;
    for (size_t i = 0; i < src_size; i++) {
        if (*(source + i) % 2 == 0) {
            *dest_ptr = *(source + i);
            dest_ptr++;
        }
    }

    return even_arr;
}

int main(void) {
    int sample_data[] = {12, 7, 19, 44, 2, 15, 88, 101, 30};
    size_t src_size = sizeof(sample_data) / sizeof(sample_data[0]);
    size_t filtered_size = 0;

    printf("=== Task 1: Array Filtering ===\n");
    printf("Original Array Elements: ");
    for (size_t i = 0; i < src_size; i++) {
        printf("%d ", *(sample_data + i));
    }
    printf("\n");

    int *even_numbers = filterEvenNumbers(sample_data, src_size, &filtered_size);

    printf("Filtered Even Numbers (%zu found): ", filtered_size);
    for (size_t i = 0; i < filtered_size; i++) {
        printf("%d ", *(even_numbers + i));
    }
    printf("\n");

    free(even_numbers);
    even_numbers = NULL;

    return 0;
}