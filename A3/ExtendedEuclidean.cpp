#include <iostream>
using namespace std;

int extendedEuclideanGCD(int a, int b, int &t1, int &t2){
    if (b == 0)
    {
        t1 = 1;
        t2 = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclideanGCD(b, a % b, x1, y1);
    t1 = y1;
    t2 = x1 - (a / b) * y1;
    return gcd;
}

int main(){
    int a, b, t1, t2;
    cout << "Enter two integers: ";
    cin >> a >> b;
    int gcd = extendedEuclideanGCD(a, b, t1, t2);
    cout << "GCD of " << a << " and " << b << " is " << gcd << endl;
    cout << "Coefficients x and y are: " << t1 << " and " << t2 << endl;
    return 0;
}
