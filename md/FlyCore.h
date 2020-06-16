//-----------------------------------------------------------------------------
// FlyCore.h
// ���� ���������. ��������� ��� ���������� ���� ������ ��������
//
// �. ��������� 25.03.2019
//-----------------------------------------------------------------------------
// � ������ ������� Fly, �������� �������������� ����������� ���, � ��� 
// ���������� ������� ������ ���������� �������, ������� ��������� �������
// ���������� ������� � �������... �� ������ ������:
//		ZF	- �������,
//		ZC	- �����,
//		ZS	- ��������� ������, 
//		ZM	- ������, ������ ����� ���� ��� �������� ��� � �������.
// � ������ ����� Z ���������� ��� ��������� ����� ������� ���������� 
// ��������������� ��� ���������� ������� Fly.
//-----------------------------------------------------------------------------

#ifdef FLYCORE_EXPORTS
#define FLYCORE_API __declspec(dllexport)
#else
#define FLYCORE_API __declspec(dllimport)
#endif

#pragma warning(disable : 4996)
#pragma warning(disable : 4251)

// �������������� ������ � ������ � �������
#include <FlyCoreSource\ModType.h>
#include <FlyCoreSource\ModSK.h>
#include <FlyCoreSource\ModGlobal.h>
// ��������� ���������� ��������� ������ ����, ��������� ��
#include <FlyCoreSource\ModPUManager.h>		
// ������������ ���������
#include <FlyCoreSource\ZCDU.h>				
// ���������� ������������� ��������� ��
#include <FlyCoreSource\ZFDUCalc.h>			
// ������ �����-������
#include <FlyCoreSource\ModAstro.h>		
//#include <FlyCoreSource\ZCAlgebraicMDF.h>
//#include <FlyCoreSource\ZCAlgebraicMdfHolder.h>
//#include <FlyCoreSource\ZEOPManager.h>
#include <FlyCoreSource\ZCEopManager.h>
// ���������������� ����������� �������������
#include <FlyCoreSource\ZCPrintManager.h>			
// ���������������� ����������� �������������
#include <FlyCoreSource\ZCPrintFormat.h>		
// ������ ��������
#include <FlyCoreSource\ZMSpaceCraft.h>		
// �������� ������������� � ��������������� ���������� ������
#include <FlyCoreSource\ZCExternalEquations.h>
// �������� ��� ����������� ����������� �������������� �� ������ ���� ������
#include <FlyCoreSource\ZCMiniStackKeeper.h>
// �������� ������� ��������� ����� ��������� �������
#include <FlyCoreSource\ZSK.h>				
// �������������� �� � ��������� ��
#include <FlyCoreSource\ZSKNU.h>	
// �������� ��� � HBL � �������
#include <FlyCoreSource\ZHBL.h>
// ��������, ������ � ������ ���
#include <FlyCoreSource\ZFUofNU01.h>
#include <FlyCoreSource\ZFUofNU50.h>

//----------------------------------------------------------------------------
// �������������� �������, ��������-��������� ����������, 
// �������� ��� ���������, �������������� ������� � 
// ������ �����������, "������������" ���� (�������������
// ������������ ���������� ��������� SSE � AVX
#define FLY_LINK_MMATH {\
#pragma message ("    ����������� ���������� FlyMMath...")\
#pragma comment(lib, "FlyMMath.lib")\
}

// ����� �������������� �������� ����������� ����� � ����� 
// FORTRAN, �������� ���������� ��������� ��������� ����������
// ������������, ������������ � ��� �����. ������ �����������
// �������� ���� ��������� ������������ � �������� �����,
// ���������� � �++ ��������� 1998 ����.
#define FLY_LINK_SSP {\
#pragma message ("    ����������� ���������� FlySSP...")\
#pragma comment(lib, "FlySSP.lib")\
}

