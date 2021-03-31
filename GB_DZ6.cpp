#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int SizeArr = 0;
static int connecting = 0;
string bufferGlob[3] = { "name1", "name2", "name3" };

int GetSizeArr()
{
	cout << " Enter size to arr " << endl;
	cin >> SizeArr;
	return SizeArr;
}

void Show(long long* arr, int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << " 2^ " << i << " = " << arr[i] << endl;
	}
}

void Show(int* arr, int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << arr[i] << " ";
	}
}

void Show2(int* arr[], int a)
{
	for (int i = 0; i < a; ++i)
	{
		Show(arr[i], a);
		cout << endl;
	}
	cout << endl;
}

void Content(string cont)
{
	string name;
	
	cout << " Enter the file name: " << endl;
	cin >> name;
	ofstream file(name + ".txt");
	file << cont;
	bufferGlob[connecting++] = name + ".txt";
}

void Connect(string name1, string name2)
{
	string name;
	char buf[255];

	cout << " Enter the name of new merget file: " << endl;
	cin >> name;
	name += ".txt";
	bufferGlob[2] = name;
	
	ifstream file1(name1);
	while (!file1.eof())
	{
		file1.getline(buf, 255); 
		//cout << buf << endl;
	}

	ofstream file;
	file.open(name);
	file << buf;
	file.close();
	
	ifstream file2(name2);
	while (!file2.eof())
	{
		file2.getline(buf, 255);
	}

	file.open (name, ios_base::app);
	file << buf;
	file.close();
	cout << endl;
}

void FindWord()
{
	
	char text[64];
	int choice = 1;
	string word;
	bool flag = false;

	cout << " Enter the word to find in the file " << endl;
	cin >> word;
	do
	{
		cout << " In which file to find for this word? 1, 2 or 3?" << endl;
		cout << " 1. " << bufferGlob[0] << endl;
		cout << " 2. " << bufferGlob[1] << endl;
		cout << " 3. " << bufferGlob[2] << endl;
		cin >> choice;
	} while (choice < 1 || choice > 3);
			
	ifstream file3(bufferGlob[--choice]);
	
	while (!file3.eof())
	{
		file3 >> text;
		if (string(text) == word)
		{
			flag = true; 
		}
		
	}
	
	
	(flag) ?
		cout << " The word " << " < " << word << " > " << " is here!!! <" << bufferGlob[choice] << ">" << endl :
			cout << " The word " << " < " << word << " > " << " is not this < " << bufferGlob[choice] << " > file " << endl;
	
}

int main()
{
	
	{	// test 1
		GetSizeArr();
		long long* Arr = new long long[SizeArr];
		for (int i = 0; i < SizeArr; ++i)
		{
			Arr[i] = (long long)pow(2, i);
		}
		Show(Arr, SizeArr);
		delete[] Arr;
		cout << endl; 
	}

	{	// test 2
		int x = 4, y = 4;
		int** Arr2 = new int* [x];
		
		for (int i = 0; i < x; i++)
		{
			Arr2[i] = new int[y];
			for (int j = 0; j < y; j++)
			{
				Arr2[i][j] = rand() % 100;
			}
		}
		cout << " Matrix 4*4 " << endl;
		Show2(*&Arr2, 4);
		for (int i = 0; i < x; i++)
		{
			delete[] Arr2[i];
		}
		delete[] Arr2;
	}
	
	{	// test 3
		Content("The fully electric Audi RS e - tron GT heralds a new era for the brand with the Four Rings.");
		cout << " File " << bufferGlob[0] << " content : " << endl;
		cout << "The fully electric Audi RS e - tron GT heralds a new era for the brand with the Four Rings." << endl <<endl;
		Content("Learn more about the powerful performance of this forward-looking top athlete. ");
		cout << " File " << bufferGlob[1] << " content : " << endl;
		cout << "Learn more about the powerful performance of this forward-looking top athlete. " << endl << endl;;
	}

	{	// test 4
		Connect(bufferGlob[0], bufferGlob[1]);
	}

	{	// test 5
		FindWord();
	}
	return 0;
}