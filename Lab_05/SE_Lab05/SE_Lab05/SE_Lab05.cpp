#include "stdafx.h"
#include "dictionary.h"
#include <windows.h>
#include <iostream>

int main() {
   
    setlocale(LC_ALL, "rus");

    std::cout << "--- Тестирование словаря ---" << std::endl;

    try {
#ifdef TEST_CREATE_01
        // Тест: слишком длинное имя словаря
        dictionary::Create("Очень длинное имя словаря", 10);
#endif

#ifdef TEST_CREATE_02
        // Тест: некорректный размер словаря
        dictionary::Create("ValidName", 150);
#endif

#ifdef TEST_ADDENTRY_03
        // Тест: переполнение словаря
        dictionary::Instance dict = dictionary::Create("Тест", 1);
        dictionary::Entry e1 = { 1, "Запись 1" };
        dictionary::Entry e2 = { 2, "Запись 2" };
        dictionary::AddEntry(dict, e1);
        dictionary::AddEntry(dict, e2);
#endif

#ifdef TEST_ADDENTRY_04
        // Тест: дублирование ID
        dictionary::Instance dict = dictionary::Create("Тест", 2);
        dictionary::Entry e1 = { 1, "Запись 1" };
        dictionary::AddEntry(dict, e1);
        dictionary::AddEntry(dict, e1);
#endif

#ifdef TEST_GETENTRY_05
        // Тест: поиск несуществующего элемента
        dictionary::Instance dict = dictionary::Create("Тест", 1);
        dictionary::Entry e1 = { 1, "Запись 1" };
        dictionary::AddEntry(dict, e1);
        dictionary::GetEntry(dict, 999);
#endif

#ifdef TEST_GETENTRY_06
        // Тест: удаление несуществующего элемента
        dictionary::Instance dict = dictionary::Create("Тест", 1);
        dictionary::Entry e1 = { 1, "Запись 1" };
        dictionary::AddEntry(dict, e1);
        dictionary::DelEntry(dict, 999);
#endif

#ifdef TEST_UPDENTRY_07
        // Тест: обновление несуществующего элемента
        dictionary::Instance dict = dictionary::Create("Тест", 1);
        dictionary::Entry e1 = { 1, "Запись 1" };
        dictionary::AddEntry(dict, e1);
        dictionary::Entry e2 = { 2, "Запись 2" };
        dictionary::UpdEntry(dict, 999, e2);
#endif

#ifdef TEST_UPDENTRY_08
        // Тест: конфликт ID при обновлении
        dictionary::Instance dict = dictionary::Create("Тест", 2);
        dictionary::Entry e1 = { 1, "Запись 1" };
        dictionary::Entry e2 = { 2, "Запись 2" };
        dictionary::AddEntry(dict, e1);
        dictionary::AddEntry(dict, e2);
        dictionary::Entry e3 = { 2, "Обновленная запись" };
        dictionary::UpdEntry(dict, 1, e3);
#endif

#ifdef TEST_DICTIONARY
        // Демонстрация работоспособности
        dictionary::Instance students = dictionary::Create("Студенты", 10);
        dictionary::AddEntry(students, { 1, "Иванов И.И." });
        dictionary::AddEntry(students, { 2, "Петров П.П." });
        dictionary::AddEntry(students, { 3, "Сидоров С.С." });
        dictionary::Print(students);

      

        dictionary::DelEntry(students, 1);
        dictionary::Print(students);
#endif

    }
    catch (const char* e) {
        std::cerr << "\n[ОШИБКА] " << e << std::endl;
    }
    catch (...) {
        std::cerr << "\n[НЕИЗВЕСТНАЯ ОШИБКА]" << std::endl;
    }

    std::cout << "\nТестирование завершено. Нажмите Enter...";
    std::cin.ignore(32767, '\n');
    return 0;
}