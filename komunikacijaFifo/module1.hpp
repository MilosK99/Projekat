#ifndef _MODULE1_HPP_
#define _MODULE1_HPP_

#include <systemc>
#include <vector>

namespace comm
{
    using namespace sc_core;

    SC_MODULE(module1)
    {
        public:
            SC_HAS_PROCESS(module1);

            module1(sc_core::sc_module_name);

            sc_fifo_in <int> pfifo;
            
        protected:
            void process();
    };
}
#endif