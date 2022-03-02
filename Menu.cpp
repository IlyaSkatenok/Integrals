#include "Integrals.h"

void help()
{
    string num;
    do
    {
        do
        {
            system("cls");
            cout << "+---------------------�����������--------------------+" << endl;
            cout << "|���������, ������� �������� ������������:           |" << endl;
            cout << "|D - ��������� ������� � ������� - tan((-5+20*2) * D)|" << endl;
            cout << "|Pi - ����� ��                                       |" << endl;
            cout << "|----------------------------------------------------|" << endl;
            cout << "|�������������� �������:                             |" << endl;
            cout << "|�������                    - cos(x)                 |" << endl;
            cout << "|�����                      - sin(x)                 |" << endl;
            cout << "|������                     - tan(x)                 |" << endl;
            cout << "|��������                   - asin(x), x=[-1,1]      |" << endl;
            cout << "|����������                 - acos(x), x=[-1,1]      |" << endl;
            cout << "|����������                 - atan(x)                |" << endl;
            cout << "|���������� ������          - sqrt(x), x=[0;+inf]    |" << endl;
            cout << "|���������� ������          - cbrt(x)                |" << endl;
            cout << "|������                     - abs(x)                 |" << endl;
            cout << "|����������                 - exp(x)                 |" << endl;
            cout << "|����������� ��������       - log(x), x=(0;+inf]     |" << endl;
            cout << "|���������� � �������       - P(x,y)                 |" << endl;
            cout << "|��������������� �����      - sinh(x)                |" << endl;
            cout << "|��������������� ��������   - asinh(x)               |" << endl;
            cout << "|��������������� �������    - cosh(x)                |" << endl;
            cout << "|��������������� ��������   - acosh(x)               |" << endl;
            cout << "|��������������� ������     - tanh(x)                |" << endl;
            cout << "|��������������� ���������� - atanh(x)               |" << endl;
            cout << "|----------------------------------------------------|" << endl;
            cout << "|�����:                                              |" << endl;
            cout << "|1 - ��������� � ����                                |" << endl;
            cout << "|2 - ��������� � �����������                         |" << endl;
            cout << "+----------------------------------------------------+" << endl;
            getline(cin, num);
        } while (num != "1" && num != "2");
        if (num == "2")
        {
            do
            {
                system("cls");
                cout << "+-----------------------�����������-------------------------+" << endl;
                cout << "|�� ���������� � �������� ������ X                          |" << endl;
                cout << "|e^x ������������ ��� exp(x)                                |" << endl;
                cout << "|(5+x)^3 ������������ ��� P((5+x),3)                        |" << endl;
                cout << "|������� ��� ���������� ��������� ����� b �� ��������� a:   |" << endl;
                cout << "| log(b).a = (log(b).c)/(log(a).c                           |" << endl;
                cout << "|-----------------------------------------------------------|" << endl;
                cout << "|������� ������ ����������:                                 |" << endl;
                cout << "|log(x)+cbrt(x)+sin(60*D)+exp(x*0.0001)                     |" << endl;
                cout << "|(sin(x*D)+cos(x*D))/(exp(1.123)-x)                         |" << endl;
                cout << "|atan(x)+x+P(1.12,x)                                        |" << endl;
                cout << "|-----------------------------------------------------------|" << endl;
                cout << "|�����:                                                     |" << endl;
                cout << "|1 - ��������� � ����                                       |" << endl;
                cout << "|2 - ��������� �����                                        |" << endl;
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
    cout << "|        ��������� ��������� ������      |" << endl;
    cout << "+----------------------------------------+" << endl;
    system("pause");
}

void makeFormula()
{
    CopyFile();
    system("cls");
    cout << "��������! ���� ��������� ����� ��������� ���������, �� ���������� �������� ���� formula.cpp �� ���� formula_copy.cpp ������ �������� _copy" << endl;
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
    cout << "��� ���������� ��������� ������� ���������� ������������� ���������!" << endl;
    system("pause");
}

// �������� �� �� ��� ���� ���� � �� �� ����
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
            cout << "���� c �������� ����" << endl;
            error = 1;
        }
    }
    if (!file.is_open())
    {
        cout << "���� � �������� �� ���������, ������ � ��������� ����������" << endl;
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

// ������� ��� ���������� � ������ ������ � �������� �� �����
void readFormula()
{
    ifstream file("formula.cpp");
    char buffer[200];
    int index = -1;
    do
    {
        index++;
        if (index == 7)                                  // �������� ������ ������
        {
            for (int i = 9; buffer[i] != ';'; i++)
            {
                cout << buffer[i];
            }
        }
        file.getline(buffer, 200);                   // ���������� ����� ������ �����
    } while (!file.eof());
}
//----------------------------------------------------

// ������� ��� �������� ����� �������� � ������
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

// �������� �� ��������� ��� �������
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

// ��������� ���� ����� ���� DOUBLE
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
    cout << "������� ������� --> ";
    readFormula();
    cout << endl << endl;
    string newformula;


    int arrayN[11] = { 100, 250, 500, 1000, 2000, 5000, 10000, 15000, 20000, 35000, 0 }; // ������ �������� N ��� ������ �����������

    do
    {
        cout << "�� ������ �������� �������?(1 - ��/0 - ���)" << endl;
        getline(cin, newformula);
    } while (newformula != "1" && newformula != "0");

    if (newformula == "1")
    {
        makeFormula();
    }

    else
    {
        system("cls");
        cout << "������� ������� --> ";
        readFormula();

        cout << endl << endl;
        string tmp;
        double aL, bH;
        int flag;
        int Incount = 0;

        cout << "������� ����� �������� ����� �������" << endl;
        do
        {
            flag = 1;
            cout << "������� ������ ������ ��������������: ";
            getline(cin, tmp);
            if (CheckEnter(tmp, &flag) == 1)
            {
                double aL2 = stod(tmp);
                aL = aL2;
            }
            else
            {
                cout << "�������� ����!" << endl;
            }
        } while (flag != 1);


        do
        {
            flag = 1;
            cout << "������� ������� ������ ��������������: ";
            getline(cin, tmp);
            if (CheckEnter(tmp, &flag) == 1)
            {
                double bH2 = stod(tmp);
                bH = bH2;
                if (is_equal(bH, aL))
                {
                    cout << "����� ������ ����������!" << endl;
                    flag = 0;
                }
            }
            else
            {
                cout << "�������� ����!" << endl;
                flag = 0;
            }
        } while (flag != 1);

        do
        {
            flag = 1;
            cout << "������� ���������� ��������� ��������� ��� ������� �������� � ��������������: ";
            getline(cin, tmp);
            if (CheckEnter(tmp, &flag) == 1)
            {
                int Incount2 = stoi(tmp);
                Incount = Incount2;
            }

            if (Incount < 1 || Incount > 100000000)
            {
                cout << "�� ����� ������������� ���������� �������� ��� ���� ��������!" << endl;
                flag = 0;
            }
        } while (flag != 1);

        if (!ODZ_cheker(aL, bH, Incount))
        {
            system("cls");
            cout << "�� ������ ��������� ���������� ��� ����� ��� ���������� �������" << endl;
            cout << "��������� ������������ ������� � ���������" << endl;
            cout << "� ������� \"�����������\" �������� ����������� ��� �������" << endl;
        }
        else
        {
            arrayN[10] = Incount;
            system("cls");
            cout << "+-------------------------���������� ����������------------------------+" << endl;
            cout << "|----------------------------------------------------------------------|" << endl;
            cout << "| N    |   ���������������  |     ��������       |        ����c���     |" << endl;
            cout << "|----------------------------------------------------------------------|" << endl;
            for (int i = 0; i < 11; i++)
            {
                cout << "|----------------------------------------------------------------------|" << endl;
                cout << "|" << setw(6) << arrayN[i] << "|" << setw(20) << setprecision(14) << rectangle(aL, bH, arrayN[i]) << "|" << setw(20) << setprecision(14) << trapezoid(aL, bH, arrayN[i]) << "|" << setw(21) << setprecision(14) << Simpson(aL, bH, arrayN[i]) << "|" << endl;
            }
            cout << "+----------------------------------------------------------------------+" << endl;
        }
        // ����� ������ �������
        cout << "������� --> ";
        readFormula();
        cout << endl << "������ ������: " << aL << endl;
        cout << "������� ������: " << bH << endl;
        //-----------------------------------------------------
        system("pause");
    }
}
