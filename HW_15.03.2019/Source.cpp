#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;

void fill_matrix(int **pp, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			pp[i][j] = rand() % 21;
}
void print_matrix(int**pp, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << left << pp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void delete_matrix(int**pp, int n, int m) {
	for (int i = 0; i < n; i++)
		delete[] pp[i];
	delete[] pp;
}
void erase_line(int **&pp, int &n, int m, int pos) {
	int **tmp = new int*[n - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = pp[i];

	for (int i = pos + 1; i < n + 1; i++)
		tmp[i - 1] = pp[i];

	delete[] pp;
	pp = tmp;
	n--;
}
// 1.	Написать программу, которая удаляет из двухмерного массива,
// заполненного случайными числами строки, содержащие нулевые элементы.
void eraseNullRows(int **&pp, int &n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (pp[i][j] == 0)
			{
				erase_line(pp, n, m, i);
				break;
			}
		}
	}
}

// 2.	Написать программу, которая поэлементно суммирует два динамических двумерных массива,
// заполненных случайными числами и сохраняет результат в третьем массиве.
// Размеры исходных массивов  задаются пользователем.
int** sum_matrix(int**a, int**b, int n, int m) {
	int **c = new int*[n];
	for (int i = 0; i < n; i++)
		c[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			c[i][j] = a[i][j] + b[i][j];

	return c;
	delete_matrix(c, n, m); // можно и после return чистить память?
}





int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			int **pp, n, m;
			cin >> n >> m;
			pp = new int*[n];
			for (int i = 0; i < n; i++)
				pp[i] = new int[m];
			fill_matrix(pp, n, m);
			print_matrix(pp, n, m);
			eraseNullRows(pp, n, m);
			print_matrix(pp, n, m);
			delete_matrix(pp, n, m);
		}
		break;
		case 2:
		{
			int **a, **b, **AB;
			int n, m;
			cin >> n >> m;
			a = new int*[n];
			b = new int*[n];

			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
				b[i] = new int[m];
			}
			fill_matrix(a, n, m);
			fill_matrix(b, n, m);
			print_matrix(a, n, m);
			print_matrix(b, n, m);

			AB=sum_matrix(a, b, n, m);
			print_matrix(AB, n, m);

			delete_matrix(a, n, m);
			delete_matrix(b, n, m);
			// delete_matrix(AB, n, m);
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}