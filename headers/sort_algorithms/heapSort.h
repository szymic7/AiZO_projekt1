#include <iostream>
#include <random>

using namespace std;

#ifndef AIZO_PROJEKT1_HEAPSORT_H
#define AIZO_PROJEKT1_HEAPSORT_H

template<typename T>
class HeapSort {
    T* array;
    int length;

public:
    HeapSort(T* arr = nullptr, int len = 0)  {
        array = arr;
        length = len;
    }

    void setArray(T* arr) {
        array = arr;
    }

    void setSize(int len) {
        length = len;
    }

    T* getArray() {
        return array;
    }

    void heapify(int n, int i) { // naprawa kopca w dol
        int largest = i; // korzen
        int left = 2 * i + 1; // lewy potomek wezla i (largest)
        int right = 2 * i + 2; // prawy potomek wezla i (largest)

        if (left < n && array[left] > array[largest])
            largest = left;

        if (right < n && array[right] > array[largest])
            largest = right;

        if (largest != i) {
            swap(array[i], array[largest]);
            heapify(n, largest);
        }
    }

    void sort() {
        int n = length;
        // Utworzenie kopca maksymalnego
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);

        // W petli dokunuje sie zamiana korzenia z ostatnim elementem tablicy i naprawa kopca
        for (int i = n - 1; i > 0; i--) {
            swap(array[0], array[i]);
            heapify(i, 0);
        }
    }
};

#endif //AIZO_PROJEKT1_HEAPSORT_H
