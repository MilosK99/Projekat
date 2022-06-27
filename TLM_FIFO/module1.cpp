#include "module1.hpp"
#include <vector>

using namespace sc_core;
using namespace std;
using std::vector;

vector<int> v; 

module1::module1(sc_module_name n) : sc_module(n)
{

    cout << name() << "constructed.\n";
    SC_THREAD(citanje);
    SC_THREAD(upisivanje);

}

void module1::citanje()
{
    
    wait(1, SC_NS);

    int n = pfifo -> num_available();

    for(int i = 0; i <= n; i++)
    {

        v.push_back(pfifo -> read());
        //v.push_back(i);
        //pfifo -> read(v[i]);
    
        cout << v[i] << ' ';

    }
}

void module1::upisivanje()
{
    for(int j = 0; j < v.size(); j++)
    {
        v[j] = v[j] * 2;
        nfifo -> write(v[j]);
    }
}