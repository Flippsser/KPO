#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "menu.h"
#include "date_utils.h"
#include "leap_year.h"
using namespace std;
int main() {
    system("chcp 1251");
    int a = 10;
    do {
        menu1();
        char n;
        cin >> n;
        cout << "\n";
        while (n < '1' || n > '2') {
            cout << "Выберите существующий вариант выполнения программы\n";
            menu2();
            cin >> n;
            cout << "\n";
        }
        switch (n) {
        case '1': {
            cout << "Введите дату (в формате ДДММГГГГ):\n";
            char data[9];
            cin >> data;
            int mes = (data[2] - '0') * 10 + data[3] - '0';
            int den = (data[0] - '0') * 10 + data[1] - '0';
            int god = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
            bool cel = Checking(god);
            if (!isValidDate(den, mes, god)) {
                cout << "Ошибка! Введена некорректная дата.\n";
                break;
            }

            cout << "Введите дату рождения (в формате ДДММГГГГ):\n";
            char birth[9];
            cin >> birth;
            int mesbirth = (birth[2] - '0') * 10 + birth[3] - '0';
            int denbirth = (birth[0] - '0') * 10 + birth[1] - '0';
            int godbirth = (birth[4] - '0') * 1000 + (birth[5] - '0') * 100 + (birth[6] - '0') * 10 + birth[7] - '0';
            if (!isValidDate(denbirth, mesbirth, godbirth)) {
                cout << "Ошибка! Введена некорректная дата рождения.\n";
                break;
            }
            if (god < godbirth){ cout << "Ошибка! Введена некорректная дата рождения.\n" ; break;
            }
            cout << "Ваша введённая дата: " << den << ":" << mes << ":" << god << "\n";
            cout << "Ваш день рождения: " << denbirth << ":" << mesbirth << ":" << godbirth << "\n";
            if (cel) {
                cout << "Данный год является високосным\n";
            }
            else {
                cout << "Данный год не является високосным\n";
            }
            int dayOfYear = quantity(mes, den, cel);
            cout << "Введённый Вами день является " << dayOfYear << " в году\n";
            int birthdayOfYear = quantity(mesbirth, denbirth, Checking(god));
            if (mesbirth == 2 && denbirth == 29 && !cel) {
                int nextLeap = nextLeapYear(god);
                int daysRemaining = (365 - dayOfYear) + quantity(2, 29, Checking(nextLeap)) + ((nextLeap - god - 1) * 365);
                cout << "До ближайшего Вашего дня рождения " << daysRemaining << " дня(ей)\n";
            }
            else if (dayOfYear < birthdayOfYear) {
                cout << "До ближайшего Вашего дня рождения " << birthdayOfYear - dayOfYear << " дня(ей)\n";
            }
            else if (dayOfYear == birthdayOfYear) {
                cout << "С днём рождения!!\n";
            }
            else {
                int nextYearIsLeap = Checking(god + 1);
                int daysInCurrentYear = 365 + cel;
                int daysToNextBirthday = (daysInCurrentYear - dayOfYear) + quantity(mesbirth, denbirth, nextYearIsLeap);
                cout << "До ближайшего Вашего дня рождения " << daysToNextBirthday << " дня(ей)\n";
            }
            break;
        }
        case '2':
            cout << "Программа завершена\n";
            return 0;
        }
    } while (a != 0);
    return 0;
}
