// Скатенок Илья 21-ПРИ
// Тема: Приближенное вычисление определенного интеграла


#include "Integrals.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int menuEnd = 0;
    string menu;
    if (isFile())
    {
        do
        {
            do
            {
                system("cls");
                cout << "+---ВЫЧИСЛЕНИЕ ОПРЕДЕЛЕННЫХ ИНТЕГРАЛОВ---+" << endl;
                cout << "|1 - Руководство                         |" << endl;
                cout << "|2 - Вычисление интеграла                |" << endl;
                cout << "|3 - Выход                               |" << endl;
                cout << "+----------------------------------------+" << endl;
                getline(cin, menu);
            } while (menu != "1" && menu != "2" && menu != "3");
            switch (stoi(menu))
            {
            case 1:
                help();
                break;
            case 2:
                EnterFunc();
                break;
            case 3:
                close();
                menuEnd = 1;
                break;
            }
        } while (menuEnd != 1);
    }
    return 0;
}
