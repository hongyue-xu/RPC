/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "TypedefTestServer.h"
#include "transports/UDPTransport.h"
#include "transports/TCPTransport.h"
#include "exceptions/ServerInternalException.h"
#include "TypedefTestRequestReplyPlugin.h"

#include "TypedefTestServerRPCSupport.h"

TypedefTestServer::TypedefTestServer(std::string serviceName, eProsima::DDSRPC::ServerStrategy *strategy,
    int domainId) :
    Server(serviceName, strategy, NULL, domainId)
{
    _impl = new TypedefTestServerImpl();

    createRPCs();
}

TypedefTestServer::TypedefTestServer(std::string serviceName, eProsima::DDSRPC::ServerStrategy *strategy,
    eProsima::DDSRPC::Transport *transport, int domainId) :
    Server(serviceName, strategy, transport, domainId)
{
    _impl = new TypedefTestServerImpl();
    
    createRPCs();
}

TypedefTestServer::~TypedefTestServer()
{
    delete _impl;    
}

void TypedefTestServer::createRPCs()
{
    this->setRPC(new TypedefTest_getLargoServerRPC("getLargo", this,
                TypedefTest_getLargoRequestUtils::registerType(getParticipant()),
                TypedefTest_getLargoReplyUtils::registerType(getParticipant()),
                &TypedefTestServer::getLargo));
    this->setRPC(new TypedefTest_getLarguisimoServerRPC("getLarguisimo", this,
                TypedefTest_getLarguisimoRequestUtils::registerType(getParticipant()),
                TypedefTest_getLarguisimoReplyUtils::registerType(getParticipant()),
                &TypedefTestServer::getLarguisimo));
    this->setRPC(new TypedefTest_getDatosDefServerRPC("getDatosDef", this,
                TypedefTest_getDatosDefRequestUtils::registerType(getParticipant()),
                TypedefTest_getDatosDefReplyUtils::registerType(getParticipant()),
                &TypedefTestServer::getDatosDef));
    this->setRPC(new TypedefTest_getDatosDefondoServerRPC("getDatosDefondo", this,
                TypedefTest_getDatosDefondoRequestUtils::registerType(getParticipant()),
                TypedefTest_getDatosDefondoReplyUtils::registerType(getParticipant()),
                &TypedefTestServer::getDatosDefondo));
    this->setRPC(new TypedefTest_getCadenaServerRPC("getCadena", this,
                TypedefTest_getCadenaRequestUtils::registerType(getParticipant()),
                TypedefTest_getCadenaReplyUtils::registerType(getParticipant()),
                &TypedefTestServer::getCadena));
    this->setRPC(new TypedefTest_getCorreaServerRPC("getCorrea", this,
                TypedefTest_getCorreaRequestUtils::registerType(getParticipant()),
                TypedefTest_getCorreaReplyUtils::registerType(getParticipant()),
                &TypedefTestServer::getCorrea));

}

