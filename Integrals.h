#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iomanip>


using namespace std;


// ������� ��� MainMenu
void help();

void close();

void EnterFunc();
//---------------

// ������� ��� ����� � ��������
bool isFile();

void CopyFile();
//--------------

// ������� ��������������
double formulaFunc( double x);

double rectangle(double aL, double bH, int Incount);                // ��������������

double trapezoid(double aL, double bH, int Incount);                // ��������

double Simpson(double aL, double bH, int Incount);                  // �������
//--------------------------------------------------

// ������� ������ ������ � �������
void Get_error(string &text, string ban, ofstream &f);
//-------------------------------------------------------------
