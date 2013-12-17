/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldRESTProtocol.cxx
 * This source file contains the definition of the protocol used to create REST messages.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "HelloWorldRESTProtocol.h"
#include "exceptions/Exceptions.h"
#include "transports/ProxyTransport.h"
#include "transports/ServerTransport.h"
#include "protocols/rest/RESTSerializer.h"

using namespace eprosima::rpcdds;
using namespace ::protocol::rest;
using namespace ::transport;
using namespace eprosima::rpcdds::exception;

#include <sstream>

using namespace std;

HelloWorldProtocol::HelloWorldProtocol() {}

HelloWorldProtocol::~HelloWorldProtocol() {}

bool HelloWorldProtocol::setTransport(Transport &transport)
{    
    if(strcmp(transport.getType(), "HTTP") != 0)
    {
        throw IncompatibleException("protocol and transport are incompatibles");
    }
    
    if(transport.getBehaviour() == SERVER_BEHAVIOUR)
    {
        // If this is a server transport, we set its callback
        eprosima::rpcdds::transport::ServerTransport &serverTransport = dynamic_cast<eprosima::rpcdds::transport::ServerTransport&>(transport);
        serverTransport.setCallback(&HelloWorldProtocol::worker);
    }
        
    _setTransport(transport);
        
    return true;
}

bool HelloWorldProtocol::activateInterface(const char* interfaceName)
{
    return true;
}

int HelloWorldProtocol::deserializeContentLength(char* buffer) {
	char contentLength[16];
	strcpy(contentLength, "Content-Length:");
	char *p = strtok(buffer, "\r\n");
	while(p) {
		p[strlen(p)] = '\r'; // strtok puts a '\0', we don't want it
		if(memcmp(p, contentLength, 15) == 0) {
			return atoi(p+15); // 15 = "Content-Length:"
		}
		p = strtok(NULL, "\r\n");
	}

	return 0;
}

void HelloWorldProtocol::worker(Protocol& protocol, void *data, size_t dataLength, eprosima::rpcdds::transport::Endpoint *endpoint)
{
    // TODO : Call the protocol
    eprosima::rpcdds::protocol::rest::HelloWorldProtocol &restProtocol = dynamic_cast<eprosima::rpcdds::protocol::rest::HelloWorldProtocol&>( protocol );
    HttpMessage *httpMessage = reinterpret_cast<HttpMessage*>(data);

    HttpMessage response = restProtocol.processRequest(*httpMessage);
    
    dynamic_cast<ServerTransport&>(restProtocol.getTransport()).sendReply(&response, 0, endpoint);
}



HelloResponse HelloWorldProtocol::HelloWorldResource_hello(/*in*/ const char* name)
{
     stringstream stream;
     RESTSerializer restSerializer;
     eprosima::rpcdds::transport::ProxyTransport &proxyTransport = dynamic_cast<eprosima::rpcdds::transport::ProxyTransport&>( getTransport() );
     HelloResponse hello_ret;
     HelloResponse_initialize(&hello_ret);
     // XXX TODO if NULL -> error
     
     // Resource Base URI = /resources/
     // Path = HelloWorld
     // Method = GET
     // Body Parameter = 

     HttpMessage httpMessage;
     
     httpMessage.setMethod(HttpMessage::HTTP_METHOD_GET);
     //TODO Chequear host en el transport.
     httpMessage.setHost("example.com");
     std::string uri("/resources/HelloWorld"); 
     
        std::string paramValue;
        stream << name;
        paramValue = stream.str();
        stream.str(std::string());
        stream.clear();
        restSerializer.serializeQueryParameter(uri, "name", paramValue);       

     
     httpMessage.setUri(uri);
     



     
     // HTTP connection
     // TODO Check connection error.
     proxyTransport.connect();
     proxyTransport.send(&httpMessage, 0);
     HttpMessage httpResponse;
     size_t dump;
     proxyTransport.receive(&httpResponse, 0, dump);
     
     int discriminator = 0;

     if(httpResponse.getBodyContentType().find("xml") != string::npos)
     {
        discriminator = 1;
     } 
     else if(httpResponse.getBodyContentType().find("json") != string::npos)
     {
        discriminator = 2;
     }
    
     hello_ret._d = discriminator;
     
     switch(discriminator)
     {
     case 1:
          hello_ret._u.xmlHelloResponse.status = httpResponse.getResponseCode();
          hello_ret._u.xmlHelloResponse.xmlRepresentation = strdup(httpResponse.getBodyData().c_str());
          break;
          
     }
              
     return hello_ret;
}

HttpMessage HelloWorldProtocol::deserialize_HelloWorldResource_hello(RESTSerializer &restSerializer, HttpMessage &httpMessage)
{
    std::stringstream stream;
    

    // Deserialize name
    std::string name = restSerializer.getQueryParameter("name");

    


    
    // TODO Check implementation.
    HelloResponse HelloResponse = _HelloWorldResource_impl->hello(  name.c_str()  );
    
    HttpMessage httpResponse;
    switch(HelloResponse._d)
    {
    case 1:
        httpResponse.setResponseCode(HelloResponse._u.xmlHelloResponse.status);
    httpResponse.setBodyData(HelloResponse._u.xmlHelloResponse.xmlRepresentation); 
        break;

    }

    if(httpResponse.getBodyData().size() > 0)
    {
        if(HelloResponse._d == 1)
            httpResponse.setBodyContentType("application/xml");
        else if(HelloResponse._d == 2)
            httpResponse.setBodyContentType("application/json");
    }

    
    return httpResponse;
}

// Server
HttpMessage HelloWorldProtocol::processRequest(HttpMessage &httpMessage)
{
    RESTSerializer restSerializer;
    
    restSerializer.deserializeUri(httpMessage.getUri(), "/resources/");
    
    // TODO Siempre se crea aunque no haya un error. Cambiar
    HttpMessage http404Response;
    http404Response.setResponseCode(404);
    http404Response.setResponseStatus("Resource not found");
    
    // BEGIN ITERATION 
    string tag;
    char *p = NULL;
    if(!restSerializer.existsTagLevel(0)) {
    return http404Response; // ERROR NO OPERATIONS
    }
    if(restSerializer.getTag(0).compare("HelloWorld") == 0) {
    // BEGIN ITERATION HelloWorld
    if(!restSerializer.existsTagLevel(1)) {
    if(httpMessage.getMethod() == HttpMessage::HTTP_METHOD_GET) {
    if(restSerializer.existsQueryParameter("name")) {
    return deserialize_HelloWorldResource_hello(restSerializer, httpMessage); // MATCHING
    }
    }
    }
    // END ITERATION HelloWorld
    }
    // ERROR NO MATCH FOUND
    // END ITERATION 

    
    return http404Response;
}