void TypedefTestServer::getLargo(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    TypedefTestServer *srv = dynamic_cast<TypedefTestServer*>(server);
    largo  l1 = 0;    
    largo  l2 = 0;    
    largo  getLargo_ret = 0;       
    TypedefTest_getLargoReply replyData;
    

    TypedefTest_getLargoRequestUtils::extractTypeData(*(TypedefTest_getLargoRequest*)requestData, l1);

    try
    {
        getLargo_ret = srv->_impl->getLargo(l1, l2);

        TypedefTest_getLargoReplyUtils::setTypeData(replyData, l2, getLargo_ret);
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::OPERATION_SUCCESSFUL;
        replyData.header.ddsrpcRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::DDSRPC::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::SERVER_INTERNAL_ERROR;
        replyData.header.ddsrpcRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    TypedefTest_getLargoRequestTypeSupport::delete_data((TypedefTest_getLargoRequest*)requestData);
    
        
        
}
void TypedefTestServer::getLarguisimo(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    TypedefTestServer *srv = dynamic_cast<TypedefTestServer*>(server);
    larguisimo  ll1 = 0;    
    larguisimo  ll2 = 0;    
    larguisimo  getLarguisimo_ret = 0;       
    TypedefTest_getLarguisimoReply replyData;
    

    TypedefTest_getLarguisimoRequestUtils::extractTypeData(*(TypedefTest_getLarguisimoRequest*)requestData, ll1);

    try
    {
        getLarguisimo_ret = srv->_impl->getLarguisimo(ll1, ll2);

        TypedefTest_getLarguisimoReplyUtils::setTypeData(replyData, ll2, getLarguisimo_ret);
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::OPERATION_SUCCESSFUL;
        replyData.header.ddsrpcRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::DDSRPC::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::SERVER_INTERNAL_ERROR;
        replyData.header.ddsrpcRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    TypedefTest_getLarguisimoRequestTypeSupport::delete_data((TypedefTest_getLarguisimoRequest*)requestData);
    
        
        
}
void TypedefTestServer::getDatosDef(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    TypedefTestServer *srv = dynamic_cast<TypedefTestServer*>(server);
    DatosDef d1;
        
    DatosDef d2;
    memset(&d2, 0, sizeof(DatosDef));    
    DatosDef getDatosDef_ret;
    memset(&getDatosDef_ret, 0, sizeof(DatosDef));       
    TypedefTest_getDatosDefReply replyData;
    

    TypedefTest_getDatosDefRequestUtils::extractTypeData(*(TypedefTest_getDatosDefRequest*)requestData, d1);

    try
    {
        getDatosDef_ret = srv->_impl->getDatosDef(d1, d2);

        TypedefTest_getDatosDefReplyUtils::setTypeData(replyData, d2, getDatosDef_ret);
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::OPERATION_SUCCESSFUL;
        replyData.header.ddsrpcRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::DDSRPC::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::SERVER_INTERNAL_ERROR;
        replyData.header.ddsrpcRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    TypedefTest_getDatosDefRequestTypeSupport::delete_data((TypedefTest_getDatosDefRequest*)requestData);
    
    DatosDef_finalize(&getDatosDef_ret);    
    DatosDef_finalize(&d2);    
}
void TypedefTestServer::getDatosDefondo(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    TypedefTestServer *srv = dynamic_cast<TypedefTestServer*>(server);
    DatosDefondo dd1;
        
    DatosDefondo dd2;
    memset(&dd2, 0, sizeof(DatosDefondo));    
    DatosDefondo getDatosDefondo_ret;
    memset(&getDatosDefondo_ret, 0, sizeof(DatosDefondo));       
    TypedefTest_getDatosDefondoReply replyData;
    

    TypedefTest_getDatosDefondoRequestUtils::extractTypeData(*(TypedefTest_getDatosDefondoRequest*)requestData, dd1);

    try
    {
        getDatosDefondo_ret = srv->_impl->getDatosDefondo(dd1, dd2);

        TypedefTest_getDatosDefondoReplyUtils::setTypeData(replyData, dd2, getDatosDefondo_ret);
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::OPERATION_SUCCESSFUL;
        replyData.header.ddsrpcRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::DDSRPC::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::SERVER_INTERNAL_ERROR;
        replyData.header.ddsrpcRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    TypedefTest_getDatosDefondoRequestTypeSupport::delete_data((TypedefTest_getDatosDefondoRequest*)requestData);
    
    DatosDefondo_finalize(&getDatosDefondo_ret);    
    DatosDefondo_finalize(&dd2);    
}
void TypedefTestServer::getCadena(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    TypedefTestServer *srv = dynamic_cast<TypedefTestServer*>(server);
    cadena  c1 = NULL;    
    cadena  c2 = NULL;    
    cadena  getCadena_ret = NULL;       
    TypedefTest_getCadenaReply replyData;
    

    TypedefTest_getCadenaRequestUtils::extractTypeData(*(TypedefTest_getCadenaRequest*)requestData, c1);

    try
    {
        getCadena_ret = srv->_impl->getCadena(c1, c2);

        TypedefTest_getCadenaReplyUtils::setTypeData(replyData, c2, getCadena_ret);
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::OPERATION_SUCCESSFUL;
        replyData.header.ddsrpcRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::DDSRPC::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::SERVER_INTERNAL_ERROR;
        replyData.header.ddsrpcRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    TypedefTest_getCadenaRequestTypeSupport::delete_data((TypedefTest_getCadenaRequest*)requestData);
    
    if(getCadena_ret != NULL) free(getCadena_ret);    
    if(c2 != NULL) free(c2);    
}
void TypedefTestServer::getCorrea(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    TypedefTestServer *srv = dynamic_cast<TypedefTestServer*>(server);
    correa  cc1 = NULL;    
    correa  cc2 = NULL;    
    correa  getCorrea_ret = NULL;       
    TypedefTest_getCorreaReply replyData;
    

    TypedefTest_getCorreaRequestUtils::extractTypeData(*(TypedefTest_getCorreaRequest*)requestData, cc1);

    try
    {
        getCorrea_ret = srv->_impl->getCorrea(cc1, cc2);

        TypedefTest_getCorreaReplyUtils::setTypeData(replyData, cc2, getCorrea_ret);
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::OPERATION_SUCCESSFUL;
        replyData.header.ddsrpcRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::DDSRPC::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::SERVER_INTERNAL_ERROR;
        replyData.header.ddsrpcRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    TypedefTest_getCorreaRequestTypeSupport::delete_data((TypedefTest_getCorreaRequest*)requestData);
    
    if(getCorrea_ret != NULL) free(getCorrea_ret);    
    if(cc2 != NULL) free(cc2);    
}