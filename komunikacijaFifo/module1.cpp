#include "module1.hpp"

using namespace sc_core;
using namespace std;

module1::module1(sc_module_name n) : sc_module(n)
{

    cout << name() << "constructed.\n";
    SC_THREAD(process);

}

void module1::process()
{
    
    wait(1, SC_NS);


    if(pfifo -> num_available())
    {
        
        vector<int> v;

        //while(1)
        //{
        //    if(pfifo -> num_available())
        //    {
        //        vector <int> v = pfifo -> read();
        //        cout << v << ' ';
        //    }
        //        wait(1, SC_NS);

        //}
        for(int i = 0; i <= pfifo -> num_available(); i++)
        //for(int i = 0; i < 5; ++i)
        {
            v.push_back(i);
            
            pfifo -> read(v[i]);
            //v.push_back(pfifo -> read());
            cout << v[i] << ' ';
        }
    }
}