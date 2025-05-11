#include "array.h"
#include <iostream>
#include <cstring>

Array::Array(int length, int increm) { // �����������
	if (length <= 0) length = 10; // ̳�������� ����� ������
	if (increm <= 0) increm = 5; // ̳�������� ���� ���������

	this->m_init_size = length; // �����������
    this->m_growThStep = increm; //���� �����. �����
    this->m_arr_ptr = 0; //�������� �� �����
	this->m_allocatedSize = length; // ����� ������
    this->m_arr_ptr = new int[m_allocatedSize]; // ��������� ������ (��  �� �� malloc() � C, ����� � new.)
	this->m_curIndex = 0; // ����������� ������� () 
    /*P.S. ======== TEST 3 ========
    Your program crashes!You are Lucky : ) 
    -��������� �� ����� - ����� ������ :)*/

    /*����, �� ����� ������� ��� ������ �����������
    : init_size(length),
      growThStep(increm),
      allocatedSize(length),
      arr_ptr(new int[length]),
      curIndex(0)*/

    //����������� 2 ������������ � ���� 
    /* for (int i = 0; i < size; ++i) {
        m_arr_ptr[i] = arr[i];
    }*/
}

Array::~Array() {
    std::cout << "[Array Destructor] Memory cleaned up\n";
    delete[] m_arr_ptr; // ������� ���'��
}

//������ ����� Array//

void Array::showElements() const { // ���� ��������
    for (int i = 0; i < m_curIndex; ++i) {
        std::cout << m_arr_ptr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int expansionSize) { // ���������� ������
	if (expansionSize <= 0) return;    // ̳�������� �����

	int* newData = new int[m_allocatedSize + expansionSize];// ��������� ������ ������
	std::memcpy(newData, m_arr_ptr, sizeof(int) * m_curIndex); // ��������� ������ �����
    delete[] m_arr_ptr;
    m_arr_ptr = newData;
	m_allocatedSize += expansionSize; // ��������� ������
}

int Array::getSize() const { // ������� ������
    return m_allocatedSize;
}

int Array::getElemSize() const { // ʳ������ ���������� ��������
    return m_curIndex;
}

void Array::setValue(int value) { // ������ ���� �������
	if (m_curIndex >= m_allocatedSize) { // �������� �� ������������
        expandArray(m_growThStep); // ���������� ������
    }
	m_arr_ptr[m_curIndex++] = value; // ��������� ��������
}

void Array::setArray(int* pArr, int EXPSize) { // ������ ����� ��������
	if (!pArr || EXPSize <= 0) return; // �������� �� ����������
    
    for (int i = 0; i < EXPSize; ++i) {
        setValue(pArr[i]);
    }
}

void Array::cleaning() { // �������� ������
    m_curIndex = 0;
}

bool Array::isEmpty() const { // �������� �� ������ �����
	return m_curIndex == 0; //�� ���� �������� ����� ��� 
}
