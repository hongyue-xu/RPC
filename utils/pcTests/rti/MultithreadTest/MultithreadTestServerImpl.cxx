/** 
 * Generated by RPCDDS                                              *
 * Empty interface implementation to be filled with your own code.  *
 */
 
#include "MultithreadTestServerImpl.h"
 
DDS_Long MultithreadTestServerImpl::test(/*in*/ const Dato& dato1, /*out*/ Dato& dato2) 
{
    DDS_Long returnedValue = 0;
        
    dato2.count = dato1.count;
	Dato_initialize(&dato2);
#if defined(RTI_WIN32)
    _snprintf(dato2.message, 255, "%s", dato1.message);
#elif defined(RTI_LINUX)
    snprintf(dato2.message, 255, "%s", dato1.message);
#endif
   
    return returnedValue;
} 