#include "date_utils.h"
#include "stdafx.h"
#include "leap_year.h"
#include <string>
using namespace std;



bool isValidDate(int day, int month, int year) {
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (Checking(year)) {
        daysInMonth[1] = 29;
    }

    return (month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth[month - 1]);
}

int quantity(int month, int day, int isLeap) {
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeap) {
        daysInMonth[1] = 29;
    }

    int sumDays = 0;
    for (int i = 0; i < month - 1; i++) {
        sumDays += daysInMonth[i];
    }
    sumDays += day;

    return sumDays;
}

string mesec(int mes) {

     string MES[]{ "Январь","Февраль","Март",
        "Апрель","Май", "Июнь",
        "Июль","Август","Сентябрь",
        "Октябрь", "Ноябрь", "Декабрь"};

    return MES[mes - 1];

}