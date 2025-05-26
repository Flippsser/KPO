#include <iostream>
#include "Call.h"

using namespace Call;

int main() {
    setlocale(LC_CTYPE, "Russian");

    int a, b, c, d;
    std::cout << "Введите a,b,c,d :";
    std::cin >> a >> b >> c >> d;

    std::cout << "Результат cdeclFunc: " << cdeclFunc(a, b, c) << std::endl;
    std::cout << "Результат stdcallFunc: " << stdcallFunc(a, b, c) << std::endl;
    std::cout << "Результат fastcallFunc: " << fastcallFunc(a, b, c, d) << std::endl;

    return 0;
}
