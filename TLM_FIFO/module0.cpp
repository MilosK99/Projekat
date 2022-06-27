#include "module0.hpp"
#include <vector>

using namespace std;
using namespace sc_core;
using std::vector;

vector<int> a;

module0::module0(sc_module_name name) : sc_module(name)
{
    module0_module_socket.register_b_transport(this, &module0::b_transport);

    SC_REPORT_INFO("module0", "Constructed.");
    SC_THREAD(process);
}

module0::~module0()
{
    SC_REPORT_INFO("module0", "Destcructed.");
}

void module0::b_transport(pl_t& p1, sc_time& offset)
{   
    tlm_command cmd     = p1.get_command();
    //uint64 addr         = p1.get_address();
    unsigned char *data = p1.get_data_ptr();
    unsigned int length = p1.get_data_length();


    switch(cmd)
    {
        case TLM_WRITE_COMMAND:

            control = *((int*)data);
            a.push_back(control);
            cout << control << ' '; 
            cout << endl;
            p1.set_response_status(TLM_OK_RESPONSE);
        break;

        case TLM_READ_COMMAND: 
        
        break;

        default:
            p1.set_response_status(TLM_COMMAND_ERROR_RESPONSE);
            SC_REPORT_ERROR("MODULE0", "TLM_wrong_address");
        break;
    }
}

void module0::process()
{
    for(int i = 0; i < a.size(); i++)
        pfifo -> write(a[i]);


}