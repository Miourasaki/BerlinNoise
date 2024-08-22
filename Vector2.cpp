//
// Created by root on 2024/8/22.
//

#include <iostream>
#include "Vector2.h"

Vector2::Vector2() {
    X= 0;Y=0;
}
Vector2::Vector2(double x, double y): X(x), Y(y) {}

Vector2 Vector2::plus(Vector2 vec2) const
{
    return {
    this->X + vec2.X,
    this->Y + vec2.Y
    };
}

Vector2 Vector2::minus(Vector2 vec2) const
{
    return {
            this->X - vec2.X,
            this->Y - vec2.Y
    };
}

double Vector2::dotProduct(Vector2 vec2) const
{
    return this->X * vec2.X + this->Y * vec2.Y;
}

std::string Vector2::print() const
{
    return std::to_string(X) + "," + std::to_string(Y);
}