// ���������� �������������� ��������, ����������� ���������
// ��������������� ������������� ��������������� ������ �
// ��������� � IERS Convention 2000-2010 �. 
// ���������� ������������� ���������, �������, ��������
// �������, ������� ��������� � ��������, ���� ������
// ����������� �� ������� �������� ������� � UTC, 
// �������������� ����� ��������� ������� ITRF (������) 
// ICRS (��������), � ����� �������� � ������������
// ������� ������� ���������� �� ������������� 
// �������� �����.
// �������� ���� ������������ �� �������� ������� �������������
// ������ �������� ����� (IERS), ������ �� 30.01.2018, �
// ������� ��� ����� �� �� �� ���� ���������.
// �������� ���� �������� � ��������� �++ 1998 ����.
#define FLY_LINK_SOFA {\
#pragma message ("    ����������� ���������� FlySofa...")\
#pragma comment(lib, "FlySofa.lib")\
}

// �������, ������� � ����������� ����� ������� ��� ������������
// ��������� �������� ������� ��������������� ���������� ��
// ��������. ������ �������� ���� ������������ � ������������.
#define FLY_LINK_CHEBYSHOV {\
#pragma message ("    ����������� ���������� FlyChebyshov...")\
#pragma comment(lib, "FlyChebyshov.lib")\
}

// ����� ������� ��� �������������� �����.
// ����, ���, ���, ���
#define FLY_LINK_ORBITDESIGN {\
#pragma message ("    ����������� ���������� FlyOrbitDesign...")\
#pragma comment(lib, "FlyOrbitDesign.lib")\
}

// ������ ���������.
// ���������, ����������� ������ ���������� ��������� ������ ����
// ��� �������������� �� ������������� ������, �� ������
// ������� �����.
#define FLY_LINK_MAGICLNS {\
#pragma message ("    ����������� ���������� FlyMagicLNS...")\
#pragma comment(lib, "FlyMagicLNS.lib")\
}

// ���� ������ ��������, ����������: ���������� ��������� ��������;
// ��������� ������ ����������� ��������, � ��� �����, �������� ���,
// ������������� ���������, �������������� ���������� (����, ������, 
// �������), �������� �������� � �.�; �������� ���������������� 
// ����������� �������� ���������� ��������;...
#define FLY_LINK_CORE {\
#pragma message ("    ����������� ���������� FlyCore...")\
#pragma comment(lib, "FlyCore.lib")\
}

// �� ��� �������� �������:
//		- �������,
//		- �����������,
//		- UTC, UTC1,
//		- �������� UTC-IAT,
//		- ���������� UTC �� UTC1
//		- ��������� ����������
//		- ������ ������������
#define FLY_LINK_TIME {\
#pragma message ("    ����������� ���������� FlyTime...")\
#pragma comment(lib, "FlyTime.lib")\
}

// ��������������� ����� ������ � ������:
//		- ����
//		- �����
//		- ����+�����
//		- ������� ��������
//		- ������� �������� � ����+���+���
//		- ����� � ��������� ������
//		- ����� � ������������� ������
#define FLY_LINK_FORMAT {\
#pragma message ("    ����������� ���������� FlyFormat...")\
#pragma comment(lib, "FlyFormat.lib")\
}

// �������� ZIP-������� 
#define FLY_LINK_ZIP {\
#pragma message ("    ����������� ���������� FlyZip...")\
#pragma comment(lib, "FlyZip.lib")\
}

#define FLY_LINK_ALL {\
FLY_LINK_SSP\
FLY_LINK_SOFA\
FLY_LINK_CHEBYSHOV\
FLY_LINK_ORBITDESIGN\
FLY_LINK_MAGICLNS\
FLY_LINK_CORE\
FLY_LINK_TIME\
FLY_LINK_FORMAT\
FLY_LINK_ZIP\
}

#pragma comment(user, "Copiled on" __DATE__ "at"  __TIME__)
#pragma comment(user, "����� �. ���������")
#pragma comment(compiler)


//-----------------------------------------------------------------------------
