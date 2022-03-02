#include "Integrals.h"

// ��������� �� ������ � �������
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


// �������� �� �� ��� ������������� ������ �������� ������ �������
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

        // X - ���������� � �������
    case 'x':
        if (i == text.length())
        {
            break;
        }
        if (text.substr(i - 1, 4) != "exp(" && !ispunct(text[i - 1]) && text[i - 1] != '(' && !ispunct(text[i + 1]) && text[i + 1] != ')') // X ������ ������� � exp() ��� x ������ ������ ����� �������/�������
        {
            error = 4;
        }
        break;
        //-----------------------------------------------------------------
        // ����� ��
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
    // �������� ������ ����� � ���������� ��������
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

        // �������� �� �� ��� ������ �� ������
        if (text.empty())
        {
            cout << "�� ������ �� �����" << endl;
            continue;
        }
        //-----------------------------------------------

        // �������� �� �� ��� � ������� ������ X
        if (text.length() == 1 && text[0] == 'x')
        {
            break;
        }
        //-----------------------------------------------

        // �������� �� �� ��� � ������� ������������ X
        if (text.find('x') == -1)
        {
            cout << "� ������� ���������� ���������� X" << endl;
            continue;
        }
        //--------------------------------------------------------------

        // �������� �� �� ��� ����� �� ����� ����� �� ����������� ������
        for (int i = 0; i < text.length() - 1; i++)
        {
            if (isdigit(text[i]) && text[i + 1] == '(')
            {
                showError(i + 1);
                cout << "����� �� ����� ������ ����� �� ������������� ������: " << i + 1 << " ������" << endl;
                error = 1;
                break;
            }
        }
        //--------------------------------------------------------------

        // �������� �� �� ��� ����� �� ����� ������ �� ����������� ������
        for (int i = 0; i < text.length() - 1; i++)
        {
            if ((text[i] == '(' && text[i + 1] == '-') || (text[i] == '(' && text[i + 1] == ')'))         // ����� ����� ���� ���������� ������� �� ������������� �����
            {
                continue;
            }
            if (text[i] == '(' && ispunct(text[i + 1]) && text[i + 1] != '(')
            {
                if (error == 0)
                {
                    showError(i + 2);
                }
                cout << "���� �� ����� ������ ������ �� ������������� ������: " << i + 2 << " ������" << endl;
                error = 1;
                break;
            }
        }
        //-------------------------------------------------------------------------------------------------------------

        // �������� �� �� ��� � ������ ��� ����������� ��������
        for (int i = 0; i < text.length(); i++)
        {
            for (int j = 0; j < ban.length(); j++)
            {
                if (text[i] == ban[j] || text.find(' ') != -1 || text.find('"') != -1)    // ������ �������� ��� ��������� ��������� �������� ������ �������
                {
                    if (error == 0)
                    {
                        showError(i + 1);
                    }
                    cout << "������ ������������ ������:  " << text[i] << endl;
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

        // �������� �� �� ��� �������������� ����� �� ����� �����
        for (int i = 0; i < text.length() - 1; i++)
        {
            if ((text[i] == '(' && text[i + 1] == '-') || (text[i] == '(' && text[i + 1] == ')'))
            {
                continue;
            }
            if (ispunct(text[i]) && text[i] != ')' && ispunct(text[i + 1]) && text[i + 1] != '(' && text[i] != '*' && text[i + 1] != '-')     // *- ����������
            {
                if (error == 0)
                {
                    showError(i + 1);
                }
                cout << "�������������� ����� �� ������ ������ �����: " << i + 1 << " ������" << endl;
                error = 3;
                break;
            }
            if (error == 3)
            {
                break;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------

        // �������� �� �� ��� ������������������ ������� ������� �����
        int flag = 0;
        text.insert(0, string("1234"));                  // ���������� 4 �������� ������� ��� ���������� ����� �������� � �������
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
                cout << "������� �������� ������������������ �������: ������� ���������� " << i + 1 - 4 << " ��������" << endl;
                break;
            }
        }
        text.erase(0, 4);                                // ��������� ������ 4 �������� ��������
    //---------------------------------------------------------------------------------------------------------------------

    // �������� ������������ ������
        if (text.find("()") != -1)
        {
            cout << "������ ������ �����������" << endl;
            error = 1;
        }

        if (count(text.begin(), text.end(), ')') != count(text.begin(), text.end(), '('))
        {
            if (count(text.begin(), text.end(), ')') > count(text.begin(), text.end(), '('))
            {
                cout << "���������� ����������� ������ ������, ��� �����������" << endl;
            }
            else
            {
                cout << "���������� ����������� ������ ������, ��� �����������" << endl;
            }
            error = 1;
        }
        //-----------------------------------------------------------------------------------------------

        // �������� �� �� ��� � ������ ����������� ������� �����
        for (int i = 0; i < text.length(); i++)
        {
            if ((text[i] >= '�' && text[i] <= '�') || (text[i] >= '�' && text[i] <= '�'))
            {
                if (error == 0)
                {
                    showError(i + 1);
                }
                cout << "������ ������� �������� �����������: " << i + 1 << " ������" << endl;
                error = 1;
                break;
            }
        }
        //-------------------------------------------------------------------------------------------

        // �������� �� ���������� ������������� �����
        for (int i = 1; i < text.length() - 1; i++)
        {
            if (!isdigit(text[i - 1]) && text[i] == '.' && !isdigit(text[i + 1]))
            {
                error = 1;
                cout << "������� ������������ �����" << endl;
                break;
            }
        }
        //----------------------------------------------------------------------------------------------------------------------------------------

        // �������� �� �� ��� ������� ����� � ������� POW()
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
            cout << "���������� ������� �� ������������ ����� ���������� � �������" << endl;
        }
        //------------------------------------------------------------------------------------------

        // �������� �� �� ��� ������������ �� �¨� �������� �����
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
            cout << "��������� �� ����� �������� � ��������� �������� �������" << endl;
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
