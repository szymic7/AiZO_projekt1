#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

#ifndef AIZO_PROJEKT1_PRESORT_H
#define AIZO_PROJEKT1_PRESORT_H

template<typename T>
class Presort {
private:
    int size;
    T* array;

public:
    Presort(T* arr, int s) {
        array = arr;
        size = s;
    }

    ~Presort() {
        delete[] array;
    }

    T* getArray() {
        return array;
    }

    void setArray(T* arr) {
        array = arr;
    }

    void presort(int sortType) {

        // Sortowanie tablicy zgodnie z wybranym typem sortowania
        switch (sortType) {
            case 1: {// sortowanie rosnaco
                std::sort(array, array + size);
                break;
            }
            case 2: // sortowanie malejaco
                std::sort(array, array + size, std::greater<T>());
                break;
            case 3: { // 1/3 tablicy posortowana
                std::sort(array, array + size); // posortowanie całej tablicy
                std::random_device rd;
                std::mt19937 g(rd());
                std::shuffle(array + (size / 3), array + size, g); // przemieszanie 2/3 najwiekszych elementow
                break;
            }
            case 4: { // 2/3 tablice posortowane
                std::sort(array, array + size); // posortowanie całej tablicy
                std::random_device rd;
                std::mt19937 g(rd());
                std::shuffle(array + (size * 2 / 3), array + size, g); // przemieszanie 1/3 najwiekszych elementow
                break;
            }
            default:
                cout << endl << "Nieprawidlowy argument wywolania metody. Przeprowadzone zostalo sortowanie rosnaco." << endl;
                std::sort(array, array + size);
                break;
        }
    }
};

#endif //AIZO_PROJEKT1_PRESORT_H
