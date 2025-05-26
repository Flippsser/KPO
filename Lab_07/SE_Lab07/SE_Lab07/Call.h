#pragma once

namespace Call {
    int __cdecl cdeclFunc(int a, int b, int c);
    int __stdcall stdcallFunc(int& a, int b, int c);
    int __fastcall fastcallFunc(int a, int b, int c, int d);
}
