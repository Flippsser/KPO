#include <iostream>
#include "defaultparm.h"

using namespace Lab08;

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "������� �������������� (5 ����������): " << defaultparm(5) << std::endl;

    std::cout << "������� �������������� (7 ����������): " << defaultparm(5, 10, 15, 20, 25) << std::endl;

    return 0;
}
