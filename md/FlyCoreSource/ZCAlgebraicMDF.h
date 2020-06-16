//-----------------------------------------------------------------------------
// ZCAlgebraicMDF.h
// �. ��������� 01.04.2019
//
// �������������� ������������ (������) ��������� �������� �������.
// ������� ��������������� ���������� ��������.
// 
// �������������� ���������:
//		- ���������� ��������������� ������� �������� �����,
//		- �������� ��������� ������� �������� ������� ��������� �����,
//		- ��� ����������� ���������� ������� ����� ������� ���������������� 
//		  ��������� �����,
//		- � �������� ������ (��������) ����� ������������� �� ���� 
//		  � ��������� ����.
//-----------------------------------------------------------------------------
#ifndef ZC_ALGEBRAIC_MDF_H
#define ZC_ALGEBRAIC_MDF_H

#include <iostream>
#include <fstream>

class ZCAlgebraicMDFManager;

class FLYCORE_API ZCAlgebraicMDF {
	// ���������
	friend ZCAlgebraicMDFManager;
	friend bool operator < (const ZCAlgebraicMDF& M1, const ZCAlgebraicMDF& M2);
public:
	// ����������� �� ���������
	ZCAlgebraicMDF();

	// ����������� �����
	ZCAlgebraicMDF(const ZCAlgebraicMDF& M);
	// ����������� ��������
	ZCAlgebraicMDF(ZCAlgebraicMDF&& M);
	// ������������ �����������
	// !!!! � ������ ������������� ���������� ��� ������������ ��������
	// ������ ������ ����������.
	ZCAlgebraicMDF(double* T, double* Y, const int N, const int D=12);

	// �������� �����
	ZCAlgebraicMDF& operator = (const ZCAlgebraicMDF& M);
	// ��������� ��������
	ZCAlgebraicMDF& operator = (ZCAlgebraicMDF&& M);

	~ZCAlgebraicMDF();

	// �������� ������ (� ��� ����� � ��������� A ������ ����������)
	void Clr();
	// ������� ������ ���������� �� ��������� A.
	void Del();
	// ����������� ������ ������
	void Cpy(const ZCAlgebraicMDF& M);
	// ������� ������ ������
	void Move(ZCAlgebraicMDF& M);

	// ���������� �������� �������� ��� ������� t, ��������� ��� 
	// ���������������� ��������� ����
	double Calc(double t) const;
	bool   IsDomainFrom(double t) const;

	// �������� �������� - ������������ �� ��������
	int Build(double* T, double* Y, int N, int D = 9);

	// �������� � ������� ���������� ������ ��� ������� ��������
	int Create(int D, double TB, double TE);
	// �������� �� ��������� ��������� �������
	int LoadFromStream(ifstream& f, double TimeFrame);
	// ���������� � �������� ��������� �������
	int StoryToStream(ofstream& f);

	// ������ ���� ������ �� ������� �������� �������
	double GetBT() const { return begTime; }
	// ����� ���� ������ �� ������� �������� �������
	double GetET() const { return endTime; }

	// ������� ��������
	int    GetDegree() const { return Degree; }

	// ������� ������������� ������
	//		0 - ��������� �� ���������
	//		1 - ������������� �� ���������� ������ ��� 
	//			������� ��������.
	bool   IsGener() const { return isGenerated; }

	// ������ � ������������� ������
	double operator [] (int   i) const { return A[i]; }
	double operator [] (short i) const { return A[i]; }
	double operator [] (long  i) const { return A[i]; }
	double* MA() const { return A; }
	
protected:
	// ������� ��������� ������ �� ��������� ���������� �������
	//		true	- ������ �������������
	//		false	- ������ ��������� �� ���������
	bool    isGenerated;
	// ������� ��������  
	int     Degree;
	// ������� ����������� ������
	double  begTime;
	double  endTime;
	// ������������ ������ 
	double* A;
};

bool operator < (const ZCAlgebraicMDF& M1, const ZCAlgebraicMDF& M2);

//-----------------------------------------------------------------------------
#endif // #ifndef ZC_ALGEBRAIC_MDF_H