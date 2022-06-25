#include "module.hpp"
#include "target.hpp"

int sc_main(int argc, char* argv[])
{
    target target("target");
    module module("module");

    sc_start(200, SC_NS);

    return 0;
}