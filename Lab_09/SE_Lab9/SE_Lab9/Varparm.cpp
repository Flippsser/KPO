#include "Varparm.h"
#include <cstdarg>
#include <climits>
#include <cfloat>
#include <algorithm>

namespace Varparm {
    int ivarparm(int count, ...) {
        va_list args;
        va_start(args, count);
        int product = 1;

        for (int i = 0; i < count; ++i) {
            int value = va_arg(args, int);
            product *= value;
        }

        va_end(args);
        return product;
    }

    int svarparm(short count, ...) {
        va_list args;
        va_start(args, count);
        int max_val = INT_MIN;

        for (short i = 0; i < count; ++i) {
            int value = va_arg(args, int); // short преобразуется в int
            max_val = std::max(max_val, value);
        }

        va_end(args);
        return max_val;
    }

    double fvarparm(float last, ...) {
        va_list args;
        va_start(args, last);
        double sum = 0.0;
        float current = last;

        while (current != FLT_MAX) {
            sum += current;
            current = va_arg(args, double); // float преобразуется в double
        }

        va_end(args);
        return sum;
    }

    double dvarparm(double last, ...) {
        va_list args;
        va_start(args, last);
        double sum = 0.0;
        double current = last;

        while (current != DBL_MAX) {
            sum += current;
            current = va_arg(args, double);
        }

        va_end(args);
        return sum;
    }
}