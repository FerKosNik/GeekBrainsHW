#include <iostream>
using namespace std;

void test1()
{
    const int extern a, b, c, d;
    float e;
    e = a * (b + (static_cast<float>(c) / d));
    cout << " e = " << e << endl;
}

void test2()
{
    int a;
    cout << " Введите число для сравнения с 21: ";
    cin >> a;
    a = (a <= 21) ? 21 - a : (a - 21)<<1;
    cout << a << endl << endl;
}

void test3()
{
    int A[3][3][3] = {  {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }},
                        {{ 10, 11, 12 }, { 13, 14, 15 }, { 16, 17, 18 }},
                        {{ 19, 20, 21 }, { 22, 23, 24 }, { 25, 26, 27 }}};
    
    int* arr1;
    
    arr1 = &A[1][1][1];
    cout << "{  {{ 1, 2, 3 }, {  4,  5,  6 }, {  7,  8,  9 }}," << endl;
    cout << "{{ 10, 11, 12 }, { 13, 14, 15 }, { 16, 17, 18 }}," << endl;
    cout << "{{ 19, 20, 21 }, { 22, 23, 24 }, { 25, 26, 27 }}};" << endl << endl;


    cout << "Значение центральной ячейки через разыменование указателя на ячейку [1][1][1]: " << *arr1 << endl <<endl;
    
    cout << "Значение следующей за центральной ячейкой через арифметику указателей: " << *(*(*(A + 1) + 1) + 2) << endl;;

}

int main()
{
    setlocale(LC_ALL, "ru");
    test1();
    test2();
    test3();
}

