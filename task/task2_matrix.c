#include <stdio.h>
#include <stdlib.h>

/**
 * Task 2: Dynamic 2D Matrix with Double Pointers & Transpose
 */

// i. Allocate array of R row pointers, then allocate each row of size C
int** createMatrix(size_t rows, size_t cols) {
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        perror("Failed to allocate row pointers!");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < rows; i++) {
        *(matrix + i) = (int*)malloc(cols * sizeof(int));
        if (*(matrix + i) == NULL) {
            perror("Failed to allocate row buffer!");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

// ii. Allocate transpose matrix (C x R) and populate T[j][i] = M[i][j]
int** transposeMatrix(int **matrix, size_t rows, size_t cols) {
    if (matrix == NULL) return NULL;

    int **transposed = createMatrix(cols, rows);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            *(*(transposed + j) + i) = *(*(matrix + i) + j);
        }
    }
    return transposed;
}

// Display matrix helper
void printMatrix(int **matrix, size_t rows, size_t cols) {
    if (matrix == NULL) return;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%4d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

// iii. Accept triple pointer to free all buffers and set original pointer to NULL
void freeMatrix(int ***matrix_ptr, size_t rows) {
    if (matrix_ptr == NULL || *matrix_ptr == NULL) return;

    int **matrix = *matrix_ptr;
    for (size_t i = 0; i < rows; i++) {
        free(*(matrix + i));
    }
    free(matrix);
    *matrix_ptr = NULL; // Safe reset to NULL
}

int main(void) {
    size_t rows = 3, cols = 4;

    printf("=== Task 2: Dynamic 2D Matrix & Transpose ===\n");
    int **mat = createMatrix(rows, cols);

    // Populate with sample values
    int val = 1;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            *(*(mat + i) + j) = val++;
        }
    }

    printf("Original Matrix (%zu x %zu):\n", rows, cols);
    printMatrix(mat, rows, cols);

    int **transposed = transposeMatrix(mat, rows, cols);

    printf("\nTransposed Matrix (%zu x %zu):\n", cols, rows);
    printMatrix(transposed, cols, rows);

    // Safely free both matrices
    freeMatrix(&mat, rows);
    freeMatrix(&transposed, cols);

    printf("\nPointer state after freeMatrix: mat=%p, transposed=%p\n", (void*)mat, (void*)transposed);

    return 0;
}