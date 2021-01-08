#pragma once

#include <vector>
#include "ptr.h"
#include "exp.h"

struct _Mu;
using Mu = Ptr<_Mu>;

// creation
Mu mu();

// aggregatation 
Mu operator<<(Mu uni, Mu e);
Mu operator<<(Mu uni, const std::vector<float> & mu);
Mu operator<<(Mu uni, Exp exp);

// instance 
//Mu operator<<=(Mu uni, Relation);

// disaggregate
Mu operator>>(Mu uni, std::vector<float> & mu);

// connection
Mu join(Mu a, Mu b);
Mu join(const std::vector<Mu> & v);

Mu chain(Mu a, Mu b);
Mu chain(const std::vector<Mu> & v);

