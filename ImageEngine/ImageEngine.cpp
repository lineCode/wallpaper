// ImageEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ImageEngine.h"


// This is an example of an exported variable
IMAGEENGINE_API int nImageEngine=0;

// This is an example of an exported function.
IMAGEENGINE_API int fnImageEngine(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see ImageEngine.h for the class definition
CImageEngine::CImageEngine()
{
    return;
}
