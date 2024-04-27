#pragma once

#include <random>
#include "point.h"
#include "config.h"

struct Food
{
public:
    Point position;

public:
    void Create()
    {
        this->position.xx = rand() % (WALL_WIDTH - 1) + 1;
        this->position.yy = rand() % (WALL_HEIGHT - 1) + 1;
    }
};

