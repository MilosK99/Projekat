#include <systemc>

#include "vp.hpp"
//#include "module0.hpp"


int sc_main(int argc, char* argv[])
{
    //comm::module0 module0("modul0");

    //test
    
    comm::vp vp("Virtual Platform", 1);
    
    sc_start(200, sc_core::SC_NS);

    return 0;
}