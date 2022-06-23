#include "module1.hpp"

namespace comm
{
    using namespace sc_core;
    using namespace std;

    module1::module1(sc_module_name n) : sc_module(n)
    {
        cout << name() << "constructed.\n";
    }

    void module1::process()
    {
    
    if(pfifo -> num_available())
    {
        int v = pfifo -> read();

        cout << v << endl;
    } 
    
    //    vector<int> v;
        

        //for(int i = 0; i <= pfifo.num_available(); i++)
        //{
        //    v.push_back(v[i]);
            
        //    pfifo -> read(v[i]);
            //v.push_back(pfifo -> read());
        //    cout << v[i] << endl;
        //}

        //for(int i = 0; i <= pfifo.num_available(); i++)
        //{
        //    pfifo -> read(v[i]);
        //
        //    cout << v[i] << endl;
        //}
    }
}