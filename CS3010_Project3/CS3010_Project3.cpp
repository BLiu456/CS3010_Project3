/*
Name: Benjamin Liu
Class: CS3010
Assignment: Programmin Project 3
Due Date: 11/19/2022
*/

#include <iostream>
#include <math.h>
#include <tgmath.h>
using namespace std;

double f1(double);
double f2(double);
void bisection(int, double, double, int, double);
void falsePos();
void newtonRaphson();
void secant();

int main()
{
    int max = 100;
    double a = 0, b = 2;
    bisection(1, a, b, max, 0.00001);
}

//The function f(x) = 2x^3 - 11.7x^2 + 17.7x - 5
double f1(double x)
{
    return ((2 * pow(x, 3)) - (11.7 * pow(x, 2)) + (17.7 * x) - 5);
}
//The function f(x) = x + 10 - xcosh(50/x)
double f2(double x)
{
    return (x + 10 - (x * cosh(50 / x)));
}

void bisection(int func, double a, double b, int max, double err)
{
    double fa = 0, fb = 0, c = 0, fc = 0;
    if (func == 1)
    {
        fa = f1(a);
        fb = f1(b);
    }
    else if (func == 2)
    {
        fa = f2(a);
        fb = f2(b);
    }

    if ((fa < 0 && fb < 0) || (fa >= 0 && fb >= 0))
    {
        //End function since fa and fb have the same sign
        return;
    }

    double error = b - a;

    for (int i = 0; i < max; i++)
    {
        error = error / 2;
        c = a + error;
        if (func == 1)
        {
            fc = f1(c);
        }
        else if (func == 2)
        {
            fc = f2(c);
        }
        //Print i, c, fc, and error

        if (abs(error) < err)
        {
            //Converged
            return;
        }

        if ((fa < 0 && fc < 0) || (fa >= 0 && fc >= 0)) //Checking if signs are same
        {
            a = c;
            fa = fc;
        }
        else
        {
            b = c;
            fb = fc;
        }
    }
}