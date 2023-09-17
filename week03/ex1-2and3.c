#include <stdio.h>

int main() {
    float m[4] = {0.25, 0.5, 0.75, 1};
    
    float *p = m;


    size_t size_of_m = sizeof(m);
    size_t size_of_p = sizeof(p);

    // Check if the pointer to a <datatype> can be considered an array
    // In C, a pointer can be used to access elements sequentially, like an array.
    // So, in some ways, you can treat a pointer as an array, but it doesn't have
    // the same array properties

    size_t size_of_char_pointer = sizeof(char *);

    // Check if the size of the pointer to char is the same as the size of the pointer to float
    // It's unlikely that the sizes will be the same, as the size of a pointer depends on the
    // architecture of the system (e.g., 32-bit or 64-bit).
    
    int n[3][3];
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            n[i][j] = count++;
        }
    }

    float q[2][4];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            q[i][j] = m[j];
        }
    }

    // Print the sizes
    printf("Size of array m: %zu bytes\n", size_of_m);
    printf("Size of pointer p: %zu bytes\n", size_of_p);
    printf("Size of pointer to char: %zu bytes\n", size_of_char_pointer);

    return 0;
}