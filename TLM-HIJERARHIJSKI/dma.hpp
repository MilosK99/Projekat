#ifndef _DMA_HPP_
#define _DMA_HPP_

#include "dma.hpp"
#include "hard_1.hpp"
#include <vector>

using namespace std;
using namespace sc_core;

class dma : public sc_core::sc_module
{
    public:
        dma(sc_core::sc_module_name name);

        sc_port< hard_write_if > wr_port;
        sc_port< hard_read_if > rd_port;

    protected:
            void komunikacija();;
};
#endif