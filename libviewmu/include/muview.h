#pragma once
#include <memory>
#include "mu.h"

struct MuView{
    virtual int Attach(Mu mu) = 0;
};