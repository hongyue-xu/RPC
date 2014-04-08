/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file StructTestClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool fastrpcgen.
 */

#include "StructTestProxy.h"
#include "StructTest.h"
#include "StructTestDDSProtocol.h"
#include "fastrpc/transports/dds/UDPProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::fastrpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    StructTestProtocol *protocol = NULL;
    UDPProxyTransport *transport = NULL;
    StructTestProxy *proxy = NULL;
    
    // Creation of the proxy for interface "StructTest".
    try
    {
        protocol = new StructTestProtocol();
        transport = new UDPProxyTransport("StructTestService");
        proxy = new StructTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    Envio ev;
    Recepcion duplicate_ret;

	Envio_initialize(&ev);    
    Recepcion_initialize(&duplicate_ret);    
        
    ev.dato = 10;
    ev.message = DDS_String_dup("HOLA");

    try
    {
        duplicate_ret = proxy->duplicate(ev);

        if(duplicate_ret.devolucion != 10 ||
                strcmp(duplicate_ret.message, "HOLA") != 0 ||
                ev.dato != 10 ||
                strcmp(ev.message, "HOLA") != 0)
        {
            std::cout << "TEST FAILED<duplicate>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<duplicate>: " << ex.what() << std::endl;
        _exit(-1);
    }

    Envio_finalize(&ev);    
    Recepcion_finalize(&duplicate_ret);    

	Envio ev1;    
	Envio ev2;       
	Recepcion suma_ret;

	Envio_initialize(&ev1);    
	Envio_initialize(&ev2);    
	Recepcion_initialize(&suma_ret);  

	ev1.dato = 10;
	ev1.message = DDS_String_dup("HOLA");
	ev2.dato = 20;
	ev2.message = DDS_String_dup("ADIOS");

    try
    {
        suma_ret = proxy->suma(ev1, ev2);

        if(suma_ret.devolucion != 30 ||
                strcmp(suma_ret.message, "HOLAADIOS") != 0 ||
                ev1.dato != 10 ||
                strcmp(ev1.message, "HOLA") != 0 ||
                ev2.dato != 20 ||
                strcmp(ev2.message, "ADIOS") != 0)
        {
            std::cout << "TEST FAILED<suma>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<suma>: " << ex.what() << std::endl;
        _exit(-1);
    }

	Envio_finalize(&ev1);    
	Envio_finalize(&ev2);    
	Recepcion_finalize(&suma_ret);    

    StructTest::InnerStruct inn;
    StructTest::InnerStruct inn_res;

    StructTest::InnerStruct_initialize(&inn);
    StructTest::InnerStruct_initialize(&inn_res);

    inn.count = 43;
    inn.message = DDS_String_dup("PAPITO");

    try
    {
        inn_res = proxy->inner(inn);

        if(inn.count != 43 ||
                strcmp(inn_res.message, "PAPITO") != 0)
        {
            std::cout << "TEST FAILED<inner>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<inner>: " << ex.what() << std::endl;
        _exit(-1);
    }

    StructTest::InnerStruct_finalize(&inn);
    StructTest::InnerStruct_finalize(&inn_res);

    std::cout << "TEST SUCCESFULLY" << std::endl;

	delete(proxy);
    delete(transport);
    delete(protocol);

	_exit(0);
	return 0;
}
