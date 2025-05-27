#include <iostream>

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct date {
	day dd;
	month mm;
	year yyyy;

	bool operator==(const date& other) const {
		return dd == other.dd && mm == other.mm && yyyy == other.yyyy;
	}

	bool operator>(const date& other) const {
		return dd > other.dd && mm > other.mm && yyyy > other.yyyy;
	}

	bool operator<(const date& other) const {
		return dd < other.dd && mm < other.mm && yyyy < other.yyyy;
	}
};

int main() {
	date date1 = { 7,1,1980 };
	date date2 = { 8,2,1993 };
	date date3 = { 7,1,1980 };
	std::cout << (date1 < date2) << std::endl;
	std::cout << (date1 > date2) << std::endl;
	std::cout << (date1 == date2) << std::endl;
	std::cout << (date1 == date3) << std::endl;
}