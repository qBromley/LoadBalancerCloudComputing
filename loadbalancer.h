#define LOADBALANCER_H
#ifndef REQUEST_CPP
#include "request.cpp"
#endif
#include <deque>
using namespace std;

/**
 * @class loadbalancer
 * @brief Manages the distribution and processing of requests in a web server environment.
 */
class loadbalancer
{
public:
    /**
     * @brief Default constructor for the loadbalancer class.
     *
     * Initializes the system time to 0.
     */
    loadbalancer()
    {
        systemTime = 0;
    }

    /**
     * @brief Retrieves the current system time.
     * 
     * @return The current system time.
     */
    int getTime();

    /**
     * @brief Increments the system time by one unit.
     */
    void incrementTime();

    /**
     * @brief Adds a request to the load balancer's request queue and increments the system time.
     * 
     * @param r The request to be added to the queue.
     */
    void addRequest(request r);

    /**
     * @brief Retrieves and removes the next request from the load balancer's request queue, if available.
     * 
     * @return The next request in the queue.
     * 
     * @note If the request queue is empty, the behavior is undefined.
     */
    request getRequest();

    /**
     * @brief Checks if the request queue is empty.
     * 
     * @return true if the request queue is empty, false otherwise.
     */
    bool isRequestQueueEmpty();

    int queueSize();
    

private:
    int systemTime;                 /**< The current system time. */
    deque<request> requestQueue;    /**< The queue of requests to be processed. */
};

#include "loadbalancer.cpp"


