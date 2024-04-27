#pragma once

#include <list>

#include "point.h"
#include "def.h"
#include "opt.h"
#include "food.h"

struct Snake
{
public:
    std::list<Point> body;
    Direction direction;

    std::list<Point> preTail;

public:
    bool MoveSnake(Direction& moveDirection)
    {
        CorrectDirection(moveDirection);

        auto pre_itor = this->body.end();
        --pre_itor;
        auto cur_itor = this->body.end();

        preTail.push_back(Point(pre_itor->xx, pre_itor->yy));

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

            if (0 == pre_itor->xx)
            {
                return false;
            }
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
            if (0 == pre_itor->yy)
            {
                return false;
            }
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
            if (WALL_WIDTH == pre_itor->xx)
            {
                return false;
            }
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
            if (WALL_HEIGHT == pre_itor->yy)
            {
                return false;
            }
        }
        break;

        default:
            return false;
        }

        auto itor = this->body.begin();
        ++itor;
        while (this->body.end() != itor)
        {
            if (*(this->body.begin()) == (*itor))
            {
                return false;
            }
            ++itor;
        }

        this->direction = moveDirection;
        return true;
    }

    void TryEatFood(Food& food)
    {
        Point snakeHead = *(this->body.begin());

        if (snakeHead == food.position)
        {
            for (auto itor : this->preTail)
            {
                this->body.push_back(itor);
            }

            food.Init();
        }
        else
        {
            this->preTail.clear();
        }
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
        this->preTail.clear();
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
    snake.preTail.clear();
}

