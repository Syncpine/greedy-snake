#pragma once

struct Point
{
    int xx;
    int yy;
    Point() :Point(0, 0) { ; }
    Point(int x, int y) :xx(x), yy(y) { ; }
};

