#pragma once

#include <list>

#include "point.h"
#include "def.h"
#include "opt.h"

struct Snake
{
public:
    std::list<Point> body;
    Direction direction;

public:
    void MoveSnake(Direction& moveDirection)
    {
        CorrectDirection(moveDirection);

        auto pre_itor = this->body.end();
        --pre_itor;
        auto cur_itor = this->body.end();

        switch (moveDirection)
        {
        case Left:
        {
            while (this->body.begin() != pre_itor && this->body.begin() != cur_itor)
            {
                --pre_itor;
                --cur_itor;
                cur_itor->xx = pre_itor->xx;
                cur_itor->yy = pre_itor->yy;
            }

            --(pre_itor->xx);
        }
        break;

        case Up:
        {
            while (this->body.begin() != pre_itor && this->body.begin() != cur_itor)
            {
                --pre_itor;
                --cur_itor;
                cur_itor->xx = pre_itor->xx;
                cur_itor->yy = pre_itor->yy;
            }

            --(pre_itor->yy);
        }
        break;

        case Right:
        {
            while (this->body.begin() != pre_itor && this->body.begin() != cur_itor)
            {
                --pre_itor;
                --cur_itor;
                cur_itor->xx = pre_itor->xx;
                cur_itor->yy = pre_itor->yy;
            }

            ++(pre_itor->xx);
        }
        break;

        case Down:
        {
            while (this->body.begin() != pre_itor && this->body.begin() != cur_itor)
            {
                --pre_itor;
                --cur_itor;
                cur_itor->xx = pre_itor->xx;
                cur_itor->yy = pre_itor->yy;
            }

            ++(pre_itor->yy);
        }
        break;

        default:
            return;
        }

        this->direction = moveDirection;
    }

    void PrintSnake() const
    {
        std::cout << "Direction: " << GetDirectionStr(this->direction) << std::endl << std::endl;

        for (auto point : this->body)
        {
            std::cout << "[" << point.xx << ", " << point.yy << "]" << std::endl;
        }

        std::cout << std::endl;
    }

    void DeInit()
    {
        this->body.clear();
        direction = Right;
    }

private:
    void CorrectDirection(Direction& moveDirection) const
    {
        if (Left == this->direction || Right == this->direction)
        {
            if (Left == moveDirection || Right == moveDirection)
            {
                moveDirection = this->direction;
            }
        }
        else if (Up == this->direction || Down == this->direction)
        {
            if (Up == moveDirection || Down == moveDirection)
            {
                moveDirection = this->direction;
            }
        }
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

    snake.direction = Right;
}

