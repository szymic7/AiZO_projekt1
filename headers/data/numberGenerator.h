#ifndef NUMBERGENERATOR_H
#define NUMBERGENERATOR_H

#include <cstdlib>
#include <ctime>

template<typename T>
class NumberGenerator {
    int array_size;

public:
    NumberGenerator(int size = 0) {
        array_size = size;
        srand(time(nullptr));
    }

    ~NumberGenerator() {
        // Tu możesz dodać kod do zwolnienia pamięci, jeśli to konieczne
    }

    void setSize(int size = 0) {
        array_size = size;
    }

    T* generateArray() {
        T* array = new T[array_size];

        T max_value = static_cast<T>(array_size);

        for (int i = 0; i < array_size; i++) {
            T random_value;
            if constexpr (std::is_floating_point<T>::value) {
                random_value = static_cast<T>(rand()) / (RAND_MAX / max_value);
            } else {
                random_value = static_cast<T>(rand() % (max_value + 1));
            }
            array[i] = random_value;
        }
        return array;
    }

};

#endif // NUMBERGENERATOR_H