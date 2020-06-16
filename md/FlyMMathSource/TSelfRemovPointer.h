//------------------------------------------------------------------------------
// TSelfRemovPointer.h
// А. Николенко 14.06.2019
//------------------------------------------------------------------------------
#ifndef SELF_REMOVE_POINTER_H
#define SELF_REMOVE_POINTER_H

template<typename T>
class ZTSelfRemovPointer
{
public:
	ZTSelfRemovPointer() { P = new T; }
	~ZTSelfRemovPointer() { if (P) delete P; }
	T* operator -> () { return P; }
	T* operator & () { return P; }
	operator T* () { return P; }
	operator T& () { return *P; }
private:
	T* P;
};

//------------------------------------------------------------------------------
#endif // #ifndef SELF_REMOVE_POINTER_H