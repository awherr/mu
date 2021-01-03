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
    return std::make_shared<_Mu>();
}

// aggregatation 
Mu operator<<(Mu uni, Mu e){
    uni->m_children.push_back(e);
    e->m_parents.push_back(uni);
    return uni; 
}

Mu operator<<(Mu uni, const std::vector<float> & v){
    return uni << std::make_shared<_Mu>(v);
}

Mu operator>>(Mu uni, std::vector<float> & v){
    v = uni->m_data;
    return uni;
}

Mu operator-(Mu a, Mu b){
    a->m_peers.push_back(b);
    b->m_peers.push_back(a);
}
