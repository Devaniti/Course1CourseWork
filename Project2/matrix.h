#pragma once
#include <vector>//Нужен для хранения матрицы
#include <math.h>//Нужен для вычисления корня в методе вращения
extern int operations, iterations;// Об'явлены в MyForm.h
#define inc operations++//Макрос для увеличения количества операций
#define iter iterations++//Макрос для увеличения количества итераций
typedef double matrixtype;//Можно изменить тип данных в котором будут храниться елементы в матрице
struct matrix//Пользовательская структура для хранения и обработки матриц
{
	std::vector < std::vector < matrixtype > > m;//m содержит в себе значение всех ячеек матрицы
	int h, w;//Высота Ширина
	void makeidendity();//Делает матрицу единичной
	void swaprows(int a, int b);//Меняет местами строки
	void tr();//Транспонирует матрицу
	void simplerows(int a, int b, int i);//Избавляеться от 1 переменной действиями с матрицей
	void simplerows(int a, int b, int i, matrix &f);//Этот вариант также делает соответственные преобразование с матрицей свободных коефициентов
	void transformrows(int r1, int r2, int st, matrix &fr);//Изменяет строки в соответствии с методов вращения
	void multiplyrow(int j, matrixtype koef);//Умножает строку на число
	double det();//Вычисляет детерминант
	matrix(int dh, int dw);//Конструктор (инициализирует m,и сохраняет высоту и ширину)
	std::vector < matrixtype > &operator[](int a);//Позволяет обращаться к елементам матрицы через [][] без обращения к m
	matrix operator*(matrix g);//Умножение на матрицу
	matrix operator*(matrixtype a);//Умножение на число
	matrix operator/(matrixtype a);//Деление на число
	matrix inverse();//Вычисление обратной матрицы (Асимптотика O(N*N*N))
};