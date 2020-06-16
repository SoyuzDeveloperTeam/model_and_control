//---------------------------------------------------------------------------
// ZCMiniStackKeeper.h
//
// Стек для хзранения двух последних расчитанных или загруженных 
// астрономических данных или геоданных: параметры прецессии, нутации, ПВЗ,
// координаты Солнца и Луны.
//---------------------------------------------------------------------------
#ifndef ZC_MINI_STACK_KEEPER_H
#define ZC_MINI_STACK_KEEPER_H

template<typename T, const int N>
class FLYCORE_API ZCMiniStackKeeper{
public:
	ZCMiniStackKeeper(
				double eps = 1e-8 )	// Точность с которой определяется 
	{								// равенство двух моментоав времени, в ССС. 
		// Значение точности
		e = eps;
		// Признак (индекс) последней записанной строки в массив стека
		SwitchFirst = false;
		// Стек данных обнуляется
		memset(Result, 0, sizeof(Result));
	}

	~ZCMiniStackKeeper(){}

	// Сохранение данных в стеке на момент времени t.
	void Story(double  t,	// Время на котопрое сохраняются данные
			   double* Q,	// Массив сохраняемых данных.
			   int     M=0) // Метод вычислений
	{
		// Смена номера последней записанной строки данных.
		int i1 = SwitchFirst = !SwitchFirst;
		// Запись последних полученных данных в "стек".
		memcpy(&Result[i1][1], Q, N*sizeof(T));
		Method[i1] = M;
	}

	// Проверка наличие данных в стеке на момент времени t
	bool IsExistResultFor(
				double t,		// Время на которое проверяется наличие данных
				T*  Q,			// Массив для возврата данных
				int M=0) const	// Метод вычислений
	{
		int i1 = SwitchFirst;	// индекс последних расчитанных данных
		int i2 =!SwitchFirst;	// индекс предыдущего массива данных
		if (Method[i1] == M && fabs(t - Result[i1][0]) <= e) {
			// Если время совпадает с моментом в "первой" строке,
			// то копируем данные из первой стрпоки
			memcpy(Q, &Result[i1][1], N*sizeof(T));
			// Возвращается признак найденных данных
			return true;
		} else {
			if (Method[i2] == M && fabs(t - Result[i2][0]) <= e) {
				// Если время совпадает с моментом во "второй" строке,
				// то копируем данные из второй стрпоки
				memcpy(Q, &Result[i2][1], N*sizeof(T));
				// Возвращается признак найденных данных
				return true;
		}	}
		// возвращяется признак, того что запрашиваемых данных в стеке нет
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