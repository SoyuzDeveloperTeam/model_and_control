//-----------------------------------------------------------------------------
// ZСHtmlTeg.h
//-----------------------------------------------------------------------------
#ifndef ZS_HTML_TEG_H
#define ZS_HTML_TEG_H

#include <FlyHtmlWriterSource\\ZSHtmlAtribute.h>

class ZCHtmlBuilder;
class ZCHtmlTegChain;
class ZСHtmlItem;

//-----------------------------------------------------------------------------
// Описание тега с атрибутами. 
// Тег состоит из имени и массива атрибутов
// Каждый атрибут состоит из двух строк: имени атрибута и его значения.
//-----------------------------------------------------------------------------
class FLY_HTML_WRITER_API ZСHtmlTeg{
	friend ZCHtmlBuilder;
	friend ZCHtmlTegChain;
	friend ZСHtmlItem;
public:
	// Имя тега 
	string n;
protected:
	// Набор атрибутов
	vector<ZSHtmlAttr> a;

public:
	ZСHtmlTeg(const char* sn = nullptr, const char* sa = nullptr);
	~ZСHtmlTeg();

	bool isEmpty()  const;
	int  CetCountAttr() const;

	//-------------------------------------------------------------------------
	// Присвоить тегу значение "d", "div", "font", "style" ...
	ZСHtmlTeg& operator = (const char* sn);

	//-------------------------------------------------------------------------
	// Добавить в тег атрибуты со значениями через список инициализации
	ZСHtmlTeg& operator+= (const std::initializer_list<const char*> ss);
	ZСHtmlTeg& operator << (vector<ZSHtmlAttr>& va);
	ZСHtmlTeg& operator << (ZSHtmlAttr& _a);
	ZСHtmlTeg& operator << (const char* ss);
	ZСHtmlTeg& operator << (char* ss[]);
	ZСHtmlTeg& operator << (const std::initializer_list<const char*> ss);

	//-------------------------------------------------------------------------
	// Доступ к атрибуту по индексу
	ZSHtmlAttr& operator[] (const long i);

protected:
	// Документирование тега с атрибутами тега
	virtual void Open(FILE* of, int level = 1);
	virtual void Close(FILE* of, int level = 1);

protected:
	void Tab(FILE* of, int level);
};

//-----------------------------------------------------------------------------
#endif //#ifndef ZS_HTML_TEG_H