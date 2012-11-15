#ifndef _ServerException_ASYNC_SUPPORT_H_
#define _ServerException_ASYNC_SUPPORT_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "client/AsyncTask.h"


class ServerException_sendExceptionTask : public eProsima::DDSRPC::AsyncTask
{
    public:

        /// \brief The default constructor.
        ServerException_sendExceptionTask(ServerException_sendExceptionCallbackHandler &obj,
           eProsima::DDSRPC::Client *client);

        /// \brief The default destructor.
        virtual ~ServerException_sendExceptionTask();
        
        virtual void execute();
        
        virtual void on_exception(const eProsima::DDSRPC::SystemException &ex);
        
        ServerException_sendExceptionCallbackHandler& getObject();
        
        void* getReplyInstance();
        
        private:
        
           ServerException_sendExceptionCallbackHandler &m_obj;
           
           ServerException_sendExceptionReply m_reply;
};

class ServerException_sendExceptionTwoTask : public eProsima::DDSRPC::AsyncTask
{
    public:

        /// \brief The default constructor.
        ServerException_sendExceptionTwoTask(ServerException_sendExceptionTwoCallbackHandler &obj,
           eProsima::DDSRPC::Client *client);

        /// \brief The default destructor.
        virtual ~ServerException_sendExceptionTwoTask();
        
        virtual void execute();
        
        virtual void on_exception(const eProsima::DDSRPC::SystemException &ex);
        
        ServerException_sendExceptionTwoCallbackHandler& getObject();
        
        void* getReplyInstance();
        
        private:
        
           ServerException_sendExceptionTwoCallbackHandler &m_obj;
           
           ServerException_sendExceptionTwoReply m_reply;
};

class ServerException_sendExceptionThreeTask : public eProsima::DDSRPC::AsyncTask
{
    public:

        /// \brief The default constructor.
        ServerException_sendExceptionThreeTask(ServerException_sendExceptionThreeCallbackHandler &obj,
           eProsima::DDSRPC::Client *client);

        /// \brief The default destructor.
        virtual ~ServerException_sendExceptionThreeTask();
        
        virtual void execute();
        
        virtual void on_exception(const eProsima::DDSRPC::SystemException &ex);
        
        ServerException_sendExceptionThreeCallbackHandler& getObject();
        
        void* getReplyInstance();
        
        private:
        
           ServerException_sendExceptionThreeCallbackHandler &m_obj;
           
           ServerException_sendExceptionThreeReply m_reply;
};

#endif // _ServerException_ASYNC_SUPPORT_H_