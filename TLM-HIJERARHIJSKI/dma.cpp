#include "dma.hpp"
#include "hard_1.hpp"
#include <vector>
#include <algorithm>
#include <tlm>

using namespace std;
using namespace sc_core;
using std::vector;
using namespace sc_dt;

vector<sc_uint<8>> v {7, 5, 1, 3, 8};
vector<sc_uint<16>> n;
SC_HAS_PROCESS(dma);

dma::dma(sc_module_name name) : sc_module(name)
{
    SC_REPORT_INFO("dma", "Constructed.");
    SC_THREAD(komunikacija);
}

void dma::komunikacija()
{
    Data input;

    for(int i = 0; i < v.size(); i++)
    {
        input.last = false;
        if(i == (v.size() - 1))
        {
            input.last = true;
        }
        input.byte = v[i];
        wr_port -> write(input);
    }

    for(int i = 0; i < v.size(); i++)
    {
        rd_port -> read(input, i);
        n.push_back(input.byte);
        cout << n[i] << endl;
    }
}



