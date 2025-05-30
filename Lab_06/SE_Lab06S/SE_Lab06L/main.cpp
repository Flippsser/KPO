#include "Dictionary.h"
#include <iostream>
#include <windows.h>

using namespace Dictionary;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    try {
        Instance teachers = Create("�������������", 5);

        Entry t1 = { 1, "�������" };
        Entry t2 = { 2, "���������" };
        Entry t3 = { 3, "�������" };
        Entry t4 = { 4, "���������" };

        AddEntry(teachers, t1);
        AddEntry(teachers, t2);
        AddEntry(teachers, t3);

        std::cout << "------- " << teachers.name << " -------\n";
        std::cout << "�����������: " << teachers.maxsize << ", �������: " << teachers.size << "\n";
        for (int i = 0; i < teachers.size; i++) {
            std::cout << teachers.dictionary[i].id << ": " << teachers.dictionary[i].name << "\n";
        }
        std::cout << "-------------------------\n";

        DelEntry(teachers, 2);

        std::cout << "------- " << teachers.name << " -------\n";
        std::cout << "�����������: " << teachers.maxsize << ", �������: " << teachers.size << "\n";
        for (int i = 0; i < teachers.size; i++) {
            std::cout << teachers.dictionary[i].id << ": " << teachers.dictionary[i].name << "\n";
        }
        std::cout << "-------------------------\n";

        Entry newTeacher = { 6, "�����" };
        UpdEntry(teachers, 3, newTeacher);

        std::cout << "------- " << teachers.name << " -------\n";
        std::cout << "�����������: " << teachers.maxsize << ", �������: " << teachers.size << "\n";
        for (int i = 0; i < teachers.size; i++) {
            std::cout << teachers.dictionary[i].id << ": " << teachers.dictionary[i].name << "\n";
        }
        std::cout << "-------------------------\n";

        Instance students = Create("��������", 5);


        Entry s1 = { 1, "������" };
        Entry s2 = { 2, "������" };
        Entry s3 = { 3, "�������" };
        Entry s4 = { 4, "���������" };


        AddEntry(students, s1);
        AddEntry(students, s2);
        AddEntry(students, s3);
        AddEntry(students, s4);


        std::cout << "------- " << students.name << " -------\n";
        std::cout << "�����������: " << students.maxsize << ", �������: " << students.size << "\n";
        for (int i = 0; i < students.size; i++) {
            std::cout << students.dictionary[i].id << ": " << students.dictionary[i].name << "\n";
        }
        std::cout << "-------------------------\n";


        Entry newStudent = { 5, "��������" };
        UpdEntry(students, 3, newStudent);

        std::cout << "------- " << students.name << " -------\n";
        std::cout << "�����������: " << students.maxsize << ", �������: " << students.size << "\n";
        for (int i = 0; i < students.size; i++) {
            std::cout << students.dictionary[i].id << ": " << students.dictionary[i].name << "\n";
        }
        std::cout << "-------------------------\n";

        DelEntry(students, 2);

        std::cout << "------- " << students.name << " -------\n";
        std::cout << "�����������: " << students.maxsize << ", �������: " << students.size << "\n";
        for (int i = 0; i < students.size; i++) {
            std::cout << students.dictionary[i].id << ": " << students.dictionary[i].name << "\n";
        }
        std::cout << "-------------------------\n";

        Delete(teachers);
        Delete(students);
    }
    catch (const char* e) {
        std::cerr << "������: " << e << std::endl;
    }

    system("pause");
    return 0;
}