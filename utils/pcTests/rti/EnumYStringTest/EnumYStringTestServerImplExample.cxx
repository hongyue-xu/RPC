/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file EnumYStringTestServerImplExample.cxx
 * This source file contains the definition of the skeleton for all interfaces.
 *
 * This file was generated by the tool fastrpcgen.
 */

#include "EnumYStringTestServerImplExample.h"

#include "ndds/ndds_namespace_cpp.h"

Valores EnumYStringTestServerImplExample::getEnum(/*in*/ Valores v1, /*inout*/ Valores& v2, /*out*/ Valores& v3) 
{
    Valores  returnedValue = VALOR1;    

    v3 = v2;
    returnedValue = v1;
    v2 = v1;

    return returnedValue;
} 

char* EnumYStringTestServerImplExample::getString(/*in*/ const char* s1, /*inout*/ char*& s2, /*out*/ char*& s3) 
{
    char* returnedValue;

    s3 = DDS::String_dup(s2);
    returnedValue = DDS::String_dup(s1);
    DDS::String_free(s2);
    s2 = DDS::String_alloc(strlen(s1) + strlen(s3) + 1);
#if defined(RTI_WIN32)
    _snprintf(s2, strlen(s1) + strlen(s3) + 1, "%s%s", s1, s3);
#elif defined(RTI_LINUX)
    snprintf(s2, strlen(s1) + strlen(s3) + 1, "%s%s", s1, s3);
#endif

    return returnedValue;
} 

char* EnumYStringTestServerImplExample::getStringBounded(/*in*/ const char* sb1, /*inout*/ char*& sb2, /*out*/ char*& sb3) 
{
    char* returnedValue;

    sb3 = DDS::String_dup(sb2);
    returnedValue = DDS::String_dup(sb1);
    DDS::String_free(sb2);
    sb2 = DDS::String_alloc(strlen(sb1) + strlen(sb3) + 1);
#if defined(RTI_WIN32)
    _snprintf(sb2, strlen(sb1) + strlen(sb3) + 1, "%s%s", sb1, sb3);
#elif defined(RTI_LINUX)
    snprintf(sb2, strlen(sb1) + strlen(sb3) + 1, "%s%s", sb1, sb3);
#endif

    return returnedValue;
} 
