#pragma once
#include <vector>
#include "mu.h"

struct Exp {
    Exp(float scalar);
    Exp(bool b);
    Exp(int i);
    Exp(const std::vector<float> & v);
    Exp operator()(Exp a);
    Exp operator++();
    Exp operator--();
    Exp operator*=(Exp a);
    Exp operator/=(Exp a);
    Exp operator+=(Exp a);
    Exp operator-=(Exp a);
    Exp operator=(Exp a);
   // Mu operator->();
};

Exp & operator+(const Exp & a, const Exp b);
Exp & operator-(const Exp & a, const Exp & b);
Exp & operator*(const Exp & a, const Exp & b);
Exp & operator/(const Exp & a, const Exp & b);
Exp & operator==(const Exp & a, const Exp & b);
Exp & operator!=(const Exp & a, const Exp & b);
Exp & operator&&(const Exp & a, const Exp & b);
Exp & operator||(const Exp & a, const Exp & b);
Exp & operator<(const Exp & a, const Exp & b);
Exp & operator>(const Exp & a, const Exp & b);
Exp & operator<=(const Exp & a, const Exp & b);
Exp & operator>=(const Exp & a, const Exp & b);
Exp & operator+(const Exp & a);
Exp & operator-(const Exp & a);
Exp & operator!(const Exp & a);
Exp & operator~(const Exp & a);

struct Args{
    Args(std::vector<Exp> & v );
};

struct Def{
    Exp operator()(Args a); 
};
