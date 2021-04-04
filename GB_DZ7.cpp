#include <iostream>
#include <string>
#include <fstream>
#include "mylib.h"
using namespace std;

#define value1 int val1; std::cin >> val1;
#define value2 int val2; std::cin >> val2;

#define SizeArray  int sizeArr; \
std::cin >> sizeArr;

#define SwapINT(a,b) int temp = a; a = b; b = temp;

const int sz = 5;
float arr[sz] = { 0.00 };

void Check()
{
	std::cout << " Введите число для проверки " << std::endl;
	value1;
	std::cout << " Введите верхнюю границу диапазонв проверки " << std::endl;
	value2;
	(val1 > 0 && val1 <= val2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
}

void Show(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void Sort()
{
	std::cout << " Введите размер массива " << std::endl;
	SizeArray;

	int* arr = new int[sizeArr];

	for (int i = 0; i < sizeArr; ++i)
	{
		arr[i] = rand() % 100;
	};

	Show(arr, sizeArr);
	std::cout << std::endl;

	for (int i = 0; i < (sizeArr-1); ++i)
	{
		for (int j = i+1; j < sizeArr; ++j)
		{
			if (arr[i] > arr[j])
			{
				SwapINT(arr[i], arr[j]);
			}
		}
	};
	Show(arr, sizeArr);
}



	void SaveFile()
	{
	#pragma pack(push, 1)
	struct Stuff
	{
		string name; // 1 byte
		short var1; // 2 bytes
		string post; // 1 byte
		int var2; // 4 byte
	};
	#pragma pack(pop)
		
	Stuff *Ivanov = new Stuff;
	Ivanov->name = " Ivanov Sergei Petrovich";
	Ivanov->var1 = 23;
	Ivanov->post = "Director";
	Ivanov->var2 = 120'000;

	ofstream fout;
	fout.open("data.txt", ios_base::trunc);
	fout << Ivanov->name << " ";
	fout << Ivanov->var1 << " ears old ";
	fout << Ivanov->post << " ";
	fout << Ivanov->var2 << " RUB ";
	
	fout.close();
	}

int main()
{
	setlocale(LC_ALL, "ru");
	MySpace::PushArray(arr, sz); // test1 and test 5
	MySpace::Show(arr, sz);
	MySpace::Couner(arr, sz);
	 
	Check(); // test 2
	 
	Sort(); // test 3
		
	SaveFile(); // test 4
	
	return 0;
}