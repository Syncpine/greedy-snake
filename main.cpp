#include <iostream>

#include "interface.h"

using namespace std;


Snake snake;
Food food;

int main()
{
    char ch = '\0';
    Direction direction = Right;

    srand(time(0));

    InitSnake(snake);

    while (true)
    {
        system("CLS");

        ShowWall();

        ShowSnake(snake);

        food.Create();
        ShowFood(food);

        gotoxy(0, WALL_HEIGHT + 2);
        snake.PrintSnake();

        while ('\0' == ch)
        {
            std::cout << "Please input move direction:" << std::endl;
            cin >> ch;
            std::cout << std::endl;
            switch (ch)
            {
            case 'a':
            case 'A':
            {
                direction = Left;
            }
            break;
            case 'w':
            case 'W':
            {
                direction = Up;
            }
            break;
            case 'd':
            case 'D':
            {
                direction = Right;
            }
            break;
            case 's':
            case 'S':
            {
                direction = Down;
            }
            break;
            case 'q':
            case 'Q':
            {
                std::cout << "Game over." << std::endl << std::endl;
                return 0;
            }
            break;
            default:
                break;
            }
        }

        snake.MoveSnake(direction);

        ch = '\0';
    }

    snake.DeInit();

    return 0;
}

