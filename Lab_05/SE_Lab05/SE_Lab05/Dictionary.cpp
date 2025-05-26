#include "dictionary.h"
#include "stdafx.h"
#include <iostream>
#include <windows.h>

namespace dictionary {

    Instance Create(const char* name, int size) {
        if (strlen(name) >= DICTNAMEMAXSIZE) throw THROW01;
        if (size > DICTMAXSIZE || size <= 0) throw THROW02;

        Instance newDict{};
        strcpy_s(newDict.name, name);
        newDict.maxsize = size;
        newDict.size = 0;
        return newDict;
    }

    void AddEntry(Instance& inst, Entry ed) {
        if (inst.size >= inst.maxsize) throw THROW03;

        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i]->id == ed.id) throw THROW04;
        }

        if (strlen(ed.name) >= ENTRYNAMEMAXSIZE)
            throw "AddEntry: превышена длина имени записи";

        inst.dictionary[inst.size] = new Entry();
        inst.dictionary[inst.size]->id = ed.id;
        strcpy_s(inst.dictionary[inst.size]->name, ed.name);
        inst.size++;
    }

    void DelEntry(Instance& inst, int id) {
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i]->id == id) {
                delete inst.dictionary[i];
                for (int j = i; j < inst.size - 1; j++) {
                    inst.dictionary[j] = inst.dictionary[j + 1];
                }
                inst.size--;
                return;
            }
        }
        throw THROW06;
    }

    Entry GetEntry(Instance inst, int id) {
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i]->id == id) {
                return *inst.dictionary[i];
            }
        }
        throw THROW05;
    }

    void UpdEntry(Instance& inst, int id, Entry new_ed) {
        int target_index = -1;
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i]->id == id) target_index = i;
            else if (inst.dictionary[i]->id == new_ed.id) throw THROW08;
        }
        if (target_index == -1) throw THROW07;

        if (strlen(new_ed.name) >= ENTRYNAMEMAXSIZE)
            throw "UpdEntry: превышена длина имени записи";

        *inst.dictionary[target_index] = new_ed;
    }

    void Delete(Instance& inst) {
        for (int i = 0; i < inst.size; i++) {
            delete inst.dictionary[i];
        }
        inst.size = 0;
    }

    void Print(Instance inst) {
        UINT old_cp = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);

        std::cout << "------- " << inst.name << " -------" << std::endl;
        std::cout << "¬местимость: " << inst.maxsize << ", «аписей: " << inst.size << std::endl;

        for (int i = 0; i < inst.size; i++) {
            std::cout << inst.dictionary[i]->id << ": " << inst.dictionary[i]->name << std::endl;
        }

        std::cout << "-------------------------" << std::endl;
        SetConsoleOutputCP(old_cp);
    }

} // namespace dictionary