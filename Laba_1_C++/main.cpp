#include <iostream>
#include "array.h"

int main() {
    Array arr(5, 1); // ���������� ����� � 3, ���� � 2

    // ����� ���:
    arr.setValue(6);
    arr.setValue(60);
    arr.setValue(40);

    // ������ ���:
    arr.showElements(); // ���������: 6 60 40\n


	// �������� 2 ���������� � ���Ѳ
    /*    int readyArray[] = {1, 2, 3, 4, 5};
    Array arr2(readyArray, 5); // ������ �����������

    arr1.setValue(100);
    arr2.showElements(); // �� ������� 1 2 3 4 5*/

    return 0;
}