#include "target.hpp"

target::target(sc_module_name name) : sc_module(name)
{
    target_module_socket.register_b_transport(this, &target::b_transport);

    SC_REPORT_INFO("target", "Constructed.");

}

target::~target()
{
    SC_REPORT_INFO("target", "Destcructed.");
}

void target::b_transport(pl_t& p1, sc_time& offset)
{
    tlm_command cmd     = p1.get_command();
    //uint64 addr         = p1.get_address();
    unsigned char *data = p1.get_data_ptr();
    unsigned int length = p1.get_data_length();


    switch(cmd)
    {
        case TLM_WRITE_COMMAND:
            control = *((int*)data);
            p1.set_response_status( TLM_OK_RESPONSE);
            cout << control;
        break;

        case TLM_READ_COMMAND: 
        break;

        default:
            p1.set_response_status(TLM_COMMAND_ERROR_RESPONSE);
            SC_REPORT_ERROR("TARGET", "TLM_wrong_address");
        break;
    }
}