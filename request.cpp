#include <string>
#define REQUEST_CPP
using namespace std;
/**
 * @struct request
 * @brief Represents a request with input and output IP addresses and processing time.
 */
struct request
{
    string ip_in;
    string ip_out;
    int process_time;
};