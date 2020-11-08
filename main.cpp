#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <cmath>

using namespace std;

double func(double x, double y)
{
	return 1 - pow(x, 4) - pow(y, 4);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double x_min = 0.;
	double x_max = 1.;
	double y_min = 0.;
	double y_max = 1.;
	int N = 0;
	cout << " ������ ����� ���������: ";
	cin >> N;
	int M = 0;
	double S0 = (x_max - x_min) * (y_max - y_min);
	srand(time(NULL));
    double sum = 0;
	for (int i = 0; i < N; i++)
	{
		double r1 = double(rand()) / RAND_MAX; // ��������� �������������� ��������� �������� ��� ���������� � �� ��������� [0,1]
		double r2 = double(rand()) / RAND_MAX; // ��������� �������������� ��������� �������� ��� ���������� � �� ��������� [0,1]
		double x = x_min + r1 * (x_max - x_min);  // ��������� ���������� �� �
		double y = y_min + r2 * (y_max - y_min);  // ��������� ���������� �� �
		if (x > 0 && y > 0 && 0.25 < pow(x, 2) + pow(y, 2) && pow(x, 2) + pow(y, 2) < 1)
		{
			sum += func(x, y);
			M = M + 1;
		}
	}
	double F_avg = sum / (double)M;
	double S = S0 * (double)M / (double)N;

    double V = F_avg * S;
	cout << " ��������������� ����� �� ������ ����� - ����� �����  = " << " " << V << endl;
	cout << " ��� ���������� ���������: " << N << endl;
	getchar(); getchar();

	return 0;
}