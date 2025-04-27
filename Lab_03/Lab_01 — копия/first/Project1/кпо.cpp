#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "menu.h"
#include "date_utils.h"
#include "leap_year.h"
#include <string>



using namespace std;



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a = 1;

    do {
        menu1();
        char n;
        cin >> n;
        cout << "\n";

        while (n < '1' || n > '2') {
            cout << "Вы ввели некорректный номер.\n";
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

            cout << "Введите номер года с событием\n";
            int godsob;
            cin >> godsob;

           

            cout << "Введите порядковый номер дня события\n";
            int daysob;
            cin >> daysob;

            bool celsob = Checking(godsob);

            if (!celsob && !(daysob > 0 && daysob < 366)) {
                
                    cout << "Введен неправильный порядковый номер дня события!\n";
                    break;
                
            }
            else if  (!(daysob > 0 && daysob < 367)){
          
                    cout << "Введен неправильный порядковый номер дня события!\n";
                    break;
                
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
            cout << "Введённый Вами день является: " << dayOfYear << " в году\n";
            cout << "Введённый Вами месяц является: " << mes << " в году\n";
            cout << "Название введенного месяца: " << mesec(mes) << '\n';

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
            
            if (daysob == 256) {

                cout << "День: " << daysob << " - День программиста, ";

                if (!celsob) {
                    cout << "Дата: 13 сентября " << godsob << '\n';
                }
                else {
                    cout << "Дата: 12 сентября " << godsob << '\n';
                }

            }

            if ((!celsob && daysob == 67) || (celsob && daysob == 68)) {
                cout << "День: " << daysob << " - Международный женский день " << godsob << '\n';
            }

            if ((!celsob && daysob == 311) || (celsob && daysob == 312)) {
                cout << "День: " << daysob << " - День Октябрьской Революции " << godsob << '\n';

            }
            if (daysob == 1) {
                cout << "День: " << daysob << " - Новый год " << godsob << '\n';
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
