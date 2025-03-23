#include <iostream>
#include "stdafx.h"
#include "menu.h"

using namespace std;
void menu1() {
    cout << "Выберите вариант выполнения программы:\n";
    cout << "1 - Информация о введённой Вами дате\n";
    cout << "2 - Выход из программы\n";
    cout << "Вариант выполнения программы: ";
}
void menu2() {
    cout << "Вы ввели некорректный вариант выполнения\n";
    menu1();
}
