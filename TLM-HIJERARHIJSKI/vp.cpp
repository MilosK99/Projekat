#include "vp.hpp"
#include "hard.hpp"
#include "dma.hpp"

using namespace std;
using namespace sc_core;

vp::vp(sc_module_name name) : 
    sc_module(name),
    hard1(NULL),
    komunikacija(NULL)
{
    hard1 = new hard("m_hard");
    komunikacija = new dma("m_dma");

    komunikacija -> wr_port(*hard1);
    komunikacija -> rd_port(*hard1);
}