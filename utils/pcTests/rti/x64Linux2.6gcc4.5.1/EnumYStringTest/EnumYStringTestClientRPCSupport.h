#ifndef _EnumYStringTest_CLIENT_RPC_SUPPORT_H_
#define _EnumYStringTest_CLIENT_RPC_SUPPORT_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "utils/GenericClientRPC.h"
#include "EnumYStringTestRequestReplySupport.h"


GENERIC_CLIENT_RPC(EnumYStringTest_getEnumClientRPC, EnumYStringTest_getEnumRequestDataWriter, EnumYStringTest_getEnumReplyDataReader);


GENERIC_CLIENT_RPC(EnumYStringTest_getStringClientRPC, EnumYStringTest_getStringRequestDataWriter, EnumYStringTest_getStringReplyDataReader);


GENERIC_CLIENT_RPC(EnumYStringTest_getStringBoundedClientRPC, EnumYStringTest_getStringBoundedRequestDataWriter, EnumYStringTest_getStringBoundedReplyDataReader);


#endif  // _EnumYStringTest_CLIENT_RPC_SUPPORT_H_