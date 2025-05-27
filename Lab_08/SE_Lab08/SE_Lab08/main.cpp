#include <iostream>
#include "defaultparm.h"

using namespace Lab08;

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Среднее арифметическое (5 параметров): " << defaultparm(5) << std::endl;

    std::cout << "Среднее арифметическое (7 параметров): " << defaultparm(5, 10, 15, 20, 25) << std::endl;

    return 0;
}
