//-----------------------------------------------------------------------------
// Z�HtmlCssStyles.h
//-----------------------------------------------------------------------------
#ifndef ZS_HTML_CSS_STYLES_H
#define ZS_HTML_CSS_STYLES_H

#pragma once
#include <FlyHtmlWriterSource\\Z�HtmlTeg.h>

class ZCHtmlBuilder;
class Z�HtmlCssStyles;

//-----------------------------------------------------------------------------
// ������� ������� ������
//-----------------------------------------------------------------------------
class FLY_HTML_WRITER_API Z�HtmlCssItem : public Z�HtmlTeg {
	friend ZCHtmlBuilder;
	friend Z�HtmlCssStyles;
public:
	Z�HtmlCssItem(const char* sn = nullptr);

protected:
	// ���������������� ���� � ���������� ����
	virtual void Open(FILE* of, int level = 1);
	virtual void Close(FILE* of, int level = 1);
};

//-----------------------------------------------------------------------------
// ������� ������
//-----------------------------------------------------------------------------
class FLY_HTML_WRITER_API Z�HtmlCssStyles{
	friend ZCHtmlBuilder;
public:
	// ������������ ������ CSS �� ������� ����� ��������� ��������
	//	0 - ����� ����� �������� � ��������� ���������;
	//	1 - ����� ����� �������� � ��������� ���� � ������ ��������� 
	//	    � ����������� css;
	//	2 - �������� ����� ��������� �� ����� �� ����� 
	//	    � ������ defautFlyProjectCssFile.
	char   cssLocation;

protected:
	// ����� ���������
	vector<Z�HtmlCssItem> t;
	static string defautFlyProjectCssFile;

public:
	Z�HtmlCssStyles();
	~Z�HtmlCssStyles();

	void Clear();
	bool isEmpty() const;
	int  CetCount() const ;

	// �������� ����� ���
	Z�HtmlCssStyles& Add(const char* sn, const char* sa = nullptr);
	Z�HtmlCssStyles& operator += (const char* sn);
	// ��������� ��������� ����������� ��� ���������� 
	Z�HtmlCssStyles& operator << (const char* ss);
	// ������ � ��������� ����
	Z�HtmlCssItem&   operator () (const long i = -1);

protected:
	void Self(FILE* of);
};

//-----------------------------------------------------------------------------
#endif //#ifndef ZS_HTML_CSS_STYLES_H