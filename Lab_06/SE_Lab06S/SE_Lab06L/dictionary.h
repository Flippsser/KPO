#pragma once
#include <string>
#include <memory> 

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30

#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышена максимальная ёмкость словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: элемент не найден"
#define THROW06 "DelEntry: элемент не найден"
#define THROW07 "UpdEntry: элемент не найден"
#define THROW08 "UpdEntry: дублирование идентификатора"

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

    // Методы словаря
    Instance Create(std::string name, int size);
    void AddEntry(Instance& inst, Entry ed);
    void DelEntry(Instance& inst, int id);
    void UpdEntry(Instance& inst, int id, Entry new_ed);
    Entry GetEntry(Instance inst, int id);
    void Print(Instance d);
    void Delete(Instance& d);
};