// lab_6_1_rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Функція для генерації масиву
void Create(int* b, const int size, const int Low, const int High, int i) {
    b[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(b, size, Low, High, i + 1);
}

// Функція для виведення масиву
void Print(const int* b, const int size, int i) {
    cout << setw(4) << b[i];
    if (i < size - 1)
        Print(b, size, i + 1);
    else
        cout << endl;
}

// Функція для обчислення кількості елементів, які задовольняють критерію
int Count(int* b, const int size, int index = 0) {
    if (index == size) {
        return 0; 
    }
    
    if (!(b[index] % 2 != 0 && b[index] % 3 == 0)) {
        return Count(b, size, index + 1) + 1;
    }
    else {
        b[index] = 0; 
        return Count(b, size, index + 1);
    }
}


int Sum(int* b, const int size, int index = 0)
{ 
    if (index == size) {
        return 0; 
    }
     
    if (!(b[index] % 2 != 0 && b[index] % 3 == 0)) {
        return Sum(b, size, index + 1) + b[index]; 
    }
    else {
        return Sum(b, size, index + 1); 
    }
}



int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int size = 21;
    int b[size];
    const int Low = 10;
    const int High = 90;

    // Генерація масиву
    Create(b, size, Low, High, 0);
    cout << "massif b:" << endl;
    Print(b, size, 0);

    // Обчислення кількості та суми
    int count = Count(b, size);
    int sum = Sum(b, size);

    // Виведення результатів
    cout << "count: " << count << endl;
    cout << "sum: " << sum << endl;
    cout << "modified b:" << endl;
    Print(b, size, 0);

    cin.get();
    return 0;
}