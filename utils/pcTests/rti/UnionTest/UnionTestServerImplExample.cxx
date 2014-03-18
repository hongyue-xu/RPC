/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file UnionTestServerImplExample.cxx
 * This source file contains the definition of the skeleton for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */
 
#include "UnionTestServerImplExample.h"

#include "ndds/ndds_namespace_cpp.h"
 
Empleado UnionTestServerImplExample::getEmpleado(/*in*/ const Empleado& em1, /*inout*/ Empleado& em2, /*out*/ Empleado& em3) 
{
    Empleado getEmpleado_ret;

	Empleado_initialize(&getEmpleado_ret);
        
	em3._d = em2._d;
	if(em3._d == 1)
		em3._u.id = em2._u.id;
	else
		em3._u.name = DDS::String_dup(em2._u.name);

	getEmpleado_ret._d = em1._d;
	if(getEmpleado_ret._d == 1)
		getEmpleado_ret._u.id = em1._u.id;
	else
		getEmpleado_ret._u.name = DDS::String_dup(em1._u.name);

	em2._d = em1._d;
	if(em2._d == 1)
		em2._u.id = em1._u.id;
	else
    {
		DDS::String_free(em2._u.name);
		em2._u.name = NULL;
		em2._u.name = DDS::String_dup(em1._u.name);
    }
   
    return getEmpleado_ret;
} 

UnionTest::Jefe UnionTestServerImplExample::getJefe(/*in*/ const UnionTest::Jefe& je1, /*inout*/ UnionTest::Jefe& je2, /*out*/ UnionTest::Jefe& je3)
{
    UnionTest::Jefe getJefe_ret;

    UnionTest::Jefe_initialize(&getJefe_ret);

    je3._d = je2._d;
    if(je3._d == UnionTest::BUENO)
        je3._u.id = je2._u.id;
    else if(je3._d == UnionTest::MALO)
        je3._u.name = DDS::String_dup(je2._u.name);
    else if(je3._d == UnionTest::MALVADO ||
            je3._d == UnionTest::SATAN)
        je3._u.seq.copy(je2._u.seq);

    getJefe_ret._d = je1._d;
    if(getJefe_ret._d == UnionTest::BUENO)
        getJefe_ret._u.id = je1._u.id;
    else if(getJefe_ret._d == UnionTest::MALO)
        getJefe_ret._u.name = DDS::String_dup(je1._u.name);
    else if(getJefe_ret._d == UnionTest::MALVADO ||
            getJefe_ret._d == UnionTest::SATAN)
        getJefe_ret._u.seq.copy(je1._u.seq);

    je2._d = je1._d;
    if(je2._d == UnionTest::BUENO)
        je2._u.id = je1._u.id;
    else if(je2._d == UnionTest::MALO)
    {
		DDS::String_free(je2._u.name);
		je2._u.name = NULL;
        je2._u.name = DDS::String_dup(je1._u.name);
    }
    else if(je2._d == UnionTest::MALVADO ||
            je2._d == UnionTest::SATAN)
        je2._u.seq.copy(je1._u.seq);

    return getJefe_ret;
}
