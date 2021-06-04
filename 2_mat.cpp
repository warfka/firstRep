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
//--------------------------------------------------------------------------------------------

/*a = x1;
x1 = (10.41 - 4.21 * x2 - 4.12 * x3) / 34.25;
b = x2;
x2 = (20.43 - 1.12 * x1 - 1.52 * x3) / 41.49;
c = x3;
x3 = (12.34 - 2.54 * x1 - 4.85 * x2) / 30.92;
*/
#include <iostream>
using namespace std;
// Вывод системы уравнений
void equaout(double** a, double* y, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "*x" << j;
            if (j < n - 1)
                cout << " + ";
        }
        cout << " = " << y[i] << endl;
    }
    return;
}
double* gauss(double** a, double* y, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.00001;  // точность
    x = new double[n];
    k = 0;
    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            cout << "Решение получить невозможно из-за нулевого столбца ";
            cout << index << " матрицы A" << endl;
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }
        k++;
    }
    // обратная подстановка
    for (k = n - 1; k >= 0; k--)
    {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }
    return x;
}
int main()
{
    double** a, * y, * x;
    int n;

    cout << "Enter the number of equations: ";
    cin >> n;
    a = new double* [n];
    y = new double[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "y[" << i << "]= ";
        cin >> y[i];
    }
    equaout(a, y, n);
    x = gauss(a, y, n);
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "]=" << x[i] << endl;

    return 0;
}

/*
X1=-1,90944*X2-12,17322*X3+4,85826
X2=-8,17577*X1-0,97862*X3+2,47268
X3=-0,73684*X1-27,29605*X2+13,44078
*/

