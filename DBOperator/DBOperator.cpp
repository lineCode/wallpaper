// DBOperator.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DBOperator.h"


// This is an example of an exported variable
DBOPERATOR_API int nDBOperator=0;

// This is an example of an exported function.
DBOPERATOR_API int fnDBOperator(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see DBOperator.h for the class definition
CDBOperator::CDBOperator()
{
    return;
}
