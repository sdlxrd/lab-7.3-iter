#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int ZeroElem(int** a, const int rowCount, const int colCount);


int main()
{
	srand((unsigned)time(NULL));
	int n;
	int k;
	cout << "n = "; cin >> n;

	int rowCount = n;
	int colCount = n;
	int Low = -1;
	int High = 1;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	
	cout << "j w max 0 = " << ZeroElem(a, rowCount, colCount) +1 << endl;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;

}

int ZeroElem(int** a, const int rowCount, const int colCount)
{
	int k = 0;
	int nomr = 0;
	int maxk = 0;

	for (int i = 0; i < colCount; i++)
	{
		k = 0;

		for (int j = 0; j < rowCount; j++)
		{
			if (a[j][i] == 0)
				k++;
		}

		if (k >= maxk)
		{
			maxk = k;
			nomr = i;
		}
	}
	return nomr;
}

