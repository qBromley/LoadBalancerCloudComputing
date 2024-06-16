#ifndef REQUEST_CPP

#include "request.cpp"
#endif
class webserver
{
    public:
        webserver()
        {
            requestStartTime = 0;
            serverID =' ';
        }
    private:
        request req;
        int requestStartTime;
        char serverID;
}