/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this FASTRPC distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorServer.cxx
 * This source file contains the definition of the server for all interfaces.
 *
 * This file was generated by the tool fastrpcgen.
 */

#include "CalculatorServer.h"
#include "fastrpc/strategies/ServerStrategy.h"
#include "fastrpc/transports/ServerTransport.h"
#include "CalculatorProtocol.h"
#include "fastrpc/exceptions/ServerInternalException.h"


#include "CalculatorExceptions.h"

CalculatorServer::CalculatorServer(eprosima::fastrpc::strategy::ServerStrategy &strategy, eprosima::fastrpc::transport::ServerTransport &transport,
            eprosima::fastrpc::protocol::CalculatorProtocol &protocol, CalculatorServerImpl &servant) :
    Server(strategy, transport, protocol), _impl(servant)
{
   protocol.activateInterface("Calculator");
   protocol.linkCalculatorImpl(servant);
}

CalculatorServer::~CalculatorServer()
{
    //TODO Unlink an deactivate.
}



