#include <iostream>
using namespace std;

int euclideanGCD(int a, int b)
{
    if (b == 0)
        return a;

    return euclideanGCD(b, a % b);
}

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int gcd = euclideanGCD(a, b);

    cout << "GCD of " << a << " and " << b << " is " << gcd << endl;

    return 0;
}
