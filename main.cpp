#include <iostream>

#include "interface.h"

using namespace std;


Snake snake;

int main()
{
    InitSnake(snake);

    ShowWall();

    ShowSnake(snake);

    // todo

    gotoxy(0, WALL_HEIGHT + 2);
    snake.PrintSnake();

    snake.DeInit();

    return 0;
}

