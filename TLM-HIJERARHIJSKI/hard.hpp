#ifndef _HARD_HPP_
#define _HARD_HPP_

#include <systemc>
#include <vector>
#include "hard_1.hpp"


class hard : 
    public sc_core::sc_channel,
    public hard_write_if,
    public hard_read_if
{
    public:
        SC_HAS_PROCESS(hard);
        hard(sc_core::sc_module_name);

        void write(const Data& data);
        void read(Data& data, int i);
        void calculate();

    protected:
         std::vector<sc_uint<8>> niz;
         std::vector<sc_uint<16>> obradjeni_niz;
};
#endif
