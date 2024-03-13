#include "vena_utility.h"

// teaching friend pointers

int main() {

    int array[4] = {1, 5, 3, 10};
    int random = 88;

    print(array, "\t", array + 1);

    for (size_t i = 0; i < 6; i++) {
        print(*(array + i));
    }
    



    /*
    int a = 0;
    int* pointerToA = &a;    

    print(a);
    print("Address:\t", &a);
    print("Pointer\t\t", pointerToA);

    a++;

    print(a);
    print("Pointer\t\t", pointerToA);

    print("Derefeneced\t", *pointerToA);

    int** pointerToPointerToA = &pointerToA;

    print(pointerToPointerToA);

    (**pointerToPointerToA)++;
    print(a);

    int*** pointer3ToA = &pointerToPointerToA;
    */
}