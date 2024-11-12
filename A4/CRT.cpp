#include <iostream>
#include <vector>
using namespace std;
int modInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;

    while (a > 1)
    {
        // q = quotient
        q = a / m;
        t = m;

        // m = remainder
        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int chineseRemainderTheorem(const vector<int> &num, const vector<int> &rem)
{
    int prod = 1;
    int result = 0;

    for (int i = 0; i < num.size(); i++)
    {
        prod *= num[i];
    }

    for (int i = 0; i < num.size(); i++)
    {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main()
{
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<int> num(n), rem(n);

    cout << "Enter the values of num[] (moduli): ";
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    cout << "Enter the values of rem[] (remainders): ";
    for (int i = 0; i < n; i++)
    {
        cin >> rem[i];
    }

    int result = chineseRemainderTheorem(num, rem);
    cout << "Result : " << result << endl;

    return 0;
}
