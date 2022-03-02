#include "Integrals.h"

void help()
{
    string num;
    do
    {
        do
        {
            system("cls");
            cout << "+---------------------РУКОВОДСТВО--------------------+" << endl;
            cout << "|Константы, которые возможно использовать:           |" << endl;
            cout << "|D - переводит радианы в градусы - tan((-5+20*2) * D)|" << endl;
            cout << "|Pi - число Пи                                       |" << endl;
            cout << "|----------------------------------------------------|" << endl;
            cout << "|Математические функции:                             |" << endl;
            cout << "|Косинус                    - cos(x)                 |" << endl;
            cout << "|Синус                      - sin(x)                 |" << endl;
            cout << "|Тангес                     - tan(x)                 |" << endl;
            cout << "|Арксинус                   - asin(x), x=[-1,1]      |" << endl;
            cout << "|Арккосинус                 - acos(x), x=[-1,1]      |" << endl;
            cout << "|Арктангенс                 - atan(x)                |" << endl;
            cout << "|Квадратный корень          - sqrt(x), x=[0;+inf]    |" << endl;
            cout << "|Кубический корень          - cbrt(x)                |" << endl;
            cout << "|Модуль                     - abs(x)                 |" << endl;
            cout << "|Экспонента                 - exp(x)                 |" << endl;
            cout << "|Натуральный логарифм       - log(x), x=(0;+inf]     |" << endl;
            cout << "|Возведение в степень       - P(x,y)                 |" << endl;
            cout << "|Гиперболический синус      - sinh(x)                |" << endl;
            cout << "|Гиперболический арксинус   - asinh(x)               |" << endl;
            cout << "|Гиперболический косинус    - cosh(x)                |" << endl;
            cout << "|Гиперболический арксинус   - acosh(x)               |" << endl;
            cout << "|Гиперболический тангес     - tanh(x)                |" << endl;
            cout << "|Гиперболический арктангенс - atanh(x)               |" << endl;
            cout << "|----------------------------------------------------|" << endl;
            cout << "|Далее:                                              |" << endl;
            cout << "|1 - Вернуться в меню                                |" << endl;
            cout << "|2 - Подробнее о вычислениях                         |" << endl;
            cout << "+----------------------------------------------------+" << endl;
            getline(cin, num);
        } while (num != "1" && num != "2");
        if (num == "2")
        {
            do
            {
                system("cls");
                cout << "+-----------------------РУКОВОДСТВО-------------------------+" << endl;
                cout << "|За переменную в формулах принят X                          |" << endl;
                cout << "|e^x записывается как exp(x)                                |" << endl;
                cout << "|(5+x)^3 записывается как P((5+x),3)                        |" << endl;
                cout << "|Формула для вычисления логарифма числа b по основанию a:   |" << endl;
                cout << "| log(b).a = (log(b).c)/(log(a).c                           |" << endl;
                cout << "|-----------------------------------------------------------|" << endl;
                cout << "|Примеры записи интегралов:                                 |" << endl;
                cout << "|log(x)+cbrt(x)+sin(60*D)+exp(x*0.0001)                     |" << endl;
                cout << "|(sin(x*D)+cos(x*D))/(exp(1.123)-x)                         |" << endl;
                cout << "|atan(x)+x+P(1.12,x)                                        |" << endl;
                cout << "|-----------------------------------------------------------|" << endl;
                cout << "|Далее:                                                     |" << endl;
                cout << "|1 - Вернуться в меню                                       |" << endl;
                cout << "|2 - Вернуться назад                                        |" << endl;
                cout << "+-----------------------------------------------------------+" << endl;
                getline(cin, num);
            } while (num != "1" && num != "2");
        }
    } while (num != "1");
}

void close()
{
    system("cls");
    cout << "+----------------------------------------+" << endl;
    cout << "|        Программа завершила работу      |" << endl;
    cout << "+----------------------------------------+" << endl;
    system("pause");
}

