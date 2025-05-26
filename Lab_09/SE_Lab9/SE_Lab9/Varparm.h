#pragma once
#include <cfloat>
#ifndef VARPARM_H
#define VARPARM_H

namespace Varparm {
    int ivarparm(int count, ...);
    int svarparm(short count, ...);
    double fvarparm(float last = FLT_MAX, ...);
    double dvarparm(double last = DBL_MAX, ...);
}

#endif