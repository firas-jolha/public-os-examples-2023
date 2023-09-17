#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    float height;
};

struct Person *createPerson(char *name, int age, float height) {
    struct Person *person = (struct Person *)malloc(sizeof(struct Person));
    
    person->name = name;
    person->age = age;
    person->height = height;
    return person;
}

void showPerson(struct Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
}

int main() {
    struct Person *friends[3];

    friends[0] = createPerson("Sherif", 22, 35.0);
    friends[1] = createPerson("Micheal", 35, 22.0);
    friends[2] = createPerson("Firas", 22, 35.0);

    for (int i = 0; i < 3; i++) {
        printf("Friend %d:\n", i + 1);
        showPerson(friends[i]);
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        free(friends[i]);
    }

    return 0;
}