void makeFormula()
{
    CopyFile();
    system("cls");
    cout << "Внимание! Если программа будет экстренно завершена, то НЕОБХОДИМО заменить файл formula.cpp на файл formula_copy.cpp стерев приписку _copy" << endl;
    ofstream f("formula.cpp");
    string text;
    string ban = "dfjkmuvwyzABCEFGHIJKLMNOQRSTUVWXYZ=|\#@$;%:?&_'<>!~`";
    f << "#define _USE_MATH_DEFINES" << endl;
    f << "#include \"Integrals.h\"" << endl;
    f << "double D = 3.1415926535 / 180;"<< endl;
    f << "#define Pi M_PI" << endl;
    f << "#define P pow" << endl;
    f << "double formulaFunc(double x){" << endl;
    f << "  return ";
    Get_error(text, ban, f);
    f << ";\n}";
    f.close();
    system("cls");
    cout << "ДЛЯ ПРИМЕНЕНИЯ ИЗМЕНЕНИЯ ФУНКЦИИ НЕОБХОДИМО ПЕРЕЗАПУСТИТЬ ПРОГРАММУ!" << endl;
    system("pause");
}

// ПРОВЕРКА НА ТО ЧТО ФАЙЛ ЕСТЬ И ОН НЕ ПУСТ
bool isFile()
{
    ifstream file("formula.cpp");
    int error = 0;
    if (file.is_open())
    {
        string str;
        getline(file, str);
        if (file.eof() && str.empty())
        {
            cout << "Файл c формулой пуст" << endl;
            error = 1;
        }
    }
    if (!file.is_open())
    {
        cout << "Файл с формулой не обнаружен, работа с формулами невозможна" << endl;
        error = 1;
    }
    if (error == 1)
    {
        system("pause");
        return false;
    }
    else
    {
        return true;
    }
}
//-------------------------------------------------------------------------------------

// ФУНКЦИЯ ДЛЯ СЧИТЫВАНИЯ И ВЫВОДА СТРОКИ С ФОРМУЛОЙ ИЗ ФАЙЛА
void readFormula()
{
    ifstream file("formula.cpp");
    char buffer[200];
    int index = -1;
    do
    {
        index++;
        if (index == 7)                                  // Проверка номера строки
        {
            for (int i = 9; buffer[i] != ';'; i++)
            {
                cout << buffer[i];
            }
        }
        file.getline(buffer, 200);                   // Считывание одной строки файла
    } while (!file.eof());
}
//----------------------------------------------------

// ФУНКЦИЯ ДЛЯ ПРОВЕРКИ ВВОДА ЗНАЧЕНИЯ В СТРОКУ
int CheckEnter(string tmp, int* flag)
{
    int pointCount = 0;
    if (tmp.empty() || tmp.length() > 20 || (!isdigit(tmp[0]) && tmp[0] != '-'))
    {
        *flag = 0;
    }
    if (flag != 0)
    {
        for (int i = 1; i < tmp.length(); i++)
        {
            if (tmp[i] == '.' || tmp[i] == ',')
            {
                pointCount++;
            }
            if (!isdigit(tmp[i]) && tmp[i] != '.' && tmp[i] != ',')
            {
                *flag = 0;
                break;
            }
        }
        if (pointCount > 1)
        {
            *flag = 0;
        }
    }
    return *flag;
}
//-------------------------------------------------------

// ПРОВЕРКА НА НАРУШЕНИЕ ОДЗ ФУНКЦИИ
bool ODZ_cheker(double aL, double bH, int Incount)
{
    int arrayODZ[8] = { 5, 250,500, 1000, 2500, 15000,20000, 0 };
    arrayODZ[7] = Incount;
    for (int i = 0; i < 8; i++)
    {
        if (isnan(rectangle(aL, bH, arrayODZ[i])) || isnan(Simpson(aL, bH, arrayODZ[i])) || isinf(rectangle(aL, bH, arrayODZ[i])) || isinf(Simpson(aL, bH, arrayODZ[i])))
        {
            return false;
        }
    }
    return true;
}
//----------------------------------------------------------

// СРАВНЕНИЕ ДВУХ ЧИСЕЛ ТИПА DOUBLE
bool is_equal(double x, double y)
{
    if (!(x > y) && !(y > x))
    {
        return true;
    }
    return false;
}
//--------------------------------

