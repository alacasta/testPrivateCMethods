/*
	customOps.c
*/

#include "customOps.h"

#ifdef __cplusplus
extern "C" {
#endif

int _myPrivateVariable = 0;

int returnTrueIfAPrivateMethodIsCalled()
{
	if(_myPrivateVariable)
	{
		return 1;
	}
	return 0;
}

void modifyMyPrivateVariable(int value)
{
	_myPrivateVariable = value;
}

#ifdef __cplusplus
}
#endif


