#ifndef _VP1_HPP_
#define _VP1_HPP_

#include "module.hpp"
#include "target.hpp"

class vp1 : public sc_core::sc_module
{
    public:
        vp1(sc_core::sc_module_name name);
        ~vp1();
    
    protected:
        module inicijator;
        target cilj;
};
#endif