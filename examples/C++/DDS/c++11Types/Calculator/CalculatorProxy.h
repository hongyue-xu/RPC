/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this FASTRPC distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorProxy.h
 * This header file contains the declaration of the proxy for all interfaces.
 *
 * This file was generated by the tool fastrpcgen.
 */

#ifndef _Calculator_PROXY_H_
#define _Calculator_PROXY_H_

#include "fastrpc/client/Proxy.h"
#include "Calculator.h"
#include "CalculatorAsyncCallbackHandlers.h"
namespace eprosima
{
    namespace fastrpc
    {
        namespace protocol
        {
            class CalculatorProtocol;
        }
    }
}

/*!
 * @brief This class implements a specific server's proxy for the defined interface Calculator.
 * @ingroup CALCULATOR
 */
class FASTRPCUSERDllExport CalculatorProxy : public eprosima::fastrpc::proxy::Proxy
{
    public:
   
        /*!
         * @brief This constructor sets the transport that will be used by the server's proxy.
         *
         * @param transport The network transport that server's proxy has to use.
         *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
         * @param protocol The protocol used to send the information over the transport.
         *        This protocol's object is not deleted by this class in its destructor. Cannot be NULL.
         * @exception eprosima::fastrpc::exception::InitializeException This exception is thrown when the initialization was wrong.
         */
        CalculatorProxy(eprosima::fastrpc::transport::ProxyTransport &transport,
            eprosima::fastrpc::protocol::CalculatorProtocol &protocol);

        //! @brief The default destructor.
        virtual ~CalculatorProxy();
        
        //! @brief Proxy method for the operation addition
        int32_t addition(/*in*/ int32_t value1, /*in*/ int32_t value2);

        //! @brief Proxy asynchronous method for the operation addition
        void addition_async(Calculator_additionCallbackHandler &obj, /*in*/ int32_t value1, /*in*/ int32_t value2);

        //! @brief Proxy method for the operation subtraction
        int32_t subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2);

        //! @brief Proxy asynchronous method for the operation subtraction
        void subtraction_async(Calculator_subtractionCallbackHandler &obj, /*in*/ int32_t value1, /*in*/ int32_t value2);

};


#endif // _Calculator_PROXY_H_