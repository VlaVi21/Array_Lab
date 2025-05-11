#include "array.h"
#include <iostream>
#include <cstring>

Array::Array(int length, int increm) { // Конструктор
	if (length <= 0) length = 10; // Мінімальний розмір масиву
	if (increm <= 0) increm = 5; // Мінімальний крок збільшення

	this->m_init_size = length; // Ініціалізація
    this->m_growThStep = increm; //Крок збільш. маиву
    this->m_arr_ptr = 0; //Вказівник на масив
	this->m_allocatedSize = length; // Розмір масиву
    this->m_arr_ptr = new int[m_allocatedSize]; // Створення масиву (як  Це як malloc() у C, тільки з new.)
	this->m_curIndex = 0; // Ініціалізація індексу () 
    /*P.S. ======== TEST 3 ========
    Your program crashes!You are Lucky : ) 
    -Провтикав цю штуку - шукаєш багггг :)*/

    /*Варік, як можна замінити цей список ініціалізації
    : init_size(length),
      growThStep(increm),
      allocatedSize(length),
      arr_ptr(new int[length]),
      curIndex(0)*/

    //опрацювання 2 конструктору в класі 
    /* for (int i = 0; i < size; ++i) {
        m_arr_ptr[i] = arr[i];
    }*/
}

Array::~Array() {
    std::cout << "[Array Destructor] Memory cleaned up\n";
    delete[] m_arr_ptr; // Очистка пам'яті
}

//Методи класу Array//

void Array::showElements() const { // Вивід елементів
    for (int i = 0; i < m_curIndex; ++i) {
        std::cout << m_arr_ptr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int expansionSize) { // Розширення масиву
	if (expansionSize <= 0) return;    // Мінімальний розмір

	int* newData = new int[m_allocatedSize + expansionSize];// Створення нового масиву
	std::memcpy(newData, m_arr_ptr, sizeof(int) * m_curIndex); // Копіювання старих даних
    delete[] m_arr_ptr;
    m_arr_ptr = newData;
	m_allocatedSize += expansionSize; // Збільшення розміру
}

int Array::getSize() const { // Поточна ємність
    return m_allocatedSize;
}

int Array::getElemSize() const { // Кількість збережених елементів
    return m_curIndex;
}

void Array::setValue(int value) { // Додати один елемент
	if (m_curIndex >= m_allocatedSize) { // Перевірка на переповнення
        expandArray(m_growThStep); // Розширення масиву
    }
	m_arr_ptr[m_curIndex++] = value; // Додавання елемента
}

void Array::setArray(int* pArr, int EXPSize) { // Додати масив елементів
	if (!pArr || EXPSize <= 0) return; // Перевірка на коректність
    
    for (int i = 0; i < EXPSize; ++i) {
        setValue(pArr[i]);
    }
}

void Array::cleaning() { // Очищення масиву
    m_curIndex = 0;
}

bool Array::isEmpty() const { // Перевірка на пустий масив
	return m_curIndex == 0; //він читає значення змінної кур 
}
