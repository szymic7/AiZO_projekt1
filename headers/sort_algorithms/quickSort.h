#include <iostream>
#include <random>
#include <ctime>

using namespace std;

#ifndef AIZO_PROJEKT1_QUICKSORT_H
#define AIZO_PROJEKT1_QUICKSORT_H

template<typename T>
class QuickSort {
    T* array;
    int length;
    std::random_device rd;
    std::mt19937 gen;

public:
    QuickSort(T* arr = nullptr, int len = 0)  {
        array = arr;
        length = len;
        rd();
        gen = std::mt19937(rd());
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

    int getSize() {
        return length;
    }

    void quickSort(int l, int p, int pivotSelect) {
        if(l>=p) return;
        int m = partition(l, p, pivotSelect);
        quickSort(l, m, pivotSelect);
        quickSort(m+1, p, pivotSelect);
    }

    int partition(int left, int right, int pivotSelect) {
        T pivot;

        switch (pivotSelect) {
            case 1: // PIVOT = SKRAJNY LEWY ELEMENT
                pivot = array[left];
                break;
            case 2: // PIVOT = SKRAJNY PRAWY ELEMENT
                pivot = array[right];
                break;
            case 3: // PIVOT = SRODKOWY ELEMENT
                pivot = array[(left+right)/2];
                break;
            case 4: { // PIVOT = LOSOWY ELEMENT
                std::uniform_int_distribution<int> dist(left, right);
                int randomIndex = dist(gen);
                pivot = array[randomIndex];
                break;
            }
            default:
                cout << "Nieprawidlowy numer opcji wyboru pivota. Pivot zostanie przyjety jako skrajny lewy element." << endl;
                pivot = array[left];
                break;
        }

        int l = left;
        int r = right;
        while (true) {
            while (array[l] < pivot) ++l;
            while (array[r] > pivot) --r;
            if (l < r) {
                swap(array[l], array[r]);
                ++l;
                --r;
            } else {
                if (r == right) r--;
                return r;
            }
        }
    }

};

#endif //AIZO_PROJEKT1_QUICKSORT_H
