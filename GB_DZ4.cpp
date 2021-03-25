#include <iostream>
using namespace std;


int a = 0, b = 0;

void test1(int a, int b)
{
	
	if ((a + b) >= 10 && (a + b) <= 20)
	{
		cout << " true: " << endl;
		cout << "\t Сумма первого числа со вторым входит в диапазон от 10 до 20 : " << endl;
	}
	else
	{
		cout << " false: " << endl;
		cout << "\t Сумма первого числа со вторым не входит в диапазон от 10 до 20 : " << endl;
	} 
	cout << " a (" << a << ") +  b (" <<b<< ") = " << a + b << endl;
}

void test2(int a, int b)
{
	if (a == 10 && b == 10 || a + b == 10)
	{
		cout << " true: " << endl;
		cout << "\t Оба числа равны десяти сами по себе, либо их сумма равна десяти " << endl;
	}
	else
	{
		cout << " false: " << endl;
		cout << "\t Хотябы одно число не равно десяти сами по себе, и их сумма не равна десяти " << endl;
	}
}

void test3()
{
	cout << " Your numbers: \t";
	for (int i = 1; i < 51; i += 2)
	{
		cout << i << " ";
	}
}

void test4()
{
	int count = 0, a = 0;
	cout << " Введите любое число " << endl;
	cin >> a;

	for (int i = 1; i <= a; ++i)
	{
		if (a % i == 0)
		{
			++count;
		}
	}
	if (count <= 2 && a>0)
	{
		cout << " Число " << a << " простое ";
	}
	else
	{
		cout << " Число " << a << " не является простым ";
	}
}

void test5()
{
	int a = 1;
	do
	{
		cout << " Введите год от 1 до 3000 " << endl;
		cin >> a;
	} 	while (a < 1 || a>3000);
	 
	if (a < 100)
	{
		if (a % 4 == 0)
		{
			cout << " Это високосный год" << endl;
		}
		else
		{
			cout << " Этот не високосный год" << endl;
		}
	}
	else
	{
		int b = a / 100;
		if (b % 4 == 0)
		{
			cout << " Это високосный год" << endl;
		}
		else
		{
			while (a > 100)
			{
				a -= 100;
			}
			if (a % 4 == 0)
			{
				cout << " Это високосный год" << endl;
			}
			else
			{
				cout << " Этот не високосный год" << endl;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << " Введите первое число a: " << endl;
	cin >> a;
	cout << " Введите второе число b:  " << endl;
	cin >> b;
	test1(a, b);
	cout << endl;
	test2(a, b);
	cout << endl;
	test3();
	cout << endl;
	test4();
	cout << endl;
	test5();
	cout << endl;
	
	return 0;
}
