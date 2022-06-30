#include "hard.hpp"
#include "hard_1.hpp"
#include <vector>
#include <systemc>

using namespace std;
using namespace sc_core;

hard::hard(sc_module_name name) : sc_channel(name)
{
    SC_REPORT_INFO("hard", "Constructed.");
}

void hard::write(const Data& data)
{
    niz.push_back(data.byte);

    if(data.last)
    {
        calculate();
    }
}

void hard::read(Data& data, int i)
{
    data.byte = obradjeni_niz[i];
}

void hard::calculate()
{
    for(int i = 0; i < niz.size(); i++)
    {
        obradjeni_niz.push_back(niz[i] * 2);
    }
}
