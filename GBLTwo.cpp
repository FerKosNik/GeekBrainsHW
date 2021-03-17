#include <iostream>

 // Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики //

enum TikTakToe { X, O, _ };

//==========================================================================================//

/*  **Создать структуру (struct) объединяющую: union (int, float, char) и 
3-и битовых поля (флага) указывающими какого типа значение в данный момент содержится в объединении (isInt, isFloat, isChar) */

struct MyFlag
{
    unsigned int isInt : 1;
    unsigned int isFloat : 1;
    unsigned int isChar : 1;
    
    union MyUnion
    {
        int nVal;
        float fVal;
        char cVal;
    };
    
};

  /*===========================================================================================================================*/

    
    //* Создать структуру (struct) данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами (подумайте что может понадобиться)//

struct MyGame
{
    int player = 0; // Метка какой игрок сделал последний ход

    int x = 0, y = 0; // Координаты в таблице 3*3

    bool GameOver = false; // Задаем режим для досрочного окончания игры
    
    char aTool[3][3] = { {'X','\0','O'},  {'\0','X','\0'}, {'O','\0','X'} }; // Формируем пустой массив для игры
    
    void VerLine() // Рисуем вертикальную линию
    {
        for (int i = 0; i < 2; ++i)
        {
            std::cout << "        |";
        }
            std::cout << std::endl;
    }
    void HorLine() // Рисует горизонтальную линию
    {
        for (int i = 0; i < 8; ++i)
        {
            std::cout << "  -"; 
        }
        std::cout << std::endl;
    }

    void GPlace() // Рисуем новое поле с учетом последнего хода игрока
    {
        
        for (int i = 0; i < 3; ++i)
        {
            VerLine();
            for (int j = 0; j < 3; ++j)
            {
                if (j < 2)
                {
                    std::cout << "    " << aTool[i][j] << "   |";
                }
                else std::cout << "    " << aTool[i][j] << "   ";
            }
            std::cout << std::endl;
            VerLine();
            if (i <= 1) HorLine();
        }
    }
};

     //==================================================================================================================//

int main()
{
    // Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double)//
    
    short int nVar;
    nVar = 32'767;
    int iVar {}; //присвоение 0 при инициализации {}
    long long lVar { 9'223'372'036'854'775'807 };
    char cVar = 'C';
    float fVar = 3.1417;
    bool bIsTrue = true;
    double dVar (9.81);

    //=======================================================================================================================//

    std::cout << "nVar = " << nVar << std::endl;
    std::cout << "iVar = " << iVar << std::endl;
    std::cout << "lVar = " << lVar << std::endl;
    std::cout << "cVar = " << cVar << std::endl;
    std::cout << "fVar = " << fVar << std::endl;
    std::cout << "bIsTrue = " << bIsTrue << std::endl;
    std::cout << "dVar = " << dVar << std::endl;
    std::cout << std::endl;

    // Создать массив, способный содержать значения такого перечисления и инициализировать его //
    
    TikTakToe Items [3] = { X,O,_}; // Массив на основе списка

    //========================================================================================//

    
    // Отрисовка игрового поля по структуре заданной выше //
    
    MyGame mg;
    mg.GPlace(); // Рисуем рабочее поля для игры
    
                 //===================================================//


    // Продемонстрировать пример использования в коде структуры из 5-го задания //

    MyFlag::MyUnion a;
    MyFlag f;
        
    int Temp = a.nVal = -507;
    
    float Temp1 = a.fVal = 1.2;
    
    char Temp2 = a.cVal = '9';

    if (Temp1 == a.fVal)
    {
            f.isInt = 0;
            f.isFloat = 1;
            f.isChar = 0;
    }
    else
    {
        if (Temp2 == a.cVal)
        {
            f.isInt = 0;
            f.isFloat = 0;
            f.isChar = 1;
        }
        else
        {
            f.isInt = 1;
            f.isFloat = 0;
            f.isChar = 0;
        };
    };
    
    std::cout << " a.nVal = " << a.nVal << "\t a.fVal = " << a.fVal << "\t a.cVal = " << a.cVal << std::endl;
    std::cout << " f.isInt = " << f.isInt << "\t f.isFloat = " << f.isFloat << "\t f.isChar = " << f.isChar << std::endl;
    
    //=======================================================================================================//

    return 0;
}