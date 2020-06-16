//-------------------------------------------------------------------------------
// ZCMemoryKeepper.h
// А. Николенко 03.08.2018
// Хранилка памяти - для сохранения состояний модели движения и последующего  
// их восстановления на различные моменты времени
//-------------------------------------------------------------------------------
#ifndef CLASS_MEMORYKEEPPER_H
#define CLASS_MEMORYKEEPPER_H
//-------------------------------------------------------------------------------

#include <FlyCoreSource\\ZSmartPtr.h>

class FLYCORE_API ZCMemoryKeeper {
public:
	ZCMemoryKeeper();
	~ZCMemoryKeeper();

	void Bind(double* Q, int N) ; 

    virtual int  Story    (int  key=0, void** Params=nullptr, int* SizeParams=nullptr, int CountParams=0) ;
	virtual int  ReStory  (int  key,   void** Params=nullptr, int* SizeParams=nullptr, int CountParams=0) ;
	virtual void FreeStory(int* key=nullptr) ;

private:
	int FaindFreeStoryKey( ) ;

	int				m_SizeA ;
	double*			m_A ;
	vector<char*>	m_sa ;		// Буфер для записи сохраняемых данных 
} ;

//-------------------------------------------------------------------------------
#endif	// CLASS_MEMORYKEEPPER_H
