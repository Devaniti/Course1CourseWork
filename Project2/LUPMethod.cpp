#include "matrix.h"

matrix LUP(matrix SLAR, matrix fr, int n)//LUP метод
{
	matrix C = SLAR;//Создаем копию матрицы коефициентов
	for (int i = 0; i < n; i++)
	{
		//Ищем строку с наибольшим i'м коефициентом
		double OpV = 0;
		int Op = -1;
		for (int j = i; j < n; j++,iter)
			if (fabs(C[j][i]) > OpV)
			{
				OpV = fabs(C[j][i]);
				Op = j;
			}
		if (OpV == 0)
		{
			return matrix(n, 1);
		}
		C.swaprows(Op, i);//Меняем местами строку с наибольшим i'м коефициентом и i'ю
		fr.swaprows(Op, i);
		for (int j = i + 1; j < n; j++) {
			C[j][i] /= C[i][i]; inc;
			for (int k = i + 1; k < n; k++)
			{
				C[j][k] -= C[j][i] * C[i][k]; inc; inc; iter;//Преобразовываем матрицу чтобы получить LU разложение
			}
		}
	}
	matrix L = matrix(n, n), U = matrix(n, n);
	L.makeidendity();//Делаем матрицу L единичной
	for (int i = 0; i<n; i++)
		for (int j = 0; j < i; j++,iter)
			L[i][j] = C[i][j];//Переносим нижнюю часть матрицы C в матрицу L
	for (int i = 0; i<n; i++)
		for (int j = 0; j <= i; j++)
			U[j][i] = C[j][i];//Переносим верхнюю часть матрицы C в матрицу U
							  //На данный момент матрицы L и U уже являються LU разложением матрицы коефициентов
	matrix y = matrix(n, 1);//Создаем промежуточную матрицу y которая нужна для решения уравнения Ux=y 
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			L.simplerows(i, j, i, fr);//Преобразованиями матриц избавляемся от переменных тем самым решая уравнение Ly=b 
		}
	for (int i = 0; i<n; i++,iter)
		y[i][0] = fr[i][0] / L[i][i];//После приведения L в вид матрицы у которой все елементы кроме елементов главной диагонали нулевые можем записать ответ в y
	matrix x = matrix(n, 1);//Аналогично решаем ищем x который и будет ответом
	matrix U1 = U;
	for (int i = n - 1; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			U.simplerows(i, j, i, y);
	for (int i = 0; i < n; i++)
	{
		x[i][0] = y[i][0] / U[i][i]; inc; iter;
	}
	return x;
}