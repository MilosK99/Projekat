#include "module.hpp"
#include "target.hpp"
#include "vp1.hpp"

int sc_main(int argc, char* argv[])
{
    //target target("target");
    //module module("module");

    vp1 vp1("Virtual Platform");

    sc_start(200, SC_NS);

    return 0;
}