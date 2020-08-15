#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double a, b, c, d;

double fx(double x) 
{
    return a*pow(x, 3) + b*pow(x, 2) + c*x + d;
}

int main() 
{
    int count = 0;
    cin >> a >> b >> c >> d;

    for (double i = -100; i <= 100; i++) 
    {
        double l = i;
        double r = i + 1;
        double x1 = fx(l);
        double x2 = fx(r);

        if (!x1) 
        {
            cout << fixed << setprecision(2) << l << ' ';
        }
        if (x1 * x2 < 0) 
        {
            while (r - l >= 0.001)
            {
                double mid = (l + r) / 2;
                if (fx(mid) * fx(r) <= 0) l = mid;
                else r = mid;
            }
            count++;
            cout << fixed << setprecision(2) << l << ' ';
        }

        if (count == 3) break;
    }

    return 0;
}