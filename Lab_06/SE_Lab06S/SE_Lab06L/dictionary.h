#pragma once
#include <string>
#include <memory> 

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30

#define THROW01 "Create: �������� ������ ����� �������"
#define THROW02 "Create: ��������� ������������ ������� �������"
#define THROW03 "AddEntry: ������������ �������"
#define THROW04 "AddEntry: ������������ ��������������"
#define THROW05 "GetEntry: ������� �� ������"
#define THROW06 "DelEntry: ������� �� ������"
#define THROW07 "UpdEntry: ������� �� ������"
#define THROW08 "UpdEntry: ������������ ��������������"

namespace Dictionary {

    struct Entry {
        int id = 0;
        char name[ENTRYNAMEMAXSIZE]{};
    };


    struct Instance {
        std::string name{};
        int maxsize = 0;
        int size = 0;
        Entry* dictionary = nullptr;

    };

    // ������ �������
    Instance Create(std::string name, int size);
    void AddEntry(Instance& inst, Entry ed);
    void DelEntry(Instance& inst, int id);
    void UpdEntry(Instance& inst, int id, Entry new_ed);
    Entry GetEntry(Instance inst, int id);
    void Print(Instance d);
    void Delete(Instance& d);
};