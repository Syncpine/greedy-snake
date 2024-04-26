#include <iostream>

#include "interface.h"

using namespace std;


Snake snake;

int main()
{
    InitSnake(snake);

    std::cout << std::endl << std::endl;

    ShowWall();

    ShowSnake(snake);

    // snake.PrintSnake();

    // todo

    snake.DeInit();

    return 0;
}

