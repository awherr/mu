#pragma once

#include <memory>
#include <vector>

struct _Mu;
using Mu = std::shared_ptr<_Mu>;

// creation
Mu mu();

// aggregatation 
Mu operator<<(Mu uni, Mu e);
Mu operator<<(Mu uni, const std::vector<float> & mu);

// disaggregate
Mu operator>>(Mu uni, std::vector<float> & mu);

// connection
Mu operator-(Mu a, Mu b);

  
