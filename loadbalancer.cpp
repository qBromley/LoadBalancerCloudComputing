#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

void loadbalancer::incrementTime()
{
    systemTime++;
}
int loadbalancer::getTime()
{
    return systemTime;
}

void loadbalancer::addRequest(request r)
{
    requestQueue.push_back(r);
    
    incrementTime();
}

request loadbalancer::getRequest()
{
    incrementTime();
    if(!requestQueue.empty())
    {
        request r = requestQueue.at(0);
        requestQueue.pop_front();
        return r;

    }
}

bool loadbalancer::isRequestQueueEmpty()
{
    return requestQueue.empty();
}