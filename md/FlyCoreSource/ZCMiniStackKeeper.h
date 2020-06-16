//---------------------------------------------------------------------------
// ZCMiniStackKeeper.h
//
// ���� ��� ��������� ���� ��������� ����������� ��� ����������� 
// ��������������� ������ ��� ���������: ��������� ���������, �������, ���,
// ���������� ������ � ����.
//---------------------------------------------------------------------------
#ifndef ZC_MINI_STACK_KEEPER_H
#define ZC_MINI_STACK_KEEPER_H

template<typename T, const int N>
class FLYCORE_API ZCMiniStackKeeper{
public:
	ZCMiniStackKeeper(
				double eps = 1e-8 )	// �������� � ������� ������������ 
	{								// ��������� ���� ��������� �������, � ���. 
		// �������� ��������
		e = eps;
		// ������� (������) ��������� ���������� ������ � ������ �����
		SwitchFirst = false;
		// ���� ������ ����������
		memset(Result, 0, sizeof(Result));
	}

	~ZCMiniStackKeeper(){}

	// ���������� ������ � ����� �� ������ ������� t.
	void Story(double  t,	// ����� �� �������� ����������� ������
			   double* Q,	// ������ ����������� ������.
			   int     M=0) // ����� ����������
	{
		// ����� ������ ��������� ���������� ������ ������.
		int i1 = SwitchFirst = !SwitchFirst;
		// ������ ��������� ���������� ������ � "����".
		memcpy(&Result[i1][1], Q, N*sizeof(T));
		Method[i1] = M;
	}

	// �������� ������� ������ � ����� �� ������ ������� t
	bool IsExistResultFor(
				double t,		// ����� �� ������� ����������� ������� ������
				T*  Q,			// ������ ��� �������� ������
				int M=0) const	// ����� ����������
	{
		int i1 = SwitchFirst;	// ������ ��������� ����������� ������
		int i2 =!SwitchFirst;	// ������ ����������� ������� ������
		if (Method[i1] == M && fabs(t - Result[i1][0]) <= e) {
			// ���� ����� ��������� � �������� � "������" ������,
			// �� �������� ������ �� ������ �������
			memcpy(Q, &Result[i1][1], N*sizeof(T));
			// ������������ ������� ��������� ������
			return true;
		} else {
			if (Method[i2] == M && fabs(t - Result[i2][0]) <= e) {
				// ���� ����� ��������� � �������� �� "������" ������,
				// �� �������� ������ �� ������ �������
				memcpy(Q, &Result[i2][1], N*sizeof(T));
				// ������������ ������� ��������� ������
				return true;
		}	}
		// ������������ �������, ���� ��� ������������� ������ � ����� ���
		return false;
	}

private:
	double			e;
	mutable bool	SwitchFirst;
	int				Method[2];
	T				Result[2][N + 1];
};

//-----------------------------------------------------------------------------
typedef ZCMiniStackKeeper < double, 2 >  ZCKeepper2D;
typedef ZCMiniStackKeeper < double, 3 >  ZCKeepper3D;
typedef ZCMiniStackKeeper < double, 4 >  ZCKeepper4D;
typedef ZCMiniStackKeeper < double, 6 >  ZCKeepper6D;
typedef ZCMiniStackKeeper < double, 9 >  ZCKeepperMart3;
typedef ZCMiniStackKeeper < double, 36>  ZCKeepperMart6;

//-----------------------------------------------------------------------------
#endif // #ifndef ZC_MINI_STACK_KEEPER_H