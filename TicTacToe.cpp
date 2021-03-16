#include <iostream>
using namespace std;

struct GamePlace
{
    int player = 0; // Метка какой игрок сделал последний ход
    
    int x = 0, y = 0; // Координаты в таблице 3*3
    
    bool GameOver = false; // Задаем режим для досрочного окончания игры

    char aTool[3][3] = { {'\0','\0','\0'},  {'\0','\0','\0'}, {'\0','\0','\0'} }; // Формируем пустой массив для игры

    void FirstLine() // Рисуем вертикальную линию
    {
        cout << "        *        *        " << endl;
    }

    void SecondLine() // Рисует горизонтальную линию
    {
        cout << "  *  *  *  *  *  *  *  *  " << endl;
    }

    
    void Position() // Вводим позицию для крестика или нолика
    {
        cout << "Insert position for 0: row and stack (0-2): " << endl;
        cout << "row: ";
        cin >> x;
        cout << "stack: ";
        cin >> y;
        if ((x < 0 || x>2) || (y < 0 || y>2)) // Проверка диапазона
        {
            cout << "You out of range! Try agane. " << endl;
            Position();
        }

    }

    void Player1() // Ход первого игрока
    {
        if (GameOver == false)
        {
            cout << " Player 1 ";
            Position();

            if (aTool[x][y] == '\0') aTool[x][y] = 'X';
            else
            {
                cout << " This position is Fulling! Try again " << endl;
                Player1();
            };
            player = 1;
            Result();
        }
    }

    void Player2() // Ход второго игрока
    {
        if (GameOver == false)
        {
            cout << " Player 2 ";
            Position();

            if (aTool[x][y] == '\0') aTool[x][y] = 'O';
            else
            {
                cout << " This position is Fulling! Try again " << endl;
                Player2();
            };
            player = 2;
            Result();

        }
    }

    void Result() // Рисуем новое поле с учетом последнего хода игрока
    {
        system("cls"); // Очистка экрана
        for (int i = 0; i < 3; ++i)
        {
            this->FirstLine();
            for (int j = 0; j < 3; ++j)
            {
                cout << "    " << GamePlace::aTool[i][j] << "    ";
            }
            cout << endl;
            this->FirstLine();
            if (i <= 1) this->SecondLine();
        }
        Test();
    }

    void Test() // Проверяем совпадение линий 
    {
        if ((aTool[0][0] == aTool[0][1] && aTool[0][1] == aTool[0][2] && (aTool[0][0] == 'X' || aTool[0][0] == 'O')) ||
            (aTool[0][0] == aTool[1][1] && aTool[1][1] == aTool[2][2] && (aTool[0][0] == 'X' || aTool[0][0] == 'O')) ||
            (aTool[0][0] == aTool[1][0] && aTool[1][0] == aTool[2][0] && (aTool[0][0] == 'X' || aTool[0][0] == 'O')) ||
            (aTool[1][0] == aTool[1][1] && aTool[1][1] == aTool[1][2] && (aTool[1][0] == 'X' || aTool[1][0] == 'O')) ||
            (aTool[2][0] == aTool[2][1] && aTool[2][1] == aTool[2][2] && (aTool[2][0] == 'X' || aTool[2][1] == 'O')) ||
            (aTool[0][2] == aTool[1][1] && aTool[1][1] == aTool[2][0] && (aTool[0][2] == 'X' || aTool[0][2] == 'O')) ||
            (aTool[0][1] == aTool[1][1] && aTool[1][1] == aTool[2][1] && (aTool[0][1] == 'X' || aTool[0][1] == 'O')) ||
            (aTool[0][2] == aTool[1][2] && aTool[1][2] == aTool[2][2] && (aTool[0][2] == 'X' || aTool[0][2] == 'O')))
        {
            
            cout << " Player " << player << " WON !!!" << endl;

            GameOver = true; // Меняем флажок на игра окончена, при победе одного из играков
        }

    }



};

int main()
{

    GamePlace Gp;
    Gp.Result();
    cout << endl;
    Gp.Player1();
    Gp.Player2();
    Gp.Player1();
    Gp.Player2();
    Gp.Player1();
    Gp.Player2();
    Gp.Player1();
    Gp.Player2();
    Gp.Player1();

    return 0;
}
