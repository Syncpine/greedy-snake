#pragma once

#include <iostream>
#include <Windows.h>

#include "config.h"
#include "snake.h"
#include "food.h"

using namespace std;


void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printxy(int x, int y, char symbol)
{
    gotoxy(x, y);

    printf("%c", symbol);
}

void printxy(int x, int y, string str)
{
    gotoxy(x, y);
    printf("%s", str.c_str());
}

void ShowSnake(const Snake& snake)
{
    auto snakeBody = snake.body.begin();

    while (snake.body.end() != snakeBody)
    {
        printxy(snakeBody->xx, snakeBody->yy, SNAKE_ICON);
        ++snakeBody;
    }
}

void ShowFood(const Food& food)
{
    printxy(food.position.xx, food.position.yy, FOOD_ICON);
}

void ShowWall()
{
    int ii, jj;

    // WALL->UP
    for (ii = 0; ii <= WALL_WIDTH; ++ii)
    {
        printxy(ii, 0, WALL_ICON);
    }

    // WALL->DOWN
    for (ii = 0; ii <= WALL_WIDTH; ++ii)
    {
        printxy(ii, WALL_HEIGHT, WALL_ICON);
    }

    // WALL->LEFT
    for (jj = 0; jj <= WALL_HEIGHT; ++jj)
    {
        printxy(0, jj, WALL_ICON);
    }

    // WALL->RIGHT
    for (jj = 0; jj <= WALL_HEIGHT; ++jj)
    {
        printxy(WALL_WIDTH, jj, WALL_ICON);
    }
}

