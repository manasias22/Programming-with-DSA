#include <stdio.h>
#include <stdlib.h>

// Define the struct with a proper pointer declaration
struct MyArray {
    int Total;
    int Used;
    int *ptr;
};

// Function to create and initialize the array
void createit(struct MyArray *a, int total, int used) {
    a->Total = total;
    a->Used = used;
    a->ptr = (int *)malloc(total * sizeof(int));
}

// Function to display the array elements
void show(struct MyArray *a) {
    for (int i = 0; i < a->Used; i++) {
        printf("%d ", (a->ptr)[i]);
    }
    printf("\n");
}

// Function to set the values in the array
void setit(struct MyArray *a) {
    int n, i;
    for (i = 0; i < a->Used; i++) {
        printf("ENTER IT NOW %d\n", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;  // Assign input value to array
    }
}

int main() {
    struct MyArray marks;
    int ts = 10;  // Define total size
    int us = 5;   // Define used size

    // Create and initialize the array
    createit(&marks, ts, us);

    printf("Before setting values:\n");
    show(&marks);

    setit(&marks);

    printf("After setting values:\n");
    show(&marks);

    // Free the allocated memory
    free(marks.ptr);

    return 0;
}
