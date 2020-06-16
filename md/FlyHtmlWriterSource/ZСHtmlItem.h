//-----------------------------------------------------------------------------
// Z�HtmlItem.h
//-----------------------------------------------------------------------------
#pragma once
#include <FlyHtmlWriterSource\\ZSHtmlAtribute.h>
#include <FlyHtmlWriterSource\\Z�HtmlTeg.h>

class ZCHtmlBuilder;

//-----------------------------------------------------------------------------
// ������� ��������� � ������� HTML - 
// - ����� ��� � ���������� ����������, ������� � ���������� ��������� ������.
// ������ �������� ��� ����� ����� ����� �������� ����.
// ���� ��� � �������� �������� ��������������� ���������� � ����� 
// �������������. ������������ � ������������ ��������� ���� �������� ��� ���,
// ��������: "p", "div", "a" ...
//-----------------------------------------------------------------------------
class FLY_HTML_WRITER_API Z�HtmlItem : public Z�HtmlTeg {
	friend ZCHtmlBuilder;
public:
	// ����� ��������� � �������� ����
	string txt;
	// ������� ����������� ������ txt ����� ��������� �����
	char   txtPos;

	//-------------------------------------------------------------------------
	// ������� �����
	class ZChain{
		friend Z�HtmlItem;
	protected:
		vector<Z�HtmlTeg> t;
	public:
		ZChain()  {}
		~ZChain() { t.clear(); }

		int  CountItem() const { return t.size(); }
		void Clear() { t.clear(); }

		Z�HtmlTeg& operator() (const long i = -1) {
			int j = i;
			int n = t.size();
			if (j < 0) j = n ? n - 1 : 0;
			if (j >= n) t.resize(j + 1);
			return t[j];
		}
	} C;
	//-------------------------------------------------------------------------

protected:
	// ������ ��������� �����
	vector<Z�HtmlItem> nestedItems;
	// ������� ����������� ����
	char level;

public:
	Z�HtmlItem(const char* tegName = nullptr, int textPos = 0,
		char* text = nullptr, vector<ZSHtmlAttr>* atribut = nullptr);
	~Z�HtmlItem();

	// ������������ ����������� � �����������
	Z�HtmlItem(const Z�HtmlItem& I);
	Z�HtmlItem(Z�HtmlItem&& I);

	// ����������� � �����������
	Z�HtmlItem& operator = (const Z�HtmlItem& I);
	Z�HtmlItem& operator = (Z�HtmlItem&& I);

	//-------------------------------------------------------------------------
	// �������� �������� ���.
	// ��� ����������� � ����� ������ �������� ����� ������� 
	// �����������, �� ���� �������� ��������� ������, ����������
	// ����������� ��� ����� ���������� �������� ������� ������.
	// ������������ vove-�������� C++ 11.
	// ������ ������ ������������ ��� ��������� ���������������.
	Z�HtmlItem& operator << (Z�HtmlItem& I);
	Z�HtmlItem& operator << (char* s);

	//-------------------------------------------------------------------------
	// ������ � �������� ����� �� �������
	// ���� ������ �� ��������, �� ������������ ������ �� ��������� 
	// �������� ���. ���� ������ ������� �� ������� �������, �� ������
	// ������������� ����������� ������� ������.
	Z�HtmlItem& operator() (const long i = -1);

	int CountItems() const;

protected:
	void Open(FILE* of);
	void Close(FILE* of);
	void PrintText(FILE* of);
	void Self(FILE* of);

private:
	Z�HtmlItem& Move(Z�HtmlItem&& I);
	Z�HtmlItem& Copy(const Z�HtmlItem& I);
};