#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Fixed-size array
    char fixedArray[5] = "inno";
    char fixedArray2[] = {'i', 'n', 'n', 'o', '\n'};

    printf("Fixed Array Before: %s\n", fixedArray);
    
    int i;
    for (i = 0; i < 5; ++i) {
        printf("%c\t", fixedArray2[i]);
    }

    // Attempt to increase the size of the string (This is not possible)
    fixedArray = "innopolis"; 
    // This line would result in an error

    // Dynamic-size array using malloc
    char *dynamicArray = (char *)malloc(9 * sizeof(char)); // 9 characters for "innopolis" + null terminator
  

    // Copy the "inno" string to the dynamic array
    strcpy(dynamicArray, "inno");
    printf("Dynamic Array Before: %s\n", dynamicArray);

    // Extend the dynamic array to "innopolis"
    strcat(dynamicArray, "polis");
    printf("Dynamic Array After: %s\n", dynamicArray);

    // Free the dynamically allocated memory
    free(dynamicArray);

    return 0;
}
