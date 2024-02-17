/*
К каждому элементу аi массива А(m) добавить значение элемента аm / 2 этого
массива.Элементы массива Т сгенерировать датчиком псевдослучайных чисел.
Количество элементов массива m≤800, , значения элементов принадлежат отрезку
[-20, 80].Выполнить сортировку элементов преобразованного массива по
возрастанию методом пирамидальной сортировки
*/

#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>

using namespace std;

// Функция заполнения массива
void arrIn(const size_t&, int*);
// Функция преобразования массива
void arrUpd(const size_t&, int*);
// Вспомогательная функция сортировки массива
void arrSwap(const size_t&, size_t, int*);
// Основная функция сортировки массива
void arrSort(const size_t&, int*);
// Функция вывода массива
void arrOut(const size_t&, int*);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    // Определение размера массива
    size_t m; // m - Число элементов массива
    cout << "Введите количество элементов массива (0 < m > 800): ";
    cin >> m;
    if (m > 800)
    {
        cerr << "Ошибка! : Недопустимое значение m\n";
        return 1;
    }

    // Создание массива и его преобразование
    int* array = new int [m];
    arrIn(m, array);
    cout << "Изначальный массив:\n";
    arrOut(m, array);
    arrUpd(m, array);

    // Сортировка массива
    arrSort(m, array);

    // Вывод массива
    cout << "Обработанный и отсортированный массив:\n";
    arrOut(m, array);

    // Освобождение памяти
    delete[] array;
}

void arrIn(const size_t& m, int* array)
{
    int b = -20; // b - beginning
    int e = 80; //e - end

    for (size_t i = 0; i < m; i++)
    {
        array[i] = b + rand() % (e - b + 1);
    }
}

void arrUpd(const size_t& m, int* array)
{
    int a_m2 = array[m / 2]; // a_m2 - элемент массива array[m / 2]

    for (size_t i = 0; i < m; i++)
    {
        array[i] += a_m2;
    }
}

void arrSwap(const size_t& m, size_t i, int* array)
{
    int larg = i; // larg - largest
    int rt = i * 2 + 1; // rt - right
    int lt = i * 2 + 2; // lt - left

    if (lt < m && array[lt] > array[larg])
    {
        larg = lt;
    }
    if (rt < m && array[rt] > array[larg])
    {
        larg = rt;
    }

    if (larg != i)
    {
        swap(array[i], array[larg]);
        arrSwap(m, larg, array);
    }
}

void arrSort(const size_t& m, int* array)
{
    for (int i = m / 2 - 1; i >= 0; i--)
    {
        arrSwap(m, i, array);
    }

    for (int i = m - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        arrSwap(i, 0, array);
    }
}

void arrOut(const size_t& m, int* array)
{
    for (size_t i = 0; i < m; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}