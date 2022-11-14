/*
Name: Benjamin Liu
Class: CS3010
Assignment: Programmin Project 3
Due Date: 11/19/2022
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <tgmath.h>
using namespace std;

double f1(double);
double f2(double);
void bisection(int, double, double, int, double);
void falsePos(int, double, double, int, double);
void newtonRaphson();
void secant();

int main()
{
    int max = 100;
    string func1 = "2x^3 - 11.7x^2 + 17.7x - 5";
    string func2 = "x + 10 - xcosh(50/x)";
    double a, b;

    cout << "---Bisection Method of f(x) = " << func1 << "---\n";
    cout << "Enter the a value: ";
    cin >> a;
    cout << "Enter the b value: ";
    cin >> b;
    bisection(1, a, b, max, 0.01);

    cout << "\n---False Position of f(x) = " << func1 << "---\n";
    cout << "Enter the a value: ";
    cin >> a;
    cout << "Enter the b value: ";
    cin >> b;
    falsePos(1, a, b, max, 0.01);

    return 0;
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

    cout << "  n  " << setw(8) << "a  " << setw(10) << "f(a)  " << setw(8) << "b  " << setw(10) << "f(b)  " << setw(8) << "c  " << setw(10) << "f(c)  " << setw(7) << "err" << endl;
    cout << "---------------------------------------------------------------------------------------\n";
    if ((fa < 0 && fb < 0) || (fa >= 0 && fb >= 0))
    {
        //End function since fa and fb have the same sign
        cout << setw(3) << 0 << setw(5) << right << a << setprecision(4) << setw(8) << fa << setw(5) << b << setw(8) << fb << endl;
        cout << "Function has same signs at a and b" << endl;
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
        //Print out data in table format
        cout << right << setw(3) << i << "  ";
        cout << right << setfill(' ') << setw(6) << fixed << showpoint << setprecision(4) << a << "  ";
        cout << right << setw(8) << fixed << showpoint << setprecision(4) << fa << "  ";
        cout << right << setw(6) << fixed << showpoint << setprecision(4) << b << "  "; 
        cout << right << setw(8) << fixed << showpoint << setprecision(4) << fb << "  ";
        cout << right << setw(6) << fixed << showpoint << setprecision(4) << c << "  ";
        cout << right << setw(8) << fixed << showpoint << setprecision(4) << fc << "  ";
        cout << right << setw(9) << setprecision(10) << abs(error) << endl;

        if (abs(error) < err)
        {
            cout << "Converged at iteration " << i << ". Root is approximately " << c << endl;
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

void falsePos(int func, double a, double b, int max, double err)
{
    double fa = 0, fb = 0, c = 0, fc = 0, error = 100, prevc;
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

    cout << "  n  " << setw(8) << "a  " << setw(10) << "f(a)  " << setw(8) << "b  " << setw(10) << "f(b)  " << setw(8) << "c  " << setw(10) << "f(c)  " << setw(7) << "err" << endl;
    cout << "---------------------------------------------------------------------------------------\n";
    if ((fa < 0 && fb < 0) || (fa >= 0 && fb >= 0))
    {
        //End function since fa and fb have the same sign
        cout << setw(3) << 0 << setw(5) << right << a << setprecision(4) << setw(8) << fa << setw(5) << b << setw(8) << fb << endl;
        cout << "Function has same signs at a and b" << endl;
        return;
    }

    for (int i = 0; i < max; i++)
    {
        if (i != 0)
        {
            prevc = c;
        }
        c = a - ((fa * (b - a)) / (fb - fa));

        if (func == 1)
        {
            fc = f1(c);
        }
        else if (func == 2)
        {
            fc = f2(c);
        }

        if (i != 0)
        {
            error = (c - prevc) / c;
        }
        //Print out data in table format
        cout << right << setw(3) << i << "  ";
        cout << right << setfill(' ') << setw(6) << fixed << showpoint << setprecision(4) << a << "  ";
        cout << right << setw(8) << fixed << showpoint << setprecision(4) << fa << "  ";
        cout << right << setw(6) << fixed << showpoint << setprecision(4) << b << "  ";
        cout << right << setw(8) << fixed << showpoint << setprecision(4) << fb << "  ";
        cout << right << setw(6) << fixed << showpoint << setprecision(4) << c << "  ";
        cout << right << setw(8) << fixed << showpoint << setprecision(4) << fc << "  ";
        if (i != 0)
        {
            cout << right << setw(9) << setprecision(10) << abs(error) << endl;
        }
        else
        {
            cout << left << setw(9) << "---------" << endl;
        }
        

        if (abs(error) < err)
        {
            cout << "Converged at iteration " << i << ". Root is approximately " << c << endl;
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