#ifndef _SOFT_HPP_
#define _SOFT_HPP_

#include "soft.hpp"
#include <systemc>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/simple_target_socket.h>
#include <vector>
#include <tlm>
#include <iostream>
#include <string>

using namespace sc_core;
using namespace sc_dt;
using namespace tlm;
using namespace std;

typedef tlm::tlm_base_protocol_types::tlm_payload_type pl_t;
typedef tlm::tlm_base_protocol_types::tlm_phase_type ph_t;

class soft : public sc_core::sc_module
{
    public:
        soft(sc_core::sc_module_name name);
        
        tlm_utils::simple_initiator_socket <soft> soft_dma_socket;

    protected:
        pl_t pl;
        sc_core::sc_time offset;

        void komunikacija();
};
#endif
