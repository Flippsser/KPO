#include <iostream>
#include "Varparm.h"

int main() {
    std::cout << "ivarparm(0): " << Varparm::ivarparm(0) << std::endl;
    std::cout << "ivarparm(1, 5): " << Varparm::ivarparm(1, 5) << std::endl;
    std::cout << "ivarparm(3, 2, 3, 4): " << Varparm::ivarparm(3, 2, 3, 4) << std::endl;
    std::cout << "ivarparm(7, 1, 2, 3, 4, 5, 6, 7): " << Varparm::ivarparm(7, 1, 2, 3, 4, 5, 6, 7) << std::endl;

    std::cout << "\nsvarparm(0): " << Varparm::svarparm(0) << std::endl;
    std::cout << "svarparm(1, 5): " << Varparm::svarparm(1, 5) << std::endl;
    std::cout << "svarparm(3, 2, 3, 4): " << Varparm::svarparm(3, 2, 3, 4) << std::endl;
    std::cout << "svarparm(7, 1, 2, 3, 4, 5, 6, 7): "<< Varparm::svarparm(7, 1, 2, 3, 4, 5, 6, 7) << std::endl;

    std::cout << "\nfvarparm: " << Varparm::fvarparm(FLT_MAX) << std::endl;
    std::cout << "fvarparm(1.5): " << Varparm::fvarparm(1.5f, FLT_MAX) << std::endl;
    std::cout << "fvarparm(1.1, 2.2, 3.3): "<< Varparm::fvarparm(1.1f, 2.2f, 3.3f, FLT_MAX) << std::endl;
    std::cout << "fvarparm(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7): "<< Varparm::fvarparm(1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, FLT_MAX) << std::endl;

    std::cout << "\ndvarparm: " << Varparm::dvarparm(DBL_MAX) << std::endl;
    std::cout << "dvarparm(1.5): " << Varparm::dvarparm(1.5, DBL_MAX) << std::endl;
    std::cout << "dvarparm(1.1, 2.2, 3.3): "<< Varparm::dvarparm(1.1, 2.2, 3.3, DBL_MAX) << std::endl;
    std::cout << "dvarparm(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7): " << Varparm::dvarparm(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, DBL_MAX) << std::endl;

    return 0;
}