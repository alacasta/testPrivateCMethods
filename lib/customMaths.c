/*
	customMaths.c
*/

#include "customMaths.h"

#ifdef __cplusplus
extern "C" {
#endif

int suma(int op1, int op2)
{
	return op1 + op2;
}

int resta(int op1, int op2)
{
	return suma(op1, -op2);
}

#ifdef __cplusplus
}
#endif