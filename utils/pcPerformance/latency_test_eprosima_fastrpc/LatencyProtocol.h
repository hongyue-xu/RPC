/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * fastrpc_LICENSE file included in this fastrpc distribution.
 *
 *************************************************************************
 * 
 * @file LatencyProtocol.h
 * This header file contains the declaration of the interface for all protocols.
 *
 * This file was generated by the tool fastrpcgen.
 */

#ifndef _Latency_PROTOCOL_H_
#define _Latency_PROTOCOL_H_

#include "fastrpc/protocols/Protocol.h"
#include "Latency.h"
#include "LatencyServerImpl.h"

namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
            /*!
             * @brief Protocol base class for the specific application
             * @ingroup LATENCY
             */
            class FASTRPCUSERDllExport LatencyProtocol : public Protocol
            {
                public:
                
                   /*!
                    * @brief This method sets the transport for the communications. It has to be implemented by the children classes.
                    * @param transport Transport to use.
                    * @return True if the assignment is successful, false otherwise
                    */
                    virtual bool setTransport(eprosima::rpc::transport::Transport &transport) = 0;
                    
                        /*!
                         * @brief In some protocols this function activates needed entities to use an interface.
                         * @param interfaceName Interface name.
                         * @return Whether the activation works successfully.
                         */
                    virtual bool activateInterface(const char* interfaceName) = 0;
                    
                                       /*!
                                        * @brief This method links a specific servant with the protocol.
                                        * @param impl Servant implementation.
                                        */
                                        void linkLatencyImpl(LatencyServerImpl &impl)
                                        {
                                            _Latency_impl = &impl;
                                        }
                                        
                             


                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation latency.
                     *        It has to be implemented by the child classes.
                     */
                    virtual st Latency_latency(/*in*/ const st& param) = 0;


                    
                protected:
                
                    LatencyProtocol() : Protocol()
                                         
                                        , _Latency_impl(NULL)
                                        
                    {}
                    
                    virtual ~LatencyProtocol(){}
                
                	                     
                	                    LatencyServerImpl *_Latency_impl;
                	                    
                    
            };
        } // namespace protocol
    } // namespace rpc
} // namespace eprosima

#endif // _Latency_PROTOCOL_H_