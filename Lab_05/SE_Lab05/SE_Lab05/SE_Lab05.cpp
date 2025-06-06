#include "stdafx.h"
#include "dictionary.h"
#include <windows.h>
#include <iostream>

int main() {
   
    setlocale(LC_ALL, "rus");

    std::cout << "--- ������������ ������� ---" << std::endl;

    try {
#ifdef TEST_CREATE_01
        // ����: ������� ������� ��� �������
        dictionary::Create("����� ������� ��� �������", 10);
#endif

#ifdef TEST_CREATE_02
        // ����: ������������ ������ �������
        dictionary::Create("ValidName", 150);
#endif

#ifdef TEST_ADDENTRY_03
        // ����: ������������ �������
        dictionary::Instance dict = dictionary::Create("����", 1);
        dictionary::Entry e1 = { 1, "������ 1" };
        dictionary::Entry e2 = { 2, "������ 2" };
        dictionary::AddEntry(dict, e1);
        dictionary::AddEntry(dict, e2);
#endif

#ifdef TEST_ADDENTRY_04
        // ����: ������������ ID
        dictionary::Instance dict = dictionary::Create("����", 2);
        dictionary::Entry e1 = { 1, "������ 1" };
        dictionary::AddEntry(dict, e1);
        dictionary::AddEntry(dict, e1);
#endif

#ifdef TEST_GETENTRY_05
        // ����: ����� ��������������� ��������
        dictionary::Instance dict = dictionary::Create("����", 1);
        dictionary::Entry e1 = { 1, "������ 1" };
        dictionary::AddEntry(dict, e1);
        dictionary::GetEntry(dict, 999);
#endif

#ifdef TEST_GETENTRY_06
        // ����: �������� ��������������� ��������
        dictionary::Instance dict = dictionary::Create("����", 1);
        dictionary::Entry e1 = { 1, "������ 1" };
        dictionary::AddEntry(dict, e1);
        dictionary::DelEntry(dict, 999);
#endif

#ifdef TEST_UPDENTRY_07
        // ����: ���������� ��������������� ��������
        dictionary::Instance dict = dictionary::Create("����", 1);
        dictionary::Entry e1 = { 1, "������ 1" };
        dictionary::AddEntry(dict, e1);
        dictionary::Entry e2 = { 2, "������ 2" };
        dictionary::UpdEntry(dict, 999, e2);
#endif

#ifdef TEST_UPDENTRY_08
        // ����: �������� ID ��� ����������
        dictionary::Instance dict = dictionary::Create("����", 2);
        dictionary::Entry e1 = { 1, "������ 1" };
        dictionary::Entry e2 = { 2, "������ 2" };
        dictionary::AddEntry(dict, e1);
        dictionary::AddEntry(dict, e2);
        dictionary::Entry e3 = { 2, "����������� ������" };
        dictionary::UpdEntry(dict, 1, e3);
#endif

#ifdef TEST_DICTIONARY
        // ������������ �����������������
        dictionary::Instance students = dictionary::Create("��������", 10);
        dictionary::AddEntry(students, { 1, "������ �.�." });
        dictionary::AddEntry(students, { 2, "������ �.�." });
        dictionary::AddEntry(students, { 3, "������� �.�." });
        dictionary::Print(students);

      

        dictionary::DelEntry(students, 1);
        dictionary::Print(students);
#endif

    }
    catch (const char* e) {
        std::cerr << "\n[������] " << e << std::endl;
    }
    catch (...) {
        std::cerr << "\n[����������� ������]" << std::endl;
    }

    std::cout << "\n������������ ���������. ������� Enter...";
    std::cin.ignore(32767, '\n');
    return 0;
}