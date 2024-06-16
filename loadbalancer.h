#define LOADBALANCER_H
#ifndef REQUEST_CPP
#include "request.cpp"
#endif
#include <deque>



class loadbalancer
{
    public:
        loadbalancer()
        {
            systemTime =0;
        }
        int getTime();
        void incrementTime();
        void addRequest(request r);
        request getRequest();
        bool isRequestQueueEmpty();
   
    private:
        int systemTime;
        deque<request> requestQueue;

};
#include "loadbalancer.cpp"
