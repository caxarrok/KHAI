#include <iostream>

const int MAX_SIZE = 100; //максимальний розмір масиву(тобто скільки всього чисел ми зможемо ввести)

// swapCount це змінна, в якій буде зберігатися кількість перестановок

void insertionSort(int arr[], int size, int& swapCount) {
    int assignmentCount = 0; // Для подсчета присваиваний
    int comparisonCount = 0; // Для подсчета сравнений

    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        assignmentCount++; // Присваивание key = arr[i]
        int j = i - 1;

        // Увеличиваем comparisonCount перед циклом, так как сравнение j >= 0 происходит всегда перед входом в цикл
        while (j >= 0) {
            comparisonCount++; // За каждое сравнение arr[j] > key
            if (arr[j] > key) { // Сравниваем элементы
                arr[j + 1] = arr[j]; // Сдвигаем элемент вправо
                assignmentCount++; // Присваивание arr[j + 1] = arr[j]
                swapCount++; // Увеличиваем счетчик обменов
                j--;
            }
            else {
                // Если элемент не больше key, то сравнение выполнено, но обмен не происходит
                break;
            }
        }
        // Выполнение этого присваивания происходит всегда, когда выход из цикла произошел
        arr[j + 1] = key;
        assignmentCount++; // Присваивание arr[j + 1] = key

    }

    std::cout << "Number of comparisons: " << comparisonCount << std::endl;
    std::cout << "Number of assignments: " << assignmentCount << std::endl;
}

int main() {
    int size;
    std::cout << "Enter the size of the array (up to " << MAX_SIZE << "): ";//вводимо кількість чисел, які ми хочемо відсортувати
    std::cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        std::cerr << "Invalid array size.\n";         //якщо вводимо значення більше ніж дохволений розмір в константі, то програма не спрацює і поверне 2
        return 2;
    }

    int arr[MAX_SIZE];

    std::cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter number #" << (i + 1) << ": ";
        std::cin >> arr[i];
    }

    int swapCountAscending = 0;
    insertionSort(arr, size, swapCountAscending);

    std::cout << "Sorted in ascending order: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nNumber of swaps: " << swapCountAscending << "\n";

    //скидання масиву та змінна кількості перестановок
    int arr2[MAX_SIZE];

    std::cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter number #" << (i + 1) << ": ";
        std::cin >> arr2[i];
    }

    int swapCountDescending = 0;

    //сортування в зворотньому напрямку
    insertionSort(arr2, size, swapCountDescending);

    std::cout << "Sorted in descending order: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << "\nNumber of swaps: " << swapCountDescending << "\n";

    return 0;
}


