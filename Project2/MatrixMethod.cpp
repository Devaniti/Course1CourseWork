#include "matrix.h"
#include "MatrixMethod.h"

matrix MatrixMethod(matrix SLAR, matrix fr)//��������� �����
{
	return SLAR.inverse()*fr;//�������� ������� ��������� �� ������� ��������� ������ ���� � ���������� ������� x'�� ��� ��������� �������
}