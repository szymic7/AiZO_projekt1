#include <iostream>
#include <algorithm>
#include <chrono>
#include <filesystem>
#include "../../headers/data/numberGenerator.h"
#include "../../headers/sort_algorithms/insertionSort.h"
#include "../../headers/sort_algorithms/quickSort.h"
#include "../../headers/data/txtToArray.h"
#include "../../headers/sort_algorithms/heapSort.h"
#include "../../headers/sort_algorithms/ShellSort.h"
#include "../../headers/data/presort.h"

using namespace std;

std::random_device rd;
std::mt19937 gen(rd());

void showMenu() {

    // ZMIENNE POMOCNICZE
    bool quit = false, sorted = false;
    int choice, rozmiar, data_type = 0;
    string filename;
    chrono::high_resolution_clock::time_point start, end;
    chrono::duration<double, std::milli> time(0);

    // WSKAZNIKI NA DYNAMICZNE TABLICE PRZED POSORTOWANIEM
    int *intArray = nullptr;
    float *floatArray = nullptr;
    double *doubleArray = nullptr;

    // OBIEKTY KLASY TxtToArray, TWORZACE TABLICE NA PODSTAWIE PLIKU .TXT
    TxtToArray<int> txtToInt;
    TxtToArray<float> txtToFloat;
    TxtToArray<double> txtToDouble;

    // OBIEKTY KLASY NumberGenerator, GENERUJACE TABLICE LICZB LOSOWYCH
    NumberGenerator<int> intGenerator;
    NumberGenerator<float> floatGenerator;
    NumberGenerator<double> doubleGenerator;

    // WSKAZNIKI NA DYNAMICZNE TABLICE LICZB DO POSORTOWANIA - KOPIE
    int* intToSort = nullptr;
    float* floatToSort = nullptr;
    double* doubleToSort = nullptr;

    // OBIEKTY KLASY InsertionSort, SORTUJACE TABLICE METODA PRZEZ WSTAWIANIE
    InsertionSort<int> intInsertionSort;
    InsertionSort<float> floatInsertionSort;
    InsertionSort<double> doubleInsertionSort;

    // OBIEKTY KLASY HeapSort, SORTUJACE TABLICE METODA PRZEZ KOPCOWANIE
    HeapSort<int> intHeapSort;
    HeapSort<float> floatHeapSort;
    HeapSort<double> doubleHeapSort;

    // OBIEKTY KLASY ShellSort, SORTUJACE TABLICE METODA ALGORYTMU SHELLA
    ShellSort<int> intShellSort;
    ShellSort<float> floatShellSort;
    ShellSort<double> doubleShellSort;

    // OBIEKTY KLASY QuickSort, SORTUJACE TABLICE METODA SORTOWANIA SZYBKIEGO
    QuickSort<int> intQuickSort;
    QuickSort<float> floatQuickSort;
    QuickSort<double> doubleQuickSort;

    // PIERWSZY POZIOM MENU - WYBOR TYPU DANYCH DO SORTOWANIA
    do {
        cout << endl << "Z jakim typem danych chcesz pracowac?" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1) int" << endl << "2) float" << endl << "3) double" << endl;
        cout << "Wybor:";
        cin >> choice;

        switch(choice) {
            case 1: // int
                data_type = 1;
                break;
            case 2: // float
                data_type = 2;
                break;
            case 3: // double
                data_type = 3;
                break;
            default:
                cout << endl << "Niepoprawny numer wybranej opcji. Wybierz ponownie." << endl;
                break;
        }

    } while (data_type == 0);

    // DRUGI POZIOM MENU - TWORZENIE TABLICY/WYSWIETLANIE/SORTOWANIE
    do {
        cout << endl << "Wybierz operacje: " << endl;
        cout << "-------------------------------------" << endl;
        cout << "1) Wczytaj tablice liczb z pliku .txt" << endl;
        cout << "2) Wygeneruj tablice z losowymi wartosciami" << endl;
        cout << "3) Wyswietl ostatnio utworzona tablice" << endl;
        cout << "4) Posortuj ostatnio utworzona tablice" << endl;
        cout << "5) Wyswietl posortowana tablice" << endl;
        cout << "6) Zakoncz" << endl;
        cout << "Wybor:";
        cin >> choice;

        switch(choice) {
            case 1: // wczytaj tablice z pliku .txt

                while (true) {
                    cout << endl << "Podaj nazwe pliku: " << endl;
                    cin >> filename;
                    ifstream file(filename);

                    if(file.good()) {
                        file.close();
                        break;
                    } else {
                        file.close();
                        cout << "W projekcie nie ma pliku o takiej nazwie." << endl;
                    }
                }

                switch (data_type) {
                    case 1: { // int
                        delete [] intArray;
                        txtToInt.setFilename(filename);
                        intArray = txtToInt.readArray();
                        rozmiar = txtToInt.getLength();
                        sorted = false;
                        break;
                    }

                    case 2: { // float
                        delete [] floatArray;
                        txtToFloat.setFilename(filename);
                        floatArray = txtToFloat.readArray();
                        rozmiar = txtToFloat.getLength();
                        sorted = false;
                        break;
                    }

                    case 3: { // double
                        delete [] doubleArray;
                        txtToDouble.setFilename(filename);
                        doubleArray = txtToDouble.readArray();
                        rozmiar = txtToDouble.getLength();
                        sorted = false;
                        break;
                    }

                }
                break;

            case 2: // wygeneruj tablice - NumberGenerator

                cout << endl << "Podaj rozmiar tablicy: " << endl;
                cin >> rozmiar;
                switch (data_type) {
                    case 1: { // int
                        delete [] intArray;
                        intGenerator.setSize(rozmiar);
                        intArray = intGenerator.generateArray();
                        sorted = false;
                        break;
                    }

                    case 2: { // float
                        delete [] floatArray;
                        floatGenerator.setSize(rozmiar);
                        floatArray = floatGenerator.generateArray();
                        sorted = false;
                        break;
                    }

                    case 3: { // double
                        delete [] doubleArray;
                        doubleGenerator.setSize(rozmiar);
                        doubleArray = doubleGenerator.generateArray();
                        sorted = false;
                        break;
                    }
                }
                break;

            case 3: // wyswietl ostatnio utworzona tablice

                if(intArray != nullptr) {
                    cout << "Tablica liczb typu int:" << endl << "{ ";
                    for (int i = 0; i < rozmiar; i++) {
                        cout << intArray[i] << ", ";
                    }
                    cout << "}" << endl;
                } else if(floatArray != nullptr) {
                    cout << "Tablica liczb typu float:" << endl << "{ ";
                    for (int i = 0; i < rozmiar; i++) {
                        cout << floatArray[i] << ", ";
                    }
                    cout << "}" << endl;
                } else if(doubleArray != nullptr) {
                    cout << "Tablica liczb typu double:" << endl << "{ ";
                    for (int i = 0; i < rozmiar; i++) {
                        cout << doubleArray[i] << ", ";
                    }
                    cout << "}" << endl;
                } else {
                    cout << endl << "Nie utworzono zadnej tablicy. Utworz tablice, aby moc ja wyswietlic." << endl;
                }
                break;

            case 4: // posortuj ostatnio utworzona tablice

                if(intArray == nullptr && floatArray == nullptr && doubleArray == nullptr) {
                    cout << endl << "Tablica nie zostala utworzona. Utworz tablice, aby moc ja posortowac." << endl;
                } else if(sorted) {
                    cout << endl << "Tablica zostala juz posortowana. Utworz nowa tablice, aby ja posortowac." << endl;
                } else {
                    do {
                        cout << endl << "Wybierz algorytm sortowania: " << endl;
                        cout << "-----------------------------------------------" << endl;
                        cout << "1) Sortowanie przez wstawianie (Insertion sort)" << endl;
                        cout << "2) Sortowanie przez kopcowanie (Heap sort)" << endl;
                        cout << "3) Sortowanie Shella" << endl;
                        cout << "4) Sortowanie szybkie (Quick sort)" << endl;
                        cout << "Wybor:";
                        cin >> choice;

                        if(choice < 1 || choice > 4)
                            cout << endl << "Niepoprawny numer wybranej opcji. Wybierz ponownie." << endl;

                    } while(choice < 1 || choice > 4);

                    // przygotowanie bufora na kopie tablicy do posortowania
                    switch(data_type) {
                        case 1: // int
                            delete[] intToSort;
                            intToSort = new int[rozmiar];
                            copy(intArray, intArray + rozmiar, intToSort);
                            break;
                        case 2: // float
                            delete[] floatToSort;
                            floatToSort = new float[rozmiar];
                            copy(floatArray, floatArray + rozmiar, floatToSort);
                            break;
                        case 3: // double
                            delete[] doubleToSort;
                            doubleToSort = new double[rozmiar];
                            copy(doubleArray, doubleArray + rozmiar, doubleToSort);
                            break;
                    }


                    switch (choice) { // ALGORYTMY SORTOWANIA
                        case 1: { // INSERTION SORT
                            if (intArray != nullptr) { // int

                                intInsertionSort.setSize(rozmiar);
                                intInsertionSort.setArray(intToSort);
                                start = chrono::high_resolution_clock::now();
                                intInsertionSort.sort();
                                end = chrono::high_resolution_clock::now();
                                copy(intInsertionSort.getArray(), intInsertionSort.getArray() + rozmiar, intToSort);

                            } else if (floatArray != nullptr) { // float

                                floatInsertionSort.setSize(rozmiar);
                                floatInsertionSort.setArray(floatToSort);
                                start = chrono::high_resolution_clock::now();
                                floatInsertionSort.sort();
                                end = chrono::high_resolution_clock::now();
                                copy(floatInsertionSort.getArray(), floatInsertionSort.getArray() + rozmiar,
                                     floatToSort);

                            } else if (doubleArray != nullptr) { // double

                                doubleInsertionSort.setSize(rozmiar);
                                doubleInsertionSort.setArray(doubleToSort);
                                start = chrono::high_resolution_clock::now();
                                doubleInsertionSort.sort();
                                end = chrono::high_resolution_clock::now();
                                copy(doubleInsertionSort.getArray(), doubleInsertionSort.getArray() + rozmiar,
                                     doubleToSort);

                            }

                            time = chrono::duration<double, std::milli>(end - start);
                            cout << endl << "Sortowanie zakonczone." << endl;
                            cout << "Czas sortowania: " << time << endl;
                            sorted = true;
                            break;
                        }

                        case 2: // HEAP SORT

                            if (intArray != nullptr) { // int

                                intHeapSort.setSize(rozmiar);
                                intHeapSort.setArray(intToSort);
                                start = chrono::high_resolution_clock::now();
                                intHeapSort.sort();
                                end = chrono::high_resolution_clock::now();
                                copy(intHeapSort.getArray(), intHeapSort.getArray() + rozmiar, intToSort);

                            } else if (floatArray != nullptr) { // float

                                floatHeapSort.setSize(rozmiar);
                                floatHeapSort.setArray(floatToSort);
                                start = chrono::high_resolution_clock::now();
                                floatHeapSort.sort();
                                end = chrono::high_resolution_clock::now();
                                copy(floatHeapSort.getArray(), floatHeapSort.getArray() + rozmiar, floatToSort);

                            } else if (doubleArray != nullptr) { // double

                                doubleHeapSort.setSize(rozmiar);
                                doubleHeapSort.setArray(doubleToSort);
                                start = chrono::high_resolution_clock::now();
                                doubleHeapSort.sort();
                                end = chrono::high_resolution_clock::now();
                                copy(doubleHeapSort.getArray(), doubleHeapSort.getArray() + rozmiar, doubleToSort);

                            }

                            time = chrono::duration<double, std::milli>(end - start);
                            cout << endl << "Sortowanie zakonczone." << endl;
                            cout << "Czas sortowania: " << time << endl;
                            sorted = true;
                            break;

                        case 3: // SHELL

                            do {
                                cout << endl << "Wybierz wzor tworzacy algorytm: " << endl;
                                cout << "----------------------------------------------------------------------------" << endl;
                                cout << "1) Oryginalny algorytm Shella: n = floor(N/2^k) - zlozonosc O(N^2)" << endl;
                                cout << "2) Algorytm Frank & Lazarus: n = 2*floor(N/2^(k+1))+1 - zlozonosc O(N^(3/2))" << endl;
                                cout << "Wybor:";
                                cin >> choice;

                                if (choice != 1 && choice != 2)
                                    cout << endl << "Nieprawidlowy numer wybranej opcji. Wybierz jeszcze raz." << endl;

                            } while(choice != 1 && choice != 2);

                            if (intArray != nullptr) { // int

                                intShellSort.setSize(rozmiar);
                                intShellSort.setArray(intToSort);
                                start = chrono::high_resolution_clock::now();
                                intShellSort.sort(choice);
                                end = chrono::high_resolution_clock::now();
                                copy(intShellSort.getArray(), intShellSort.getArray() + rozmiar, intToSort);

                            } else if (floatArray != nullptr) { // float

                                floatShellSort.setSize(rozmiar);
                                floatShellSort.setArray(floatToSort);
                                start = chrono::high_resolution_clock::now();
                                floatShellSort.sort(choice);
                                end = chrono::high_resolution_clock::now();
                                copy(floatShellSort.getArray(), floatShellSort.getArray() + rozmiar, floatToSort);

                            } else if (doubleArray != nullptr) { // double

                                doubleShellSort.setSize(rozmiar);
                                doubleShellSort.setArray(doubleToSort);
                                start = chrono::high_resolution_clock::now();
                                doubleShellSort.sort(choice);
                                end = chrono::high_resolution_clock::now();
                                copy(doubleShellSort.getArray(), doubleShellSort.getArray() + rozmiar, doubleToSort);

                            }

                            time = chrono::duration<double, std::milli>(end - start);
                            cout << endl << "Sortowanie zakonczone." << endl;
                            cout << "Czas sortowania: " << time << endl;
                            sorted = true;
                            break;

                        case 4: // QUICK SORT
                            do {
                                cout << endl << "W jaki sposob ma byc wybierany pivot: " << endl;
                                cout << "-----------------------------------------------" << endl;
                                cout << "1) Skrajny lewy element tablicy" << endl;
                                cout << "2) Skrajny prawy element tablicy" << endl;
                                cout << "3) Srodkowy element tablicy" << endl;
                                cout << "4) Losowy element tablicy" << endl;
                                cout << "Wybor:";
                                cin >> choice;

                                if (choice < 1 || choice > 4)
                                    cout << endl << "Nieprawidlowy numer wybranej opcji. Wybierz jeszcze raz." << endl;

                            } while(choice < 1 || choice > 4);


                            if (intArray != nullptr) { // int

                                intQuickSort.setSize(rozmiar);
                                intQuickSort.setArray(intToSort);
                                start = chrono::high_resolution_clock::now();
                                intQuickSort.quickSort(0, intQuickSort.getSize() - 1, choice);
                                end = chrono::high_resolution_clock::now();
                                copy(intQuickSort.getArray(), intQuickSort.getArray() + rozmiar, intToSort);

                            } else if (floatArray != nullptr) { // float

                                floatQuickSort.setSize(rozmiar);
                                floatQuickSort.setArray(floatToSort);
                                start = chrono::high_resolution_clock::now();
                                floatQuickSort.quickSort(0, floatQuickSort.getSize() - 1, choice);
                                end = chrono::high_resolution_clock::now();
                                copy(floatQuickSort.getArray(), floatQuickSort.getArray() + rozmiar, floatToSort);

                            } else if (doubleArray != nullptr) { // double

                                doubleQuickSort.setSize(rozmiar);
                                doubleQuickSort.setArray(doubleToSort);
                                start = chrono::high_resolution_clock::now();
                                doubleQuickSort.quickSort(0, doubleQuickSort.getSize() - 1, choice);
                                end = chrono::high_resolution_clock::now();
                                copy(doubleQuickSort.getArray(), doubleQuickSort.getArray() + rozmiar, doubleToSort);

                            }

                            time = chrono::duration<double, std::milli>(end - start);
                            cout << endl << "Sortowanie zakonczone." << endl;
                            cout << "Czas sortowania: " << time << endl;
                            sorted = true;
                            break;

                        default:
                            cout << endl << "Sortowanie nie powiodło się. Sprobuj ponownie." << endl;
                            break;
                    }

                }
                break;

            case 5: // wyswietl posortowana tablice

                if(sorted) {

                    if(intToSort != nullptr) { // int
                        cout << endl << "Posortowana tablica liczb typu int:" << endl << "{ ";
                        for (int i = 0; i < rozmiar; i++) {
                            cout << intToSort[i] << ", ";
                        }
                        cout << "}" << endl;
                    } else if(floatToSort != nullptr) { // float
                        cout << endl << "Posortowana tablica liczb typu float:" << endl << "{ ";
                        for (int i = 0; i < rozmiar; i++) {
                            cout << floatToSort[i] << ", ";
                        }
                        cout << "}" << endl;
                    } else if(doubleToSort != nullptr) { // double
                        cout << endl << "Posortowana tablica liczb typu double:" << endl << "{ ";
                        for (int i = 0; i < rozmiar; i++) {
                            cout << doubleToSort[i] << ", ";
                        }
                        cout << "}" << endl;
                    }

                } else {
                    cout << endl << "Tablica nie zostala jeszcze posortowana. Utworz tablice, a nastepnia ja posortuj." << endl;
                }
                break;

            case 6: // zakoncz
                quit = true;
                break;

            default:
                cout << endl << "Niepoprawny numer wybranej opcji. Wybierz ponownie." << endl;
                break;
        }

    } while (!quit);

}



int main() {
    showMenu();
    return 0;
}
