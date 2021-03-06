/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * fastrpc_LICENSE file included in this fastrpc distribution.
 *
 *************************************************************************
 * 
 * @file InheritanceServerExample.cxx
 * This source file shows a simple example of how to create a server for an interface.
 *
 * This file was generated by the tool fastrpcgen.
 */

#include "InheritanceServer.h"
#include <strategies/ThreadPoolStrategy.h>
#include "InheritanceDDSProtocol.h"
#include <transports/dds/UDPServerTransport.h>
#include <exceptions/Exceptions.h>
#include <utils/Utilities.h>
#include "InheritanceServerImplExample.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::strategy;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    unsigned int threadPoolSize = 5;
    ThreadPoolStrategy *pool = NULL;
    InheritanceProtocol *protocol = NULL;
    UDPServerTransport *transport = NULL;
    ModuleA::Interface1Server *server1 = NULL;
    ModuleA::Interface2Server *server2 = NULL;
    ModuleB::Interface3Server *server3 = NULL;
    Interface1ServerImplExample servant1;
    Interface2ServerImplExample servant2;
    Interface3ServerImplExample servant3;
    
    // Create and initialize the server for interface "ModuleB::Interface3".
    try
    {
        pool = new ThreadPoolStrategy(threadPoolSize);
        protocol = new InheritanceProtocol();
        transport = new UDPServerTransport("InheritanceService", "Instance");
        server1 = new ModuleA::Interface1Server(*pool, *transport, *protocol, servant1);
        server2 = new ModuleA::Interface2Server(*pool, *transport, *protocol, servant2);
        server3 = new ModuleB::Interface3Server(*pool, *transport, *protocol, servant3);
        server1->serve();
        server2->serve();
        server3->serve();
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    while(1)
    {
        eprosima::rpc::sleep(10000);
    }
    
    // Stop and delete the server.
    server1->stop();
    server2->stop();
    server3->stop();
    delete server1;
    delete server2;
    delete server3;
    delete protocol;
    delete transport;
    delete pool;
    
    return 0;
}







