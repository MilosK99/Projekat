#include "vp.hpp"

namespace comm
{
    using namespace sc_core;
    using namespace std;

    vp::vp(sc_module_name n) : 
        sc_module(n),
        f0("f0"),
        m0("m0"),
        m1("m1")
    {

        cout << name() << " constructed.\n";
        m0.pfifo.bind(f0);
        m1.pfifo(f0);
        
    }
}
