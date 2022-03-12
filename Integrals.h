#define _USE_MATH_DEFINES
#define D = 3.1415926535 / 180;
#define Pi M_PI
#define P pow

#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iomanip>


using namespace std;


// Функции для MainMenu
void help();

void close();

void EnterFunc();
//---------------

// Функции для файла с формулой
bool isFile();
//--------------

// Функции интегрирования
double formulaFunc( double x);

double rectangle(double aL, double bH, int Incount);                // Прямоугольники

double trapezoid(double aL, double bH, int Incount);                // Трапеция

double Simpson(double aL, double bH, int Incount);                  // Симпсон
//--------------------------------------------------

// Функция поиска ошибки в формуле
void Get_error(string &text, string ban);
//-------------------------------------------------------------
