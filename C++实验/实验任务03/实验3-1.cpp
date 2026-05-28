#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
   int  i;
   double a = 0;
const double epsilon = 0.000001; 
   for(i=1; i<=10; i++) {
      if (i % 2 != 0) {
        int n = (i-1)/2;
        a += pow(-1, n) * (1.0 / (2 * n + 1));
        if (fabs(pow(-1, n) * (1.0 / (2 * n + 1))) < epsilon) {
            break;
        }
        if (fabs(pow(-1, n) * (1.0 / (2 * n + 1))) < epsilon) {
                break;
            }
        }
    }
    cout << fixed << setprecision(6) << a << endl;
    return 0;
}
