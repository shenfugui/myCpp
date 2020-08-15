#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main() {
    double n;
    cin >> n;
    const double eps = 1e-7;
    
    double l = -10000, r = 10000;
    while (r-l > eps) {
        double mid = (l+r)/2;
        if (pow(mid, 3) >= n) r = mid;
        else l = mid;
    }
    
    cout << fixed << setprecision(6) << l;
    
    return 0;
}