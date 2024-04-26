#pragma once

#include <list>

#include "point.h"

struct Snake
{
    std::list<Point> body;

    void PrintSnake()
    {
        for (auto point : this->body)
        {
            std::cout << "[" << point.xx << ", " << point.yy << "]" << std::endl;
        }
        std::cout << std::endl;
    }

    void DeInit()
    {
        this->body.clear();
    }
};

void InitSnake(Snake& snake)
{
    snake.body.push_back({ 15,5 });
    snake.body.push_back({ 14,5 });
    snake.body.push_back({ 13,5 });
    snake.body.push_back({ 12,5 });
    snake.body.push_back({ 11,5 });
    snake.body.push_back({ 10,5 });
}

