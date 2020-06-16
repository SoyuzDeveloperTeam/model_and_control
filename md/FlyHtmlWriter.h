// FlyHtmlWriter.h
//-----------------------------------------------------------------------------

#ifdef FLY_HTML_WRITER_EXPORTS
#define FLY_HTML_WRITER_API __declspec(dllexport)
#else
#define FLY_HTML_WRITER_API __declspec(dllimport)
#endif

// ����������� ������ �������������� ... ���� ������ ...
// ������ �������������� �� ������
#pragma warning(disable : 4251)

#include <FlyHtmlWriterSource\\ZSHtmlAtribute.h>
#include <FlyHtmlWriterSource\\Z�HtmlTeg.h>
#include <FlyHtmlWriterSource\\Z�HtmlItem.h>
#include <FlyHtmlWriterSource\\Z�HtmlCssStyles.h>
#include <FlyHtmlWriterSource\\ZCHtmlBuilder.h>

//-----------------------------------------------------------------------------
// ��� ����������� ���������� FlyHtmlWriter.dll � �������
// ���������� ��������� ���������� ����� ���������� ������� ���������
// ���������:
//		#define  IMPORT_FLY_HTML_WRITER
//		#include <FlyHtmlWriter.h>
// ������� ����� ��� ������ ���� ���, ������ � ����� ������ ���������.
// �� ���� ��������� ������� ��������� ������ #includ ... ��� �������
// #define ...
#ifdef IMPORT_FLY_HTML_WRITER
	//-------------------------------------------------------------------------
	// �������������� �������, ��������-��������� ����������, 
	// �������� ��� ���������, �������������� ������� � 
	// ������ �����������, "������������" ���� (�������������
	// ������������ ���������� ��������� SSE � AVX
	#pragma message ("    ����������� ���������� FlyMMath...")
	#pragma comment(lib, "FlyHtmlWriter.lib")
#endif 