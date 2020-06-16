//-----------------------------------------------------------------------------
// ZCAlgebraicMDF.h
// А. Николенко 01.04.2019
//
// Алгебраическая апроксимация (модель) дискретно заданной функции.
// Функция апроксимируется полиномами Чебышёва.
// 
// Предполагается следующее:
//		- аргументом апроксимируемой функции является время,
//		- единицей измерения времени являются среднии солнечные сутки,
//		- при определении дискретной функции время задаётся модифицированной 
//		  юлианской датой,
//		- В пределах модели (полинома) время отсчитывается от нуля 
//		  в юлианских днях.
//-----------------------------------------------------------------------------
#ifndef ZC_ALGEBRAIC_MDF_H
#define ZC_ALGEBRAIC_MDF_H

#include <iostream>
#include <fstream>

class ZCAlgebraicMDFManager;

class FLYCORE_API ZCAlgebraicMDF {
	// Диспетчер
	friend ZCAlgebraicMDFManager;
	friend bool operator < (const ZCAlgebraicMDF& M1, const ZCAlgebraicMDF& M2);
public:
	// Конструктор по умолчанию
	ZCAlgebraicMDF();

	// Конструктор копии
	ZCAlgebraicMDF(const ZCAlgebraicMDF& M);
	// Конструктор переноса
	ZCAlgebraicMDF(ZCAlgebraicMDF&& M);
	// Генерирующий конструктор
	// !!!! В случае некорректного исполнения или некорректных исходных
	// данных кидвет исключения.
	ZCAlgebraicMDF(double* T, double* Y, const int N, const int D=12);

	// Оператор копии
	ZCAlgebraicMDF& operator = (const ZCAlgebraicMDF& M);
	// Опереатор переноса
	ZCAlgebraicMDF& operator = (ZCAlgebraicMDF&& M);

	~ZCAlgebraicMDF();

	// Обнулить данные (в том числе и указатель A просто обнуляется)
	void Clr();
	// Удалить память выделенную по указателю A.
	void Del();
	// Скопировать другую модель
	void Cpy(const ZCAlgebraicMDF& M);
	// Перенос другой модели
	void Move(ZCAlgebraicMDF& M);

	// Вычисление значения полинома для времени t, заданному как 
	// модифицированная юлианская дата
	double Calc(double t) const;
	bool   IsDomainFrom(double t) const;

	// Создание полинома - апроксимация по Чебышёву
	int Build(double* T, double* Y, int N, int D = 9);

	// Создание с простым выделением памяти без расчёта полинома
	int Create(int D, double TB, double TE);
	// Загрузка из двоичного хранилища моделей
	int LoadFromStream(ifstream& f, double TimeFrame);
	// Сохранение в двоичном хранилище моделей
	int StoryToStream(ofstream& f);

	// Начало Тайм фрейма на котором определён полином
	double GetBT() const { return begTime; }
	// Конец Тайм фрейма на котором определён полином
	double GetET() const { return endTime; }

	// Степень полинома
	int    GetDegree() const { return Degree; }

	// Признак происхождения модели
	//		0 - загружена из хранилища
	//		1 - сгенерирована по дискретным данным как 
	//			полином Чеьышёва.
	bool   IsGener() const { return isGenerated; }

	// Доступ к коэффициентам модели
	double operator [] (int   i) const { return A[i]; }
	double operator [] (short i) const { return A[i]; }
	double operator [] (long  i) const { return A[i]; }
	double* MA() const { return A; }
	
protected:
	// Признак генерации модели по значениям дискретной функции
	//		true	- модель сгенерирована
	//		false	- модель зкгружена из хранилища
	bool    isGenerated;
	// Степень полинома  
	int     Degree;
	// Область определения модели
	double  begTime;
	double  endTime;
	// Коэффициенты модели 
	double* A;
};

bool operator < (const ZCAlgebraicMDF& M1, const ZCAlgebraicMDF& M2);

//-----------------------------------------------------------------------------
#endif // #ifndef ZC_ALGEBRAIC_MDF_H