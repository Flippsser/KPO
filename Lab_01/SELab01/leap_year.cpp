#include "leap_year.h"
#include "stdafx.h"
bool Checking(int x) {
    return ((x % 4 == 0) && ((x % 100 != 0) || (x % 400 == 0)));
}
int nextLeapYear(int year) {
    while (!Checking(year)) {
        year++;
    }
    return year;
}
