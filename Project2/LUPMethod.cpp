#include "matrix.h"

matrix LUP(matrix SLAR, matrix fr, int n)//LUP �����
{
	matrix C = SLAR;//������� ����� ������� ������������
	for (int i = 0; i < n; i++)
	{
		//���� ������ � ���������� i'� ������������
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
		C.swaprows(Op, i);//������ ������� ������ � ���������� i'� ������������ � i'�
		fr.swaprows(Op, i);
		for (int j = i + 1; j < n; j++) {
			C[j][i] /= C[i][i]; inc;
			for (int k = i + 1; k < n; k++)
			{
				C[j][k] -= C[j][i] * C[i][k]; inc; inc; iter;//��������������� ������� ����� �������� LU ����������
			}
		}
	}
	matrix L = matrix(n, n), U = matrix(n, n);
	L.makeidendity();//������ ������� L ���������
	for (int i = 0; i<n; i++)
		for (int j = 0; j < i; j++,iter)
			L[i][j] = C[i][j];//��������� ������ ����� ������� C � ������� L
	for (int i = 0; i<n; i++)
		for (int j = 0; j <= i; j++)
			U[j][i] = C[j][i];//��������� ������� ����� ������� C � ������� U
							  //�� ������ ������ ������� L � U ��� ��������� LU ����������� ������� ������������
	matrix y = matrix(n, 1);//������� ������������� ������� y ������� ����� ��� ������� ��������� Ux=y 
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			L.simplerows(i, j, i, fr);//���������������� ������ ����������� �� ���������� ��� ����� ����� ��������� Ly=b 
		}
	for (int i = 0; i<n; i++,iter)
		y[i][0] = fr[i][0] / L[i][i];//����� ���������� L � ��� ������� � ������� ��� �������� ����� ��������� ������� ��������� ������� ����� �������� ����� � y
	matrix x = matrix(n, 1);//���������� ������ ���� x ������� � ����� �������
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