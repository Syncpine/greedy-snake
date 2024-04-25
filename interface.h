#pragma once

#include <iostream>
#include <Windows.h>

#include "config.h"

using namespace std;


void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ShowWall()
{
    int ii, jj;

    // WALL->UP
    for (ii = 0; ii <= WALL_WIDTH; ++ii)
    {
        gotoxy(ii, 0);
        printf("%c", WALL_ICON);
    }

    // WALL->DOWN
    for (ii = 0; ii <= WALL_WIDTH; ++ii)
    {
        gotoxy(ii, WALL_HEIGHT);
        printf("%c", WALL_ICON);
    }

    // WALL->LEFT
    for (jj = 0; jj <= WALL_HEIGHT; ++jj)
    {
        gotoxy(0, jj);
        printf("%c", WALL_ICON);
    }

    // WALL->RIGHT
    for (jj = 0; jj <= WALL_HEIGHT; ++jj)
    {
        gotoxy(WALL_WIDTH, jj);
        printf("%c", WALL_ICON);
    }
}

