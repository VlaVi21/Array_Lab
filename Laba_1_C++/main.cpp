#include <iostream>
#include "array.h"

int main() {
    Array arr(5, 1); // Початковий розмір — 3, крок — 2

    // Вхідні дані:
    arr.setValue(6);
    arr.setValue(60);
    arr.setValue(40);

    // Вихідні дані:
    arr.showElements(); // Очікується: 6 60 40\n


	// Завдання 2 констуктор В КЛАСІ
    /*    int readyArray[] = {1, 2, 3, 4, 5};
    Array arr2(readyArray, 5); // Другий конструктор

    arr1.setValue(100);
    arr2.showElements(); // Має вивести 1 2 3 4 5*/

    return 0;
}