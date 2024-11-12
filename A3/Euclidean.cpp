#include <iostream>
using namespace std;
int euclideanGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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
