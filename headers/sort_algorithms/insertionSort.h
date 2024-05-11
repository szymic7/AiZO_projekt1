#include <iostream>

using namespace std;

#ifndef AIZO_PROJEKT1_INSERTIONSORT_H
#define AIZO_PROJEKT1_INSERTIONSORT_H

template<typename T>
class InsertionSort {

    T* array;
    int length;

public:

    InsertionSort(T* arr = nullptr, int len = 0) {
        length = len;
        array = arr;
    }

    // Destruktor
    ~InsertionSort() {
        //delete[] array;
    }

    void setSize(int rozmiar) {
        length = rozmiar;
    }

    void setArray(T* arr) {
        array = arr;
    }


    void sort() {
        T key;
        for (int i = 1; i < length; i++) {
            key = array[i];
            int j = i;
            while (j > 0 && array[j-1] > key) {
                array[j] = array[j-1];
                j--;
            }
            array[j] = key;
        }
    }

    T* getArray() {
        return array;
    }

};

#endif //AIZO_PROJEKT1_INSERTIONSORT_H
