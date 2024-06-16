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
        webserver(char c)
        {
            requestStartTime = 0;
            serverID = c;
        }
        void addReq(request r, int currentTime)
        {
            req = r;
            requestStartTime = currentTime;
        }
        char getID()
        {
            return serverID;
        }
        request getRequest()
        {
            return req;
        } 
        bool isReqDone(int currTime)
        {
            return(currTime>= (requestStartTime + req.process_time)); 
        }

        
    private:
        request req;
        int requestStartTime;
        char serverID;
};