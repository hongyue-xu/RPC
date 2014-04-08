/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file $ctx.filename$ClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool fastrpcgen.
 */

#include "EnumYStringTestProxy.h"
#include "EnumYStringTest.h"
#include "EnumYStringTestDDSProtocol.h"
#include "fastrpc/transports/dds/UDPProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::fastrpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    EnumYStringTestProtocol *protocol = NULL;
    UDPProxyTransport *transport = NULL;
    EnumYStringTestProxy *proxy;
        
    // Creation of the proxy for interface "EnumYStringTest".
    try
    {
        protocol = new EnumYStringTestProtocol();
        transport = new UDPProxyTransport("EnumYStringTestService");
        proxy = new EnumYStringTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    Valores  v1 = VALOR1;    
    Valores  v2 = VALOR2;    
    Valores  v3 = VALOR1;       
    Valores  getEnumRetValue = VALOR1;    

    try
    {
        getEnumRetValue = proxy->getEnum(v1, v2, v3);

        if(v3 != VALOR2 ||
                getEnumRetValue != VALOR1 ||
                v2 != VALOR1 ||
                v1 != VALOR1)
        {
            std::cout << "TEST FAILED<getEnum>: Wrong values" << std::endl;
            _exit(-1);
        }       
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getEnum>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::string s1 = "PRUEBA";       
    std::string s2 = "PRUEBA2";       
    std::string s3;    
    std::string getStringRetValue;       

    try
    {
        getStringRetValue = proxy->getString(s1, s2, s3);

        if(s3.compare("PRUEBA2") != 0 ||
                getStringRetValue.compare("PRUEBA") != 0 ||
                s2.compare("PRUEBAPRUEBA2") != 0 ||
                s1.compare("PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getString>: Wrong values" << std::endl;
            _exit(-1);
        }       
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getString>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::string sb1 = "PRUEBA";       
    std::string sb2 = "PRUEBA2";       
    std::string sb3;    
    std::string getStringBoundedRetValue;       

    try
    {
        getStringBoundedRetValue = proxy->getStringBounded(sb1, sb2, sb3);

        if(sb3.compare("PRUEBA2") != 0 ||
                getStringBoundedRetValue.compare("PRUEBA") != 0 ||
                sb2.compare("PRUEBAPRUEBA2") != 0 ||
                sb1.compare("PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getStringBounded>: Wrong values" << std::endl;
            _exit(-1);
        }    
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getStringBounded>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete(proxy);
    delete(transport);
    delete(protocol);

    _exit(0);
    return 0;
}
