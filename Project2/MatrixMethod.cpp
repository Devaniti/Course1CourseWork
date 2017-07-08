#include "matrix.h"
#include "MatrixMethod.h"

matrix MatrixMethod(matrix SLAR, matrix fr)//Матричный метод
{
	return SLAR.inverse()*fr;//Обратная матрица умноженая на матрицу свободных членов дает в результате матрицу x'ов что являеться ответом
}