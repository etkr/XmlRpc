#include <iostream>
#include <vector>
#include <xmlrpc-c/client_simple.hpp>

namespace math_api
{
    static void get_sum_and_difference(const int x, const int y)
    {
        std::string const server_url{"http://xmlrpc-c.sourceforge.net/api/sample.php"};

        xmlrpc_c::clientSimple client;
        xmlrpc_c::value result;
        client.call(server_url, "sample.sumAndDifference", "ii", &result, x, y);

        xmlrpc_c::value_struct value(result);
        std::map<std::string, xmlrpc_c::value> map = (std::map<std::string, xmlrpc_c::value>)value;

        xmlrpc_c::value_int sum(map["sum"]);
        xmlrpc_c::value_int diff(map["difference"]);

        std::cout << "Sum: " << sum << ", Difference: " << diff << std::endl;
    }
}

int main(int argc, char **argv)
{
    try
    {
        math_api::get_sum_and_difference(5, 7);
    }
    catch (xmlrpc_c::fault &fault)
    {
        std::cerr << argv[0] << ": XML-RPC fault #" << fault.getCode() << ": " << fault.getDescription() << std::endl;
        exit(1);
    }
    return 0;
}