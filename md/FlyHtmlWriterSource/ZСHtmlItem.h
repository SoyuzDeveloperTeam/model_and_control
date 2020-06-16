//-----------------------------------------------------------------------------
// ZСHtmlItem.h
//-----------------------------------------------------------------------------
#pragma once
#include <FlyHtmlWriterSource\\ZSHtmlAtribute.h>
#include <FlyHtmlWriterSource\\ZСHtmlTeg.h>

class ZCHtmlBuilder;

//-----------------------------------------------------------------------------
// Элемент документа в формате HTML - 
// - любой тег с возможными атрибутами, текстом и вложенными дочерними тегами.
// Каждый дочерний тег также может иметь дочернии теги.
// Тест как и атрибуты являются необязательными элементами и могут 
// отсутствовать. Обязательным и неотъемлемым элементом тега является его имя,
// например: "p", "div", "a" ...
//-----------------------------------------------------------------------------
class FLY_HTML_WRITER_API ZСHtmlItem : public ZСHtmlTeg {
	friend ZCHtmlBuilder;
public:
	// Текст выводимый в пределах тега
	string txt;
	// Позиция отображения текста txt среди вложенных тегов
	char   txtPos;

	//-------------------------------------------------------------------------
	// Цепочка тегов
	class ZChain{
		friend ZСHtmlItem;
	protected:
		vector<ZСHtmlTeg> t;
	public:
		ZChain()  {}
		~ZChain() { t.clear(); }

		int  CountItem() const { return t.size(); }
		void Clear() { t.clear(); }

		ZСHtmlTeg& operator() (const long i = -1) {
			int j = i;
			int n = t.size();
			if (j < 0) j = n ? n - 1 : 0;
			if (j >= n) t.resize(j + 1);
			return t[j];
		}
	} C;
	//-------------------------------------------------------------------------

protected:
	// Массив вложенных тегов
	vector<ZСHtmlItem> nestedItems;
	// Уровень вложенности тега
	char level;

public:
	ZСHtmlItem(const char* tegName = nullptr, int textPos = 0,
		char* text = nullptr, vector<ZSHtmlAttr>* atribut = nullptr);
	~ZСHtmlItem();

	// Конструкторы копирования и перемещения
	ZСHtmlItem(const ZСHtmlItem& I);
	ZСHtmlItem(ZСHtmlItem&& I);

	// Копирование и перемещение
	ZСHtmlItem& operator = (const ZСHtmlItem& I);
	ZСHtmlItem& operator = (ZСHtmlItem&& I);

	//-------------------------------------------------------------------------
	// Дабавить дочерний тег.
	// Тег добавляется в конец списка дочерних тегов методом 
	// перемещения, то есть исходная структура данных, содержащая
	// добавляемый тег после завершения операции остаётся пустой.
	// Используется vove-семантик C++ 11.
	// Данный подход используется для повышения бысмтродействия.
	ZСHtmlItem& operator << (ZСHtmlItem& I);
	ZСHtmlItem& operator << (char* s);

	//-------------------------------------------------------------------------
	// Доступ к дочерним тегам по индексу
	// Если индекс не задавать, то возвращается ссылка на последний 
	// дочерний тег. Если индекс выходит за границу массива, то массив
	// автоматически дополняется пустыми тегами.
	ZСHtmlItem& operator() (const long i = -1);

	int CountItems() const;

protected:
	void Open(FILE* of);
	void Close(FILE* of);
	void PrintText(FILE* of);
	void Self(FILE* of);

private:
	ZСHtmlItem& Move(ZСHtmlItem&& I);
	ZСHtmlItem& Copy(const ZСHtmlItem& I);
};