#include "matrix.h"
#include "RotationMethod.h"

matrix RotationMethod(matrix SLAR, matrix fr, int n)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = i + 1; j < n; j++)
			SLAR.transformrows(i, j, i, fr);//������ ��� ������ ��������
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
			SLAR.simplerows(i, j, i, fr);//�������� ��� ������ ��������
	}
	matrix sol = matrix(n, 1);
	for (int i = 0; i < n; i++)
	{
		sol[i][0] = fr[i][0] / SLAR[i][i]; inc; iter;//������� ����� � ���������� �������
	}
	return sol;
}
