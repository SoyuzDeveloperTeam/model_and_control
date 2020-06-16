//-------------------------------------------------------------------------------
// ZSmartPtr.h
// А. Николенко 08.02.2019
// 
// Шаблон "умного" указаталя
//-------------------------------------------------------------------------------
#ifndef CLASS_ZSMART_PTR_H
#define CLASS_ZSMART_PTR_H
//-------------------------------------------------------------------------------

template<typename T> class FLYCORE_API ZSmartPtr {
public : 
	ZSmartPtr() {
		p = nullptr ;
		s = 0 ;
	} ;
	~ZSmartPtr() {
		Clear() ;
	} ;

	void Clear() {
		FAST_SEMAPFORE_OPEN("ZSmartPtrClear") ;
		if (p) delete[] p ; p = nullptr ;  
		s = 0 ;
		FAST_SEMAPFORE_CLOSE() ;
	}

	bool New(int size) {
		bool rc = true ;
		FAST_SEMAPFORE_OPEN("ZSmartPtrNew") ;

		if (p) rc = false ; 
		else {
			p = new T[size] ; 
			if (p) s = size ; 
			else rc = false ;
		}

		FAST_SEMAPFORE_CLOSE() ;
		return rc ;
	}

	bool ReSize(int size) {
		bool rc = true ;
		FAST_SEMAPFORE_OPEN("ZSmartPtrReSize") ;

		if (!p) rc = New(size) ; 
		else {
			if (size!=s) {
				T* p2 ; 
				p2 = new T[size] ; 
				if (p2) {
					if (size>s) {
						memcpy(p2, p, s*sizeof(T)) ;
						memset(&p2[s], 0, (size-s)*sizeof(T)) ;
					} else {
						memcpy(p2, p, size*sizeof(T)) ;
					}
					p = p2 ;
					s = size ;
				} else rc = false ; 
		}	}

		FAST_SEMAPFORE_CLOSE() ;
		return rc ;
	}

	T& operator [] (int i) { assert(p) ; return p[i] ; }

protected: 
	T* p ;
	int s ; 
} ;

//-------------------------------------------------------------------------------
typedef ZSmartPtr<char>   ZSmartPtrChar ;
typedef ZSmartPtr<int>    ZSmartPtrInt ;
typedef ZSmartPtr<long>   ZSmartPtrLomg ;
typedef ZSmartPtr<short>  ZSmartPtrShort ;
typedef ZSmartPtr<float>  ZSmartPtrFloat ;
typedef ZSmartPtr<double> ZSmartPtrDouble ;
typedef ZSmartPtr<bool>   ZSmartPtrBool ;

//-------------------------------------------------------------------------------
#endif	// CLASS_ZSMART_PTR_H
