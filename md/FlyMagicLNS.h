// FlyMagicLNS.h

#ifdef FLYMAGICLNS_EXPORTS
	#define FLYMAGICLNS_API __declspec(dllexport)
#else
	#define FLYMAGICLNS_API __declspec(dllimport)
#endif

//---------------------------------------------------------------------------
// ���������� Fly
#include <FlyMMath.h>		// �������������� �������
#include <FlyCore.h>		// ���� ������ ��������

#include <FlyMagicLNSSource\MagicLNS.h>
#include <FlyMagicLNSSource\MagicSolution.h>