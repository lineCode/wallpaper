// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IMAGEENGINE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IMAGEENGINE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef IMAGEENGINE_EXPORTS
#define IMAGEENGINE_API __declspec(dllexport)
#else
#define IMAGEENGINE_API __declspec(dllimport)
#endif

// This class is exported from the ImageEngine.dll
class IMAGEENGINE_API CImageEngine {
public:
	CImageEngine(void);
	// TODO: add your methods here.
};

extern IMAGEENGINE_API int nImageEngine;

IMAGEENGINE_API int fnImageEngine(void);
