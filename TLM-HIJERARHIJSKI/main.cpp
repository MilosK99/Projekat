#include <systemc>

#include "vp.hpp"

int sc_main(int argc, char* argv[])
{

    vp vp("Virtuelna platforma");
    //soft soft("hard dio");
    //dma dma ("dma dio");

    sc_start(200, sc_core::SC_NS);

    return 0;

}