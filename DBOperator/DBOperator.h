// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DBOPERATOR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DBOPERATOR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DBOPERATOR_EXPORTS
#define DBOPERATOR_API __declspec(dllexport)
#else
#define DBOPERATOR_API __declspec(dllimport)
#endif

// This class is exported from the DBOperator.dll
class DBOPERATOR_API CDBOperator {
public:
	CDBOperator(void);
	// TODO: add your methods here.
};

extern DBOPERATOR_API int nDBOperator;

DBOPERATOR_API int fnDBOperator(void);
