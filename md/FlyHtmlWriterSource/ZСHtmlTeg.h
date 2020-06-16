//-----------------------------------------------------------------------------
// Z�HtmlTeg.h
//-----------------------------------------------------------------------------
#ifndef ZS_HTML_TEG_H
#define ZS_HTML_TEG_H

#include <FlyHtmlWriterSource\\ZSHtmlAtribute.h>

class ZCHtmlBuilder;
class ZCHtmlTegChain;
class Z�HtmlItem;

//-----------------------------------------------------------------------------
// �������� ���� � ����������. 
// ��� ������� �� ����� � ������� ���������
// ������ ������� ������� �� ���� �����: ����� �������� � ��� ��������.
//-----------------------------------------------------------------------------
class FLY_HTML_WRITER_API Z�HtmlTeg{
	friend ZCHtmlBuilder;
	friend ZCHtmlTegChain;
	friend Z�HtmlItem;
public:
	// ��� ���� 
	string n;
protected:
	// ����� ���������
	vector<ZSHtmlAttr> a;

public:
	Z�HtmlTeg(const char* sn = nullptr, const char* sa = nullptr);
	~Z�HtmlTeg();

	bool isEmpty()  const;
	int  CetCountAttr() const;

	//-------------------------------------------------------------------------
	// ��������� ���� �������� "d", "div", "font", "style" ...
	Z�HtmlTeg& operator = (const char* sn);

	//-------------------------------------------------------------------------
	// �������� � ��� �������� �� ���������� ����� ������ �������������
	Z�HtmlTeg& operator+= (const std::initializer_list<const char*> ss);
	Z�HtmlTeg& operator << (vector<ZSHtmlAttr>& va);
	Z�HtmlTeg& operator << (ZSHtmlAttr& _a);
	Z�HtmlTeg& operator << (const char* ss);
	Z�HtmlTeg& operator << (char* ss[]);
	Z�HtmlTeg& operator << (const std::initializer_list<const char*> ss);

	//-------------------------------------------------------------------------
	// ������ � �������� �� �������
	ZSHtmlAttr& operator[] (const long i);

protected:
	// ���������������� ���� � ���������� ����
	virtual void Open(FILE* of, int level = 1);
	virtual void Close(FILE* of, int level = 1);

protected:
	void Tab(FILE* of, int level);
};

//-----------------------------------------------------------------------------
#endif //#ifndef ZS_HTML_TEG_H