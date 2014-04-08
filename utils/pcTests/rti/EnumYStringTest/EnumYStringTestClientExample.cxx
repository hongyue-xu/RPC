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

    char*  s1  = DDS::String_dup("PRUEBA");       
    char*  s2  = DDS::String_dup("PRUEBA2");       
    char*  s3  = NULL;    
    char*  getStringRetValue = NULL;       

    try
    {
        getStringRetValue = proxy->getString(s1, s2, s3);

        if(strcmp(s3, "PRUEBA2") != 0 ||
                strcmp(getStringRetValue, "PRUEBA") != 0 ||
                strcmp(s2, "PRUEBAPRUEBA2") != 0 ||
                strcmp(s1, "PRUEBA") != 0)
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

    if(s1 != NULL) DDS::String_free(s1);    
    if(s2 != NULL) DDS::String_free(s2);    
    if(s3 != NULL) DDS::String_free(s3);    
    if(getStringRetValue != NULL) DDS::String_free(getStringRetValue);    

    char*  sb1  = DDS::String_dup("PRUEBA");       
    char*  sb2  = DDS::String_dup("PRUEBA2");       
    char*  sb3  = NULL;    
    char*  getStringBoundedRetValue = NULL;       

    try
    {
        getStringBoundedRetValue = proxy->getStringBounded(sb1, sb2, sb3);

        if(strcmp(sb3, "PRUEBA2") != 0 ||
                strcmp(getStringBoundedRetValue, "PRUEBA") != 0 ||
                strcmp(sb2, "PRUEBAPRUEBA2") != 0 ||
                strcmp(sb1, "PRUEBA") != 0)
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

    if(sb1 != NULL) DDS::String_free(sb1);    
    if(sb2 != NULL) DDS::String_free(sb2);    
    if(sb3 != NULL) DDS::String_free(sb3);    
    if(getStringBoundedRetValue != NULL) DDS::String_free(getStringBoundedRetValue);

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete(proxy);
    delete(transport);
    delete(protocol);

    _exit(0);
    return 0;
}
