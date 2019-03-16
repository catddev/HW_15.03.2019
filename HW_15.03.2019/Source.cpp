#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;

// 1.	Написать программу, которая удаляет из двухмерного массива,
// заполненного случайными числами строки, содержащие нулевые элементы.



// 2.	Написать программу, которая поэлементно суммирует два динамических двумерных массива,
// заполненных случайными числами и сохраняет результат в третьем массиве.
// Размеры исходных массивов  задаются пользователем.


void createArray(int *&a, int n) {
	a = new int[n];
}
void fillArray(int *a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = rand() % 50 - 10;
}
void printArray(const int *a, int n) {
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << " ";
	cout << endl;
}
void deleteArray(int *&a) {
	delete[] a;
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

		}
		break;
		case 2:
		{

		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}