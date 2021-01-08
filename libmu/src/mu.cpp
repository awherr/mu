#include "mu.h"
#include <list>

struct _Mu : std::enable_shared_from_this<_Mu>{
    _Mu(){}
    _Mu(const std::vector<float> & v): m_data(v){}
    std::list<Mu>       m_children;
    std::list<std::weak_ptr<_Mu>> m_peers, m_parents;
    std::vector<float>  m_data;
};

// creation
Mu mu(){
    static auto p = Mu::create();
    return p;
}

// aggregatation 
Mu operator<<(Mu uni, Mu e){
    uni->m_children.push_back(e);
    e->m_parents.push_back(uni);
    return uni; 
}

Mu operator<<(Mu uni, const std::vector<float> & v){
    auto ret = Mu();
    ret->m_data = v;
    return uni << ret;
}

Mu operator>>(Mu uni, std::vector<float> & v){
    v = uni->m_data;
    return uni;
}

Mu join(Mu a, Mu b){
    a->m_peers.push_back(b);
    b->m_peers.push_back(a);
    return a;
}

Mu join(Mu a, std::list<Mu> v){
    for(auto b: v){
        join(a, b);
    }
    return a;
}

Mu chain(std::list<Mu> v){
    Mu t, f;
    for(auto a: v){
        if(t){
            join(a, t);
        }else{
            f = a;
        }
        t = a;
    }
    return f;
}