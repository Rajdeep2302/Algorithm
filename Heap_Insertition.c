// Write a C Program to insert an element into heap, also compute time complexity for an input of size N.
#include <stdio.h>
#include <stdlib.h>

int complexity = 0;

void Insert_Data(int **array, int *size)
{
    complexity++;
    *size += 1;
    *array = (int *)realloc(*array, (*size + 1) * sizeof(int)); // +1 for 1-based index

    printf("Enter the value to insert: ");
    int value;
    scanf("%d", &value);
    (*array)[*size] = value;

    int i = *size;
    while (i > 1 && (*array)[i] > (*array)[i / 2])
    {
        complexity++;
        int temp = (*array)[i];
        (*array)[i] = (*array)[i / 2];
        (*array)[i / 2] = temp;
        i = i / 2;
    }
}

void display(int array[], int size)
{
    if (size == 0)
    {
        printf("Heap is empty.\n");
        return;
    }

    printf("Heap Elements: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int *array = NULL;
    array = (int *)malloc(sizeof(int) * 2);
    int size = 1;

    printf("Write the first value to insert: ");
    scanf("%d", &array[1]);

    char key;
    int wrongKeyCount = 0;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Press 'i' or 'I' to insert data.\n");
        printf("2. Press 'e' or 'E' to exit the program.\n");
        printf("3. Press 'd' or 'D' to display the heap.\n");
        printf("Enter your choice: ");

        // Consume newline before reading a character
        while ((key = getchar()) == '\n')
            ;

        if (key == 'i' || key == 'I')
        {
            Insert_Data(&array, &size);
            wrongKeyCount = 0;
        }
        else if (key == 'e' || key == 'E')
        {
            printf("Exiting the program.\n");
            free(array);
            printf("Time complexity: %d\n", complexity);
            exit(EXIT_SUCCESS);
        }
        else if (key == 'd' || key == 'D')
        {
            display(array, size);
            wrongKeyCount = 0;
        }
        else
        {
            wrongKeyCount++;
            printf("Incorrect key. Try again...\n");
            if (wrongKeyCount == 3)
            {
                printf("Time complexity: %d\n", complexity);
                printf("You entered the wrong key three times. The program will now terminate.\n");
                free(array);
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}
