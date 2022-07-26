#include <iostream>
#include <vector>
#include <xmlrpc-c/client_simple.hpp>

namespace math_api
{
    static void get_sum_and_difference()
    {
        std::string const server_url("http://127.0.0.1:40474/RPC2");

        xmlrpc_c::clientSimple client;
        xmlrpc_c::value result;
        client.call(server_url, "notify.log", "ss", &result, "TESTc++", "Open");

        // xmlrpc_c::value_struct value(result);
        // std::map<std::string, xmlrpc_c::value> map = (std::map<std::string, xmlrpc_c::value>)value;

        // xmlrpc_c::value_int sum(map["sum"]);
        // xmlrpc_c::value_int diff(map["difference"]);

        // std::cout << "Sum: " << sum << ", Difference: " << diff << std::endl;
    }
}

int main(int argc, char **argv)
{
    try
    {
        math_api::get_sum_and_difference();
    }
    catch (xmlrpc_c::fault &fault)
    {
        std::cerr << argv[0] << ": XML-RPC fault #" << fault.getCode() << ": " << fault.getDescription() << std::endl;
        // exit(1);
    }
    return 0;
}