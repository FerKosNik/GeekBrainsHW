#include <iostream>
using namespace std;

void Show(double arr[], int s)
{
	for (int i = 0; i < s; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Show(int arr[], int s)
{
	for (int i = 0; i < s; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Revers(int* arr, int s)
{
	for (int i = 0; i < s; ++i)
	{
		if (arr[i])
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = 1;
		}
	}
}

void Push(int* arr, int s)
{
	int j = 1;
	for (size_t i = 0; i < 8; ++i)
	{
		arr[i] = j;
		j += 3;
	}
}

void Offset(int* arr, int s, int n)
{
		int newarr[10] = { 0 };
		int i = 0;
		if (n < 0)
		{
			for (i = 0; i < s; ++i)
			{
				if (i < s + n)
				{
					newarr[i] = arr[i - n];
				}
				else
				{
					newarr[i] = 0;
				}
			}
		}
		else 
		{
			for (i = s-1; i >= 0; --i)
			{
				if (i >= n)
				{
					newarr[i] = arr[i - n];
				}
				else
				{
					newarr[i] = 0;
				}
			}
		}
		for (i = 0; i < s; ++i)
		{
			arr[i] = newarr[i];
		}
		cout << endl;
}

void checkBalance(int* arr5, int s)
{
	int SumLeft = 0;
	int SumRith = 0;
	bool result = false;
	for (int i = 0; i < s; ++i)
	{
		SumLeft += arr5[i];
		SumRith = 0;
		cout << arr5[i] << " ";
		for (int j = i + 1; j < s; ++j)
		{
			SumRith = SumRith + arr5[j];
		}
		if (SumLeft == SumRith)
		{
			result = true;
			cout << "|| " ;
		}
		
	}
	cout << endl;
	(result) ? cout << "true" : cout << "false" << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");

	{	double arr1[10];
		for (int i = 0; i < 10; ++i)
		{
			arr1[i] = double(rand() % 20) / 10;
		};
		Show(arr1, 10); // функция выводит массив double чисел на экран
		cout << endl;
		cout << endl;
	}

	{
		int arr2[10] = { 0,1,1,0,1,1,1,0,0,0 };

		Show(arr2, 10);
		Revers(arr2, 10); // функция заменяет в принятом массиве 0 на 1, 1 на 0
		Show(arr2, 10);
		cout << endl;
		cout << endl;
	}
	
	{
		int arr3[8] = {0};
		Push(arr3, 8); // функция заполнит массив значениями 1 4 7 10 13 16 19 22
		Show(arr3, 8);
		cout << endl;
		cout << endl;
	}

	{
		int arr4[10] = { 0 };
		for (int i = 0; i < 10; i++)
		{
			arr4[i] = rand() % 40;
		}
		Show(arr4, 10);
		Offset(arr4, 10, 5); // сместить все элементы массива на n(5) позиций
		Show(arr4, 10);
		cout << endl;
		cout << endl;
	}

	{
		const int s = 5;
		int arr5[s] = { 10,1,2,9,4 };
		checkBalance(arr5, 5); // метод возврощает истину если в массиве есть место, в котором сумма левой и правой части массива равны
		cout << endl;
	}
	return 0;

}