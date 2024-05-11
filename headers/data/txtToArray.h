#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

#ifndef AIZO_PROJEKT1_TXTTOARRAY_H
#define AIZO_PROJEKT1_TXTTOARRAY_H

template<typename T>
class TxtToArray {
private:
    string filename;
    int length;

public:
    TxtToArray(string fname = "", int size = 0) {
        filename = fname;
        length = size;
    }

    void setFilename(string fname) {
        filename = fname;
    }

    int getLength() {
        return length;
    }

    T* readArray() {
        ifstream file(filename);
        if (file.is_open()) {
            int size;
            file >> size; // Wczytanie rozmiaru tablicy
            length = size;
            file.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoruj znak nowej linii
            T* array = new T[size];

            // Wczytywanie kolejnych liczb z pliku
            for (int i = 0; i < size; ++i) {
                string line;
                if (getline(file, line)) {
                    stringstream ss(line);
                    ss >> array[i]; // Konwertuj linie na odpowiedni typ i zapisz do tablicy
                } else {
                    cout << endl << "Nie można odczytać wystarczającej liczby linii." << endl;
                    delete[] array; // Zwolnienie pamieci w przypadku błędu
                    array = nullptr;
                    break;
                }
            }
            file.close();
            return array;
        } else {
            cout << endl << "Nie można otworzyć pliku " << filename << endl;
            return nullptr; // Zwroc nullptr w przypadku niepowodzenia odczytu pliku
        }
    }

};


#endif //AIZO_PROJEKT1_TXTTOARRAY_H
