#include "request.cpp"
#include "WebServer.cpp"
#include "loadbalancer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>

request createRequest()
{
    stringstream ip_inc, ip_dest;
    request r; 
    ip_inc << (rand()%256) << "."<<(rand()%256)<<"."<<(rand()%256)<<"."<<(rand()%256);
    ip_dest << (rand()%256)<<"."<<(rand()%256)<<"."<<(rand()%256)<<"."<<(rand()%256);
    r.ip_in = ip_inc.str();
    r.ip_out = ip_dest.str();
    r.process_time = (rand()%100);
    return r;
}

int main() 
{
    srand(time(0)); // Initialize random seed
    loadbalancer lb;
    
    int numServers;
    int runTime;

    std::cout << "Enter the number of web servers: ";
    std::cin >> numServers;

    std::cout << "Enter the time to run the load balancer (in cycles): ";
    std::cin >> runTime;
    std::ofstream logFile("log.txt", std::ios::trunc);
    for(int i = 0; i < numServers * 100; i++)
    {
        request r = createRequest();
        lb.addRequest(r);
        logFile << "Adding Request Ip in:" << r.ip_in << " IP destination "<< r.ip_out <<" to Queue, time to process "<< r.process_time <<" Cycles"<<endl;
    }

    webserver webServerArr[numServers];
    for(int i = 0; i < numServers; i++)
    {
        webserver w((char)(i + 65));
        webServerArr[i] = w;
        webServerArr[i].addReq(lb.getRequest(), lb.getTime());
        logFile << "Starting Server: " << w.getID() << std::endl;
    }

    // Open log file
    

    while(lb.getTime() < runTime)
    {
        int currTime = lb.getTime();
        if(webServerArr[currTime % numServers].isReqDone(currTime))
        {
            request r = webServerArr[currTime % numServers].getRequest();
            logFile <<"Server "<<  webServerArr[currTime % numServers].getID() << "Processing request from " << r.ip_in << " to " << r.ip_out << " at Cycle" << currTime << std::endl;
            webServerArr[currTime % numServers].addReq(lb.getRequest(), currTime);
        }
        if(rand() % 14 == 0)
        {
            request r = createRequest();
            lb.addRequest(r);
            logFile << "Adding Request Ip in:" << r.ip_in << " IP destination "<< r.ip_out <<" to Queue, time to process "<< r.process_time <<" Cycles"<<endl;
        }
        lb.incrementTime();
    }

    // Close log file
    logFile.close();

    return 0;
}
