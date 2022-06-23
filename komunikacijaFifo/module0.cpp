#include "module0.hpp"

namespace comm
{
    using namespace sc_core;
    using namespace std;

    module0::module0(sc_module_name n) : sc_module(n)
    {
        cout << name() << "constructed.\n";
        SC_METHOD(process);
    }

    void module0::process()
    {
        int v = 5;
        pfifo -> write(v);

        //cout << pfifo -> num_available();
        
        //vector<int> v {7, 5, 1, 3, 12};

        //for(int i = 0; i <= v.size(); i++)
        //for(i = v.begin(); i != v.end(); ++i)
        //{
        //    pfifo -> write(v[i]);
        //}
    }
}