//-----------------------------------------------------------------------------
// ZСHtmlCssStyles.h
//-----------------------------------------------------------------------------
#ifndef ZS_HTML_CSS_STYLES_H
#define ZS_HTML_CSS_STYLES_H

#pragma once
#include <FlyHtmlWriterSource\\ZСHtmlTeg.h>

class ZCHtmlBuilder;
class ZСHtmlCssStyles;

//-----------------------------------------------------------------------------
// Элемент таблицы стилей
//-----------------------------------------------------------------------------
class FLY_HTML_WRITER_API ZСHtmlCssItem : public ZСHtmlTeg {
	friend ZCHtmlBuilder;
	friend ZСHtmlCssStyles;
public:
	ZСHtmlCssItem(const char* sn = nullptr);

protected:
	// Документирование тега с атрибутами тега
	virtual void Open(FILE* of, int level = 1);
	virtual void Close(FILE* of, int level = 1);
};

//-----------------------------------------------------------------------------
// Таблица стилей
//-----------------------------------------------------------------------------
class FLY_HTML_WRITER_API ZСHtmlCssStyles{
	friend ZCHtmlBuilder;
public:
	// Расположение стилей CSS на которые будет ссылаться документ
	//	0 - стили будут записаны в заголовке документа;
	//	1 - стили будут записаны в отдельный файл с именем документа 
	//	    и расширением css;
	//	2 - документ будет ссылаться на стили из файла 
	//	    с именем defautFlyProjectCssFile.
	char   cssLocation;

protected:
	// Набор атрибутов
	vector<ZСHtmlCssItem> t;
	static string defautFlyProjectCssFile;

public:
	ZСHtmlCssStyles();
	~ZСHtmlCssStyles();

	void Clear();
	bool isEmpty() const;
	int  CetCount() const ;

	// Добавить новый тег
	ZСHtmlCssStyles& Add(const char* sn, const char* sa = nullptr);
	ZСHtmlCssStyles& operator += (const char* sn);
	// Наполнить последний добавленный тег атрибутами 
	ZСHtmlCssStyles& operator << (const char* ss);
	// Доступ к заданному тегу
	ZСHtmlCssItem&   operator () (const long i = -1);

protected:
	void Self(FILE* of);
};

//-----------------------------------------------------------------------------
#endif //#ifndef ZS_HTML_CSS_STYLES_H