#pragma once
#include <vector>
#include <math.h>
#include "matrix.h"

//Макрос для увеличения количества операций

typedef double matrixtype;
void matrix::makeidendity()//Делает матрицу единичной
{
	if (h != w) throw std::exception();//Если матрица не квадратная выкидываем ошибку
	for (int i = 0; i<h; i++)
	{
		for (int j = 0; j < w; j++,iter)
			m[i][j] = 0;
		m[i][i] = 1;
	}
}
void matrix::swaprows(int a, int b)//Меняет местами строки
{
	if (a == b) return;//Если на вход даны номера одной и той же строки ничего делать не требуеться
	matrixtype t;//Временная переменная
	for (int i = 0; i<w; i++)
	{
		t = m[a][i];
		m[a][i] = m[b][i];
		m[b][i] = t;
		iter;
	}
}
void matrix::tr()//Транспонирует матрицу
{
	if (w == h)//Для моих задач не требуеться транспонировать не квадратную матрицу
	{
		matrixtype t;//Временная переменная
		for (int i = 0; i<w; i++)
			for (int j = i + 1; j<h; j++)
			{
				t = m[i][j];
				m[i][j] = m[j][i];
				m[j][i] = t;
				iter;
			}
	}
}
void matrix::simplerows(int a, int b, int i)//Избавляеться от 1 переменной действиями с матрицей
{
	if (m[a][i] != 0)
	{
		matrixtype koef = -m[b][i] / m[a][i]; inc;//Вычисление коефициента с которым a'я строка прибавиться к b'той
		for (int i = 0; i < w; i++)//Прибавление строк
		{
			m[b][i] += m[a][i] * koef; inc; inc; iter;
		}
	}
}
void matrix::simplerows(int a, int b, int i, matrix &f)//Аналогично предыдущему методу
{
	if (m[a][i] != 0)
	{
		matrixtype koef = -m[b][i] / m[a][i]; inc;
		for (int i = 0; i < w; i++)
		{
			m[b][i] += m[a][i] * koef; inc; inc; iter;
		}
		f[b][0] += f[a][0] * koef; inc; inc;//Обновляем значение матрицы свободных членов
	}
}
void matrix::multiplyrow(int j, matrixtype koef)//Умножение строки на число
{
	for (int i = 0; i < w; i++)
	{
		m[j][i] *= koef; inc; iter;
	}
}
void matrix::transformrows(int r1, int r2, int st, matrix &fr)//Преобразование используемое в методе вращения
{
	if (m[r2][st] != 0)
	{
		double c = m[r1][st] / sqrt(m[r1][st] * m[r1][st] + m[r2][st] * m[r2][st]), s = m[r2][st] / sqrt(m[r1][st] * m[r1][st] + m[r2][st] * m[r2][st]); operations += 10;//Формулы из теории
		for (int i = 0; i < w; i++)
		{
			matrixtype t1 = m[r1][i], t2 = m[r2][i];//Сохраняем старые значения для коректного вычисления новых
			m[r1][i] = c*t1 + s*t2; inc; inc; inc;//Обновляем i'й елемент в строках r1
			m[r2][i] = -s*t1 + c*t2; inc; inc; inc;//r2
			iter;
		}
		matrixtype t1 = fr[r1][0], t2 = fr[r2][0];//Те же действия для матрицы свободных членов
		fr[r1][0] = c*t1 + s*t2; inc; inc; inc;
		fr[r2][0] = -s*t1 + c*t2; inc; inc; inc;
	}
}
double matrix::det()//Вычисление детерминанта
{
	if (w == h)//Данный метод коректно работает только на квадратных матрицах
	{
		int koef = 1;
		matrix copy = *this;//Копируем матрицу чтобы исходная матрица не изменилась после выполнения функции
		int n = copy.w;
		for (int i = 0; i < n - 1; i++)//Делаем матрицу треугольной
		{
			//Ищем строку с наибольшым i'м коефициентом (чтобы избежать деления на 0)
			int Op = -1;
			matrixtype OpV = 0;
			for (int j = i; j<n; j++)
				if (fabs(copy.m[j][i])>OpV)
				{
					OpV = fabs(copy.m[j][i]);
					Op = j;
					iter;
				}
			if (OpV == 0) return 0;//Если наибольний i'й коефициент равен нулю значит матрица вырождения и детерминант равен 0
			{
				copy.swaprows(i, Op);//Меняем строки местами
				if (i != Op) koef *= -1;//Если строки были поменяны местами значит нужно будет домножить результат на -1 (Замене 2х строк местами знак детерминанта меняеться на противоположный)
			}
			for (int j = i + 1; j < n; j++)
				copy.simplerows(i, j, i);//Убираем i'ю переменную со следуйщих строк
		}
		//Если алгоритм дошел сюда то матрица верхнетреугольная
		double ans = 1;
		for (int i = 0; i < n; i++)
		{
			ans *= copy.m[i][i]; inc; iter;//Для вичисления детерминанта треугольной матрицы достаточно перемножить числа на главной диагонали
		}
		inc; return ans*koef;//Возвращаем найденый детерминант на тот коефициент который получили при сведении матрицы к треугольной
	}
	return 0;
}
matrix::matrix(int dh, int dw)//Конструктор
{
	h = dh;//Сохраняем высоту
	w = dw;//и ширину
	m.resize(h);//Измением размер вектора векторов до нужных значений
	for (int i = 0; i < h; i++,iter)
		m[i].resize(w);
}
std::vector < matrixtype > &matrix::operator[](int a)//Позволяет обращаться к елементам матрицы через [][] без обращения к m
{
	return m[a];
}
matrix matrix::operator*(matrix g)//Умножает матрицу на матрицу
{
	if (w != g.h) throw std::exception();//Если матрицы нельзя перемножить (ширина первой не равна высоте второй) выкидывает ошибку
	matrix sol = matrix(h, g.w);//Создаем матрицу для хранения ответа
	for (int i = 0; i < h; i++)
		for (int j = 0; j < g.w; j++)
		{
			sol[i][j] = 0;
			for (int r = 0; r < w; r++)
			{
				sol[i][j] += m[i][r] * g[r][j]; inc; inc; iter;//Считаем по формуле перемноженую матрицу
			}
		}
	return sol;
}
matrix matrix::operator*(matrixtype a)//Умножаем матрицу на число
{
	matrix sol = matrix(h, w);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			sol[i][j] = m[i][j] * a; inc; iter;//Умножаем каждый елемент
		}
	return sol;
}
matrix matrix::operator/(matrixtype a)//Делаит матрицу на число
{
	matrix sol = matrix(h, w);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			sol[i][j] = m[i][j] / a; inc; iter;//Делит каждый елемент
		}
	return sol;
}
matrix matrix::inverse()//Ищет обратную матрицу
{
	matrix inv = matrix(h, 2 * w);//Создает матрицу с присоединенной матрицей
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			inv[i][j] = m[i][j];//Копирует данные из данной матрицы в левую часть созданой
			inv[i][j + w] = 0;//Обнуляет правую часть
			iter;
		}
		inv[i][i + w] = 1;//Заполняет единицами главную диагональ правой части
	}
	for (int i = 0; i < h; i++)
	{
		//Ищем строку с наибольшим i'м коефициентом
		double OpV = 0;
		int Op = -1;
		for (int j = i; j < h; j++)
			if (fabs(inv[j][i]) > OpV)
			{
				OpV = fabs(inv[j][i]);
				Op = j;
			}
		inv.swaprows(Op, i);//Меняем местами строку с наибольшим i'м коефициентом и i'ю
		for (int j = i + 1; j < h; j++)
			inv.simplerows(i, j, i);//Преобразованиями матриц делаем 1 коефициент в матрице нулевым на каждом шаге
	}
	//В данном месте программы матрица уже являеться верхнетреугольной
	for (int i = h - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			inv.simplerows(i, j, i);//Дальше преобразованиями удаляем переменные
									//Теперь все елементы левой части матрицы кроме главной диагонали нулевые
	for (int i = 0; i < h; i++)
		inv.multiplyrow(i, 1 / inv[i][i]);//Домножаем строки матрицы на такие коефициенты чтобы матрица полученая слева была единичной
	matrix ans = matrix(h, w);
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++,iter)
			ans[i][j] = inv[i][j + w];//Переносим присоединенную матрицу в матрицу-ответ
	return ans;//Возвращаем ответ
}
