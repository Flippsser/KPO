#pragma once
#include <iostream>
#include <cstring>

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30

// ������
constexpr auto THROW01 = "Create: �������� ������ ����� �������";
constexpr auto THROW02 = "Create: �������� ������ ������������ ������� �������";
constexpr auto THROW03 = "AddEntry: ������������ �������";
constexpr auto THROW04 = "AddEntry: ������������ ��������������";
constexpr auto THROW05 = "GetEntry: �� ������ �������";
constexpr auto THROW06 = "DelEntry: �� ������ �������";
constexpr auto THROW07 = "UpdEntry: �� ������ �������";
constexpr auto THROW08 = "UpdEntry: ������������ ��������������";

namespace dictionary {
    struct Entry {
        int id;
        char name[ENTRYNAMEMAXSIZE];
    };

    struct Instance {
        char name[DICTNAMEMAXSIZE];
        int maxsize;
        int size;
        Entry* dictionary[DICTMAXSIZE];
    };

    Instance Create(const char* name, int size);
    void AddEntry(Instance& inst, Entry ed);
    void DelEntry(Instance& inst, int id);
    void UpdEntry(Instance& inst, int id, Entry new_ed);
    Entry GetEntry(Instance inst, int id);
    void Print(Instance d);
    void Delete(Instance& d);
}