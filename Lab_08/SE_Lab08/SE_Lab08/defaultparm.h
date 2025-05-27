#pragma once
#include <iostream>

namespace Lab08 {
    int defaultparm(int a1, int a2 = 10, int a3 = 20, int a4 = 30, int a5 = 40) {
        int sum = a1 + a2 + a3 + a4 + a5;
        return sum / 5; 
    }
}
