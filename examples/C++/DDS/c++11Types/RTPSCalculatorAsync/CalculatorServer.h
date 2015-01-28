/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorServer.h
 * This header file contains the declaration of the server for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _CalculatorSERVER_H_
#define _CalculatorSERVER_H_

#include <rpcdds/server/Server.h>
#include "CalculatorServerImpl.h"

namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
            class CalculatorProtocol;
        }
    }
}

/*!
 * @brief This class implements a specific server for the defined interface Calculator by user.
 * @ingroup CALCULATOR
 */
class FASTRPCUSERDllExport CalculatorServer : public eprosima::rpc::server::Server
{
    public:

        /*!
         * @brief This constructor sets the transport that will be used by the server.
         *
         * @param strategy Strategy used by server to work with new requests.
         *        This class doesn't delete this object in its destructor. Cannot be NULL.
         * @param transport The network transport that the server has to use.
         *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
         * @param protocol Generated protocol that the server has to use.
         *        This class has the information to process requests and build responses for this application environment. 
         * @param servant Servant that the server will use to invoke user's functions.
         * @exception eProsima::RPCDDS::InitializeException This exception is thrown when the initialization was wrong.
         */
        CalculatorServer(eprosima::rpc::strategy::ServerStrategy &strategy, eprosima::rpc::transport::ServerTransport &transport,
            eprosima::rpc::protocol::CalculatorProtocol &protocol, CalculatorServerImpl &servant);

        //! @brief Destructor.
        virtual ~CalculatorServer();



        
     private:
        
        //! \brief Pointer to the server's servant implemented by the user.
        CalculatorServerImpl &_impl;
};


#endif // _CalculatorSERVER_H_