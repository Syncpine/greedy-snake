#pragma once

#include <iostream>

#include "def.h"
using namespace std;

string GetDirectionStr(const Direction& direction)
{
    switch (direction)
    {
    case Left: return "Left";
    case Up: return "Up";
    case Right: return "Right";
    case Down: return "Down";
    default: return "";
    }
}

