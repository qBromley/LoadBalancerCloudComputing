#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

/**
 * @brief Increments the system time by one unit.
 */
void loadbalancer::incrementTime()
{
    systemTime++;
}

/**
 * @brief Retrieves the current system time.
 * 
 * @return The current system time.
 */
int loadbalancer::getTime()
{
    return systemTime;
}

/**
 * @brief Adds a request to the load balancer's request queue and increments the system time.
 * 
 * @param r The request to be added to the queue.
 */
void loadbalancer::addRequest(request r)
{
    requestQueue.push_back(r);
    incrementTime();
}

/**
 * @brief Retrieves and removes the next request from the load balancer's request queue, if available.
 * 
 * @return The next request in the queue.
 * 
 */
request loadbalancer::getRequest()
{
    incrementTime();
    request r = requestQueue.at(0);
    requestQueue.pop_front();
    return r;

    
}

/**
 * @brief Checks if the request queue is empty.
 * 
 * @return true if the request queue is empty, false otherwise.
 */
bool loadbalancer::isRequestQueueEmpty()
{
    return requestQueue.empty();
}

int loadbalancer::queueSize()
{
    return requestQueue.size(); 
}
