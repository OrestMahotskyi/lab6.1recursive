#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 26;
const int MIN_VALUE = 3;
const int MAX_VALUE = 92;

// Рекурсивна функція для генерації випадкового масиву
void generateArray(int arr[], int size, int index = 0) {
    if (index == size) return; // Базовий випадок
    arr[index] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    generateArray(arr, size, index + 1); // Рекурсивний виклик для наступного елементу
}

// Рекурсивна функція для форматного виведення масиву
void printArray(const int arr[], int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return; // Базовий випадок
    }
    cout << setw(4) << arr[index];
    printArray(arr, size, index + 1); // Рекурсивний виклик для наступного елементу
}

// Рекурсивна функція для обчислення кількості та суми елементів, що відповідають критерію
void countAndSum(const int arr[], int size, int &count, int &sum, int index = 0) {
    if (index == size) return; // Базовий випадок
    if (arr[index] % 2 == 0 && index % 7 != 0) {
        count++;
        sum += arr[index];
    }
    countAndSum(arr, size, count, sum, index + 1); // Рекурсивний виклик для наступного елементу
}

// Рекурсивна функція для заміни елементів, що відповідають критерію, на нулі
void replaceWithZeros(int arr[], int size, int index = 0) {
    if (index == size) return; // Базовий випадок
    if (arr[index] % 2 == 0 && index % 7 != 0) {
        arr[index] = 0;
    }
    replaceWithZeros(arr, size, index + 1); // Рекурсивний виклик для наступного елементу
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    int arr[SIZE];

    // Генерація масиву
    generateArray(arr, SIZE);

    // Виведення початкового масиву
    cout << "Initial array:" << endl;
    printArray(arr, SIZE);

    // Підрахунок кількості та суми елементів, що відповідають критерію
    int count = 0, sum = 0;
    countAndSum(arr, SIZE, count, sum);

    // Виведення кількості та суми
    cout << "Count of elements matching the condition: " << count << endl;
    cout << "Sum of elements matching the condition: " << sum << endl;

    // Заміна елементів на нулі
    replaceWithZeros(arr, SIZE);

    // Виведення модифікованого масиву
    cout << "Modified array:" << endl;
    printArray(arr, SIZE);

    return 0;
}
