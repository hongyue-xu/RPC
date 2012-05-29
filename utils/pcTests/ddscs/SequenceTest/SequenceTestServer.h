#ifndef _SequenceTestSKELETON_H_
#define _SequenceTestSKELETON_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "server/DDSCSServer.h"
#include "SequenceTestServerImpl.h"
#include "SequenceTestRequestReplyUtils.h"

class SequenceTestServer : public DDSCSServer
{
    private: 
      SequenceTestImpl *_impl;
    public:

        /// \brief The default constructor.
        SequenceTestServer(int domainId = 0, unsigned int threadCount = DDSCS_MIN_THREADS_DEFAULT);

        /// \brief The default destructor.
        virtual ~SequenceTestServer();

        static void getSLong(DDSCSServer *server, void *requestData, ServerRemoteService *service);
        static void getString(DDSCSServer *server, void *requestData, ServerRemoteService *service);
        static void getStringBounded(DDSCSServer *server, void *requestData, ServerRemoteService *service);
};

#endif // _SequenceTestSKELETON_H_