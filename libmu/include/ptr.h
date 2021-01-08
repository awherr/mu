#pragma once
#include <memory>

template<typename _Ty>
struct Ptr : std::shared_ptr<_Ty>{
    Ptr(){}
    Ptr(_Ty * p):std::shared_ptr<_Ty>(p){}
    operator _Ty&(){return *this->get();}
    static Ptr<_Ty> create(){return Ptr<_Ty>(new _Ty);}
};
