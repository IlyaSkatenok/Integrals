#define _USE_MATH_DEFINES
#include "Integrals.h"
double D = 3.1415926535 / 180;
#define Pi M_PI
#define P pow
double formulaFunc(double x){
  return sqrt(x-exp(x*0.05))+tan(x*D);
}