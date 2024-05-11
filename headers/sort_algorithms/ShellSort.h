#include <iostream>
#include <cmath>

using namespace std;

#ifndef AIZO_PROJEKT1_SHELLSORT_H
#define AIZO_PROJEKT1_SHELLSORT_H

template<typename T>
class ShellSort {
    T* array;
    int length;

public:
    ShellSort(T* arr = nullptr, int len = 0)  {
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

    void sort(int wzor) {
        int n = length;
        int gap;
        T temp;
        switch (wzor) {
            case 1: { // Algorytm Shella (oryginalny)
                for (gap = n / 2; gap > 0; gap /= 2) {
                    for (int i = gap; i < n; i++) {
                        temp = array[i];
                        int j;
                        // zmodyfikowany algorytm sortowania przez wstawianie
                        for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                            array[j] = array[j - gap];
                        array[j] = temp;
                    }
                }
                break;
            }

            case 2: { // Algorytm Franka i Lazarusa
                int k = 1;
                do {
                    gap = n / pow(2, k + 1) + 1;
                    for (int i = gap; i < n; ++i) {
                        temp = array[i];
                        int j;
                        for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                            array[j] = array[j - gap];
                        array[j] = temp;
                    }
                    gap--; // po wykonaniu sortowania dla gap = 1 algorytm zakonczy sie
                    k++;
                } while(gap > 0);
                break;
            }

            default: // Bledny argument wyboru algorytmu - realizacja oryginalnego algorytmu Shella
                cout << "Nieprawidlowy argument wybranego algorytmu. Tablice zostanie posrotowana za pommoca oryginalnego algorytm Shella." << endl;
                for (gap = n / 2; gap > 0; gap /= 2) {
                    for (int i = gap; i < n; ++i) {
                        temp = array[i];
                        int j;
                        for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                            array[j] = array[j - gap];
                        array[j] = temp;
                    }
                }
                break;
        }
    }
};


#endif //AIZO_PROJEKT1_SHELLSORT_H