void EnterFunc()
{
    system("cls");
    cout << "Текущая функция --> ";
    readFormula();
    cout << endl << endl;
    string newformula;


    int arrayN[11] = { 100, 250, 500, 1000, 2000, 5000, 10000, 15000, 20000, 35000, 0 }; // МАССИВ ЗНАЧЕНИЙ N ДЛЯ ВЫВОДА РЕЗУЛЬТАТОВ

    do
    {
        cout << "Вы хотите изменить функцию?(1 - ДА/0 - НЕТ)" << endl;
        getline(cin, newformula);
    } while (newformula != "1" && newformula != "0");

    if (newformula == "1")
    {
        makeFormula();
    }

    else
    {
        system("cls");
        cout << "Текущая функция --> ";
        readFormula();

        cout << endl << endl;
        string tmp;
        double aL, bH;
        int flag;
        int Incount = 0;

        cout << "Дробные числа вводятся через запятую" << endl;
        do
        {
            flag = 1;
            cout << "Введите нижний предел интегрирования: ";
            getline(cin, tmp);
            if (CheckEnter(tmp, &flag) == 1)
            {
                double aL2 = stod(tmp);
                aL = aL2;
            }
            else
            {
                cout << "Неверный ввод!" << endl;
            }
        } while (flag != 1);


        do
        {
            flag = 1;
            cout << "Введите верхний предел интегрирования: ";
            getline(cin, tmp);
            if (CheckEnter(tmp, &flag) == 1)
            {
                double bH2 = stod(tmp);
                bH = bH2;
                if (is_equal(bH, aL))
                {
                    cout << "Числа должны отличаться!" << endl;
                    flag = 0;
                }
            }
            else
            {
                cout << "Неверный ввод!" << endl;
                flag = 0;
            }
        } while (flag != 1);

        do
        {
            flag = 1;
            cout << "Введите количество разбиений интеграла для методов трапеции и прямоугольника: ";
            getline(cin, tmp);
            if (CheckEnter(tmp, &flag) == 1)
            {
                int Incount2 = stoi(tmp);
                Incount = Incount2;
            }

            if (Incount < 1 || Incount > 100000000)
            {
                cout << "Вы ввели недостаточное количество участков или ввод неверный!" << endl;
                flag = 0;
            }
        } while (flag != 1);

        if (!ODZ_cheker(aL, bH, Incount))
        {
            system("cls");
            cout << "На данном диапазоне нарушается ОДЗ одной или нескольких функций" << endl;
            cout << "ПРОВЕРЬТЕ ПРАВИЛЬНОСТЬ ФОРМУЛЫ И ДИАПАЗОНА" << endl;
            cout << "В разделе \"Руководство\" написаны ограничения для функций" << endl;
        }
        else
        {
            arrayN[10] = Incount;
            system("cls");
            cout << "+-------------------------РЕЗУЛЬТАТЫ ВЫЧИСЛЕНИЙ------------------------+" << endl;
            cout << "|----------------------------------------------------------------------|" << endl;
            cout << "| N    |   Прямоугольников  |     Трапеции       |        Симпcона     |" << endl;
            cout << "|----------------------------------------------------------------------|" << endl;
            for (int i = 0; i < 11; i++)
            {
                cout << "|----------------------------------------------------------------------|" << endl;
                cout << "|" << setw(6) << arrayN[i] << "|" << setw(20) << setprecision(14) << rectangle(aL, bH, arrayN[i]) << "|" << setw(20) << setprecision(14) << trapezoid(aL, bH, arrayN[i]) << "|" << setw(21) << setprecision(14) << Simpson(aL, bH, arrayN[i]) << "|" << endl;
            }
            cout << "+----------------------------------------------------------------------+" << endl;
        }
        // ВЫВОД ДАННЫХ ФОРМУЛЫ
        cout << "Формула --> ";
        readFormula();
        cout << endl << "Нижний предел: " << aL << endl;
        cout << "Верхний предел: " << bH << endl;
        //-----------------------------------------------------
        system("pause");
    }
}
