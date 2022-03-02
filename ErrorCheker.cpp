#include "Integrals.h"

// УКАЗАТЕЛЬ НА ОШИБКУ В ФОРМУЛЕ
void showError(int number)
{
    for (int i = 0; i < number - 1; i++)
    {
        cout << " ";
    }
    cout << "^" << endl;
    for (int j = 0; j < number - 1; j++)
    {
        cout << " ";
    }
    cout << "|" << endl << endl;
}
//------------------------------------------------


// ПРОВЕРКА НА ТО ЧТО НЕЗАПРЕЩЕННЫЙ СИМВОЛ ЯВЛЯЕТСЯ ЧАСТЬЮ ФУНКЦИИ
void ErrorTrig(string text, int& error, int i)
{
    switch (text[i])
    {
    case 'c':
        if (text.substr(i, 4) != "cos(" && text.substr(i, 5) != "cbrt(" &&
            text.substr(i, 5) != "cosh(" && text.substr(i - 1, 6) != "acosh(")
        {
            error = 4;
        }
        break;
    case 's':
        if (text.substr(i - 3, 5) != "acos(" && text.substr(i - 2, 4) != "cos(" && text.substr(i - 2, 4) != "abs(" && text.substr(i, 4) != "sin(" && text.substr(i, 5) != "sqrt(" &&
            text.substr(i, 5) != "sinh(" && text.substr(i - 1, 6) != "asinh(" && text.substr(i - 2, 5) != "cosh(" && text.substr(i - 3, 6) != "acosh(")
        {
            error = 4;
            break;
        }
        break;
    case 'a':
        if (text.substr(i - 2, 5) != "atan(" && text.substr(i - 1, 4) != "tan(" && text.substr(i, 4) != "abs(" && text.substr(i, 5) != "asin(" && text.substr(i, 5) != "acos(" && text.substr(i, 5) != "atan(" &&
            text.substr(i, 6) != "asinh(" && text.substr(i, 6) != "acosh(" && text.substr(i - 1, 5) != "tanh(" && text.substr(i, 6) != "atanh(" && text.substr(i - 2, 6) != "atanh(")
        {
            error = 4;
            break;
        }
        break;
    case 'e':
        if (text.substr(i, 4) != "exp(")
        {
            error = 4;
        }
        break;
    case 'l':
        if (text.substr(i, 4) != "log(")
        {
            error = 4;
        }
        break;
    case 't':
        if (text.substr(i - 3, 5) != "sqrt(" && text.substr(i - 1, 5) != "atan(" && text.substr(i, 4) != "tan(" && text.substr(i - 3, 5) != "cbrt(" &&
            text.substr(i, 5) != "tanh(" && text.substr(i - 1, 6) != "atanh(")
        {
            error = 4;
            break;
        }
        break;
    case 'n':
        if (text.substr(i - 2, 4) != "tan(" && text.substr(i - 2, 4) != "sin(" && text.substr(i - 3, 5) != "asin(" && text.substr(i - 3, 5) != "atan(" &&
            text.substr(i - 2, 5) != "sinh(" && text.substr(i - 3, 6) != "asinh(" && text.substr(i - 2, 5) != "tanh(" && text.substr(i - 3, 6) != "atanh(")
        {
            error = 4;
            break;
        }
        break;
    case 'o':
        if (text.substr(i - 1, 4) != "log(" && text.substr(i - 1, 4) != "cos(" && text.substr(i - 2, 5) != "acos(" &&
            text.substr(i - 1, 5) != "cosh(" && text.substr(i - 1, 6) != "acosh(")
        {
            error = 4;
            break;
        }
        break;
    case 'r':
        if (text.substr(i - 2, 5) != "sqrt(" && text.substr(i - 2, 5) != "cbrt(")
        {
            error = 4;
            break;
        }
        break;
    case 'b':
        if (text.substr(i - 1, 4) != "abs(" && text.substr(i - 1, 5) != "cbrt(")
        {
            error = 4;
            break;
        }
        break;

        // X - ПЕРЕМЕННАЯ В ФОРМУЛЕ
    case 'x':
        if (i == text.length())
        {
            break;
        }
        if (text.substr(i - 1, 4) != "exp(" && !ispunct(text[i - 1]) && text[i - 1] != '(' && !ispunct(text[i + 1]) && text[i + 1] != ')') // X должен входить в exp() или x должен стоять между знаками/кобками
        {
            error = 4;
        }
        break;
        //-----------------------------------------------------------------
        // ЧИСЛО ПИ
    case 'P':
    {
        if (text[i + 1] != 'i' && text[i + 1] != '(')
        {
            error = 4;
        }
    }
    break;
    case 'i':
        if (text[i - 1] != 'P' && text.substr(i - 1, 4) != "sin(" && text.substr(i - 2, 5) != "asin(" && text.substr(i - 1, 6) != "asinh(" && text.substr(i - 1, 5) != "sinh(")
        {
            error = 4;
            break;
        }
        break;
        //----------------------------------------------------------------
    case 'p':
        if (text.substr(i - 2, 4) != "exp(")
        {
            error = 4;
            break;
        }
        break;
    case 'g':
        if (text.substr(i - 2, 4) != "log(")
        {
            error = 4;
            break;
        }
        break;
    case 'q':
        if (text.substr(i - 1, 5) != "sqrt(")
        {
            error = 4;
            break;
        }
        break;
    case 'h':
        if (text.substr(i - 3, 5) != "tanh(" && text.substr(i - 4, 6) != "atanh(" && text.substr(i - 3, 5) != "sinh(" && text.substr(i - 4, 6) != "asinh(" && text.substr(i - 3, 5) != "cosh(" && text.substr(i - 4, 6) != "acosh(")
        {
            error = 4;
            break;
        }
        break;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

void CopyFile()
{
    // Создание бекапа файла с предыдущей функцией
    ifstream orig;
    ofstream copya;

    orig.open("formula.cpp");
    copya.open("formula_copy.cpp");

    char buffer[250];

    while (!orig.eof())
    {
        orig.getline(buffer, sizeof(buffer));
        copya << buffer << endl;
    }

    orig.close();
    copya.close();
}
//----------------------------------------------------

void Get_error(string& text, string ban, ofstream& f)
{
    int tmp = 0;
    int error = 0;
    do
    {

        getline(cin, text);

        // ПРОВЕРКА НА ТО ЧТО СТРОКА НЕ ПУСТАЯ
        if (text.empty())
        {
            cout << "Вы ничего не ввели" << endl;
            continue;
        }
        //-----------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО В ФОРМУЛЕ ТОЛЬКО X
        if (text.length() == 1 && text[0] == 'x')
        {
            break;
        }
        //-----------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО В ФОРМУЛЕ ПРИСУТСТВУЕТ X
        if (text.find('x') == -1)
        {
            cout << "В формуле отсутсвует переменная X" << endl;
            continue;
        }
        //--------------------------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО ЦИФРЫ НЕ СТОЯТ СЛЕВА ОТ ОТКРЫВАЮЩИХ СКОБОК
        for (int i = 0; i < text.length() - 1; i++)
        {
            if (isdigit(text[i]) && text[i + 1] == '(')
            {
                showError(i + 1);
                cout << "Цифра не может стоять слева от открывающейся скобки: " << i + 1 << " символ" << endl;
                error = 1;
                break;
            }
        }
        //--------------------------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО ЗНАКИ НЕ СТОЯТ СПРАВА ОТ ОТКРЫВАЮЩИХ СКОБОК
        for (int i = 0; i < text.length() - 1; i++)
        {
            if ((text[i] == '(' && text[i + 1] == '-') || (text[i] == '(' && text[i + 1] == ')'))         // Чтобы можно было записывать функции от отрицательных чисел
            {
                continue;
            }
            if (text[i] == '(' && ispunct(text[i + 1]) && text[i + 1] != '(')
            {
                if (error == 0)
                {
                    showError(i + 2);
                }
                cout << "Знак не может стоять справа от открывающейся скобки: " << i + 2 << " символ" << endl;
                error = 1;
                break;
            }
        }
        //-------------------------------------------------------------------------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО В СТРОКЕ НЕТ ЗАПРЕЩЕННЫХ СИМВОЛОВ
        for (int i = 0; i < text.length(); i++)
        {
            for (int j = 0; j < ban.length(); j++)
            {
                if (text[i] == ban[j] || text.find(' ') != -1 || text.find('"') != -1)    // Пробел запрещен для упрощения выявления неверной записи формулы
                {
                    if (error == 0)
                    {
                        showError(i + 1);
                    }
                    cout << "Введен недопустимый символ:  " << text[i] << endl;
                    error = 2;
                    break;
                }
            }
            if (error == 2)
            {
                break;
            }
        }
        //--------------------------------------------------------------------------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО МАТЕМАТИЧЕСКИЕ ЗНАКИ НЕ СТОЯТ РЯДОМ
        for (int i = 0; i < text.length() - 1; i++)
        {
            if ((text[i] == '(' && text[i + 1] == '-') || (text[i] == '(' && text[i + 1] == ')'))
            {
                continue;
            }
            if (ispunct(text[i]) && text[i] != ')' && ispunct(text[i + 1]) && text[i + 1] != '(' && text[i] != '*' && text[i + 1] != '-')     // *- Исключение
            {
                if (error == 0)
                {
                    showError(i + 1);
                }
                cout << "Математические знаки не должны стоять рядом: " << i + 1 << " символ" << endl;
                error = 3;
                break;
            }
            if (error == 3)
            {
                break;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО ТРИГОНОМЕТРИЧЕСКИЕ ФОРМУЛЫ ВВЕДЕНЫ ВЕРНО
        int flag = 0;
        text.insert(0, string("1234"));                  // ДОБАЛЯЮТСЯ 4 СИМВОЛОВ ВНАЧАЛЕ ДЛЯ УМЕНЬШЕНИЯ ЧИСЛА ПРОВЕРОК В ФУНКЦИИ
        if (error != 0)
        {
            flag = 1;
        }
        for (int i = 4; i < text.length() - 1; i++)
        {
            if (text[i] == ')' && isalpha(text[i + 1]))
            {
                error = 4;
            }
            ErrorTrig(text, error, i);
            if (error == 4)
            {
                if (flag == 0)
                {
                    showError(i + 1 - 4);
                }
                cout << "Неверно записана тригонометрическая функция: функция начинается " << i + 1 - 4 << " символом" << endl;
                break;
            }
        }
        text.erase(0, 4);                                // УДАЛЯЮТСЯ ПЕРВЫЕ 4 НЕНУЖНЫХ СИМВОЛОВ
    //---------------------------------------------------------------------------------------------------------------------

    // ПРОВЕРКА СООТВЕТСТВИЯ СКОБОК
        if (text.find("()") != -1)
        {
            cout << "Пустые скобки недопустимы" << endl;
            error = 1;
        }

        if (count(text.begin(), text.end(), ')') != count(text.begin(), text.end(), '('))
        {
            if (count(text.begin(), text.end(), ')') > count(text.begin(), text.end(), '('))
            {
                cout << "Количество закрывающих скобок больше, чем открывающих" << endl;
            }
            else
            {
                cout << "Количество открывающих скобок больше, чем закрывающих" << endl;
            }
            error = 1;
        }
        //-----------------------------------------------------------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО В СТРОКЕ ОТСТУТСВУЮТ РУССКИЕ БУКВЫ
        for (int i = 0; i < text.length(); i++)
        {
            if ((text[i] >= 'А' && text[i] <= 'Я') || (text[i] >= 'а' && text[i] <= 'я'))
            {
                if (error == 0)
                {
                    showError(i + 1);
                }
                cout << "Запись русских символов недопустима: " << i + 1 << " символ" << endl;
                error = 1;
                break;
            }
        }
        //-------------------------------------------------------------------------------------------

        // ПРОВЕРКА НА ПРАВИЛЬНОЕ ИСПОЛЬЗОВАНИЕ ТОЧКИ
        for (int i = 1; i < text.length() - 1; i++)
        {
            if (!isdigit(text[i - 1]) && text[i] == '.' && !isdigit(text[i + 1]))
            {
                error = 1;
                cout << "Неверно использована точка" << endl;
                break;
            }
        }
        //----------------------------------------------------------------------------------------------------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО ЗАПЯТАЯ СТОИТ В СКОБКАХ POW()
        int countPoint = 0;
        for (int i = 0; i < text.length() - 1; i++)
        {
            if (text[i] == 'P' && text[i + 1] == '(')
            {
                i++;
                while (text[i] != ')')
                {
                    if (text[i] == ',')
                    {
                        countPoint++;
                    }
                    i++;
                }
                if (countPoint != 1)
                {
                    error = 5;
                    break;
                }
            }
            countPoint = 0;
        }
        if (error == 5)
        {
            cout << "Количество запятых не соответсвует числу возведений в степень" << endl;
        }
        //------------------------------------------------------------------------------------------

        // ПРОВЕРКА НА ТО ЧТО ПОЛЬЗОВАТЕЛЬ НЕ ВВЁЛ ОГРОМНОЕ ЧИСЛО
        int countDigits = 0;
        int maxcountDigits = 0;
        for (int i = 0; i < text.length(); i++)
        {
            if (isdigit(text[i]))
            {
                countDigits++;
                if (countDigits > maxcountDigits)
                {
                    maxcountDigits = countDigits;
                }
            }
            else
            {
                countDigits = 0;
            }
        }
        if (maxcountDigits > 9)
        {
            error = 6;
            cout << "Программа не может работать с настолько большими числами" << endl;
        }
        //--------------------------------------------------------
        if (error == 0)
        {
            tmp = 1;
        }
        error = 0;
    } while (tmp == 0);

    f << text;
}
