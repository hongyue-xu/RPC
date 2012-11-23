/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file EnumYStringTestRequestReplyUtils.cxx
 * This source file contains the definition of helpful functions for the DDS messages for interface EnumYStringTest.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "EnumYStringTestRequestReplyUtils.h"
#include "EnumYStringTestRequestReplyPlugin.h"


const char* EnumYStringTest_getEnumRequestUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = EnumYStringTest_getEnumRequestTypeSupport::get_type_name();

        if(EnumYStringTest_getEnumRequestTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void EnumYStringTest_getEnumRequestUtils::setTypeData(EnumYStringTest_getEnumRequest& instance, /*in*/ Valores v1, /*inout*/ Valores v2)
{
    instance.v1 = v1;
    instance.v2 = v2;
    
}

void EnumYStringTest_getEnumRequestUtils::extractTypeData(EnumYStringTest_getEnumRequest& data, /*in*/ Valores& v1, /*inout*/ Valores& v2)
{
    v1 = data.v1;
    v2 = data.v2;  
    
}


const char* EnumYStringTest_getEnumReplyUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = EnumYStringTest_getEnumReplyTypeSupport::get_type_name();

        if(EnumYStringTest_getEnumReplyTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void EnumYStringTest_getEnumReplyUtils::setTypeData(EnumYStringTest_getEnumReply& instance, /*inout*/ Valores v2, /*out*/ Valores v3, /*out*/ Valores getEnum_ret)
{
    instance.v2 = v2;
    instance.v3 = v3;
    instance.getEnum_ret = getEnum_ret;            
}

void EnumYStringTest_getEnumReplyUtils::extractTypeData(EnumYStringTest_getEnumReply& data, eProsima::RPCDDS::ReturnMessage& retcode, /*inout*/ Valores& v2, /*out*/ Valores& v3, /*out*/ Valores& getEnum_ret)
{
retcode = (eProsima::RPCDDS::ReturnMessage)data.header.rpcddsRetCode;
    v2 = data.v2;
    v3 = data.v3;  
    getEnum_ret = data.getEnum_ret;            
}


const char* EnumYStringTest_getStringRequestUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = EnumYStringTest_getStringRequestTypeSupport::get_type_name();

        if(EnumYStringTest_getStringRequestTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void EnumYStringTest_getStringRequestUtils::setTypeData(EnumYStringTest_getStringRequest& instance, /*in*/ char* s1, /*inout*/ char* s2)
{
    instance.s1 = s1;
    instance.s2 = s2;
    
}

void EnumYStringTest_getStringRequestUtils::extractTypeData(EnumYStringTest_getStringRequest& data, /*in*/ char*& s1, /*inout*/ char*& s2)
{
    s1 = data.s1;
    s2 = strdup(data.s2);  
    
}


const char* EnumYStringTest_getStringReplyUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = EnumYStringTest_getStringReplyTypeSupport::get_type_name();

        if(EnumYStringTest_getStringReplyTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void EnumYStringTest_getStringReplyUtils::setTypeData(EnumYStringTest_getStringReply& instance, /*inout*/ char* s2, /*out*/ char* s3, /*out*/ char* getString_ret)
{
    instance.s2 = s2;
    instance.s3 = s3;
    instance.getString_ret = getString_ret;            
}

void EnumYStringTest_getStringReplyUtils::extractTypeData(EnumYStringTest_getStringReply& data, eProsima::RPCDDS::ReturnMessage& retcode, /*inout*/ char*& s2, /*out*/ char*& s3, /*out*/ char*& getString_ret)
{
retcode = (eProsima::RPCDDS::ReturnMessage)data.header.rpcddsRetCode;
    if(s2 != NULL)
    	free(s2);s2 = data.s2;
    s3 = data.s3;  
    getString_ret = data.getString_ret;            
}


const char* EnumYStringTest_getStringBoundedRequestUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = EnumYStringTest_getStringBoundedRequestTypeSupport::get_type_name();

        if(EnumYStringTest_getStringBoundedRequestTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void EnumYStringTest_getStringBoundedRequestUtils::setTypeData(EnumYStringTest_getStringBoundedRequest& instance, /*in*/ char* sb1, /*inout*/ char* sb2)
{
    instance.sb1 = sb1;
    instance.sb2 = sb2;
    
}

void EnumYStringTest_getStringBoundedRequestUtils::extractTypeData(EnumYStringTest_getStringBoundedRequest& data, /*in*/ char*& sb1, /*inout*/ char*& sb2)
{
    sb1 = data.sb1;
    sb2 = strdup(data.sb2);  
    
}


const char* EnumYStringTest_getStringBoundedReplyUtils::registerType(DDS::DomainParticipant *participant)
{
    const char *typeName = NULL;

    if(participant != NULL)
    {
        typeName = EnumYStringTest_getStringBoundedReplyTypeSupport::get_type_name();

        if(EnumYStringTest_getStringBoundedReplyTypeSupport::register_type(participant, typeName) != DDS::RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

void EnumYStringTest_getStringBoundedReplyUtils::setTypeData(EnumYStringTest_getStringBoundedReply& instance, /*inout*/ char* sb2, /*out*/ char* sb3, /*out*/ char* getStringBounded_ret)
{
    instance.sb2 = sb2;
    instance.sb3 = sb3;
    instance.getStringBounded_ret = getStringBounded_ret;            
}

void EnumYStringTest_getStringBoundedReplyUtils::extractTypeData(EnumYStringTest_getStringBoundedReply& data, eProsima::RPCDDS::ReturnMessage& retcode, /*inout*/ char*& sb2, /*out*/ char*& sb3, /*out*/ char*& getStringBounded_ret)
{
retcode = (eProsima::RPCDDS::ReturnMessage)data.header.rpcddsRetCode;
    if(sb2 != NULL)
    	free(sb2);sb2 = data.sb2;
    sb3 = data.sb3;  
    getStringBounded_ret = data.getStringBounded_ret;            
}

 