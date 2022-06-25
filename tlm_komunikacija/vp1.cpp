#include "vp1.hpp"

vp1::vp1(sc_core::sc_module_name name) : sc_module(name),
    inicijator("Module"),
    cilj("Target")

{
    inicijator.module_target_socket.bind(cilj.target_module_socket);
    SC_REPORT_INFO("Virtual Platform", "Constructed.");
}

vp1::~vp1()
{
    SC_REPORT_INFO("Virtual Platform", "Destructed.");
}