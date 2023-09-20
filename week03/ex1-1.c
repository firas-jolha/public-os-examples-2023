#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Fixed-size array
    char fixedArray[5] = "inno";
    char fixedArray2[] = {'i', 'n', 'n', 'o', '\n'};

    printf("Fixed Array Before: %s\n", fixedArray);

    int i;
    for (i = 0; i < 5; ++i)
    {
        printf("%c\t", fixedArray2[i]);
    }

    // Attempt to increase the size of the string (This is not possible)
    // strcat(fixedArray, "polis");
    // This line would result in an error

    // Dynamic-size array using malloc
    char *dynamicArray = (char *)malloc(5 * sizeof(char)); // Initialize with "inno"
    strcpy(dynamicArray, "inno");

    printf("Dynamic Array: %s\n", dynamicArray);

    // Increase the size to hold "innopolis" using realloc
    dynamicArray = (char *)realloc(dynamicArray, 9 * sizeof(char)); // Allocate space for "innopolis"
    strcat(dynamicArray, "polis");

    printf("Dynamic Array (After resizing): %s\n", dynamicArray);

    free(dynamicArray);

    return 0;
}