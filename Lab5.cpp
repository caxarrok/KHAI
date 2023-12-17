// Lab5.cpp 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <windows.h>
#include <conio.h>


const int MAX_SIZE = 100;


void inputArray(int arr[], int size) {
    std::cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter number #" << (i + 1) << ": ";
        std::cin >> arr[i];
    }
}
// void тут використовується для заповнення масиву випадковими значеннями в заданому діапазоні
void generateArray(int arr[], int size, int rangeStart, int rangeEnd) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % (rangeEnd - rangeStart + 1) + rangeStart;
    }
}
// void призначений для пошуку індексів максимального негативного та мінімального позитивного елементів у масиві.
void findMinMaxIndices(int arr[], int size, int& minPositiveIndex, int& maxNegativeIndex) {
    minPositiveIndex = -1;
    maxNegativeIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0 && (minPositiveIndex == -1 || arr[i] < arr[minPositiveIndex])) {
            minPositiveIndex = i;
        }
        else if (arr[i] < 0 && (maxNegativeIndex == -1 || arr[i] > arr[maxNegativeIndex])) {
            maxNegativeIndex = i;
        }
    }
}

int main() {
    SetConsoleTitle(L"Oskorbina Masha 117");
    int size;
    std::cout << "Enter the size of the array (up to " << MAX_SIZE << "): ";
    std::cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        std::cerr << "Invalid array size.\n";
        return 1;
    }

    int arr[MAX_SIZE];
    int minPositiveIndex, maxNegativeIndex;

    int choice;
    std::cout << "Choose the initialization method:\n"
        << "1. Manual input\n"
        << "2. Random generation\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        inputArray(arr, size);
        break;
    case 2: {
        int rangeStart, rangeEnd;
        std::cout << "Enter the range for random generation (start end): ";
        std::cin >> rangeStart >> rangeEnd;
        generateArray(arr, size, rangeStart, rangeEnd);
        break;
    }
    default:
        std::cerr << "Invalid choice.\n";
        return 1;
    }

    findMinMaxIndices(arr, size, minPositiveIndex, maxNegativeIndex);

    if (minPositiveIndex != -1) {
        std::cout << "Minimum positive value: " << arr[minPositiveIndex]
            << " at index " << minPositiveIndex << std::endl;
    }
    else {
        std::cout << "No positive values found.\n";
    }

    if (maxNegativeIndex != -1) {
        std::cout << "Maximum negative value: " << arr[maxNegativeIndex]
            << " at index " << maxNegativeIndex << std::endl;
    }
    else {
        std::cout << "No negative values found.\n";
    }

    return 0;
}
