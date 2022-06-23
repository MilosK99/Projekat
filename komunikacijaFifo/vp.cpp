#include "vp.hpp"

namespace comm
{
    using namespace sc_core;
    using namespace std;

    vp::vp(sc_module_name n, int size) : 
        sc_module(n), f0(size),
        f0("f0"),
        m0("m0"),
        m1("m1")
    {

        cout << name() << " constructed.\n";
        m0.pfifo.bind(f0);
        m1.pfifo(f0);

        cout << f0.num_available();
        
    }
}
