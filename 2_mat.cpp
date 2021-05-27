#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
float eps = 0.00001;

/*!
	brief Функция сложная для поиска значения Х
*/
float X1(float X2, float X3)
{
	float X1 = (10.41 - 4.21 * X2 - 4.12 * X3)/ 34.25;
	return X1;
}

float X2(float X1, float X3)
{
	float X2 = (20.43 - 1.12 * X1 - 1.52 * X3) / 41.49;
	return X2;
}

float X3(float X1, float X2)
{
	float X3 = (12.34 - 2.54 * X1 - 4.85 * X2) / 30.92;
	return X3;
}

/*!
	\brief Дочерний класс
	\author egor
	\version 1.0
	\date 2021
	\warning Данный класс создан только в учебных целях

	Обычный дочерний класс, который отнаследован от ранее созданного класса Parent
*/
int main(int N, double** A, double* F, double* X)
{
	double* TempX = new double[N];
	double norm; // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.

	do {
		for (int i = 0; i < N; i++) {
			TempX[i] = F[i];
			for (int g = 0; g < N; g++) {
				if (i != g)
					TempX[i] -= A[i][g] * X[g];
			}
			TempX[i] /= A[i][i];
		}
		norm = fabs(X[0] - TempX[0]);
		for (int h = 0; h < N; h++) {
			if (fabs(X[h] - TempX[h]) > norm)
				norm = fabs(X[h] - TempX[h]);
			X[h] = TempX[h];
		}
	} while (norm > eps);
	return 0;
}

/*
X1=-1,90944*X2-12,17322*X3+4,85826
X2=-8,17577*X1-0,97862*X3+2,47268
X3=-0,73684*X1-27,29605*X2+13,44078
*/
