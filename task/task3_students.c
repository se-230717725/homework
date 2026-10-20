#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Task 3: Struct Records & In-Place Pointer Sorting
 */

typedef struct {
    int id;
    char name[32];
    float gpa;
} Student;

// Create dynamic array of Student structs
Student* createStudentArray(size_t count) {
    Student *arr = (Student*)malloc(count * sizeof(Student));
    if (arr == NULL) {
        perror("Failed to allocate student array!");
        exit(EXIT_FAILURE);
    }
    return arr;
}

// i. Swap two student structs using a temporary variable and pointers
void swapStudents(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// ii. Sort array by GPA descending using Bubble Sort and pointer arithmetic
void sortStudentsByGPA(Student *arr, size_t count) {
    if (arr == NULL || count < 2) return;

    for (size_t i = 0; i < count - 1; i++) {
        for (size_t j = 0; j < count - i - 1; j++) {
            if ((arr + j)->gpa < (arr + j + 1)->gpa) {
                swapStudents(arr + j, arr + j + 1);
            }
        }
    }
}

// Display student records
void printStudents(const Student *arr, size_t count) {
    if (arr == NULL) return;
    printf("%-8s %-20s %-6s\n", "ID", "Name", "GPA");
    printf("-----------------------------------\n");
    for (size_t i = 0; i < count; i++) {
        const Student *s = arr + i;
        printf("%-8d %-20s %-6.2f\n", s->id, s->name, s->gpa);
    }
}

int main(void) {
    size_t count = 5;
    Student *students = createStudentArray(count);

    // Populate sample student data
    (students + 0)->id = 101; strcpy((students + 0)->name, "Alice Smith"); (students + 0)->gpa = 3.42f;
    (students + 1)->id = 102; strcpy((students + 1)->name, "Bob Johnson"); (students + 1)->gpa = 3.89f;
    (students + 2)->id = 103; strcpy((students + 2)->name, "Charlie Brown"); (students + 2)->gpa = 2.95f;
    (students + 3)->id = 104; strcpy((students + 3)->name, "Diana Prince"); (students + 3)->gpa = 3.98f;
    (students + 4)->id = 105; strcpy((students + 4)->name, "Ethan Hunt"); (students + 4)->gpa = 3.10f;

    printf("=== Task 3: Student Records Before Sorting ===\n");
    printStudents(students, count);

    sortStudentsByGPA(students, count);

    printf("\n=== Student Records Sorted by GPA (Descending) ===\n");
    printStudents(students, count);

    // iii. Free memory cleanly
    free(students);
    students = NULL;

    return 0;
}