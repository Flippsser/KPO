#include <iostream>
using namespace std;

// Определение псевдонимов типов для полей структуры
typedef float Metrazh;         // метраж квартиры (в кв.м.)
typedef int CountRooms;        // количество жилых комнат
typedef int BuildYear;         // год постройки
typedef int Floor;             // этаж
typedef bool Flag;             // для наличия (да/нет) таких помещений, как: кухня, ванна и т.д.


struct ApartmentParams {
    Metrazh area;          
    CountRooms rooms;      
    BuildYear buildYear;   
    Floor floor;          
    Flag hasKitchen;     
    Flag hasBathroom;     
    Flag hasToilet;        
    Flag hasBasement;      
    Flag hasBalcony;       

    // Операция 1: Перегрузка оператора сравнения "<" по метражу
    bool operator<(const ApartmentParams& other) const {
        return area < other.area;
    }

    // Операция 2: Перегрузка оператора сложения "+" для объединения параметров.
    // При объединении:
    // - метраж и количество комнат суммируются;
    // - для года постройки и этажа выбирается минимальное значение (условно);
    // - логические поля объединяются с помощью логического ИЛИ.
    ApartmentParams operator+(const ApartmentParams& other) const {
        ApartmentParams result;
        result.area = area + other.area;
        result.rooms = rooms + other.rooms;
        result.buildYear = (buildYear < other.buildYear) ? buildYear : other.buildYear;
        result.floor = (floor < other.floor) ? floor : other.floor;
        result.hasKitchen = hasKitchen || other.hasKitchen;
        result.hasBathroom = hasBathroom || other.hasBathroom;
        result.hasToilet = hasToilet || other.hasToilet;
        result.hasBasement = hasBasement || other.hasBasement;
        result.hasBalcony = hasBalcony || other.hasBalcony;
        return result;
    }
};

// Перегрузка оператора вывода "<<" для удобного вывода информации об объекте
ostream& operator<<(ostream& os, const ApartmentParams& apt) {
    os << "Параметры квартиры:" << endl;
    os << "  Метраж: " << apt.area << " кв.м." << endl;
    os << "  Количество жилых комнат: " << apt.rooms << endl;
    os << "  Год постройки: " << apt.buildYear << endl;
    os << "  Этаж: " << apt.floor << endl;
    os << "  Наличие кухни: " << (apt.hasKitchen ? "да" : "нет") << endl;
    os << "  Наличие ванны: " << (apt.hasBathroom ? "да" : "нет") << endl;
    os << "  Наличие туалета: " << (apt.hasToilet ? "да" : "нет") << endl;
    os << "  Наличие подвала: " << (apt.hasBasement ? "да" : "нет") << endl;
    os << "  Наличие балкона: " << (apt.hasBalcony ? "да" : "нет") << endl;
    return os;
}

int main() {
    system("chcp 1251");

    ApartmentParams apt1 = { 65.0, 3, 1995, 4, true,  true,  true,  false, true };
    ApartmentParams apt2 = { 45.0, 2, 2005, 2, false, true, false, false, false };

    cout << "Апартамент 1:" << endl << apt1 << endl;
    cout << "Апартамент 2:" << endl << apt2 << endl;

    if (apt1 < apt2) {
        cout << "Апартамент 1 имеет меньший метраж, чем апартамент 2." << endl;
    }
    else {
        cout << "Апартамент 1 имеет больший или равный метражу по сравнению с апартаментом 2." << endl;
    }

    ApartmentParams merged = apt1 + apt2;
    cout << "Объединённые параметры (результат операции apt1 + apt2):" << endl << merged << endl;

    return 0;
}
