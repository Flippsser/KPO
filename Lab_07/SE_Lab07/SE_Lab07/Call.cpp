#include "Call.h"

namespace Call {

    int __cdecl cdeclFunc(int a, int b, int c) {
        return a + b + c; 
    }

    int __stdcall stdcallFunc(int& a, int b, int c) {
        return a * b * c; 
    }

    int __fastcall fastcallFunc(int a, int b, int c, int d) {
        return a + b + c + d;
    }
}
