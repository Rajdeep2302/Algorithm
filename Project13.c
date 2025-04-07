//Write a C Program to delete the N element, also compute time complexity for an input of size N.
#include <stdio.h>
#include <stdlib.h>

int complexity = 0;

void heapIfy(int **array, int *size){
    int i = *size;
    while (i > 1 && (*array)[i] > (*array)[i / 2]) {
        complexity++;
        int temp = (*array)[i];
        (*array)[i] = (*array)[i / 2];
        (*array)[i / 2] = temp;
        i = i / 2;
    }
}

void Insert_Data(int **array, int *size) {
    complexity++;
    *size += 1;
    *array = (int *)realloc(*array, (*size + 1) * sizeof(int));

    printf("Enter the value to insert: ");
    int value;
    scanf("%d", &value);
    (*array)[*size] = value;

    heapIfy(array, size);
}

void delete_Data(int **array, int *size) {
    if (*size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    int position;
    printf("Enter the position of the element to delete (1 to %d): ", *size);
    scanf("%d", &position);

    if (position < 1 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    (*array)[position] = (*array)[*size];
    *size -= 1;
    *array = (int *)realloc(*array, (*size + 1) * sizeof(int));

    for (int i = position; i <= *size / 2; i++) {
        heapIfy(array, size);
    }
}

void display(int array[], int size) {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Heap Elements: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array = NULL;
    array = (int *)malloc(sizeof(int) * 2);
    int size = 1;

    printf("Write the first value to insert: ");
    scanf("%d", &array[1]);

    char key;
    int wrongKeyCount = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Press 'i' or 'I' to insert data.\n");
        printf("2. Press 'e' or 'E' to exit the program.\n");
        printf("3. Press 'd' or 'D' to display the heap.\n");
        printf("4. Press 'r' or 'R' to delete data.\n");
        printf("Enter your choice: ");

        // Consume newline before reading a character
        while ((key = getchar()) == '\n');

        if (key == 'i' || key == 'I') {
            Insert_Data(&array, &size);
            wrongKeyCount = 0;
        } else if (key == 'r' || key == 'R') {
            delete_Data(&array, &size);
            wrongKeyCount = 0;
        } else if (key == 'e' || key == 'E') {
            printf("Exiting the program.\n");
            free(array);
            printf("Time complexity: %d\n", complexity);
            exit(EXIT_SUCCESS);
        } else if (key == 'd' || key == 'D') {
            display(array, size);
            wrongKeyCount = 0;
        } else {
            wrongKeyCount++;
            printf("Incorrect key. Try again...\n");
            if (wrongKeyCount == 3) {
                printf("Time complexity: %d\n", complexity);
                printf("You entered the wrong key three times. The program will now terminate.\n");
                free(array);
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}
