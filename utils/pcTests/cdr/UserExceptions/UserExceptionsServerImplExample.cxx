/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file UserExceptionsServerImplExample.cxx
 * This source file contains the definition of the skeleton for all interfaces.
 *
 * This file was generated by the tool fastrpcgen.
 */

#include "UserExceptionsServerImplExample.h"

void IfcServerImplExample::sendLevel1(/*in*/ int32_t l1, /*inout*/ int32_t& l2, /*out*/ int32_t& l3)
{
    Level1 ex;
    ex.count(l1);
    ex.msg("sendLevel1");
    throw ex;
} 

int32_t IfcServerImplExample::sendLevel2()
{
    int32_t  sendLevel2_ret = 0;

    Alfa::Level2 ex;
    ex.count(101);
    ex.ana().count(102);
    ex.ana().comment("sendLevel2");
    throw ex;

    return sendLevel2_ret;
} 

int32_t IfcServerImplExample::sendExcep(/*in*/ int32_t l1)
{
    int32_t  sendExcep_ret = 0;

    Beta::Excep ex;
    ex.count(l1);
    ex.msg("sendExcep");
    throw ex;

    return sendExcep_ret;
} 

int32_t IfcServerImplExample::sendExcepIntern(/*in*/ int32_t l1)
{
    int32_t  sendExcepIntern_ret = 0;

    Beta::Ifc::ExcepIntern ex;
    ex.count(l1);
    ex.msg("sendExcepIntern");
    throw ex;

    return sendExcepIntern_ret;
} 

void IfcServerImplExample::sendOnlyExcep()
{
    Beta::Excep ex;
    ex.count(1);
    ex.msg("sendOnlyExcep");
    throw ex;
}
