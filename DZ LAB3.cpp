#include <iostream>
#include <cmath>

using namespace std;

double f(double a, double b, double x)
{
    return a * x * x * sin(x) + b;
}

int main()
{
    double a, b, x1, x2, eps;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter epsilon: ";
    cin >> eps;


    if (x1 >= x2)
    {
        cout << "Error: x1 must be less than x2" << endl;
        return 1;
    }
    if (eps <= 0)
    {
        cout << "Error: epsilon must be positive" << endl;
        return 1;
    }

    if (f(a, b, x1) * f(a, b, x2) > 0)
    {
        cout << "No root on [x1, x2]" << endl;
        return 1;
    }

    double xmid;
    int iter = 0;

    while ((x2 - x1) > eps)
    {
        xmid = (x1 + x2) / 2.0;
        iter++;

        if (f(a, b, x1) * f(a, b, xmid) <= 0)
            x2 = xmid;
        else
            x1 = xmid;
    }

    xmid = (x1 + x2) / 2.0;

    cout << "Root x = " << xmid << endl;
    cout << "f(x) = " << f(a, b, xmid) << endl;
    cout << "Iterations: " << iter << endl;


}