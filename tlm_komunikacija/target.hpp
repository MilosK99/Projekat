#ifndef _TARGET_HPP_
#define _TARGET_HPP_

#include "module.hpp"
#include <tlm>
#include <tlm_utils/simple_target_socket.h>

using namespace sc_core;

typedef tlm::tlm_base_protocol_types::tlm_payload_type pl_t;
typedef tlm::tlm_base_protocol_types::tlm_phase_type ph_t;

class target : public sc_core::sc_module
{
    public:
        target(sc_core::sc_module_name name);
        ~target();

        tlm_utils::simple_target_socket <target> target_module_socket;

    protected:
            void b_transport(pl_t&, sc_core::sc_time&);
            int control;
};
#endif