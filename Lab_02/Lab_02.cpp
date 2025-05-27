#include <iostream>
#include <iomanip>

using namespace std; // Подключение пространства имён std

// Статическая функция для демонстрации работы указателя на функцию (пункт 21)
static void printData() {
    cout << "Вызов функции printData()" << endl;
}

int main() {
    system("chcp 1251");
    const int n = 3;
    const int X = 9 + n;     // X = 12
    const int Y = 10 + n;    // Y = 13
    const int Z = 11 + n;    // Z = 14
    const float S = 1.0f + n; // S = 4.0

    // 4. Объявляем две переменные типа bool.
    bool bool1 = false;
    bool bool2 = true;

    // 5. Переменная типа char (латинский символ) – вторая буква фамилии "Brazouski": 'r'
    char sym1 = 'r';

    // 6. Переменная типа char (русский символ) – вторая буква фамилии "Бразовский": 'р'
    char sym2 = 'р';

    // 7. Переменная типа wchar_t (латинский символ) – первый символ фамилии "Brazouski": L'B'
    wchar_t sym3 = L'B';

    // 8. Переменная типа wchar_t (русский символ) – первый символ фамилии "Бразовский": L'Б'
    wchar_t sym4 = L'Б';

    // 9. Объявляем две переменные типа short с значениями X и -X.
    short short1 = X;
    short short2 = -X;

    // 10. Шестнадцатеричные значения наибольшего и наименьшего short.
    short shortMax = 0x7FFF;
    short shortMin = -0x8000;

    // 11. Шестнадцатеричные значения для unsigned short.
    unsigned short ushortMax = 0xFFFF;
    unsigned short ushortMin = 0x0;

    // 12. Объявляем две переменные типа int с значениями Y и -Y.
    int int1 = Y;
    int int2 = -Y;

    // 13. Шестнадцатеричные значения для int.
    int intMax = 0x7FFFFFFF;
    int intMin = static_cast<int>(0x80000000); // Исправлено: явное приведение к int

    // 14. Шестнадцатеричные значения для unsigned int.
    unsigned int uintMax = 0xFFFFFFFF;
    unsigned int uintMin = 0x0;

    // 15. Объявляем две переменные типа long с значениями Z и -Z.
    long long1 = Z;
    long long2 = -Z;

    // 16. Шестнадцатеричные значения для long.
    long longMax = 0x7FFFFFFFL;
    long longMin = static_cast<long>(0x80000000); // Исправлено

    // 17. Шестнадцатеричные значения для unsigned long.
    unsigned long ulongMax = 0xFFFFFFFF;
    unsigned long ulongMin = 0x0;

    // 18. Объявляем две переменные типа float с значениями S и -S.
    float float1 = S;
    float float2 = -S;

    // 19. Операции, дающие результаты 1.#INF, -1.#INF, -1.#IND.
    double d1 = 1.0;
    double d2 = 0.0;
    double negInf = -d1 / 0.0;
    double posInf = d1 / 0.0;
    double nanVal = d2 / 0.0;

    // 20. Объявляем указатели на типы и инициализируем их адресами соответствующих переменных.
    char* charptr = &sym1;
    wchar_t* wcharptr = &sym3;
    short* shortptr = &short1;
    int* intptr = &int1;
    float* floatptr = &float1;
    double* doubleptr = &negInf;

    cout << "Адреса переменных:\n";
    cout << " bool1: " << &bool1 << "\n";
    cout << " bool2: " << &bool2 << "\n";
    cout << " sym1 (char): " << static_cast<void*>(&sym1) << "\n";
    cout << " sym2 (char): " << static_cast<void*>(&sym2) << "\n";
    cout << " sym3 (wchar_t): " << static_cast<void*>(&sym3) << "\n";
    cout << " sym4 (wchar_t): " << static_cast<void*>(&sym4) << "\n";
    cout << " short1: " << &short1 << "\n";
    cout << " int1: " << &int1 << "\n";
    cout << " float1: " << &float1 << "\n";
    cout << " negInf: " << &negInf << "\n";

    cout << "\nУказатели:\n";
    cout << " charptr: " << static_cast<void*>(charptr) << "\n";
    cout << " wcharptr: " << static_cast<void*>(wcharptr) << "\n";
    cout << " shortptr: " << shortptr << "\n";
    cout << " intptr: " << intptr << "\n";
    cout << " floatptr: " << floatptr << "\n";
    cout << " doubleptr: " << doubleptr << "\n";

    // Увеличиваем указатели на 3
    charptr += 3;
    wcharptr += 3;
    shortptr += 3;
    intptr += 3;
    floatptr += 3;
    doubleptr += 3;

    cout << "\nПосле увеличения указателей на 3:\n";
    cout << " charptr: " << static_cast<void*>(charptr) << "\n";
    cout << " wcharptr: " << static_cast<void*>(wcharptr) << "\n";
    cout << " shortptr: " << shortptr << "\n";
    cout << " intptr: " << intptr << "\n";
    cout << " floatptr: " << floatptr << "\n";
    cout << " doubleptr: " << doubleptr << "\n";

    // 21. Работа с указателем на функцию.
    void (*funcptr)() = printData;
    cout << "\nВызов функции через указатель:\n";
    funcptr();

    // Демонстрация ссылки на переменную
    int& ref = int1;
    cout << "\nСсылка ref: " << ref << "\n";

    // Вывод размера типа long
    cout << "\nРазмер типа long: " << sizeof(long) << " байт\n";

    cout << "\nКонец программы\n";

    return 0;
}
