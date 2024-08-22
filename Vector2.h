//
// Created by root on 2024/8/22.
//

#ifndef HELLOCPP_VECTOR2_H
#define HELLOCPP_VECTOR2_H

const double eps = 1e-8;

class Vector2
{
public:
    double X,Y;
public:
    Vector2();
    Vector2(double x, double y);
public:
    std::string print() const;
public:
    Vector2 plus(Vector2 vec2) const;
    Vector2 minus(Vector2 vec2) const;
    double dotProduct(Vector2 vec2) const;
};


#endif //HELLOCPP_VECTOR2_H
