#ifndef _VP_HPP_
#define _VP_HPP_

#include "dma.hpp"
#include "hard.hpp"

class vp : public sc_core::sc_module
{
    public:
        vp(sc_core::sc_module_name name);
    
    protected:
        hard* hard1;
        dma* komunikacija;
};
#endif