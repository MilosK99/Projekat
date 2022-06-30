#include "soft.hpp"

SC_HAS_PROCESS(soft);

soft::soft(sc_module_name name) : sc_module(name), offset(sc_core::SC_ZERO_TIME)
{
    SC_THREAD(komunikacija);
}

void soft::komunikacija()
{
    vector<int> v {7, 5, 1, 3, 8};

    for(int i = 0; i < v.size(); i++)
    {
        //int v = 5;
        pl_t p1;
        p1.set_command(TLM_WRITE_COMMAND);
        //p1.set_address();
        p1.set_data_ptr((unsigned char*)&v[i]);
        p1.set_data_length(1);
        p1.set_response_status(TLM_INCOMPLETE_RESPONSE);

        soft_dma_socket -> b_transport(p1, offset);
    }
}

