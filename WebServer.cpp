#ifndef REQUEST_CPP
#include "request.cpp"
#endif

/**
 * @class webserver
 * @brief Manages web server requests and tracks their processing status.
 */
class webserver
{
public:
    /**
     * @brief Default constructor for the webserver class.
     *
     * Initializes the request start time to 0 and sets the server ID to a space character.
     */
    webserver()
    {
        requestStartTime = 0;
        serverID = ' ';
    }

    /**
     * @brief Parameterized constructor for the webserver class.
     * 
     * @param c The character to set as the server ID.
     *
     * Initializes the request start time to 0 and assigns the provided character to the server ID.
     */
    webserver(char c)
    {
        requestStartTime = 0;
        serverID = c;
    }

    /**
     * @brief Adds a request to the webserver.
     *
     * @param r The request object to be processed.
     * @param currentTime The current time at which the request is received.
     *
     * Sets the request to be processed and records the time at which the request is added.
     */
    void addReq(request r, int currentTime)
    {
        req = r;
        requestStartTime = currentTime;
    }

    /**
     * @brief Retrieves the server ID.
     *
     * @return The character representing the server ID.
     */
    char getID()
    {
        return serverID;
    }

    /**
     * @brief Retrieves the current request being processed.
     *
     * @return The request object currently being processed.
     */
    request getRequest()
    {
        return req;
    }

    /**
     * @brief Checks if the current request is completed.
     *
     * @param currTime The current time to check against the request's completion status.
     * @return true if the request processing is complete, false otherwise.
     *
     * Determines if the request is finished by comparing the current time with the sum of the request start time and the request's processing time.
     */
    bool isReqDone(int currTime)
    {
        return (currTime >= (requestStartTime + req.process_time));
    }

    

private:
    request req;             /**< The current request being processed. */
    int requestStartTime;    /**< The start time of the current request. */
    char serverID;           /**< The identifier for the server. */
};
