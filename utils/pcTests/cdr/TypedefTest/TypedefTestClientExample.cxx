/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file BasicTypeTestClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "TypedefTestProxy.h"
#include "TypedefTest.h"
#include "TypedefTestCDRProtocol.h"
#include "rpcdds/transports/TCPProxyTransport.h"
#include "rpcdds/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::rpcdds;
using namespace ::exception;
using namespace ::transport;
using namespace ::protocol::cdr;

int main(int argc, char **argv)
{
    TypedefTestProtocol *protocol = NULL;
    TCPProxyTransport *transport = NULL;
    TypedefTestProxy *proxy = NULL;
    
    try
    {
        protocol = new TypedefTestProtocol();
        transport = new TCPProxyTransport("127.0.0.1:8080");
        proxy = new TypedefTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    largo  l1 = 1;    
    largo  l2 = 0;       
    largo  getLargo_ret = 0;    

    try
    {
        getLargo_ret = proxy->getLargo(l1, l2);

        if(l2 != 1 ||
                getLargo_ret != 1 ||
                l1 != 1)
        {
            std::cout << "TEST FAILED<getLargo>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getLargo>: " << ex.what() << std::endl;
        _exit(-1);
    }

    larguisimo  ll1 = 1;       
    larguisimo  ll2 = 0;    
    larguisimo  getLarguisimo_ret = 0;       

    try
    {
        getLarguisimo_ret = proxy->getLarguisimo(ll1, ll2);

        if(ll2 != 1 ||
                getLarguisimo_ret != 1 ||
                ll1 != 1)
        {
            std::cout << "TEST FAILED<getLarguisimo>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getLarguisimo>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DatosDef d1;      
    DatosDef d2;    
    DatosDef getDatosDef_ret;       

    d1.count(1);
    d1.message("PRUEBA");

    try
    {
        getDatosDef_ret = proxy->getDatosDef(d1, d2);

        if(d2.count() != 1 || d2.message().compare("PRUEBA") != 0 ||
                getDatosDef_ret.count() != 1 || getDatosDef_ret.message().compare("PRUEBA") != 0 ||
                d1.count() != 1 || d1.message().compare("PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getDatosDef>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getDatosDef>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DatosDef2 d21;      
    DatosDef2 d22;    
    DatosDef2 getDatosDef2_ret;       

    d21.count(2);
    d21.message("PRUEBA2");

    try
    {
        getDatosDef2_ret = proxy->getDatosDef2(d21, d22);

        if(d22.count() != 2 || d22.message().compare("PRUEBA2") != 0 ||
                getDatosDef2_ret.count() != 2 || getDatosDef2_ret.message().compare("PRUEBA2") != 0 ||
                d21.count() != 2 || d21.message().compare("PRUEBA2") != 0)
        {
            std::cout << "TEST FAILED<getDatosDef>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getDatosDef>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DatosDefondo dd1;       
    DatosDefondo dd2;    
    DatosDefondo getDatosDefondo_ret;       

    dd1.count(1);
    dd1.message("PRUEBA");

    try
    {
        getDatosDefondo_ret = proxy->getDatosDefondo(dd1, dd2);

        if(dd2.count() != 1 || dd2.message().compare("PRUEBA") != 0 ||
                getDatosDefondo_ret.count() != 1 || getDatosDefondo_ret.message().compare("PRUEBA") != 0 ||
                dd1.count() != 1 || dd1.message().compare("PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getDatosDef>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getDatosDef>: " << ex.what() << std::endl;
        _exit(-1);
    }

    cadena c1  = "PRUEBA";       
    cadena c2;    
    cadena getCadena_ret;       

    try
    {
        getCadena_ret = proxy->getCadena(c1, c2);

        if(c2.compare("PRUEBA") != 0 ||
                getCadena_ret.compare("PRUEBA") != 0 ||
                c1.compare("PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getCadena>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getCadena>: " << ex.what() << std::endl;
        _exit(-1);
    }

    correa cc1 = "PRUEBA";       
    correa cc2;    
    correa getCorrea_ret;       

    try
    {
        getCorrea_ret = proxy->getCorrea(cc1, cc2);

        if(cc2.compare("PRUEBA") != 0 ||
                getCorrea_ret.compare("PRUEBA") != 0 ||
                cc1.compare("PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getCadena>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getCadena>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete proxy;
    delete transport;
    delete protocol;

    _exit(0);
    return 0;
}
